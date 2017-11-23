#ifndef ATTACK_H
#define ATTACK_H

#include "unit.h"
#include "map.h"
#include "player.h"

typedef struct {
    Unit *enemy[4];
    int count;
} Target;

void Attack(Unit *attacker);
void Kill(Unit *unit);
void PrintTarget(Target target, Unit selectedUnit);
Target GetCloseEnemy(Unit unit);

#endif