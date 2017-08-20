#include "ResourceManager.h"

namespace ResourceManager
{
  namespace Background
  {
    sf::Sprite background;

    void initialise()
    {
      background.setTexture(ResourceManager::Texture::background);
    }
  }
  namespace Texture
  {
    sf::Texture player;
    sf::Texture asteroid;
    sf::Texture background;

    void initialise()
    {
      player.loadFromFile("../texture2.png");
      asteroid.loadFromFile("../texture.jpg");
      background.loadFromFile("../background2.jpg");
    }
  }

  namespace Attributes
  {
    namespace Player
    {
      double maxVelocity = 5;
      double radius = 40;
      int damageAmount = 1;
      int initialAmmunition = 100;
      double outlineThichkness = 25;
      double baseOutLineThickness = 10;
    }
    namespace Asteroid
    {
      double maxVelocity = 4;
      int colorVariance = 100;
      int maxEdges = 10;
      int minEdges = 4;
      int maxPositionEdgeX = 200;
      int maxPositionEdgeY = 200;
      int minimalEdgeDisplacement = 40;
      int damageAmount = 1;
    }
    namespace Missle
    {
      double maxVelocity = 12;
      double width = 3;
      double height = 30;
      unsigned maxNumber = 1000;
      int damageAmount = 1;
    }
  }

  void initialise()
  {
    Texture::initialise();
    Background::initialise();
  }
}
