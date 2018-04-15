#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <sstream>
#include "Unit.h"
using namespace std;


int main()
{
   srand(time(NULL));
   Unit testMan = Unit("testman", "test", 1, 10, 10, 10, 10, 10, 10,10);
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
