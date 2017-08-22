#include "GameLogic.h"


namespace GameLogic
{
  gameState state;

  void update(ObjectManager& manager, Timer& timer)
  {
    Physics::update(manager);
    Weapon::update(manager, timer);
    Keyboard::update(manager);
    Mouse::update(manager);
    Camera::update(manager);
  }
  namespace Keyboard
  {
    bool pressingW;
    bool pressingA;
    bool pressingS;
    bool pressingD;

    void update(ObjectManager& manager)
    {
      if (Display::window.hasFocus()) {
        Keyboard::handleKeyboardInput(manager);
      }
    }

    void keyW(ObjectManager& manager)
    {
      if (state == gameState::Playing) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
          if(!pressingS) {
            double maxAcc = manager.getPlayer()->getMaxAcceleration();
            double rotation = manager.getPlayer()->getShape().getRotation() * M_PI / 180;
            manager.getPlayer()->adjustAcceleration(1.0 * maxAcc * sin(rotation),
                                                    -1.0 * maxAcc * cos(rotation));
            pressingW = true;
          }
        }
        else {
          if (pressingW && !pressingS) {
            //manager.getPlayer()->setVelocityY(0);
            //manager.getPlayer()->setVelocityX(0);
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
            double maxAcc = manager.getPlayer()->getMaxAcceleration();
            double rotation = manager.getPlayer()->getShape().getRotation() * M_PI / 180;
            manager.getPlayer()->adjustAcceleration( -1.0 * maxAcc * sin(rotation),
                                                     1.0 * maxAcc * cos(rotation));
            pressingS = true;
          }
        }
        else {
          if (pressingS && !pressingW) {
            //manager.getPlayer()->setVelocityY(0);
            //manager.getPlayer()->setVelocityX(0);
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

  namespace Mouse
  {
    void update(ObjectManager& manager)
    {
      if (Display::window.isOpen()){
        handleMouse(manager);
      }
    }

    void handleMouse(ObjectManager& manager)
    {
      if (state == gameState::Playing) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
          double xMouse = sf::Mouse::getPosition(Display::window).x;
          double yMouse = sf::Mouse::getPosition(Display::window).y;
          double xPlayer = manager.getPlayer()->getPosition().x;
          double yPlayer = manager.getPlayer()->getPosition().y;

          double xDelta = xMouse - xPlayer;
          double yDelta = yMouse - yPlayer;

          double angleRad = atan2(yDelta, xDelta);

          double maxAcc = manager.getPlayer()->getMaxAcceleration();
          manager.getPlayer()->getShape().setRotation(angleRad * 180/M_PI + 90);

          manager.getPlayer()->adjustAcceleration(1.0 * maxAcc * cos(angleRad),
                                                  1.0 * maxAcc * sin(angleRad));

        }
      }
    }
  }
  namespace Weapon
  {
    void update(ObjectManager& manager, Timer& timer)
    {
      reloadMissle(manager, timer);
    }
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
    Random::initialise();
    Camera::initialise();
  }

  namespace Random
  {
    void initialise()
    {
      std::default_random_engine generator;
      std::uniform_real_distribution<double> distributionX(0, Display::Bounds::WIDTH);
      std::uniform_real_distribution<double> distributionY(0, Display::Bounds::HEIGHT);
      auto randomPositionX = std::bind(generator, distributionX);
      auto randomPositionY = std::bind(generator, distributionY);
    }
  }

  namespace Physics
  {
    void update(ObjectManager& manager)
    {
      Gravity::update(manager);
    }
    namespace Gravity
    {
      void update(ObjectManager& manager)
      {
        // Provide "gravitional attraction" such that objects are pulled towards the player
        auto objects = manager.getObjectMap();
        for(auto itr = objects.cbegin(); itr != objects.cend(); ++itr) {
          auto object1 = itr->second;

          double acceleration_x = 0;
          double acceleration_y = 0;
          double gravConstant = 25;

          for(auto itr2 = objects.cbegin(); itr2 != objects.cend(); ++itr2){
            auto object2 = itr2->second;
            if (object1->getID() == object2->getID()) { continue; }
            // ignore influence from player
            if (std::shared_ptr<Player> p = std::dynamic_pointer_cast<Player>(object2)) { continue; }
            if (std::shared_ptr<Missle> m = std::dynamic_pointer_cast<Missle>(object1)) {
              if (std::shared_ptr<Asteroid> a = std::dynamic_pointer_cast<Asteroid> (object2)) { gravConstant = 100000; }
          }

            double xDelta = - object1->getPosition().x + object2->getPosition().x;
            double yDelta = - object1->getPosition().y + object2->getPosition().y;
            double angleRad = atan2(yDelta, xDelta);

            double gravConstant = 25;
            double acceleration = gravConstant * object2->getMass() / std::sqrt((std::pow(xDelta,2) + std::pow(yDelta, 2)) + 0.00001); 
            acceleration_x += acceleration * cos(angleRad);
            acceleration_y += acceleration * sin(angleRad);
          }
          //std::cerr << "accl: " << acceleration_x << " " << acceleration_y << "\n\n";
          object1->setAcceleration(acceleration_x, acceleration_y);
        }
      }
    }
  }

  namespace Camera
  {
    sf::View view;
    double zoom;

    void initialise()
    {
      view = Display::window.getDefaultView();
      zoom = 1.0;
    }
    void update(ObjectManager& manager)
    {
      view.setCenter(manager.getPlayer()->getShape().getPosition());
      //view.setRotation(manager.getPlayer()->getShape().getRotation());
      view.zoom(zoom);
      Display::window.setView(view);
    }
  }

  namespace PowerUp
  {
    
  }

  namespace Collision
  {
  }

}



