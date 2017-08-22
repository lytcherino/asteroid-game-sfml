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
  int experience = 0;
  int requiredExperience = level * 3;
  int kills = 0;

  int ammunition = ResourceManager::Attributes::Player::initialAmmunition;
  double maxVelocity = ResourceManager::Attributes::Player::maxVelocity;

  void displayHealth();
  void initialise(double, double, double);

 public:
  Player(double x, double y, double health, const std::string& name);
  ~Player() {}

  virtual void collision(const std::shared_ptr<Object>&, const sf::Vector2f&, const double&) override;
  virtual void death() override;
  virtual int getDamageAmount() const override;

  void levelPlayer();

  void gainExperience(double amount);
  void fireMissle();
  void indicateAmmunition();
  void updateAmmunition(int amount);
  int getAmmunition() const;
  void rotate(double amount);

  std::string setName(const std::string& _name);

  double getMaxAcceleration() const;
  double getMaxVelocity() const;
  void setMaxVelocity(double velocity);

  std::string getName();
};


#endif
