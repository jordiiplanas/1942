#pragma once
#include <SDL.h>
#include <unordered_map>
#include <string>

#define inputManager InputManager::Instance()

enum KeyState
{
  EMPTY = 0,
  PRESSED = 1,
  HOLD = 2, 
  RELEASED = 4, 
  UP = 8
};

class InputManager
{
private:
  std::unordered_map<Sint32, int> keys;
  bool quitEvent;
  int mouseX;
  int mouseY;
  int puntuation;
  InputManager() : quitEvent(false), mouseX(0), mouseY(0) {};
  InputManager(const InputManager&) = delete;
  InputManager& operator =(const InputManager&) = delete;
  
public:
    bool mousePressed;
    std::string textInput;
    bool canText = false;


  inline static InputManager& Instance()
  {
      static InputManager manager;
      return manager;
  }
  
  void Listen();
  bool CheckKeyState(Sint32 key, KeyState state);
  inline bool GetQuitEvent() { return quitEvent; }
  inline int GetMouseX() { return mouseX; }
  inline int GetMouseY() { return mouseY; }
  inline void SetQuitEvent(bool value) { quitEvent = value; }
  void SavePuntuation(int points) {
      puntuation = points;
  }
  int GetPuntuation()
  {
      return puntuation;
  }
  void ReturnChar()
  {
      textInput.pop_back();
  }
  std::string TextInputFunction()
  {
      return textInput;
  }
  
};


  
  


