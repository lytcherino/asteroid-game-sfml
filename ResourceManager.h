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

  void initialise();

}

#endif
