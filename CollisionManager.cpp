#include "CollisionManager.h"

namespace CollisionManager
{
  void update(ObjectManager& manager)
  {
    auto objects = manager.getObjectVector();

    for(auto object : objects) {
      for(auto object2 : objects) {
        if (object->getID() == object2->getID()) { continue; }

        SingleAxisTheorem::MTV mtv;
        if (SingleAxisTheorem::intersect(object->returnShape(), object2->returnShape(), mtv)) {
          object->collision(object2, mtv.axis, mtv.overlap);
          object2->collision(object, mtv.axis, mtv.overlap);

          manager.checkObject(object);
          manager.checkObject(object2);
        }
      }
    }
  }

  namespace VectorMath
  {
    double dotProduct(const sf::Vector2f& lhs, const sf::Vector2f& rhs)
    {
      return lhs.x * rhs.x + lhs.y * rhs.y;
    }
    sf::Vector2f unitVector(const sf::Vector2f& vector)
    {
      double distance = std::sqrt(dotProduct(vector, vector));
      return sf::Vector2f(vector.x / distance, vector.y / distance);
    } 
    sf::Vector2f perpendicularVector(const sf::Vector2f& vector)
    {
      return sf::Vector2f(-vector.x, vector.y);
    }
  }
  namespace SingleAxisTheorem
  {

    sf::Vector2f getPoint(const sf::Shape& shape, unsigned int index)
    {
      return shape.getTransform().transformPoint(shape.getPoint(index));
    }
    sf::Vector2f projectShapeOnAxis(const sf::Shape& shape, const sf::Vector2f& axis)
    {
      auto point = getPoint(shape, 0);
      auto initial = VectorMath::dotProduct(point, axis);

      sf::Vector2f minmax(initial, initial);

      for(unsigned int i = 1; i < shape.getPointCount(); i++) {
        point = getPoint(shape, i);
        auto projected = VectorMath::dotProduct(point, axis);

        if (projected < minmax.x) { minmax.x = projected; }
        if (projected > minmax.y) { minmax.y = projected; }
      }
      return minmax;
    }
    bool existsSeparateAxisForFirst(const sf::Shape& shape_1, const sf::Shape& shape_2, MTV& mtv) {
      unsigned int pointCount = shape_1.getPointCount();

      for(unsigned int i = 0; i < pointCount; i++) {
        unsigned int nextPoint = (i + 1) % pointCount;

        auto side = getPoint(shape_1, nextPoint) - getPoint(shape_1, i);
        auto perpendicular = VectorMath::unitVector(VectorMath::perpendicularVector(side));
        auto minmax_1 = projectShapeOnAxis(shape_1, perpendicular);
        auto minmax_2 = projectShapeOnAxis(shape_2, perpendicular);

        double overlap;
        // Here .y is max value, .x is min value
        if (minmax_1.y < minmax_2.x || (minmax_2.y < minmax_1.x)) { return true; }
        
        else {
          if (minmax_1.y > minmax_2.x) { overlap = minmax_1.y - minmax_2.x; }
          else { overlap = minmax_2.y - minmax_1.x; }
        }

        if (overlap < mtv.overlap) { mtv.overlap = overlap; mtv.axis = perpendicular; }
      }

      return false;
    }

    bool intersect(const sf::Shape& shape_1, const sf::Shape& shape_2, MTV& mtv) {
      if (existsSeparateAxisForFirst(shape_1, shape_2, mtv)) {return false; }
      //std::cerr << "overlap: " << mtv.overlap << "axis: " <<
      //mtv.axis.x << ", " << mtv.axis.y << "\n";
      return (!existsSeparateAxisForFirst(shape_2, shape_1, mtv));
    }

  }
}
 
