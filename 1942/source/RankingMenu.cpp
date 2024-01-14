#include "RankingMenu.h"

RankingMenu::RankingMenu()
{
	Object* backButton = new Button(Vector2(50, 450), "MainMenu", "Back");
    backButton->SetScale(Vector2(1.4, 1.3));
    dynamic_cast<Button*>(backButton)->ChangeTextPosition(backButton->GetCenteredPosition());

    ui.push_back(backButton);
    for (int i = 1; i <= 10; i++)
    {
        int puntuation = 0;
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
}

void RankingMenu::Update(float dt)
{
    for (Object* o : ui)
    {
        o->Update(dt);
        if (dynamic_cast<Button*>(o))
        {
            if (dynamic_cast<Button*>(o)->pressed)
            {
                isFinished = true;
                nextScene = dynamic_cast<Button*>(o)->nextScene;
                dynamic_cast<Button*>(o)->pressed = false;
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

