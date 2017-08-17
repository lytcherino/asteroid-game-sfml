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

  void initialise()
  {
    Texture::initialise();
  }
}
