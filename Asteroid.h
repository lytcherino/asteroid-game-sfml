#ifndef ENEMIES_H
#define ENEMIES_H

#include "Enemies.h"
#include "ResourceManager.h"

class Asteroid : public Enemies<sf::ConvexShape>
{
 private:
  double size;
  int colorVariance = ResourceManager::Attributes::Asteroid::colorVariance;
  double maxVelocity = ResourceManager::Attributes::Asteroid::maxVelocity;
  int edges;
  int minEdges = ResourceManager::Attributes::Asteroid::minEdges;
  int maxEdges = ResourceManager::Attributes::Asteroid::maxEdges;
  int maxPositionEdgeX = ResourceManager::Attributes::Asteroid::maxPositionEdgeX;
  int maxPositionEdgeY = ResourceManager::Attributes::Asteroid::maxPositionEdgeY;

  void generateShape();
 public:
  Asteroid(double x, double y, double size, double health);
  ~Asteroid() {}

  virtual int getExperience() override;
  virtual void collision(const std::shared_ptr<Object>&, const sf::Vector2f&, const double&) override;
  virtual void death() override;
  virtual int getDamageAmount() const override;
};

#endif
