#include "corefiles.h"
#include "adt.h"
#include "commands.h"
#include <stdio.h>
#include <stdlib.h>

int turn;
Unit *selectedUnit;
boolean gameOver;
Stack S_moves;
Map map;

int main() {
    char colors[] = {'1', '2'};
    POINT coordinates[] = {MakePOINT(1,8), MakePOINT(8,1)};

    CreateMap(10, 10);

    InitializeMap(2, coordinates, 3);
    InitializePlayers(2, coordinates);

    Unit *whitemage = CreateUnit(WhiteMage, 2, MakePOINT(8,2));
    SetUnit(GetGrid(8,2), whitemage);

    selectedUnit = GetUnit(*GetGrid(8,1));
    SetMovementPoints(GetUnit(*GetGrid(8,1)), 5);

    //PrintMap();

    char command[11];
    do {
        PrintMap();
        printf("\n");
        scanf(" %s", command);
        if (!strcmp(command, "MOVE")) {
            Move(selectedUnit, &map);
        } else if (!strcmp(command, "UNDO")) {
            Undo();
        } else if (!strcmp(command, "CHANGE_UNIT")) {

        } else if (!strcmp(command, "RECRUIT")) {

        } else if (!strcmp(command, "ATTACK")) {

        } else if (!strcmp(command, "MAP")) {

        } else if (!strcmp(command, "INFO")) {

        } else if (!strcmp(command, "END_TURN")) {

        } else if (!strcmp(command, "SAVE")) {

        } else {
            printf("Invalid input\n");
        }
    } while (strcmp(command, "EXIT"));

}
