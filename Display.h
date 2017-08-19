#ifndef DISPLAY_H
#define DISPLAY_H
#include <SFML/Graphics.hpp>
#include <string>

namespace Display
{
  constexpr int WIDTH = 1400;
  constexpr int HEIGHT = 800;

  extern std::string gameName; 
  namespace Bounds
  {
    extern int WIDTH;
    extern int HEIGHT;
  }
  extern sf::RenderWindow window;

  extern unsigned int frameRateLimit;
  void initialise();

  void clear();
  void update();

  void close();
}

#endif
