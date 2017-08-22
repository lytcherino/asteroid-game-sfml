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
    update(itr->second, elapsed);
  }
}

void ObjectManager::update(std::shared_ptr<Object> object, sf::Time elapsed)
{
  updatePosition(object, elapsed);
  if (outOfBounds(object)) {
    if (auto missle = std::dynamic_pointer_cast<Missle>(object)) {
      missle->setHealth(0);
    }
    if (auto asteroid = std::dynamic_pointer_cast<Asteroid>(object)) {
      //object->ellasticReverse();
    }
    if (auto player = std::dynamic_pointer_cast<Player>(object)) {
      object->teleportAtEdge();
    }
  }
  checkObject(object);
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
  double x_acc = object->getAcceleration().x;
  double y_acc = object->getAcceleration().y;

  double x_vel = x_acc * elapsed.asSeconds() + object->getVelocity().x;
  double y_vel = y_acc * elapsed.asSeconds() + object->getVelocity().y;

  object->setVelocity(x_vel, y_vel);
  object->move(sf::Vector2f(x_vel, y_vel));
  //object->adjustPosition(sf::Vector2f(x_vel * elapsed.asSeconds(), y_vel * elapsed.asSeconds()));
}

bool ObjectManager::outOfBounds(std::shared_ptr<Object> object)
{
  double x = object->getPosition().x;
  double y = object->getPosition().y;

  if (x > ResourceManager::Attributes::World::width/2) { return true; }
  if (x < - ResourceManager::Attributes::World::width/2) { return true; }
  if (y > ResourceManager::Attributes::World::height/2) { return true; }
  if (y < - ResourceManager::Attributes::World::height/2) { return true; }
  return false;
}


void ObjectManager::checkObject(std::shared_ptr<Object> object)
{
  if (object->getHealth() <= 0) {
    if (std::shared_ptr<Asteroid> a = std::dynamic_pointer_cast<Asteroid>(object)) {
      getPlayer()->gainExperience(a->getExperience());
    }
    remove(object->getID());
  }
}

std::map<int, std::shared_ptr<Object>> ObjectManager::getObjectMap() const
{
  return m_gameObjects;
}
