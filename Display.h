#ifndef DISPLAY_H
#define DISPLAY_H
#include <SFML/Graphics.hpp>
#include <string>
#include "ResourceManager.h"

namespace Display
{
  constexpr int WIDTH = 1920;
  constexpr int HEIGHT = 1080;

  class Background
  {
    sf::Sprite background;
  public:
    Background();

    void loadBackground();
    sf::Sprite getBackground() const;
  };

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
