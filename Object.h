#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <memory>
#include "ResourceManager.h"


struct Velocity {
  double x, y;
  Velocity() : x(0), y(0) {}
};

enum ObjectTypes {PLAYER, ASTEROID, MISSLE};

class Object
{
protected:
  ObjectTypes type;

  double health;
  double mass = 1;

  static int idCounter;
  const int currentID;

  Velocity velocity;

 public:
  Object(double _health);

  virtual ~Object() {}

  double getHealth() const;

  Velocity getVelocity() const;

  void setVelocity(double x, double y);

  void setVelocityX(double x);
  void setVelocityY(double y);

  void setHealth(int value);

  int getID() const;

 double getMass() const;
  void setMass(double value);

  virtual void takeDamage(int amount);

  virtual void collision(std::shared_ptr<Object>) = 0;
  virtual void death() = 0;

  virtual sf::Vector2f getPosition() const = 0;
  virtual void move(const sf::Vector2f&) = 0;
  virtual void draw(sf::RenderWindow&) = 0;
  virtual void setPosition(const sf::Vector2f&) = 0;
  virtual void collision(const std::shared_ptr<Object>&) = 0;

  void setType(ObjectTypes _type);
  ObjectTypes getType() const;
};

#endif
