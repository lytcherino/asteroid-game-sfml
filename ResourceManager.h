#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <string>

namespace ResourceManager
{
  namespace Background
  {
    extern sf::Sprite background;
    void initialise();
  }
  namespace Texture
  {
    extern sf::Texture player;
    extern sf::Texture asteroid;
    extern sf::Texture background;

    void initialise();
  }
  namespace Attributes
  {
    namespace Player
    {
      extern double maxVelocity;
      extern double radius;
      extern int damageAmount;
      extern int initialAmmunition;
      extern double outlineThichkness;
      extern double baseOutLineThickness;
    }
    namespace Asteroid
    {
      extern double maxVelocity;
      extern int colorVariance;
      extern int minEdges;
      extern int maxEdges;
      extern int maxPositionEdgeX;
      extern int maxPositionEdgeY;
      extern int minimalEdgeDisplacement;
      extern int damageAmount;
    }
    namespace Missle
    {
      extern double maxVelocity;
      extern double width;
      extern double height;
      extern unsigned maxNumber;
      extern int damageAmount;
    }
  }

  void initialise();

}

#endif
