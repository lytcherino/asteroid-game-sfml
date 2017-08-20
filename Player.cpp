#include "Player.h"

Player::Player(double x, double y, double health, const std::string & name) :
  ObjectInterface(x, y, health) {
  this->name = name;
  setType(ObjectTypes::PLAYER);

  initialise(x, y, 0);
}

void Player::initialise(double x, double y, double rotation)
{
  shape = sf::CircleShape(radius, level);

  shape.rotate(rotation);
  shape.setOrigin(shape.getRadius(),shape.getRadius());
  setPosition(sf::Vector2f(x, y));
  displayHealth();
  indicateAmmunition();
}

void Player::levelPlayer()
{
  std::cerr << experience << "\n";
  while (experience >= requiredExperience) {
    level++;
    initialise(shape.getPosition().x, shape.getPosition().y, shape.getRotation());

    clamp(experience, -requiredExperience, 100, 0);
    requiredExperience += experience * level;
  }
}

void Player::fireMissle()
{
  updateAmmunition(-1);
}
void Player::updateAmmunition(int amount)
{
  clamp(ammunition, amount, ResourceManager::Attributes::Player::initialAmmunition, 0);
  indicateAmmunition();
}

void Player::displayHealth()
{
  shape.setFillColor(sf::Color(255 - 255 * health/100, 255 * health/100, 0)); 
}

void Player::indicateAmmunition()
{
  double ratio = static_cast<double>(ammunition) / ResourceManager::Attributes::Player::initialAmmunition;
  shape.setOutlineThickness(ratio * ResourceManager::Attributes::Player::outlineThichkness + ResourceManager::Attributes::Player::baseOutLineThickness);
  double experienceRatio = static_cast<double>(experience) / requiredExperience;
  shape.setOutlineColor(sf::Color(0, 255 * experienceRatio, 0));
}

int Player::getAmmunition() const
{
  return ammunition;
}

void Player::rotate(double amount)
{
  shape.rotate(amount);
}

void Player::gainExperience(double amount)
{
  experience += amount;
  levelPlayer();
}

void Player::collision(const std::shared_ptr<Object>& o)
{
  ObjectTypes type = o->getType();
  if (type == ObjectTypes::MISSLE) {
    //takeDamage(o->getDamageAmount());
  }
  if (type == ObjectTypes::ASTEROID) {
    //takeDamage(o->getDamageAmount());
  }

  displayHealth();
} 

void Player::death()
{
  // Game over or extra lives
}

int Player::getDamageAmount() const
{
  return ResourceManager::Attributes::Player::damageAmount;
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
