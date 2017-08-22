#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "ObjectManager.h"
#include <math.h>
#include "Timer.h"
#include "Object.h"
#include <cmath>
#include <random>
#include "ResourceManager.h"

namespace GameLogic
{
  enum gameState {Uninitialized, Playing, ShowingMenu, Paused};
  extern gameState state;

  void initialise();
  void update(ObjectManager&, Timer& timer);

  namespace Mouse
  {
    void update(ObjectManager& manager);

    void handleMouse(ObjectManager& manager);
  }
  namespace Keyboard
  {
    extern bool pressingW;
    extern bool pressingA;
    extern bool pressingS;
    extern bool pressingD;

    void update(ObjectManager& manager);

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
    void update(ObjectManager& manager, Timer& timer);
    
    void fireMissle(ObjectManager& manager);
    void reloadMissle(ObjectManager& manager, Timer& timer);
  }

  namespace PowerUp
  {
    
  }

  namespace Camera
  {
    extern sf::View view;
    extern double zoom;
    void initialise();
    void update(ObjectManager&);
  }
  namespace Random
  {
    void initialise();
  }
  namespace Physics
  {
    void update(ObjectManager&);
    namespace Gravity
    {
      void update(ObjectManager&);
    }
  }

  namespace Collision
  {
  }

}

#endif
