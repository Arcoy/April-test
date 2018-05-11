#pragma once
#include "Unit.h"
class UI
{
private:
   Unit * unit;
public:
   UI();
   ~UI();
   void unitSelect();
   void unitMenu();
   void attackMenuu();
   void invMenu();
   void equipMenu();
   void itemMenu();
};

