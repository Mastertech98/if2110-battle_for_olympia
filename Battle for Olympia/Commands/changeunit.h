#ifndef CHANGEUNIT_H
#define CHANGEUNIT_H

#include "../corefiles.h"

void COMMAND_CHANGE_UNIT(Player *player);
void COMMAND_NEXT_UNIT(Player *player);
void PrintUnits(List units);
Unit *GetSelectedUnit();
void SetSelectedUnit(Unit *unit);

#endif