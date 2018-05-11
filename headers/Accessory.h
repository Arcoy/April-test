#pragma once
#include "Item.h"
class Accessory :
   public Item
{
   friend class UI;
private:
   Type type;
public:
   Type getType() { return type; }
   Accessory();
   Accessory(int id);
   ~Accessory();
   string toString();
};

