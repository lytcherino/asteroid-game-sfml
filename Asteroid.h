#ifndef ENEMIES_H
#define ENEMIES_H

#include "Enemies.h"
#include "ResourceManager.h"

class Asteroid : public Enemies
{
 private:
  double size;
 public:
  Asteroid(double x, double y, double size, double health);
  ~Asteroid() {}

  virtual void collision(std::shared_ptr<Object>);
  virtual void death();
};

#endif
