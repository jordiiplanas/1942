#include "WritePuntuation.h"

WritePuntuation::WritePuntuation()
{

}

void WritePuntuation::OnEnter()
{
    ui.push_back(new UiText(" ", Vector2(250, 160)));
    dynamic_cast<UiText*>(ui[0])->textRend->SetText("Whats your username: ", 20, { 255,255,255 });
    inputManager.canText = true;

}

void WritePuntuation::Update(float dt)
{
    for (Object* o : ui)
    {
        o->Update(dt);
    }

    ui.push_back(new UiText(" ", Vector2(250, 320)));
    if (inputManager.TextInputFunction().length() > 1)
    {
        if (inputManager.CheckKeyState(SDLK_SPACE, PRESSED))
        {
            inputManager.ReturnChar();
        }
      dynamic_cast<UiText*>(ui[1])->textRend->SetText(inputManager.TextInputFunction(), 20, { 255,255,255 });
      if (inputManager.CheckKeyState(SDLK_UP, PRESSED))
      {
          isFinished = true;
          nextScene = "MainMenu";
      }
    }

}

void WritePuntuation::Render()
{
    for (Object* o : ui)
    {
        o->Render();
    }
}
