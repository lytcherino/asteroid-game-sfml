#include "ObjectInterface.h"

template<typename T>
class Enemies : public ObjectInterface<T>
{
 public:
  Enemies<T>(double x, double y, double health) : ObjectInterface<T>(x, y, health) {

  }
  virtual ~Enemies() {}
};
