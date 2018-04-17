#include <string>
using namespace std;

class Item
{
private:
   string name;
   int weight, uses, maxUses;
   bool equiped;
public:
   Item();
   Item(string name, int weight, int maxUses);
   bool use();
};

