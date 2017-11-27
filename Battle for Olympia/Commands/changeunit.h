#ifndef CHANGEUNIT_H
#define CHANGEUNIT_H

#include "../corefiles.h"
#include "recruit.h"
#include <stdlib.h>

void ChangeUnit (Player *P);

void NextUnit (Player *P);

Unit *GetSelectedUnit();

void SetSelectedUnit(Unit *unit);

#endif