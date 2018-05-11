#pragma once
#include <string>
#include "Item.h"
using namespace std;

class Unit
{
   friend class UI;
private:
   string name;
   string unitClass;
   int level;
   int stats[7];
   int statmods[7];
   int carryWeight, hp, maxHp, carryRemaining;
   int hitRate, avoid;
   Item *equipment[5] = { NULL };
   Item *inventory[200] = { NULL };
   int invPos = 0;
public:
   ~Unit();
   int getHp() { return hp; }
   string toString();
   Unit();
   Unit(string name, string unitClass, int level, int str, int dex, int con, int wis, int intel, int cha, int skill);
   bool attack(Unit &target);
   bool update();
   bool damage(int damage);
   bool use(int item);
   int inventoryWeight();
   void resetBonus();
   bool addItem(Item * item);
   bool equip(int item);
   bool unequip(int item);
   void sortInventory();
   string getInventory();
};
