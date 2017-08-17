#include "GameEngine.h"

namespace GameEngine
{

  Timer loopTimer;
  ObjectManager objectManager;

  std::shared_ptr<Player> player;

  //enum game state {Uninitialized, Playing, ShowingMenu, Paused};

  void start()
  {
    Display::initialise();
    ResourceManager::initialise();
    GameEngine::initialise();

    GameLogic::initialise(player);
    run();
  }

  void initialise()
  {

    player = EntityFactory::createPlayer(objectManager, "Al");

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

      objectManager.updateAll(loopTimer.getElapsedTime());
      loopTimer.resetTimer();
      render();
    }
  }

}

