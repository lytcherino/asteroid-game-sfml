#include "CollisionManager.h"

namespace CollisionManager
{
  void collisionDetectionBasic(ObjectManager& manager)
  {
    std::cerr << "CHECKING\n";
    auto objects = manager.getObjectVector();

    for(auto object : objects) {
      for(auto object2 : objects) {
        if (object->getID() != object2->getID()) {
            
          }
        }
      }
    }
  }
}
 
