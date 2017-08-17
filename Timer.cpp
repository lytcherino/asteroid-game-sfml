#include "Timer.h"

Timer::Timer()
{
  
}

Timer::~Timer()
{
  
}

sf::Time Timer::getElapsedTime()
{
  sf::Time elapsed = clock.getElapsedTime();
  return elapsed;
}

void Timer::resetTimer()
{
  clock.restart();
}
