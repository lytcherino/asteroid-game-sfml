#include "GameEngine.h"

namespace GameEngine
{

  Timer reloadMissleTimer; 
  Timer loopTimer;
  ObjectManager objectManager;

  void start()
  {
    Display::initialise();
    ResourceManager::initialise();
    GameEngine::initialise();
    GameLogic::initialise();
    run();
  }

  void initialise()
  { 
    std::srand(std::time(NULL));
    EntityFactory::createPlayer(objectManager, "Al");

    EntityFactory::createAsteroid(objectManager);
    EntityFactory::createAsteroid(objectManager);
    EntityFactory::createAsteroid(objectManager);
    EntityFactory::createAsteroid(objectManager);
    EntityFactory::createAsteroid(objectManager);
    EntityFactory::createAsteroid(objectManager);
    EntityFactory::createAsteroid(objectManager);
    EntityFactory::createAsteroid(objectManager);
    EntityFactory::createAsteroid(objectManager);
    EntityFactory::createAsteroid(objectManager);
    EntityFactory::createAsteroid(objectManager);
    EntityFactory::createAsteroid(objectManager);
    EntityFactory::createAsteroid(objectManager);
  }

  void render()
  {
    Display::clear();
    // Draw
      draw();
      Display::update();
  }

  void draw()
  {
    Display::window.draw(ResourceManager::Background::background);
    objectManager.drawAll(Display::window);
  }

  void run()
  {
    // Handle events, key presses
    while(Display::window.isOpen()) {

      sf::Event event;

      // Event handler

      while (Display::window.pollEvent(event))
        {
          EventHandler::eventHandler(event);
        }

      CollisionManager::collisionDetectionBasic(objectManager);
      if (Display::window.hasFocus()) {
        GameLogic::Keyboard::handleKeyboardInput(objectManager);
      }
      GameLogic::Weapon::reloadMissle(objectManager, reloadMissleTimer);

      objectManager.updateAll(loopTimer.getElapsedTime());
      loopTimer.resetTimer();
      render();
    }
  }

}
