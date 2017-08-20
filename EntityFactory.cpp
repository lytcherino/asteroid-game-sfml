#include "EntityFactory.h"

void EntityFactory::createPlayer(ObjectManager& manager, const std::string& name)
{
  double x, y, health;
  x = 50;
  y = 50;
  health = 100;
  std::shared_ptr<Player> player = std::make_shared<Player>(x,y,health,name);

  manager.add(player);
  manager.setPlayer(player);

}

void EntityFactory::createAsteroid(ObjectManager& manager)
{
  double x, y, health, size;
  x = std::rand() % Display::WIDTH / 2;
  y = std::rand() % Display::HEIGHT / 2;
  health = std::rand() % 100 + 5;
  size = health * 0.005;

  std::shared_ptr<Asteroid> asteroid = std::make_shared<Asteroid>(x,y,size, health);

  manager.add(asteroid);
}
