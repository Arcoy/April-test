#include <string>
#include "Item.h"
using namespace std;

class Unit
{
private:
   string name;
   string unitClass;
   int level;
   int stats[7];
   int statmods[7];
   int carryWeight, hp, maxHp;
   int hitRate, avoid;
   Item inventory[5];
public:
   int getHp() { return hp; }
   string toString();
   Unit();
   Unit(string name, string unitClass, int level, int str, int dex, int con, int wis, int intel, int cha, int skill);
   bool attack(Unit &target);
   bool update();
   bool damage(int damage);
   bool use(int item);
};
