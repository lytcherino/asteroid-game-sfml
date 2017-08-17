#ifndef PLAYER_H
#define PLAYER_H

#include "Object.h"
#include <string>

class Player : public Object
{
  private:
  std::string name;
  double score = 0;

 public:
  Player(double x, double y, double health, const std::string& name);
  ~Player() {}

  virtual void collision(std::shared_ptr<Object>);
  virtual void death();
};


#endif
