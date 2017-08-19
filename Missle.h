#ifndef MISSLE_H
#define MISSLE_H

#include "ObjectInterface.h"
#include "ResourceManager.h"
#include "ObjectManager.h"

class Missle : public ObjectInterface<sf::RectangleShape>
{
private:
  double maxVelocity = ResourceManager::Attributes::Missle::maxVelocity;
  double width = ResourceManager::Attributes::Missle::width;
  double height = ResourceManager::Attributes::Missle::height;
public:
  Missle(double x, double y);
  ~Missle();
  
  virtual void collision(std::shared_ptr<Object> o);
  virtual void death();

  static unsigned missleCount;
  static unsigned maxNumber;
};
#endif
