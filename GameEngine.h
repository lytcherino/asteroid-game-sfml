#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <memory>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ObjectManager.h"
#include "Timer.h"
#include "Display.h"
#include "ResourceManager.h"
#include "EntityFactory.h"
#include "GameLogic.h"
#include "EventHandler.h"
#include "Player.h"
#include "CollisionManager.h"

namespace GameEngine
{
  extern Timer loopTimer;

  extern Timer reloadMissleTimer;

  void start();
  void run();
  void draw();

  void initialise();

  extern ObjectManager objectManager;

  void render();

}

#endif
