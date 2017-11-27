#include "map.h"
#include "player.h"
#include "unit.h"

#include "commands.h"
#include "adt.h"

#include <stdio.h>
#include <string.h>

int turn;
Unit *selectedUnit;
boolean gameOver;
Stack S_moves;

int main () {
    char command[11];
    do {
        scanf(" %s", command);
        if (!strcmp(command, "MOVE")) {
            
        } else if (!strcmp(command, "UNDO")) {
            
        } else if (!strcmp(command, "CHANGE_UNIT")) {
            ChangeUnit(&Player, &selectedUnit);
        } else if (!strcmp(command, "RECRUIT")) {
            RecruitUnit(&Player, selectedUnit);
        } else if (!strcmp(command, "ATTACK")) {
            Attack(selectedUnit);
        } else if (!strcmp(command, "MAP")) {
            
        } else if (!strcmp(command, "INFO")) {
            
        } else if (!strcmp(command, "END_TURN")) {
            
        } else if (!strcmp(command, "SAVE")) {
            
        } else {
            printf("Invalid input\n");
        }
    } while (strcmp(command, "EXIT"));

    return 0;
}