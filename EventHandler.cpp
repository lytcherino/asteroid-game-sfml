#include "EventHandler.h"
#include <iostream>

namespace EventHandler
{
  void eventHandler(sf::Event e)
  {
    if (e.type == sf::Event::Closed) { Display::window.close(); }
    if (e.type == sf::Event::Resized) {
      sf::FloatRect visibleArea(0, 0, e.size.width, e.size.height);
      Display::window.setView(sf::View(visibleArea));
    }
  }

  namespace Keyboard
  {
  }
}
