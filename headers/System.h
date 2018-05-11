#pragma once
#include "Unit.h"
class System
{
   friend class UI;
protected:
   Unit units;
public:
   System();
   ~System();
};

