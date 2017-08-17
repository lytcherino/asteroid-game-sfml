#include "EventHandler.h"
#include <iostream>

namespace EventHandler
{
  void eventHandler(sf::Event e)
  {
    if (e.type == sf::Event::Closed) { Display::window.close(); }
    if (e.type == sf::Event::KeyPressed) { Keyboard::eventHandler(e, GameLogic::keyType::PRESS); }
    if (e.type == sf::Event::KeyReleased) { Keyboard::eventHandler(e,GameLogic::keyType::RELEASE); }
  }

  namespace Keyboard
  {
    void eventHandler(sf::Event e, GameLogic::keyType type)
    {
      if (e.key.code == sf::Keyboard::W) {
        GameLogic::Keyboard::handleKeyboardEvent("W", type);
      }
      if (e.key.code == sf::Keyboard::A) {
        GameLogic::Keyboard::handleKeyboardEvent("A", type);
      }
      if (e.key.code == sf::Keyboard::S) {
        GameLogic::Keyboard::handleKeyboardEvent("S", type);
      }
      if (e.key.code == sf::Keyboard::D) {
        GameLogic::Keyboard::handleKeyboardEvent("D", type);
      }
      if (e.key.code == sf::Keyboard::Escape) {
        GameLogic::Keyboard::handleKeyboardEvent("Esc", type);
      }
      if (e.key.code == sf::Keyboard::Space) {
        GameLogic::Keyboard::handleKeyboardEvent("Space", type);
      }
    }
  }
}
