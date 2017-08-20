#ifndef OBJECT_MANAGER_H
#define OBJECT_MANAGER_H

#include "Object.h"
#include <utility>
#include <iostream>
#include "Player.h"
#include "Missle.h"
#include <iostream>
#include "Display.h"
#include "Asteroid.h"
#include <vector>

class ObjectManager
{
private:
  std::map<int, std::shared_ptr<Object>> m_gameObjects;

  std::shared_ptr<Player> player;

  struct ObjectDeallocator {
    void operator() (std::pair<int, std::shared_ptr<Object>>& pair) {
      pair.second.reset();
    } 
  };
  
  // not used
  struct ObjectUpdater {
    void operator() (std::pair<int, std::shared_ptr<Object>>& pair, sf::Time elapsed) {
      //pair.second->updatePosition(pair.second, elapsed);
    }
  };

  void updatePosition(std::shared_ptr<Object>, sf::Time);

public:
  ObjectManager();
  ~ObjectManager();

  void drawAll(sf::RenderWindow& window);

  // Put in GameLogic later
  bool outOfBounds(std::shared_ptr<Object> object);

  std::vector<std::shared_ptr<Object>> getObjectVector();
  void checkObject(std::shared_ptr<Object> object);

  void add(std::shared_ptr<Object>);
  void remove(int ID);
  int getObjectCount() const;
  void updateAll(sf::Time);
  std::shared_ptr<Player> getPlayer();
  void setPlayer(std::shared_ptr<Player>);
};

#endif
