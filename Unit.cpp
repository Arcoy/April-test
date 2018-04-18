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
   strm << unitClass << " lv " << level << endl;
   strm << "Hp: " << hp << "/" << maxHp << endl;

   strm << "str " << stats[0];
   if (statmods[0] != 0)
      strm << " +" << statmods[0];
   strm << endl;

   strm << "dex " << stats[1];
   if (statmods[1] != 0)
      strm << " +" << statmods[1];
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
   for (int i = 0; i < 20; i++)
   {
      inventory[i] = NULL;
   }
   carryWeight = str*2+20;
   carryRemaining = carryWeight;
   update();
   hp = maxHp;
}
bool Unit::attack(Unit &target)
{
   int chance = (hitRate - target.avoid) + 50;
   int randNum = (rand() % 100 + 1 + rand() % 100 + 1) / 2;
   if (randNum <= chance)
   {
      int damage = (stats[0] + statmods[0]) - (target.stats[2] + target.statmods[2]);
      if (damage < 0)
      {
         damage = 0;
      }
      if (randNum <= 25)
      {
         target.damage(damage * 3);
      }
      else
      {
         target.damage(damage);
      }
   }
   return true;
}

bool Unit::update()
{
   hitRate = stats[6] + (2 * level) + statmods[6];
   avoid = stats[1] + (2 * level) + statmods[1];
   maxHp = stats[2] + (2 * level);
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

bool Unit::use(int item)
{
   inventory[item].use(statmods);
   return true;
}
