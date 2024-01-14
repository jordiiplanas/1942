#include "RankingMenu.h"

RankingMenu::RankingMenu()
{
	Object* backButton = new LoadSceneButton(Vector2(50, 450), "Back", "MainMenu");
    backButton->SetScale(Vector2(1.4, 1.3));
    dynamic_cast<Button*>(backButton)->ChangeTextPosition(backButton->GetCenteredPosition());
    ui.push_back(backButton);

    std::ifstream myFileIn;
    myFileIn.open("config/rankingsSave.dat", std::ios::in | std::ios::binary);
    if (!myFileIn.is_open())
    {
        std::cout << "cant open file" << std::endl;
        return;
    }
    myFileIn.read(reinterpret_cast<char*>(&puntuations), sizeof(int) * 10);
    myFileIn.close();
    for (int i = 1; i <= 10; i++)
    {
        int puntuation = puntuations[i-1];
        std::string name = "AAA";
        std::string textRank = std::to_string(i) + ".  " + name + "  " + std::to_string(puntuation);
        if (i == 1)
        {
            UiText* newRank = new UiText(textRank, Vector2(250, 60));
            ui.push_back(newRank);
        }
        else
        {
            UiText* newRank = new UiText(textRank, Vector2(250, ui.back()->GetPosition().y + 35));
            ui.push_back(newRank);
        }
    }
}

void RankingMenu::OnEnter()
{
    for (Object* o : ui)
    {
        if (dynamic_cast<Button*>(o))
        {
            dynamic_cast<Button*>(o)->Reset();
        }
    }
}

void RankingMenu::Update(float dt)
{
    for (Object* o : ui)
    {
        o->Update(dt);
        if (dynamic_cast<Button*>(o))
        {
            if (dynamic_cast<Button*>(o)->IsPressed())
			{
                if (dynamic_cast<LoadSceneButton*>(o))
                {
                    isFinished = true;
                    nextScene = dynamic_cast<LoadSceneButton*>(o)->GetSceneName();
                }
			}
        }
    }
}

void RankingMenu::Render()
{
    for (Object* o : ui)
    {
        o->Render();
    }
}

