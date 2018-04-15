#include "Unit.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <sstream>
string Unit::toString()
{
   stringstream strm;
   strm << "Name: " << name << endl;
   strm << "Class: " << unitClass << endl;
   strm << "str " << str << endl;
   strm << "dex " << dex << endl;
   strm << "con " << con << endl;
   strm << "wis " << wis << endl;
   strm << "int " << intel << endl;
   strm << "cha " << cha << endl;
   strm << "skill " << skill << endl;
   strm << "Hp: " << hp << "/" << maxHp << endl;
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
   this->str = str;
   this->dex = dex;
   this->con = con;
   this->wis = wis;
   this->intel = intel;
   this->cha = cha;
   this->skill = skill;
   update();
}
bool Unit::attack(Unit &target)
{
   int chance = (hitRate - target.avoid) + 50;
   int randNum = (rand() % 100 + 1 + rand() % 100 + 1) / 2;
   if (randNum >= chance)
      target.damage(1);
   return true;
}

bool Unit::update()
{
   hitRate = skill + (2 * level);
   avoid = dex + (2 * level);
   maxHp = con + (2 * level);
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
