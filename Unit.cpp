#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <sstream>
using namespace std;

class Unit
{
private:
   string name;
   string unitClass;
   int level;
   int str, dex, con, wis, intel, cha, skill;
   int carryWeight, hp, maxHp;
   int hitRate, avoid;
public:
   int getHp() { return hp; }
   string toString();
   Unit();
   Unit(string name, string unitClass, int level, int str, int dex, int con, int wis, int intel, int cha, int skill);
   bool attack(Unit &target);
   bool update();
   bool damage(int damage);
};
int main()
{
   //this code is dummy code to test two units attacking.
   //testman attacks testman2
   srand(time(NULL));
   Unit testMan = Unit("testman", "test", 1, 10, 10, 10, 10, 10, 10, 10);
   Unit testerTwo = Unit("testman2", "test", 1, 10, 10, 10, 10, 10, 10, 10);
   cout << testerTwo.toString();
   cout << testerTwo.getHp() << endl;
   testMan.attack(testerTwo);
   cout << testerTwo.getHp() << endl;
   testMan.attack(testerTwo);
   cout << testerTwo.getHp() << endl;
   testMan.attack(testerTwo);
   cout << testerTwo.getHp() << endl;
   cout << testerTwo.toString();

   return 0;
}
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
