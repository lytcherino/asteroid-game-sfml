#ifndef MISSLE_H
#define MISSLE_H

#include "ObjectInterface.h"
#include "ResourceManager.h"
#include "ObjectManager.h"
#include <math.h>

class Missle : public ObjectInterface<sf::RectangleShape>
{
private:
  double maxVelocity = ResourceManager::Attributes::Missle::maxVelocity;
  double width = ResourceManager::Attributes::Missle::width;
  double height = ResourceManager::Attributes::Missle::height;
public:
  Missle(double x, double y, double rotation);
  ~Missle();
  
  virtual void collision(const std::shared_ptr<Object>& o, const sf::Vector2f&, const double&) override;
  virtual void death() override;
  virtual int getDamageAmount() const override;

  static unsigned missleCount;
  static unsigned maxNumber;
};
#endif
