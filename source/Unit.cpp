#include "Unit.h"
#include "Weapon.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <algorithm>
#include <sstream>
#include <typeinfo>


Unit::~Unit()
{
   for (int i = 0; i < 5; i++)
   {
      if (inventory[i] != NULL)
         delete equipment[i];
   }
   for (int i = 0; i < 200; i++)
   {
      if(inventory[i]!=NULL)
         delete inventory[i];
   }
}

string Unit::toString()
{
   stringstream strm;
   strm << name << endl;
   strm << unitClass << " lv " << level << endl;
   strm << "Hp: " << hp << "/" << maxHp << endl;
   strm << "Right Hand: ";
   if (equipment[0] != NULL)
   {
      strm << equipment[0]->getName() << endl;
   }
   else
   {
      strm << endl;
   }
   strm << "Left Hand: ";
   if (equipment[1] != NULL)
   {
      strm << equipment[1]->getName() << endl;
   }
   else
   {
      strm << endl;
   }
   strm << "Body: ";
   if (equipment[2] != NULL)
   {
      strm << equipment[2]->getName() << endl;
   }
   else
   {
      strm << endl;
   }
   strm << "Accessory 1: ";
   if (equipment[3] != NULL)
   {
      strm << equipment[3]->getName() << endl;
   }
   else
   {
      strm << endl;
   }
   strm << "Accessory 2: ";
   if (equipment[4] != NULL)
   {
      strm << equipment[4]->getName() << endl;
   }
   else
   {
      strm << endl;
   }
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
   strm << "Carrying " << inventoryWeight() << " lbs" << endl;
   for (int i = 0; i < invPos; i++)
   {
      if (inventory[i]!=NULL)
         strm << inventory[i]->toString();
   }
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
   resetBonus();
   for (int i = 0; i < 5; i++)
   {
      if(equipment[i]!=NULL)
      equipment[i]->use(statmods);
   }
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
   if (inventory[item] != NULL)
   {
      inventory[item]->use(statmods);
      return true;
   }
   return false;
}

int Unit::inventoryWeight()
{
   int weight = 0;
   for (int i = 0; i < invPos; i++)
   {
      if(inventory[i]!=NULL)
         weight += inventory[i]->getWeight();
   }
   return weight;
}

void Unit::resetBonus()
{
   for (int i = 0; i < 7; i++)
   {
      statmods[i] = 0;
   }
}

bool Unit::addItem(Item *item)
{
   if (carryWeight - inventoryWeight() - item->getWeight() >= 0)
   {
      inventory[invPos] = item;
      invPos++;
      return true;
   }
   return false;
}

bool Unit::equip(int item)
{
   if ((string)typeid(*inventory[item]).name() == "class Accessory")
   {
      if (equipment[3] == NULL)
      {
         if (equipment[4] != NULL && inventory[item]->getType() == equipment[4]->getType())
            return false;
         equipment[3] = inventory[item];
         equipment[3]->equip();
         inventory[item] = NULL;
         invPos--;
      }
      else
      {
         if (equipment[4] == NULL)
         {
            if (equipment[3] != NULL && inventory[item]->getType() == equipment[3]->getType())
               return false;
            equipment[4] = inventory[item];
            equipment[4]->equip();
            inventory[item] = NULL;
            invPos--;
         }
      }
      
      update();
      return true;
   }
   if ((string)typeid(*inventory[item]).name() == "class Weapon")
   {
      if (equipment[0] != NULL)
      {
         Item *equip = inventory[item];
         inventory[item] = NULL;
         invPos--;
         addItem(equipment[0]);
         equipment[0] = equip;
         equipment[0]->equip();
      }
      else
      {
         equipment[0] = inventory[item];
         equipment[0]->equip();
         inventory[item] = NULL;
         invPos--;
      }
      update();
      return true;
   }
   if ((string)typeid(*inventory[item]).name() == "class Armor")
   {
      if (equipment[2] != NULL)
      {
         Item *equip = inventory[item];
         inventory[item] = NULL;
         invPos--;
         addItem(equipment[2]);
         equipment[2] = equip;
         equipment[2]->equip();
      }
      else
      {
         equipment[2] = inventory[item];
         equipment[2]->equip();
         inventory[item] = NULL;
         invPos--;
      }
      update();
      return true;
   }

   update();
   return false;
}

bool Unit::unequip(int item)
{
   
   update();
   return true;
}

void Unit::sortInventory()
{
   Item *sortTray[200];
   for (int i = 0; i < invPos; i++)
   {
      sortTray[i] = inventory[0];
      for (int j = 0; j < invPos; j++)
      {
         if (inventory[j] != NULL && inventory[j]->getWeight() > sortTray[i]->getWeight())
         {
            sortTray[i] = inventory[j];
            delete inventory[j];
         }
      }
   }
   for (int i = 0; i < invPos; i++)
   {
      inventory[i] = sortTray[i];
   }
}

string Unit::getInventory()
{
   stringstream strm;
   for (int i = 0; i < 200; i++)
   {
      if (inventory[i] = NULL)
         break;
      strm << inventory[i]->getName() << endl;
   }
   return strm.str();
}
