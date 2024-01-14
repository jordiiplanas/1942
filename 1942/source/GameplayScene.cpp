#include "GameplayScene.h"

void GameplayScene::OnEnter()
{
    if (hasAlreadyStarted) return;
    hasAlreadyStarted = true;
    nextScene = "MainMenu";
    
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

    // WAVES
    Transform* transform = player->GetTransform();
    stages = GetStagesFromFile("stage-", "-waves.xml", transform);
    if (stages.size() > 0) currentStage = stages[0];

    // UI
    scoreUi = new UiText("SCORE: 0", Vector2(60, 30));
    ui.push_back(new UiText("Lifes:", Vector2(40, 480)));
    ui.push_back(new UiText("Rolls:", Vector2(310, 480)));
    ui.push_back(scoreUi);
}

void GameplayScene::Update(float dt)
{
    if (inputManager.CheckKeyState(SDLK_ESCAPE, PRESSED)) isPaused = !isPaused;
    if (isPaused) return;
    bool mousePressed = false;
    if (mousePressed)
    {
        std::cout << "Casa Casita" << std::endl;
    }
    // INPUTS
    while (SDL_PollEvent(&event))
    {
        if (SDL_MOUSEBUTTONDOWN == event.type)
        {
            if (SDL_BUTTON_LEFT == event.button.button)
            {
                mousePressed = true;
                std::cout << "Casa Casita" << std::endl;
            }
        }
        if (event.type == SDL_MOUSEMOTION)
        {
            std::cout << "Casa Casita" << std::endl;

        }
    }
    //TODO : Pause

    // UPDATE Background

    for (Object* o : background)
	{
		o->Update(dt);
	}

    // ENDED GAME updates

    if (isEnded)
    {
        player->Update(dt);
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
    // Player animation to center

}
