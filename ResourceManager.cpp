#include "ResourceManager.h"

namespace ResourceManager
{
  namespace Texture
  {
    sf::Texture player;
    sf::Texture asteroid;

    void initialise()
    {
      player.loadFromFile("../texture2.png");
      asteroid.loadFromFile("../texture.jpg");
    }
  }

  namespace Attributes
  {
    namespace Player
    {
      double maxVelocity = 5;
      double radius = 40;
    }
    namespace Asteroid
    {
      double maxVelocity = 2;
      int colorVariance = 100;
      int maxEdges = 20;
      int minEdges = 7;
      int maxPositionEdgeX = 200;
      int maxPositionEdgeY = 200;
      int minimalEdgeDisplacement = 40;
    }
    namespace Missle
    {
      double maxVelocity = 12;
      double width = 3;
      double height = 30;
      unsigned maxNumber = 10;
    }
  }

  void initialise()
  {
    Texture::initialise();
  }
}
