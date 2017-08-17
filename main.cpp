#include <iostream>
#include "GameEngine.h"
#include <SFML/Graphics.hpp>

int main()
{
  sf::RenderWindow window(sf::VideoMode(1400, 800), "Game");
  GameEngine game(window);

  return 0; 
}
