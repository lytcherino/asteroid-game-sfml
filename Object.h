#ifndef OBJECT_H
#define OBJECT_H

#include "Position.h"
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

  ObjectTypes type;

  double health;
  double mass = 1;

  static int idCounter;
  const int currentID;

  Position position;
  Velocity velocity;

  sf::Sprite sprite;
  sf::Texture texture;

 public:
  Object(double _x, double _y, double _health);
  virtual ~Object() {}
  double getX() const;
  double getY() const;
  double getHealth() const;

  Velocity getVelocity() const;
  void setVelocity(double x, double y);

  void setVelocityX(double x);
  void setVelocityY(double y);

  void setHealth(int);
  void setPosition(double x, double y);

  Position getPosition() const;

  int getID();
  void setSprite(sf::Sprite);
  sf::Sprite getSprite() const;

  double getMass() const;
  void setMass(double);

  void takeDamage(int);
  virtual void death() = 0;

  void updateSprite();
  void updatePosition(sf::Time);
  void setSpriteTexture(sf::Texture);
  void setSpriteScale(double x, double y);

  virtual void collision(std::shared_ptr<Object>) = 0;
  void draw(sf::RenderWindow&);

  void setType(enum ObjectTypes);
  ObjectTypes getType() const;
};

#endif
