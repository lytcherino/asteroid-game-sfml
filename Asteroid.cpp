#include "Asteroid.h"

#include <iostream>

Asteroid::Asteroid(double x, double y, double _size, double health) :
  Enemies(x, y, health), size(_size) {

  setVelocity(0, 0);
  //setVelocity(std::rand() % (int)maxVelocity, std::rand() % (int)maxVelocity);
  setType(ObjectTypes::ASTEROID);
  shape.setFillColor(sf::Color(std::rand() % colorVariance, std::rand() % colorVariance, std::rand() % colorVariance));
  generateShape();
  shape.setPosition(x, y);
  setMass(1);
  shape.setOrigin(shape.getLocalBounds().width/2, shape.getLocalBounds().height/2);
}

void Asteroid::collision(const std::shared_ptr<Object>& o, const sf::Vector2f& axis, const double& overlap)
{
  ObjectTypes type = o->getType();
  if (type == ObjectTypes::MISSLE) {
    takeDamage(o->getDamageAmount());
  }
  if (type == ObjectTypes::ASTEROID) {
    ellasticReverse(o, axis, overlap);
  }
}

void Asteroid::generateShape()
{
  edges = std::rand() % maxEdges + minEdges;
  shape.setPointCount(edges);

  int minimalEdgeDisplacement = ResourceManager::Attributes::Asteroid::minimalEdgeDisplacement;

  int previousX = 0, previousY = 0;
  for(int i = 0; i < edges; i++) {
    int x = std::rand() % maxPositionEdgeX;
    int y = std::rand() % maxPositionEdgeY;

    if (std::abs(previousX - x) < minimalEdgeDisplacement) { x += minimalEdgeDisplacement; }
    if (std::abs(previousY - y) < minimalEdgeDisplacement) { y += minimalEdgeDisplacement; }

    shape.setPoint(i, sf::Vector2f(x, y));

    previousX = x;
    previousY = y;
  }
}

void Asteroid::death()
{

}

int Asteroid::getDamageAmount() const
{
  return ResourceManager::Attributes::Asteroid::damageAmount;
}

int Asteroid::getExperience()
{
  return 1;
}
