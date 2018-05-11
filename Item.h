#pragma once
#include <string>
using namespace std;

class Item
{
   friend class UI;
protected:
   int id;
   string name;
   string desc;
   string effectText;
   string itemLoad;
   int weight, uses, maxUses;
   bool equiped;
   int statBonus[7]; //If an equiped item grants bonus stats, they are stored here
   enum Type { sword, axe, lance, bow, crossbow, staff, wand, shield, ring, cape, helmet, boots, gauntlets, pendant, none};
public:
   ~Item();
   Item();
   Item(int id); //read from the Item.txt to find id, then load Item
   Item(string name, int weight, int maxUses); // make a new temp Item
   bool use(int statMods[7]); //parameter is the using unit's bonus stat array
   void setToDefault();
   void setToTest();
   int getWeight() { return weight; }
   bool isEquiped() { return weight; }
   bool equip();
   bool unequip();
   int getId() { return id; }
   string getName() { return name; }
   string getEffectText() { return effectText; }
   virtual string toString();
   virtual Type getType();
   virtual Type stringToType(string makeType);
};

