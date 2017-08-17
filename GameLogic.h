#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "Player.h"

namespace GameLogic
{
  enum gameState {Uninitialized, Playing, ShowingMenu, Paused};
  extern gameState state;
  enum keyType {RELEASE, PRESS};

  extern std::shared_ptr<Player> player;
   
  void initialise(std::shared_ptr<Player>);

  namespace Keyboard
  {
    void handleKeyboardEvent(const std::string& key, keyType type);
    void keyW(keyType type);
    void keyA(keyType type);
    void keyS(keyType type);
    void keyD(keyType type);
    void keyEsc(keyType type);
    void keySpace(keyType type);

  }

  namespace Collision
  {
    
  }

}

#endif
