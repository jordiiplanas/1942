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
    }
  }
  SDL_GetMouseState(&mouseX, &mouseY);
}

bool InputManager::CheckKeyState(Sint32 key, KeyState state)
{
  return (keys[key] & state) > 0;
}