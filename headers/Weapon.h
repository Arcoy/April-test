#pragma once
#include "Item.h"
class Weapon :
   public Item
{
   friend class UI;
private:
   int range;
   Type type;
public:
   Type getType() { return type; }
   Weapon();
   Weapon(int id);
   ~Weapon();
};

