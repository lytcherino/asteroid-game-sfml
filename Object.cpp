#include "Object.h"

int Object::idCounter = 0;

double Object::getHealth() const
{
  return health;
}

double Object::getMass() const
{
  return mass;
}

void Object::setMass(double m)
{
  mass = m;
}

void Object::setType(enum ObjectTypes _type)
{
  type = _type;
}

ObjectTypes Object::getType() const
{
  return type;
}

void Object::takeDamage(int amount)
{
  health -= amount;

  if (health <= 0) { death(); }
}

void Object::setHealth(int value)
{
  health = value;
}

Object::Object(double _health) :health(_health), currentID(idCounter++)
{
}

void Object::setVelocity(double x, double y)
{
  velocity.x = x;
  velocity.y = y;
}

void Object::setVelocityX(double x)
{
  velocity.x = x;
}

void Object::setVelocityY(double y)
{
  velocity.y = y;
}

void Object::ellasticReverse(std::shared_ptr<Object> object, const sf::Vector2f& axis, const double& overlap)
{
  
  velocity.x = -1 * axis.x;
  velocity.y = -1 * axis.y;

  auto sign = [=](double x){return x > 0 ? 1 : ((x < 0) ? -1 : 0); };

  //returnShape().move(axis.x * overlap * sign(velocity.x) * 0.01, axis.y * overlap * sign(velocity.y)*0.01);

  acceleration.x *= -1 * axis.x;
  acceleration.y *= -1 * axis.y;
}

void Object::adjustAcceleration(double x, double y)
{
  acceleration.x += x;
  acceleration.y += y;
}
void Object::setAcceleration(double x, double y)
{
  acceleration.x = x;
  acceleration.y = y;
}

Acceleration Object::getAcceleration() const
{
  return acceleration;
}

Velocity Object::getVelocity() const
{
  return velocity;
}

int Object::getID() const
{
  return currentID;
}

void Object::teleportAtEdge()
{
  double x = getPosition().x;
  double y = getPosition().y;
  double width = ResourceManager::Attributes::World::width;
  double height = ResourceManager::Attributes::World::height;

  if (x > width / 2) { setPosition(sf::Vector2f(-width/2, y)); }
  if (x < - width / 2) { setPosition(sf::Vector2f(width/2, y)); }
  if (y > height / 2) { setPosition(sf::Vector2f(x, -height/2)); }
  if (y < - height / 2) { setPosition(sf::Vector2f(x, height/2)); }
}
