#include "Missle.h"

unsigned Missle::missleCount = 0;
unsigned Missle::maxNumber = ResourceManager::Attributes::Missle::maxNumber;

Missle::Missle(double x, double y) : ObjectInterface(x, y, 100)
{
  setVelocity(0, -1.0*maxVelocity);
  shape = sf::RectangleShape(sf::Vector2f(width, height));
  shape.setFillColor(sf::Color(255,255,255));
  missleCount++;
  setPosition(sf::Vector2f(x,y));
}

Missle::~Missle()
{
  missleCount--;
}

void Missle::collision( std::shared_ptr<Object> o )
{
  ObjectTypes type = o->getType();
  if (type == ObjectTypes::ASTEROID) {
    setHealth(0);
  }
  if (type == ObjectTypes::PLAYER) {
    setHealth(0);
  }
}

void Missle::death()
{
  
}

