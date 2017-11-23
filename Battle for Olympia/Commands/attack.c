#include "attack.h"

#include <stdio.h>
#include <string.h>

void Attack(Unit *attacker) {
    if (!GetChanceAttack(*attacker)) {
        printf("You can't attack with this unit.\n");
        return;
    }

    Target target = GetCloseEnemy(*attacker);
    if (target.count == 0) {
        printf("No enemy nearby.\n");
        return;
    }
    
    int idxTarget;

    printf("Please select enemy you want to attack:\n");
    PrintTarget(target, *attacker);

    printf("Select enemy you want to attack: ");
    scanf("%d", &idxTarget);

    if (idxTarget < 1 || idxTarget > target.count) {
        printf("Invalid input.\n");
        return;
    }

    char stringEnemyClass[11];

    --idxTarget;
    
    SetHealth(target.enemy[idxTarget], GetHealth(*target.enemy[idxTarget]) - GetAttack(*attacker));

    UnitClassName(GetUnitClass(*target.enemy[idxTarget]), stringEnemyClass);
    printf("Enemy's %s is damaged by %d.\n", stringEnemyClass, GetAttack(*attacker));

    if (Retaliates(*target.enemy[idxTarget], *attacker)) {
        char stringAttackerClass[11];

        printf("Enemy's %s retaliates.\n", stringEnemyClass);

        SetHealth(attacker, GetHealth(*attacker) - GetAttack(*target.enemy[idxTarget]));

        UnitClassName(GetUnitClass(*attacker), stringAttackerClass);
        printf("Your %s is damaged by %d\n", stringAttackerClass, GetAttack(*target.enemy[idxTarget]));

        if (GetHealth(*attacker) <= 0) {
            printf("Your %s is dead :(\n", stringAttackerClass);
        }
    }

    SetMovementPoints(attacker, 0);
    SetChanceAttack(attacker, false);

    if (GetHealth(*attacker) <= 0) {
        Kill(attacker);
    }
    if (GetHealth(*target.enemy[idxTarget]) <= 0) {
        Kill(target.enemy[idxTarget]);
    }
}

void Kill(Unit *unit) {
    POINT location = GetLocation(*unit);
    List L = GetUnits(*GetPlayer(GetUnitColor(*unit)));
    DelP(&L, unit);
    SetUnit(GetGrid(Absis(location), Ordinat(location)), 0);
}

void PrintTarget(Target target, Unit selectedUnit) {
    char stringEnemyClass[11];
    char stringRetaliates[13];
    POINT enemyLocation;

    for (int i = 0; i < target.count; ++i) {
        UnitClassName(GetUnitClass(*target.enemy[i]), stringEnemyClass);

        if (Retaliates(*target.enemy[i], selectedUnit)) {
            strcpy(stringRetaliates, "(Retaliates)");
        } else {
            strcpy(stringRetaliates, "");
        }

        enemyLocation = GetLocation(*target.enemy[i]);

        printf("%d. %s (%d,%d) | Health %d/%d %s\n", 
            1+i, 
            stringEnemyClass, 
            enemyLocation.X, 
            enemyLocation.Y,
            GetHealth(*target.enemy[i]), 
            GetMaximumHealth(*target.enemy[i]),
            stringRetaliates
        );
    }
}

Target GetCloseEnemy(Unit unit) {
    Target target;
    target.count = 0;

    POINT location = GetLocation(unit);

    Unit *closeUnit;
    
    if (Absis(location) > 0) {
        closeUnit = GetUnit(*GetGrid(Absis(location) - 1, Ordinat(location)));
        if (closeUnit) {
            if (GetUnitColor(*closeUnit) != GetUnitColor(unit)) {
                target.enemy[target.count] = closeUnit;
                ++target.count;
            }
        }
    }
    if (Absis(location) < GetMapSizeM() - 1) {
        closeUnit = GetUnit(*GetGrid(Absis(location) + 1, Ordinat(location)));
        if (closeUnit) {
            if (GetUnitColor(*closeUnit) != GetUnitColor(unit)) {
                target.enemy[target.count] = closeUnit;
                ++target.count;
            }
        }
    }
    if (Ordinat(location) > 0) {
        closeUnit = GetUnit(*GetGrid(Absis(location), Ordinat(location) - 1));
        if (closeUnit) {
            if (GetUnitColor(*closeUnit) != GetUnitColor(unit)) {
                target.enemy[target.count] = closeUnit;
                ++target.count;
            }
        }
    }
    if (Ordinat(location) < GetMapSizeN() - 1) {
        closeUnit = GetUnit(*GetGrid(Absis(location), Ordinat(location) + 1));
        if (closeUnit) {
            if (GetUnitColor(*closeUnit) != GetUnitColor(unit)) {
                target.enemy[target.count] = closeUnit;
                ++target.count;
            }
        }
    }

    return target;
}