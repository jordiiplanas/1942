#include "RankingMenu.h"

RankingMenu::RankingMenu()
{
	Object* backButton = new Button(Vector2(50, 450), "MainMenu", "Back");
    ui.push_back(backButton);
}

void RankingMenu::OnEnter()
{
}

void RankingMenu::Update(float dt)
{
    for (Object* o : ui)
    {
        o->Update(dt);
    }
}

void RankingMenu::Render()
{
    for (Object* o : ui)
    {
        o->Render();
    }
}

