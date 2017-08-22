#include "ObjectManager.h"
#include "GameLogic.h"
#include <SFML/Graphics.hpp>
#include <limits>

namespace CollisionManager
{
  void update(ObjectManager& manager);

  namespace VectorMath
  {
    double dotProduct(const sf::Vector2f& lhs, const sf::Vector2f& rhs);
    sf::Vector2f unitVector(const sf::Vector2f& vector);
    sf::Vector2f perpendicularVector(const sf::Vector2f& vector);
  }
  namespace SingleAxisTheorem
  {
    // Minimal Translation Vector
    struct MTV
    {
      sf::Vector2f axis;
      double overlap;
      MTV() : overlap(std::numeric_limits<double>::max()), axis(sf::Vector2f(0,0)) {}
    };

    sf::Vector2f getPoint(const sf::Shape& shape, unsigned int index);
    sf::Vector2f projectShapeOnAxis(const sf::Shape& shape, const sf::Vector2f& axis);
    bool existsSeparateAxisForFirst(const sf::Shape& shape_1, const sf::Shape& shape_2, MTV&);
    bool intersect(const sf::Shape& shape_1, const sf::Shape& shape_2, MTV&);
  }
  // rectangle collision check
  void collisionDetectionBasic(ObjectManager& manager);
}
