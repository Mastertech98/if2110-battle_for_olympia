#ifndef MOVE_H
#define MOVE_H

#include "../corefiles.h"
#include "../ADT/stackt.h"

#define DUMVAL 999

extern Stack S_moves;

const Unit UNITMOV = {
    .unitClass = Movement,
    .color = 'G',

    .maximumHealth = DUMVAL,
    .health = DUMVAL,
    .attack = DUMVAL,
    .maximumMovementPoints = DUMVAL,
    .movementPoints = DUMVAL,
    .attackType = Melee,
    .chanceAttack = true,
    .location.X = -999,
    .location.Y = -999,
    .price = DUMVAL
};

void Move(Unit *unit, Map *map);
void MakeMovementMap(Unit unit);
void ClearMovementMap(Map *map);
boolean IsValidUndo();
void Undo(Unit *U);

#endif // MOVE_H
