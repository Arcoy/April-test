#include "Item.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <sstream>
#include <fstream>
using namespace std;

Item::~Item()
{
   cout << name<<" Deleted"<<endl;
}

Item::Item()
{
   setToDefault();
}

Item::Item(int id)
{
   stringstream tempInt;
   ifstream itemList;
   itemList.open("ItemList.txt");
   int testId = 0;
   int temp = 0;
   if (itemList.is_open())
   {
      while (getline(itemList, itemLoad) && itemList.is_open())
      {
         tempInt.clear();
         tempInt.str("");
         tempInt << itemLoad.front();
         tempInt >> testId;

         if (testId == id)
         {
            itemList.close();
            this->id = id;
            itemLoad = itemLoad.substr(itemLoad.find(" ") + 2);
            this->name = itemLoad.substr(0, itemLoad.find("\""));
            itemLoad = itemLoad.substr(itemLoad.find("\"") + 2);
            for (int i = 0; i < 7; i++)
            {
               tempInt.clear();
               tempInt.str("");
               tempInt << itemLoad.front();
               tempInt >> statBonus[i];
               itemLoad = itemLoad.substr(itemLoad.find(" ")+1);
            }
            tempInt.clear();
            tempInt.str("");
            tempInt << itemLoad.front();
            tempInt >> weight;
            itemLoad = itemLoad.substr(3);
            this->desc = itemLoad.substr(0, itemLoad.find("\""));
            itemLoad = itemLoad.substr(itemLoad.find("\""));
            if (itemLoad != "\"")
               itemLoad = itemLoad.substr(2);
            else
               itemLoad = "";
         }
      }
   }
   itemList.close(); 

}

Item::Item(string name, int weight, int maxUses)
{
}

bool Item::use(int statMods[7])
{
   for (int i = 0; i < 7; i++) 
   {
      statMods[i] += statBonus[i];
   }
   return true;
}

void Item::setToDefault()
{
   this->id = 000;
   this->name = "-";
   this->maxUses = 0;
   this->uses = 0;
   this->weight = 0;
   this->equiped = false;
   for (int i = 0; i < 7; i++) {
      statBonus[i] = 0;
   }
}
void Item::setToTest()
{
   this->id = 001;
   this->name = "Moonstone Band";
   this->maxUses = 0;
   this->uses = 0;
   this->weight = 1;
   this->equiped = false;
   for (int i = 0; i < 7; i++) {
      statBonus[i] = 1;
   }
   this->desc = "A small stone ring that glows faintly in the moonlight. All Stats +1";
   this->effectText = "All stats +1";
}

bool Item::equip()
{
   equiped = true;
   return true;
}

bool Item::unequip()
{
   equiped = false;
   return true;
}

string Item::toString()
{
   stringstream strm;
   strm << name << ": ";
   strm << weight << " lbs ";
   if (equiped)
      strm << "Equiped";
   strm << endl;
   strm << "   " <<desc << endl;
   return strm.str();
}

Item::Type Item::getType()
{
   return Type();
}

Item::Type Item::stringToType(string makeType)
{
   if (makeType == "sword")
      return sword;
   if (makeType == "axe")
      return axe;
   if (makeType == "lance")
      return lance;
   if (makeType == "bow")
      return bow;
   if (makeType == "crossbow")
      return crossbow;
   if (makeType == "staff")
      return staff;
   if (makeType == "wand")
      return wand;
   if (makeType == "shield")
      return ring;
   if (makeType == "cape")
      return cape;
   if (makeType == "helmet")
      return helmet;
   if (makeType == "boots")
      return boots;
   if (makeType == "gauntlets")
      return gauntlets;
   if (makeType == "pendant")
      return pendant;
   return none;
}

