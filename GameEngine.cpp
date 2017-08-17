#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "GameEngine.h"


GameEngine::GameEngine(sf::RenderWindow& window) 
{
  this->window = &window;
  initialise();

}

void GameEngine::initialise()
{


  // Load and set textures
  playerTexture.loadFromFile("../texture2.png");
  asteroidTexture.loadFromFile("../texture.jpg");

  // Create player
  createPlayer("P1");

  // Create asteroids
  generateAsteroids();

  // Run 
  run();



}

void GameEngine::createPlayer(const std::string& name)
{
  std::shared_ptr<Player> p1 = std::make_shared<Player>(100.0, 100.0, 100.0, name);
  p1->setSpriteTexture(playerTexture);
  players.emplace_back(p1);
  objects.emplace_back(p1);
}

void GameEngine::generateAsteroids()
{
  int amount = getNumberOfAsteroids();
  std::srand(std::time(0));

  for(int i = 0; i < amount; i++) {

    double x = (std::rand() % WIDTH / 3) + 1;
    double y = (std::rand() % HEIGHT / 3) + 1;
    double health = (std::rand() % 60) + 10;

    std::shared_ptr<Asteroid> asteroid = std::make_shared<Asteroid>(x,y, health);
    asteroid->setSpriteTexture(asteroidTexture);
    enemies.emplace_back(asteroid);
    objects.emplace_back(asteroid);
  }
}

int GameEngine::getNumberOfAsteroids()
{
  return 5; // depends on difficulty
}

void GameEngine::updateSpritePosition(sf::Time elapsed)
{
  for(auto object : objects) {
    double x = object->getX();
    double y = object->getY();
    double x_vel = object->getVelocity().x;
    double y_vel = object->getVelocity().y;

    x += elapsed.asSeconds() * x_vel;
    y += elapsed.asSeconds() * y_vel; 
    
    object->setPosition(x, y);
    object->updateSprite();

    spriteCollision(object);

    if (x > WIDTH / 3 || x < 0) { x_vel *= -1;  }
    if (y > HEIGHT / 3 || y < 0) { y_vel *= -1; }
    //object->setVelocity(x_vel, y_vel);

  }


}

bool GameEngine::spriteCollision(std::shared_ptr<Object> object)
{
  for(auto object2 : objects) {
    if (object->getID() != object2->getID()) {
      if (object->getSprite().getGlobalBounds().intersects(object2->getSprite().getGlobalBounds())) {
        // Collision
        std::cerr << "Collision between " << object->getID() << " and " << object2->getID() << "\n";
        // Ellastic collision physics

        // Individual collision handling
        object->collision(object2);
        object2->collision(object);

        if(object->getHealth() <= 0) {
          for(int i = 0; i < objects.size(); i++) {
            if (objects[i]->getID() == object->getID()){
              objects.erase(objects.begin() + i);
            }
          }
        }
        if (object2->getHealth() <= 0) {
          for(int i = 0; i < objects.size(); i++) {
            if (objects[i]->getID() == object2->getID()){
              objects.erase(objects.begin() + i);
            }
          }
        }
      }
    }
  }


}


void GameEngine::updateGameState(sf::Time elapsed)
{
  updateSpritePosition(elapsed);
}

void GameEngine::render()
{
    window->clear();

    // Draw
    draw();

    // Display
    window->display();

}

void GameEngine::draw()
{
  for(auto player : players) {
    window->draw(player->getSprite());
  }
  for(auto enemy : enemies) {
    window->draw(enemy->getSprite());
  }
}

void GameEngine::run()
{
  // Handle events, key presses
  while(window->isOpen()) {

    sf::Event event;

    sf::Time elapsed = clock.restart();

    window->pollEvent(event); 
    //while(window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window->close();
      }

      updateGameState(elapsed);

    render();
  }
} 

#endif
