#include "Player.h"

Player::Player(double x, double y, double health, const std::string & name) :
  ObjectInterface(x, y, health) {
  this->name = name;
  setType(ObjectTypes::PLAYER);

  shape = sf::CircleShape(radius, level);

  displayHealth();
}

void Player::levelPlayer(int amount)
{
  level += amount;
  shape = sf::CircleShape(radius, level);
}

void Player::displayHealth()
{
  shape.setFillColor(sf::Color(255 - 255 * health/100, 255 * health/100, 0)); 
}

void Player::collision(const std::shared_ptr<Object>& o)
{
  //ObjectTypes type = o->getType();
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

std::string Player::getName()
{
  return name;
}

std::string Player::setName(const std::string& _name)
{
  name = _name;
}
