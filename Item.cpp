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
}

Item::Item()
{
   setToDefault();
}

Item::Item(int id)
{
   stringstream strm;
   strm << "id" << id;
   string line;
   string archiveId;
   ifstream itemList;
   itemList.open("ItemList.txt");
   if (itemList.is_open())
   {
      while (getline(itemList, line))
      {
         archiveId = line.substr(0, 4);
         if (archiveId == strm.str())
         {
            cout << "Item loaded" << endl;
         }
         else
         {
            setToDefault();
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
   this->name = "";
   this->maxUses = 0;
   this->uses = 0;
   this->weight = 0;
   this->equiped = false;
   for (int i = 0; i < 7; i++) {
      statBonus[i] = 0;
   }
}
