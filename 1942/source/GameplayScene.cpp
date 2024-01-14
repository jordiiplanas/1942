#include "GameplayScene.h"

void GameplayScene::OnEnter()
{
    isPaused = false;
    nextScene = "MainMenu";

    if (!hasAlreadyStarted)
    {

        player = new Player(Vector2(250, 350));
        SPAWNER.InsertObject(player);

        AUDIOMANAGER.PlayMusic(AUDIOMANAGER.LoadMusic("resources/audios/musiquita.mp3"));

        Vector2 initialPos = Vector2(0, -64);
        Vector2 limitsPos = Vector2(512, 512);

        //BACKGROUND
        int counter = 0;
        background.push_back(new Background(Vector2(512, 512), 59));
        background.push_back(new Background(Vector2(512, 512), 59));
        background[0]->ChangeAnimation("initial");
        background[1]->SetPosition(Vector2(0, -512));
        // UI
        scoreUi = new UiText("SCORE: 0", Vector2(60, 30));
        ui.push_back(new UiText("Lifes:", Vector2(40, 480)));
        ui.push_back(new UiText("Rolls:", Vector2(310, 480)));
        ui.push_back(scoreUi);
    }
    else
    {
        player->ShowStatsUI();
    }


    Transform* transform = player->GetTransform();

    // WAVES
    stages = GetStagesFromFile("stage-", "-waves.xml", transform);
    if (stages.size() > 0) currentStage = stages[0];
    currentStageIndex = 0;

    hasAlreadyStarted = true;
}


void GameplayScene::Update(float dt)
{

    if (inputManager.CheckKeyState(SDLK_ESCAPE, PRESSED)) isPaused = !isPaused;
    if (isPaused) return;

    // UPDATE Background

    for (Object* o : background)
    {
        o->Update(dt);
    }

    // ENDED GAME updates

    if (isEnded)
    {
        player->Update(dt);
        for (auto back : background)
        {
            if (dynamic_cast<Background*>(back)->hasChangedToEnd)
            {
                if (back->GetPosition().y >= 0)
                {
                    //END
                    NextStage();
                }
            }
        }
       
        return;
    }

    // WAVES

    currentStage->Update(dt);
    if (currentStage->IsFinished() && !isEnded)
    {
        // Cambio de escena
        EndStage();
        isEnded = true;
    }

    // UPDATE OBJECTS
    std::cout << "Spawned enemies: " << spawnedEnemies << "  Killed Enemies: " << killedEnemies << std::endl;
    for (Object* o : objects)
    {
        if (o->IsPendingDestroy())
        {
            if (dynamic_cast<EnemyPlane*>(o))
            {
                if (dynamic_cast<EnemyPlane*>(o)->GetHealth() <= 0)
                {
                    killedEnemies++;
                }
            }
            o->Update(dt);
            objects.erase(std::remove(objects.begin(), objects.end(), o), objects.end());
            continue;
        }
        o->Update(dt);
    }

    for (Object* o : ui)
    {
        o->Update(dt);
    }
    scoreUi->ChangeText("SCORE: " + std::to_string(SCOREMANAGER.GetScore()));

    // COLLISIONS

    for (Object* o : objects)
    {
        for (Object* a : objects)
        {
            if (o == a)
                continue;

            if (o->GetRigidbody()->CheckCollision(a->GetRigidbody()))
                o->OnCollisionEnter(a);
        }
    }

    // SPAWN ELEMENTS

    if (SPAWNER.CanSpawn())
    {
        Object* o = SPAWNER.SpawnObject();
        if (dynamic_cast<EnemyPlane*>(o)) spawnedEnemies++;
        objects.push_back(o);
    }

    if (player->GetLives() <= 0)
    {
        Reset();
        player->Heal();
        isFinished = true;
        nextScene = "WritePuntuation";
    }
}

void GameplayScene::Render()
{

    for (Object* o : background)
    {
        o->Render();
    }
    if (isEnded)
    {
        player->Render();
        return;
    }
    for (Object* o : objects)
    {
        o->Render();
    }
    for (Object* o : ui)
    {
        o->Render();
    }

}

void GameplayScene::EndStage()
{
    if (background[0]->GetPosition().y < background[1]->GetPosition().y)
    {
        dynamic_cast<Background*>(background[1])->toEnd = true;
    }
    else
    {
        dynamic_cast<Background*>(background[0])->toEnd = true;
	}
}

void GameplayScene::Reset()
{
    for (Object* o : objects)
	{
        if (dynamic_cast<Player*>(o)) continue;
		o->Destroy();
	}
	objects.clear();
    objects.push_back(player);
	isEnded = false;
    SPAWNER.CleanList();
	background[0]->SetPosition(Vector2(0, -512));
	background[1]->SetPosition(Vector2(0, 0));
	dynamic_cast<Background*>(background[0])->hasChangedToEnd=false;
    dynamic_cast<Background*>(background[0])->toEnd=false;
    dynamic_cast<Background*>(background[1])->hasChangedToEnd=false;
    dynamic_cast<Background*>(background[1])->toEnd = false;
    player->ShowStatsUI();
    background[0]->ChangeAnimation("idle");
	background[1]->ChangeAnimation("initial");

}

void GameplayScene::NextStage()
{
    if (stages.size() > ++currentStageIndex)
	{
		currentStage = stages[currentStageIndex];
        Reset();
	}
	else
	{
		// SCORE SCENE
        isFinished = true;
        nextScene = "WritePuntuations";
	}
}
