#ifndef ENTITY_FACTORY_H
#define ENTITY_FACTORY_H

#include "Player.h"
#include "Asteroid.h"
#include <cstdlib>
#include <ctime>
#include <memory>
#include "ObjectManager.h"
#include "Display.h"

namespace EntityFactory
{
  std::shared_ptr<Player> createPlayer(ObjectManager& manager, const std::string& name);
  void createAsteroid(ObjectManager& manager);

}

#endif
