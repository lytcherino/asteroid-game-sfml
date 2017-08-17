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
  }
}

void ObjectManager::updatePosition(std::shared_ptr<Object> object, sf::Time elapsed)
{
  double x = object->getX();
  double y = object->getY();
  double x_vel = object->getVelocity().x;
  double y_vel = object->getVelocity().y;

  x += elapsed.asSeconds() * x_vel;
  y += elapsed.asSeconds() * y_vel; 

  object->setPosition(x, y);
  object->updateSprite(); 

  //spriteCollision(object);

  //  if (x > WIDTH / 3 || x < 0) { x_vel *= -1;  }
  //if (y > HEIGHT / 3 || y < 0) { y_vel *= -1; }
  //object->setVelocity(x_vel, y_vel);
}

/*
bool ObjectManager::spriteCollision(std::shared_ptr<Object> object)
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
*/
