#include "Player.h"

Player::Player(double x, double y, double health, const std::string & name) :
  Object(x, y, health) {
  this->name = name;
  setSpriteScale(0.5, 0.5);
  setType(ObjectTypes::PLAYER);
  setSpriteTexture(ResourceManager::Texture::player);
}

void Player::collision(std::shared_ptr<Object> o)
{
  ObjectTypes type = o->getType();

  switch(type) {
  case ObjectTypes::ASTEROID : {
    // take damage
    takeDamage(15);
    std::cerr << "HEALTH : " << getHealth() << "\n"; 
  }
  }
} 

void Player::death()
{
  // Game over or extra lives
}

double Player::getMaxVelocity() const
{
  return maxVelocity;
}

void Player::setMaxVelocity(double velocity)
{
  maxVelocity = velocity;
}
