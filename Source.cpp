#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <sstream>
#include "Unit.h"
#include "Item.h"
#include "Accessory.h"
#include "Armor.h"
#include "Weapon.h"
#include <Windows.h>
#include <conio.h>
using namespace std;


int main()
{
   srand(time(NULL));
   Unit robin = Unit("Robin", "Tactician", 1, 10, 10, 10, 10, 10, 10, 10);
   Unit grima = Unit("Grima", "Dark Dragon", 1, 10, 10, 10, 10, 10, 10, 10);
   Accessory *ring = new Accessory(1);
   Weapon *sword = new Weapon(2);
   robin.addItem(ring);
   robin.addItem(sword);
   
   while (!_kbhit())
   {
      switch (_getch())
      {
      case 'w':
      {
         system("cls");
         cout << "> Option A" << endl;
         cout << "  Option B" << endl;
         break;
      }
      case 's':
      {
         system("cls");
         cout << "  Option A" << endl;
         cout << "> Option B" << endl;
      }
      }
   }
   return 0;
}
