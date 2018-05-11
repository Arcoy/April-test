#pragma once
#include "Item.h"
class Armor :
   public Item
{
   friend class UI;
private:
   Type type;
public:
   Type getType() { return type; }
   Armor();
   ~Armor();
};

