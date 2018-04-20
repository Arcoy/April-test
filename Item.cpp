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
   /*stringstream test;
   test << "id" << id;
   string line;
   string archiveId;
   ifstream itemList;
   itemList.open("ItemList.txt");
   if (itemList.is_open())
   {
      while (getline(itemList, line))
      {
         archiveId = line.substr(0, 4);
         if (archiveId == test.str())
         {
            cout << "Item loaded" << endl;
         }
         else
         {
            setToDefault();
         }
      }
   }
   itemList.close(); */

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
   this->name = "Moonstone band";
   this->maxUses = 0;
   this->uses = 0;
   this->weight = 1;
   this->equiped = false;
   for (int i = 0; i < 7; i++) {
      statBonus[i] = 1;
   }
   this->desc = "A small stone ring that shimmers in the moonlight. All stats +1";
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
