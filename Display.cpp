#include "Display.h"


namespace Display
{

  sf::RenderWindow window;

  unsigned int frameRateLimit = 120;

  void initialise()
  {
    window.create(sf::VideoMode(WIDTH, HEIGHT), "Window");
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
