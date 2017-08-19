#include "GameLogic.h"


namespace GameLogic
{
  gameState state;

  bool pressingW;
  bool pressingA;
  bool pressingS;
  bool pressingD;

  namespace Keyboard
  {
    void keyW(ObjectManager& manager)
    {
      if (state == gameState::Playing) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
          if(!pressingS) {
            manager.getPlayer()->setVelocityY(-1.0*manager.getPlayer()->getMaxVelocity());
            pressingW = true;
          }
        }
        else {
          if (pressingW && !pressingS) {
            manager.getPlayer()->setVelocityY(0);
            pressingW = false;
          }
        }
      }
    }

    void keyA(ObjectManager& manager)
    {
      if (state == gameState::Playing) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
          if (!pressingD) {
            manager.getPlayer()->setVelocityX(-1.0*manager.getPlayer()->getMaxVelocity());
            pressingA = true;
          }
        }
        else {
          if (pressingA && !pressingD) {
            manager.getPlayer()->setVelocityX(0);
            pressingA = false;
          }
        }
      }
    }

    void keyS(ObjectManager& manager)
    {
      if (state == gameState::Playing) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
          if (!pressingW) {
            manager.getPlayer()->setVelocityY(manager.getPlayer()->getMaxVelocity());
            pressingS = true;
          }
        }
        else {
          if (pressingS && !pressingW) {
            manager.getPlayer()->setVelocityY(0); 
            pressingS = false;
          }
        }
      }
    }

    void keyD(ObjectManager& manager)
    {
      if (state == gameState::Playing) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
          if (!pressingA) {
            manager.getPlayer()->setVelocityX(manager.getPlayer()->getMaxVelocity());
            pressingD = true;
          }
        }
        else {
          if (pressingD && !pressingA) {
            manager.getPlayer()->setVelocityX(0);
            pressingD = false;
          }
        }
      }
    }

    void keyEsc(ObjectManager& manager)
    {
      if (state == gameState::Playing) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            // open/close menu
          manager.getPlayer()->levelPlayer(1);
          }
      }
    }

    void keySpace(ObjectManager& manager)
    {
      if (state == gameState::Playing) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            // start shooting
          Weapon::fireMissle(manager);
          }
      }
    }

    void handleKeyboardInput(ObjectManager& manager)
    {
      keyW(manager);
      keyD(manager);
      keyA(manager);
      keyS(manager);
      keyEsc(manager);
      keySpace(manager);
    }
  }

  namespace Weapon
  {
    void fireMissle(ObjectManager& manager)
    {
      if (Missle::missleCount > Missle::maxNumber) { return; }
      double x = manager.getPlayer()->getPosition().x;
      double y = manager.getPlayer()->getPosition().y;

      manager.add(std::make_shared<Missle>(x, y));
    }
  }

  void initialise()
  {
    state = gameState::Playing;
  }

  namespace Collision
  {
    
  }
}



