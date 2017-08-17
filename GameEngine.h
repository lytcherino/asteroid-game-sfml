#include "Player.h"
#include "Asteroid.h"
#include "Object.h"
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <iostream>

class GameEngine
{
 private:

  std::vector<std::shared_ptr<Asteroid>> enemies;
  std::vector<std::shared_ptr<Player>> players;
  std::vector<std::shared_ptr<Object>> objects;

  sf::Texture playerTexture;
  sf::Texture asteroidTexture;

  constexpr static int WIDTH = 1400;
  constexpr static int HEIGHT = 800;

  sf::RenderWindow* window;

  sf::Clock clock;

 public:

  GameEngine(sf::RenderWindow&);

  void initialise();
  void run();

  void createPlayer(const std::string&);
  void generateAsteroids();
  int getNumberOfAsteroids();

  void updateGameState(sf::Time);
  void render();
  void draw();

  bool spriteCollision(std::shared_ptr<Object>);
  void updateSpritePosition(sf::Time elapsed);
};
 
