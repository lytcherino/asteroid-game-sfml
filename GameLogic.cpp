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
            //manager.getPlayer()->setVelocityY(-1.0*manager.getPlayer()->getMaxVelocity());
            manager.getPlayer()->setVelocityY(-1.0*manager.getPlayer()->getMaxVelocity()*cos(manager.getPlayer()->getShape().getRotation()*M_PI/180));
            manager.getPlayer()->setVelocityX(1.0*manager.getPlayer()->getMaxVelocity()*sin(manager.getPlayer()->getShape().getRotation()*M_PI/180));
            pressingW = true;
          }
        }
        else {
          if (pressingW && !pressingS) {
            manager.getPlayer()->setVelocityY(0);
            manager.getPlayer()->setVelocityX(0);
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
            //manager.getPlayer()->setVelocityX(-1.0*manager.getPlayer()->getMaxVelocity());
            manager.getPlayer()->rotate(-2);
            pressingA = true;
          }
        }
        else {
          if (pressingA && !pressingD) {
            //manager.getPlayer()->setVelocityX(0);
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
            //manager.getPlayer()->setVelocityY(manager.getPlayer()->getMaxVelocity());

            manager.getPlayer()->setVelocityY(1.0*manager.getPlayer()->getMaxVelocity()*cos(manager.getPlayer()->getShape().getRotation()*M_PI/180));
            manager.getPlayer()->setVelocityX(-1.0*manager.getPlayer()->getMaxVelocity()*sin(manager.getPlayer()->getShape().getRotation()*M_PI/180));
            pressingS = true;
          }
        }
        else {
          if (pressingS && !pressingW) {
            manager.getPlayer()->setVelocityY(0);
            manager.getPlayer()->setVelocityX(0);
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
            //manager.getPlayer()->setVelocityX(manager.getPlayer()->getMaxVelocity());
            manager.getPlayer()->rotate(2);
            pressingD = true;
          }
        }
        else {
          if (pressingD && !pressingA) {
            //manager.getPlayer()->setVelocityX(0);
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
          manager.getPlayer()->levelPlayer();
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
      if (manager.getPlayer()->getAmmunition() == 0) { return; }
      if (Missle::missleCount > Missle::maxNumber) { return; }
      double x = manager.getPlayer()->getPosition().x;
      double y = manager.getPlayer()->getPosition().y;

      manager.add(std::make_shared<Missle>(x, y, manager.getPlayer()->getShape().getRotation()*M_PI/180.0));
      manager.getPlayer()->fireMissle();
    }

    void reloadMissle(ObjectManager& manager, Timer& timer)
    {
      if (timer.getElapsedTime().asMilliseconds() > 100) {
        timer.resetTimer();
        manager.getPlayer()->updateAmmunition(1);
      }
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



