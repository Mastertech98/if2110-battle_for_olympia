#ifndef RECRUIT_H
#define RECRUIT_H

#include "unit.h"
#include "player.h"
#include "map.h"
#include <stdlib.h>

void AddUnit (Player *P, Unit *unit);

void RecruitUnit (Player *P, Unit *selectedUnit);

void ChangeUnit (Player *P, Unit *selectedUnit);

void PrintListUnits (List units);

void PrintPriceList ();

#endif