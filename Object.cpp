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

Velocity Object::getVelocity() const
{
  return velocity;
}

int Object::getID() const
{
  return currentID;
}
