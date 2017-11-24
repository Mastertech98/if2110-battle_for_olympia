#ifndef RECRUIT_H
#define RECRUIT_H

#include "../corefiles.h"
#include <stdlib.h>

void RecruitUnit (Player *P, Unit *selectedUnit);

void ChangeUnit (Player *P, Unit *selectedUnit);

void PrintListUnits (List units);

void PrintPriceList ();

#endif