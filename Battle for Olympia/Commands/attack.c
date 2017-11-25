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
    
    int index;

    printf("Please select enemy you want to attack:\n");
    PrintTarget(target, *attacker);

    printf("Select enemy you want to attack: ");
    scanf("%d", &index);

    if (index < 1 || index > target.count) {
        printf("Invalid input.\n");
        return;
    }

    Unit *attacked = target.enemy[--index];
    char stringAttackedClass[11];
    
    SetHealth(attacked, GetHealth(*attacked) - GetAttack(*attacker));

    UnitClassName(GetUnitClass(*attacked), stringAttackedClass);
    printf("Enemy's %s is damaged by %d.\n", stringAttackedClass, GetAttack(*attacker));

    if (GetHealth(*attacked) <= 0) {
        printf("Enemy's %s is dead :)\n", stringAttackedClass);
    }

    if (Retaliates(*attacked, *attacker)) {
        char stringAttackerClass[11];

        printf("Enemy's %s retaliates.\n", stringAttackedClass);

        SetHealth(attacker, GetHealth(*attacker) - GetAttack(*attacked));

        UnitClassName(GetUnitClass(*attacker), stringAttackerClass);
        printf("Your %s is damaged by %d\n", stringAttackerClass, GetAttack(*attacked));

        if (GetHealth(*attacker) <= 0) {
            printf("Your %s is dead :(\n", stringAttackerClass);
        }
    }

    SetMovementPoints(attacker, 0);
    SetChanceAttack(attacker, false);

    if (GetHealth(*attacker) <= 0) {
        Kill(attacker);
    }
    if (GetHealth(*attacked) <= 0) {
        Kill(attacked);
    }
}

void Kill(Unit *unit) {
    POINT location = GetLocation(*unit);
    DelUnit(GetPlayer(GetUnitColor(*unit)), unit);
    SetUnit(GetGrid(Absis(location), Ordinat(location)), 0);
    DestroyUnit(unit);
}

void PrintTarget(Target target, Unit selectedUnit) {
    char stringAttackedClass[11];
    char stringRetaliates[13];
    POINT enemyLocation;

    for (int i = 0; i < target.count; ++i) {
        UnitClassName(GetUnitClass(*target.enemy[i]), stringAttackedClass);

        if (Retaliates(*target.enemy[i], selectedUnit)) {
            strcpy(stringRetaliates, "(Retaliates)");
        } else {
            strcpy(stringRetaliates, "");
        }

        enemyLocation = GetLocation(*target.enemy[i]);

        printf("%d. %s (%d,%d) | Health %d/%d %s\n", 
            1+i, 
            stringAttackedClass, 
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