#ifndef PLAYER_H
#define PLAYER_H

#include "Object.h"
#include <string>
#include "ResourceManager.h"

class Player : public Object
{
  private:
  std::string name;
  double score = 0;

  double maxVelocity = 250;

 public:
  Player(double x, double y, double health, const std::string& name);
  ~Player() {}

  virtual void collision(std::shared_ptr<Object>);
  virtual void death();

  double getMaxVelocity() const;
  void setMaxVelocity(double velocity);
};


#endif
