#include "CollisionManager.h"

namespace CollisionManager
{
  void collisionDetectionBasic(ObjectManager& manager)
  {
    auto objects = manager.getObjectVector();

    for(auto object : objects) {
      for(auto object2 : objects) {
        if (object->getID() != object2->getID()) {
          if(object->getIntersection(object2->getRectangleBounds())) {
            // Collision
            object->collision(object2);
            object2->collision(object);

            manager.checkObject(object);
            manager.checkObject(object2);
          }
        }
      }
    }
  }
}
 
