#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
  
}

ObjectManager::~ObjectManager()
{
  // std::for_each(m_gameObjects.begin(), m_gameObjects.end(), ObjectDeallocator());
}

void ObjectManager::drawAll(sf::RenderWindow& window)
{
  std::map<int, std::shared_ptr<Object>>::const_iterator itr = m_gameObjects.begin(); 
  while(itr != m_gameObjects.end()) {
    itr->second->draw(window);
    ++itr;
  }
}

void ObjectManager::add(std::shared_ptr<Object> o)
{
  int ID = o->getID();
  m_gameObjects.insert(std::pair<int, std::shared_ptr<Object>>(ID, o));
}

void ObjectManager::remove(int ID)
{
  auto itr = m_gameObjects.find(ID);
  if(itr != m_gameObjects.end()) {
    itr->second.reset();
    m_gameObjects.erase(itr);
  }
}

int ObjectManager::getObjectCount() const
{
  return m_gameObjects.size();
}

void ObjectManager::updateAll(sf::Time elapsed)
{
  std::map<int, std::shared_ptr<Object>>::const_iterator itr;
  for(itr = m_gameObjects.begin(); itr != m_gameObjects.end(); ++itr) {
    updatePosition(itr->second, elapsed);
    outOfBounds(itr->second);
  }
}

std::shared_ptr<Player> ObjectManager::getPlayer()
{
  return player;
}

void ObjectManager::setPlayer(std::shared_ptr<Player> _player)
{
  player = _player;
}

std::vector<std::shared_ptr<Object>> ObjectManager::getObjectVector()
{
  std::vector<std::shared_ptr<Object>> objects;
  objects.resize(getObjectCount());
  int count = 0;
  for(auto itr = m_gameObjects.begin(); itr != m_gameObjects.end(); ++itr) {
    objects[count++] = itr->second;
  }
  return objects;
}

void ObjectManager::updatePosition(std::shared_ptr<Object> object, sf::Time elapsed)
{
  double x_vel = object->getVelocity().x;
  double y_vel = object->getVelocity().y;

  object->move(sf::Vector2f(x_vel, y_vel));
}

void ObjectManager::outOfBounds(std::shared_ptr<Object> object)
{
  double x = object->getPosition().x;
  double y = object->getPosition().y;

  if (x > Display::Bounds::WIDTH) { object->setPosition(sf::Vector2f(0, y)); }
  if (x < 0) { object->setPosition(sf::Vector2f(Display::Bounds::WIDTH, y)); }
  if (y > Display::Bounds::HEIGHT) { object->setPosition(sf::Vector2f(x, 0)); }
  if (y < 0) { object->setPosition(sf::Vector2f(x, Display::Bounds::HEIGHT)); }
}


void ObjectManager::checkObject(std::shared_ptr<Object> object)
{
  if (object->getHealth() <= 0) {
    remove(object->getID());
  }
}
