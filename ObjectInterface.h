#ifndef OBJECT_INTERFACE_H
#define OBJECT_INTERFACE_H

#include "Object.h"
#include <SFML/Graphics.hpp>

template<typename Shape>
class ObjectInterface : public Object
{
public:
  Shape shape;

  ObjectInterface<Shape>(double x, double y, double health) :
    Object(health) {
  }

  virtual void collision(const std::shared_ptr<Object>&, const sf::Vector2f&, const double&) = 0;
  virtual void death() = 0;

  auto returnShape() -> sf::Shape& override
  {
    return shape;
  }
  auto setPosition(const sf::Vector2f& offset) -> void override
  {
    shape.setPosition(offset);
  }

  auto move(const sf::Vector2f& offset) -> void override
  {
    shape.move(offset);
  }

  auto getPosition() const -> sf::Vector2f override
  {
    return shape.getPosition();
  }

  auto draw(sf::RenderWindow& window) -> void override
  {
    window.draw(shape);
  }

  auto getRectangleBounds() -> sf::Rect<float> override
  {
    return shape.getGlobalBounds();
  }

  auto getIntersection(sf::Rect<float> rect) -> bool override
  { 
    return shape.getGlobalBounds().intersects(rect);
  }

  Shape& getShape()
  {
    return shape;
  }

};

#endif
