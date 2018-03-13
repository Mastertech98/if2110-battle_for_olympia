#include "attack.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void COMMAND_ATTACK(Unit *attacker) {
    if (!GetChanceAttack(*attacker)) {
        printf("You can't attack with this unit.\n");
        return;
    }

    Enemies enemies = GetAdjacentEnemyData(*attacker);
    if (enemies.count == 0) {
        printf("No enemy nearby.\n");
        return;
    }
    
    int index;

    printf("Please select enemy you want to attack:\n");
    PrintEnemies(enemies);
    
    do {
        printf("Select enemy you want to attack: ");
        scanf("%d", &index);
    } while (index < 1 || index > enemies.count);

    Unit *attacked = enemies.enemy[index-1].unit;
    char stringAttackedClass[11];
    UnitClassName(GetUnitClass(*attacked), stringAttackedClass);

    if (rand() % 100 < GetProbabilityExposedToAttack(*attacked)) {
        SetHealth(attacked, GetHealth(*attacked) - GetAttack(*attacker));
        printf("Enemy's %s is damaged by %d.\n", stringAttackedClass, GetAttack(*attacker));
    } else {
        printf("Enemy's %s dodges the attack.\n", stringAttackedClass);
    }

    SetMovementPoints(attacker, 0);
    SetChanceAttack(attacker, false);

    if (GetHealth(*attacked) <= 0) {
        Kill(attacked);
        printf("Enemy's %s is dead :)\n", stringAttackedClass);
    } else {
        if (enemies.enemy[index-1].canRetaliate) {
            char stringAttackerClass[11];
            UnitClassName(GetUnitClass(*attacker), stringAttackerClass);

            printf("Enemy's %s retaliates.\n", stringAttackedClass);

            if (rand() % 100 < GetProbabilityExposedToAttack(*attacker)) {
                SetHealth(attacker, GetHealth(*attacker) - GetAttack(*attacked));
                printf("Your %s is damaged by %d\n", stringAttackerClass, GetAttack(*attacked));

                if (GetHealth(*attacker) <= 0) {
                    Kill(attacker);
                    printf("Your %s is dead :(\n", stringAttackerClass);
                }
            } else {
                printf("Your %s dodges the attack.\n", stringAttackerClass);
            }
        }
    }

    printf("\n");
}

void Kill(Unit *unit) {
    Player *owner = GetPlayerFromColor(GetUnitColor(*unit));
    DelUnit(owner, unit);
    SetUnit(GetGrid(GetLocation(*unit)), 0);
    DestroyUnit(unit);
    SetUpkeep(owner, GetUpkeep(*owner) - 1);
}

void PrintEnemies(Enemies enemies) {
    Unit enemy;
    char stringEnemyClass[11];
    char stringRetaliates[13];
    POINT enemyLocation;

    for (int i = 0; i < enemies.count; ++i) {
        enemy = *enemies.enemy[i].unit;
        UnitClassName(GetUnitClass(enemy), stringEnemyClass);

        if (enemies.enemy[i].canRetaliate) {
            strcpy(stringRetaliates, "(Retaliates)");
        } else {
            strcpy(stringRetaliates, "");
        }

        enemyLocation = GetLocation(enemy);

        printf("%d. %s (%d,%d) | Health %d/%d %s\n", 
            1+i, 
            stringEnemyClass, 
            enemyLocation.X, 
            enemyLocation.Y,
            GetHealth(enemy), 
            GetMaximumHealth(enemy),
            stringRetaliates
        );
    }
}

Enemies GetAdjacentEnemyData(Unit unit) {
    Enemies enemies;
    enemies.count = 0;

    char color = GetUnitColor(unit);
    
    Grids adjacentGrids = GetAdjacentGrids(*GetGrid(GetLocation(unit)));
    for (unsigned int i = 0; i < adjacentGrids.count; i++) {
        Grid grid = *adjacentGrids.grids[i];
        if (isOccupied(grid) && !isOccupiedByAlly(grid, color)) {
            Unit *enemy = GetUnit(grid);
            enemies.enemy[enemies.count].unit = enemy;
            enemies.enemy[enemies.count].canRetaliate = Retaliates(unit, *enemy);
            ++enemies.count;
        }
    }

    return enemies;
}

boolean Retaliates(Unit attacked, Unit attacker) {
    if (GetUnitClass(attacker) == King) {
        return true;
    } else {
        if (GetAttackType(attacked) == GetAttackType(attacker)) {
            return true;
        } else {
            return false;
        }
    }
}