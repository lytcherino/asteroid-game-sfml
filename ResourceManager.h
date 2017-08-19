#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <string>

namespace ResourceManager
{
  namespace Texture
  {
    extern sf::Texture player; 
    extern sf::Texture asteroid;
    void initialise();
  } 
  namespace Attributes
  {
    namespace Player
    {
      extern double maxVelocity;
      extern double radius;
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
    }
    namespace Missle
    {
      extern double maxVelocity;
      extern double width;
      extern double height;
      extern unsigned maxNumber;
    }
  }

  void initialise();

}

#endif
