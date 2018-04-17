#include <string>
using namespace std;

class Item
{
private:
   int id;
   string name;
   int weight, uses, maxUses;
   bool equiped;
   int statBonus[7]; //If an equiped item grants bonus stats, they are stored here
public:
   Item();
   Item(int id); //read from the Item.txt to find id, then load Item
   Item(string name, int weight, int maxUses); // make a new temp Item
   bool use(int statMods[7]); //parameter is the using unit's bonus stat array
   void setToDefault();
};

