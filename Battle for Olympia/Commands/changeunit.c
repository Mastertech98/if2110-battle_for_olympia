#include "changeunit.h"

#include <stdio.h>

Unit *selectedUnit;

void COMMAND_CHANGE_UNIT(Player *player) {
    List units = GetUnits(*player);
    int index;

    PrintUnits(units);
    do {
        printf("Please enter the no. of unit you want to select: ");
        scanf("%d", &index);
    } while (index < 1 || index > NbElmt(units));

    addressList P = First(units);
    while (index > 1) {
        --index;
        P = Next(P);
    }
    Unit *unit = Info(P);
    SetSelectedUnit(Info(P));

    char unitClassName[11];
    UnitClassName(GetUnitClass(*unit), unitClassName);
    printf("You are now selecting %s\n", unitClassName);

    printf("\n");
}

void COMMAND_NEXT_UNIT(Player *player) {
    List units = GetUnits(*player);
    addressList P = First(units);
    while (Info(P) != GetSelectedUnit()) {
        P = Next(P);
    }
    
    do {
        P = Next(P);
        if (!P) {
            P = First(units);
        }
        Unit *unit = Info(P);
        if (GetMovementPoints(*unit) || GetChanceAttack(*unit)) {
            break;
        }
    } while (Info(P) != GetSelectedUnit());
    
    if (Info(P) != GetSelectedUnit()) {
        SetSelectedUnit(Info(P));
    } else {
        printf("No unit has movement points or attack chance\n");
    }

    printf("\n");
}

void PrintUnits(List units) {
    addressList P = First(units);

    printf("== List of Units ==\n");
    for (int i = 1; P; i++) {
        Unit *unit = Info(P);
        POINT location = GetLocation(*unit);
        char unitClassName[11];
        UnitClassName(GetUnitClass(*unit), unitClassName);

        printf("%d. %s (%d,%d) | Health %d\n", 
            i, 
            unitClassName, 
            Absis(location), 
            Ordinat(location), 
            GetHealth(*unit)
        );

        P = Next(P);
    }
}

Unit *GetSelectedUnit() {
	return selectedUnit;
}

void SetSelectedUnit(Unit *unit) {
	selectedUnit = unit;
}
