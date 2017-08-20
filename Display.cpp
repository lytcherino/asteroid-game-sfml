#include "Display.h"


namespace Display
{

  sf::RenderWindow window;

  unsigned int frameRateLimit = 120;
  std::string gameName = "Spherical";

  namespace Bounds
  {
    int WIDTH = Display::WIDTH - 40;
    int HEIGHT = Display::HEIGHT - 50;
  }
  void initialise()
  {
    window.create(sf::VideoMode(WIDTH, HEIGHT), gameName);
    window.setFramerateLimit(frameRateLimit);
  }

  void close()
  {
    window.close();
  }

  void clear()
  {
    window.clear();
  }

  void update()
  {
    window.display();
  }
}

