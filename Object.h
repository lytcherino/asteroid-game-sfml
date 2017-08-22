#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <memory>
#include "ResourceManager.h"
#include "Display.h"

struct Velocity {
  double x, y;
  Velocity() : x(0), y(0) {}
};

struct Acceleration {
  double x, y;
  Acceleration() : x(0), y(0) {}
};
enum ObjectTypes {PLAYER, ASTEROID, MISSLE};

class Object
{
protected:
  ObjectTypes type;

  double health;
  double mass;

  static int idCounter;
  const int currentID;
  
  Velocity velocity;
  Acceleration acceleration;

 public:
  Object(double _health);

  virtual ~Object() {}

  double getHealth() const;

  Velocity getVelocity() const;

  void setVelocity(double x, double y);
  void setAcceleration(double x, double y);
  void adjustAcceleration(double x, double y);
  Acceleration getAcceleration() const;

  void ellasticReverse(std::shared_ptr<Object>, const sf::Vector2f& axis, const double& overlap);

  void teleportAtEdge();

  void setVelocityX(double x);
  void setVelocityY(double y);

  template<typename T>
  void clamp(T& parameter, T amount, T max, T min) {
    if (parameter + amount <= max && parameter - amount >= min - 1) { parameter += amount; }
  }
  void setHealth(int value);

  int getID() const;

 double getMass() const;
  void setMass(double value);

  virtual void takeDamage(int amount);

  virtual void death() = 0;

  virtual sf::Shape& returnShape() = 0;
  virtual sf::Vector2f getPosition() const = 0;
  virtual void move(const sf::Vector2f&) = 0;
  virtual void draw(sf::RenderWindow&) = 0;
  virtual void setPosition(const sf::Vector2f&) = 0;
  virtual void collision(const std::shared_ptr<Object>&, const sf::Vector2f&, const double&) = 0;
  virtual sf::Rect<float> getRectangleBounds() = 0;
  virtual bool getIntersection(sf::Rect<float> rect) = 0;
  virtual int getDamageAmount() const = 0;

  void setType(ObjectTypes _type);
  ObjectTypes getType() const;
};

#endif
