#include "Asteroid.h"


Asteroid::Asteroid(double x, double y, double health) :
  Enemies(x, y, health) {
  size = 0.05;
  setVelocity(std::rand() % 100, std::rand() % 100);
  setSpriteScale(size, size);
  setType(ObjectTypes::ASTEROID);
}

void Asteroid::collision(std::shared_ptr<Object> o)
{
  ObjectTypes type = o->getType();

  switch(type) {
    case ObjectTypes::MISSLE : {
      // take damage
    }
  }
}

void Asteroid::death()
{
  // Destroyed, break into smaller pieces
}
