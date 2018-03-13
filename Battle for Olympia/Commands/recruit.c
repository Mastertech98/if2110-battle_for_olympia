#include "recruit.h"

#include <stdio.h>
#include <stdlib.h>

void COMMAND_RECRUIT(Player *player) {
    addressList P = First(GetUnits(*player));
    while (GetUnitClass(*(Unit *)Info(P)) != King) {
        P = Next(P);
    }

    POINT kingLocation = GetLocation(*(Unit *)Info(P));

    if (GetType(*GetGrid(kingLocation)) != Tower) {
        printf("Your King is not in the tower!\n");
        return;
    }

    Grids adjacentGrids = GetAdjacentGrids(*GetGrid(kingLocation));
    boolean isExistEmptyCastle = false;
    for (unsigned int i = 0; i < adjacentGrids.count; i++) {
        if (!isOccupied(*adjacentGrids.grids[i])) {
            isExistEmptyCastle = true;
        }
    }

    if (!isExistEmptyCastle) {
        printf("All castles are occupied!\n");
        return;
    }
    
    Grid *castle;
    boolean valid = false;
    do {
        int castleLocationX, castleLocationY;
        printf("Enter coordinate of empty castle: ");
        scanf("%d %d", &castleLocationX , &castleLocationY);

        if (isValidCoordinate(castleLocationX, castleLocationY)) {
            castle = GetGrid(MakePOINT(castleLocationX, castleLocationY));
            if (GetType(*castle) != Castle) {
                printf("That is not a castle!\n");
            } else if (isOccupied(*castle)) {
                printf("That castle is occupied!\n");
            } else if (GetGridColor(*castle) != GetColor(*player)) {
                printf("That is not your castle!\n");
            } else {
                valid = true;
            }
        }
    } while (!valid);
    printf("\n");

    int index;
    PrintRecruits();
    do {
        printf("Enter no. of unit you want to recruit: ");
        scanf("%d", &index);
    } while (index < 1 || index > 3);

    int gold = GetGold(*player);
    int price;
    UnitClass unitClass;
    if (index == 1) {
        unitClass = Archer;
        price = GetPrice(ARCHER);

        if (gold < price) {
            printf("You don't have enough gold to recruit an archer!\n");
            return;
        }

        printf("You have recruited an archer!\n");
    } else if (index == 2) {
        unitClass = Swordsman;
        price = GetPrice(SWORDSMAN);

        if (gold < price) {
            printf("You don't have enough gold to recruit a swordsman!\n");
            return;
        }

        printf("You have recruited a swordsman!\n");
    } else if (index == 3) {
        unitClass = WhiteMage;
        price = GetPrice(WHITEMAGE);

        if (gold < price) {
            printf("You don't have enough gold to recruit a whitemage!\n");
            return;
        }

        printf("You have recruited a whitemage!\n");
    }

    SetGold(player, gold - price);
    Unit *unit = CreateUnit(unitClass, GetColor(*player), GetCoordinate(*castle));
    InsVLast(&player->units, unit);
    SetUnit(castle, unit);
    SetHealth(unit, GetMaximumHealth(*unit));
    SetMovementPoints(unit, 0);

    printf("\n");
}

void PrintRecruits() {
    printf("== List of Recruits ==\n");
    printf("1. Archer | Health %d | ATK %d | %dG\n", 
        GetMaximumHealth(ARCHER), 
        GetAttack(ARCHER), 
        GetPrice(ARCHER)
    );
    printf("2. Swordsman | Health %d | ATK %d | %dG\n", 
        GetMaximumHealth(SWORDSMAN), 
        GetAttack(SWORDSMAN), 
        GetPrice(SWORDSMAN)
    );
    printf("3. Whitemage | Health %d | ATK %d | %dG\n", 
        GetMaximumHealth(WHITEMAGE), 
        GetAttack(WHITEMAGE), 
        GetPrice(WHITEMAGE)
    );
}