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
      background.setRepeated(true);
    }
  }

  namespace Attributes
  {
    namespace Player
    {
      double maxVelocity = 5;
      double radius = 20;
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
      int maxPositionEdgeX = 400;
      int maxPositionEdgeY = 400;
      int minimalEdgeDisplacement = 100;
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
    namespace World
    {
      double width = 4000;
      double height = 4000;
    }
  }

  void initialise()
  {
    Texture::initialise();
    Background::initialise();
  }
}
