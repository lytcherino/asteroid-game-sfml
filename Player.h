#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "ResourceManager.h"
#include "ObjectInterface.h"

class Player : public ObjectInterface<sf::CircleShape>
{
  private:
  std::string name;
  double score = 0;

  double radius = ResourceManager::Attributes::Player::radius;

  int level = 3; // start as triangle

  double maxVelocity = ResourceManager::Attributes::Player::maxVelocity;

  void displayHealth();

 public:
  Player(double x, double y, double health, const std::string& name);
  ~Player() {}

  virtual void collision(const std::shared_ptr<Object>&) override;
  virtual void death() override;

  void levelPlayer(int);

  std::string setName(const std::string& _name);

  double getMaxVelocity() const;
  void setMaxVelocity(double velocity);

  std::string getName();
};


#endif
