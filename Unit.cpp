#include "Unit.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <sstream>
string Unit::toString()
{
   stringstream strm;
   strm << name << endl;
   strm << unitClass << " level " << level << endl;
   strm << "Hp: " << hp << "/" << maxHp << endl;
   strm << "str " << stats[0];
   if (statmods[0] != 0)
      strm << " +" << statmods[0];
   strm << endl;
   strm << "dex " << stats[1];
   if (statmods[2] != 0)
      strm << " +" << statmods[2];
   strm << endl;
   strm << "con " << stats[2];
   if (statmods[2] != 0)
      strm << " +" << statmods[2];
   strm << endl;

   strm << "wis " << stats[3];
   if (statmods[3] != 0)
      strm << " +" << statmods[3];
   strm << endl;

   strm << "int " << stats[4];
   if (statmods[4] != 0)
      strm << " +" << statmods[4];
   strm << endl;

   strm << "cha " << stats[5];
   if (statmods[5] != 0)
      strm << " +" << statmods[5];
   strm << endl;

   strm << "skl " << stats[6];
   if (statmods[6] != 0)
      strm << " +" << statmods[6];
   strm << endl;

   return strm.str();
}
Unit::Unit()
{

}
Unit::Unit(string name, string unitClass, int level, int str, int dex, int con, int wis, int intel, int cha, int skill)
{
   this->name = name;
   this->unitClass = unitClass;
   this->level = level;
   stats[0] = str;
   stats[1] = dex;
   stats[2] = con;
   stats[3] = wis;
   stats[4] = intel;
   stats[5] = cha;
   stats[6] = skill;
   for (int i = 0; i < 7; i++)
   {
      statmods[i] = 0;
   }
   update();
}
bool Unit::attack(Unit &target)
{
   int chance = (hitRate - target.avoid) + 50;
   int randNum = (rand() % 100 + 1 + rand() % 100 + 1) / 2;
   if (randNum <= chance)
      target.damage(1);
   return true;
}

bool Unit::update()
{
   hitRate = stats[6] + (2 * level) + statmods[6];
   avoid = stats[1] + (2 * level) + statmods[1];
   maxHp = stats[2] + (2 * level) + statmods[2];
   hp = maxHp;
   return true;
}

bool Unit::damage(int damage)
{
   hp -= damage;
   if (hp > maxHp)
      hp = maxHp;
   if ((double)hp / maxHp < 0)
      hp = 0;
   return true;
}
