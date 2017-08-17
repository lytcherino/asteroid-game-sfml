#include "Asteroid.h"


Asteroid::Asteroid(double x, double y, double _size, double health) :
  Enemies(x, y, health), size(_size) {

  setVelocity(std::rand() % 500, std::rand() % 500);
  setSpriteScale(size, size);
  setType(ObjectTypes::ASTEROID);
  setSpriteTexture(ResourceManager::Texture::asteroid);
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
