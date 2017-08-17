#include "Object.h"

int Object::idCounter = 0;

double Object::getX() const
{
  return position.x;
}

double Object::getY() const
{
  return position.y;
}

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
void Object::setPosition( double x, double y )
{
  position.x = x;
  position.y = y;
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

Object::Object(double _x, double _y, double _health) :health(_health), position(Position(_x, _y)), currentID(idCounter++)
{
  updateSprite();
}

sf::Sprite Object::getSprite() const
{
  return sprite;
}

void Object::updateSprite()
{
  sprite.setPosition(sf::Vector2f(position.x, position.y));
}

void Object::setSpriteTexture(sf::Texture texture)
{
  this->texture = texture;
  sprite.setTexture(this->texture);
}

void Object::setSprite(sf::Sprite _sprite)
{
  sprite = _sprite;
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

Position Object::getPosition() const
{
  return position;
}

Velocity Object::getVelocity() const
{
  return velocity;
}

void Object::setSpriteScale(double x, double y)
{
  sprite.setScale(x, y);
}

int Object::getID()
{
  return currentID;
}

void Object::draw(sf::RenderWindow& window)
{
  window.draw(sprite);
}
