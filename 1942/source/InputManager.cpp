#include "InputManager.h"

void InputManager::Listen()
{
  // 1 - ???
  for (auto i = keys.begin() ; i != keys.end() ; i++)
  {
    if ((i->second & PRESSED) > 0)
    {
      i->second = HOLD;
    }
    else if ((i->second & RELEASED) > 0)
    {
      i->second = UP;
    }
  }

  // 2 -  Listen to SDL events to process them

  SDL_Event sdl_event;
  while (SDL_PollEvent(&sdl_event))
  {
    switch (sdl_event.type)
    {
    case SDL_KEYDOWN:
      if ((keys[sdl_event.key.keysym.sym] & (PRESSED | HOLD)) == 0)
      {
        keys[sdl_event.key.keysym.sym] = (PRESSED | HOLD);
      }
      break;
    case SDL_KEYUP:
      keys[sdl_event.key.keysym.sym] = (RELEASED | UP);
      break;
    case SDL_QUIT:
      quitEvent = true;
      break;
    case SDL_MOUSEBUTTONDOWN:
        if(sdl_event.button.button)
        mousePressed = true;
        break;
    case SDL_MOUSEBUTTONUP:
        if (sdl_event.button.button)
        mousePressed = false;
        break;
    case SDL_TEXTINPUT:
        {
        if (sdl_event.key.keysym.sym == SDLK_SPACE)
        {

        }
        else if(canText && textInput.length() < 3 )
        textInput += sdl_event.text.text;
        }
    }
  }
  SDL_GetMouseState(&mouseX, &mouseY);
}


bool InputManager::CheckKeyState(Sint32 key, KeyState state)
{
  return (keys[key] & state) > 0;
}