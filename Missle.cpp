#include "Missle.h"

unsigned Missle::missleCount = 0;
unsigned Missle::maxNumber = ResourceManager::Attributes::Missle::maxNumber;

Missle::Missle(double x, double y, double rotation) : ObjectInterface(x, y, 100)
{
  shape = sf::RectangleShape(sf::Vector2f(width, height));
  shape.setFillColor(sf::Color(255,255,255));
  missleCount++;
  setPosition(sf::Vector2f(x,y));
  setType(ObjectTypes::MISSLE);
  shape.rotate(rotation);
  shape.setOrigin(shape.getLocalBounds().width/2, shape.getLocalBounds().height+cos(rotation));
  setVelocity(sin(shape.getRotation()) * maxVelocity, -cos(shape.getRotation()) * maxVelocity);
}

Missle::~Missle()
{
  missleCount--;
}

void Missle::collision(const std::shared_ptr<Object>& o )
{
  ObjectTypes type = o->getType();
  if (type == ObjectTypes::ASTEROID) {
    setHealth(0);
  }
  if (type == ObjectTypes::PLAYER) {
    //setHealth(0);
  }
  if (type == ObjectTypes::MISSLE) {
    //takeDamage(10);
  }
}

void Missle::death()
{
  
}

int Missle::getDamageAmount() const
{
  return ResourceManager::Attributes::Missle::damageAmount;
}
