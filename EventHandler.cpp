#include "EventHandler.h"
#include <iostream>

namespace EventHandler
{
  void eventHandler(sf::Event e)
  {
    if (e.type == sf::Event::Closed) { Display::window.close(); }
  }

  namespace Keyboard
  {
  }
}
