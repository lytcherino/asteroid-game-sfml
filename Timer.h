#ifndef TIMER_H
#define TIMER_H

#include <SFML/Graphics.hpp>

class Timer
{
  sf::Clock clock;

public:
  Timer();
  ~Timer();
  sf::Time getElapsedTime();
  void resetTimer();
};

#endif
