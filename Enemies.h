#include "Object.h"

class Enemies : public Object
{
 public:
  Enemies(double x, double y, double health); 
  virtual ~Enemies() {}
};
