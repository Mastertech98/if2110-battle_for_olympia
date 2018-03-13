#ifndef ATTACK_H
#define ATTACK_H

#include "../corefiles.h"

typedef struct {
    struct {
        Unit *unit;
        boolean canRetaliate;
    } enemy[4];
    int count;
} Enemies;

void COMMAND_ATTACK(Unit *attacker);
void Kill(Unit *unit);
void PrintEnemies(Enemies enemies);
Enemies GetAdjacentEnemyData(Unit unit);
boolean Retaliates(Unit attacked, Unit attacker);

#endif