#include "Accesory.h"
#include "Item.h"
#include <sstream>;


Accesory::Accesory() : Item()
{
}


Accesory::~Accesory()
{
}

string Accesory::toString()
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
