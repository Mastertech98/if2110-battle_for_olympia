#ifndef MOVE_H
#define MOVE_H

//#include "../corefiles.h"
#include "attack.h"
#include "recruit.h"
#include "move.h"
#include "../ADT/stackt.h"

#define DUMVAL 999

extern Stack S_moves;

const Unit UNITMOV;

void Move(Unit *unit, Map *map);
void MakeMovementMap(Unit unit);
void ClearMovementMap(Map *map);
boolean IsValidUndo();
void Undo();

#endif // MOVE_H
