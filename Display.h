#ifndef DISPLAY_H
#define DISPLAY_H
#include <SFML/Graphics.hpp>

namespace Display
{
  constexpr static int WIDTH = 1400;
  constexpr static int HEIGHT = 800;

  extern sf::RenderWindow window;

  extern unsigned int frameRateLimit;
  void initialise();

  void clear();
  void update();

  void close();
}

#endif
