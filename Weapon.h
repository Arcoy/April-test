#pragma once
#include "Item.h"
class Weapon :
   public Item
{
private:
   enum Type{sword, axe, lance, bow, crossbow, none};
   Type type;
   int range;
public:
   Weapon();
   ~Weapon();
};

