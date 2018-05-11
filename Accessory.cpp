#include "Accessory.h"
#include "Item.h"
#include <sstream>
#include <iostream>
using namespace std;


Accessory::Accessory() : Item()
{

}

Accessory::Accessory(int id) : Item(id)
{
   type = stringToType(itemLoad);
}


Accessory::~Accessory()
{
}

string Accessory::toString()
{
      stringstream strm;
      strm << name << ": ";
      strm << weight << " lbs ";
      if (equiped)
         strm << "Equiped";
      strm << endl;
      strm << "   " << desc << endl;
      return strm.str();
}
