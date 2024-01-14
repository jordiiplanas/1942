#include "WritePuntuation.h"

WritePuntuation::WritePuntuation()
{

}

void WritePuntuation::OnEnter()
{
    ui.push_back(new UiText(" ", Vector2(250, 100)));
    dynamic_cast<UiText*>(ui[0])->textRend->SetText(std::to_string(SCOREMANAGER.GetScore()), 20, {255,255,255});

    ui.push_back(new UiText(" ", Vector2(250, 160)));
    dynamic_cast<UiText*>(ui[1])->textRend->SetText("Whats your username: ", 20, { 255,255,255 });
    inputManager.canText = true;

}

void WritePuntuation::Update(float dt)
{
    for (Object* o : ui)
    {
        o->Update(dt);
    }
    std::cout << SCOREMANAGER.GetScore();
    ui.push_back(new UiText(" ", Vector2(250, 320)));
    if (inputManager.TextInputFunction().length() > 1)
    {
        if (inputManager.CheckKeyState(SDLK_SPACE, PRESSED))
        {
            inputManager.ReturnChar();
        }
      dynamic_cast<UiText*>(ui[2])->textRend->SetText(inputManager.TextInputFunction(), 20, { 255,255,255 });
      if (inputManager.CheckKeyState(SDLK_UP, PRESSED))
      {
          SavePuntuations();
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

void WritePuntuation::SavePuntuations()
{
    std::ofstream myFileOut2;
    myFileOut2.open("resources/data.dat", std::ios::out | std::ios::binary);
        myFileOut2.close();


    std::ifstream myFileIn("resources/data.dat", std::ios::in | std::ios::binary);
    if (!myFileIn.is_open())
    {
        std::cout << "cant open file read" << std::endl;
        return;
    }
    int inSize = 0;
    myFileIn.read(reinterpret_cast<char*>(&inSize), sizeof(int));
    std::vector<int> readVector;
    readVector.resize(inSize);
    myFileIn.read(reinterpret_cast<char*> (readVector.data()), sizeof(int) * inSize);

    myFileIn.close();
    readVector.push_back(SCOREMANAGER.GetScore());
    std::vector<int> yeyeye{ 2,4,3,2,2 };
    std::ofstream myFileOut;
    myFileOut.open("resources/data.dat", std::ios::out | std::ios::binary | std::ios::trunc);
        if (!myFileOut.is_open())
        {
            std::cout << "cant open file write" << std::endl;
            return;
        }
        int sizeWrite = yeyeye.size();
        myFileOut.write(reinterpret_cast<char*>(&yeyeye), sizeof(int) * sizeWrite);
        myFileOut.close();
}
