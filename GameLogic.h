#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "ObjectManager.h"
#include <math.h>
#include "Timer.h"

namespace GameLogic
{
  enum gameState {Uninitialized, Playing, ShowingMenu, Paused};
  extern gameState state;

  extern bool pressingW;
  extern bool pressingA;
  extern bool pressingS;
  extern bool pressingD;

  void initialise();

  namespace Keyboard
  {
    void handleKeyboardInput(ObjectManager& manager);
    void keyW(ObjectManager& manager);
    void keyA(ObjectManager& manager);
    void keyS(ObjectManager& manager);
    void keyD(ObjectManager& manager);
    void keyEsc(ObjectManager& manager);
    void keySpace(ObjectManager& manager);

  }

  namespace Weapon
  {
    void fireMissle(ObjectManager& manager);
    void reloadMissle(ObjectManager& manager, Timer& timer);
  }

  namespace Collision
  {
    
  }

}

#endif
