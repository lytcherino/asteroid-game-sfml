#include "Player.h"

Player::Player(double x, double y, double health, const std::string & name) :
  Object(x, y, health) {
  this->name = name;
  setSpriteScale(0.1, 0.1);
  setType(ObjectTypes::PLAYER);
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
