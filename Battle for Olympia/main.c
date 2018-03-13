#include "corefiles.h"
#include "commands.h"

#include <stdio.h>
#include <string.h>

void PrintPlayer(Player player) {
    Unit *selectedUnit = GetSelectedUnit(player);
    POINT location = GetLocation(*selectedUnit);
    char stringUnitClass[11];
	char stringCanAttack[4];

    UnitClassName(GetUnitClass(*selectedUnit), stringUnitClass);
    if (GetChanceAttack(*selectedUnit)) {
        strcpy(stringCanAttack, "Yes");
    } else {
        strcpy(stringCanAttack, "No");
    }

    printf("Player %d's Turn\n", GetPlayerIndex(player));
    printf("Cash: %dG | Income: %dG | Upkeep: %dG\n", 
		GetGold(player), 
		GetIncome(player), 
		GetUpkeep(player)
	);
	printf("Unit: %s (%d,%d) | Movement Point: %d | Can Attack: %s\n", 
		stringUnitClass, 
		Absis(location), 
		Ordinat(location), 
		GetMovementPoints(*selectedUnit), 
		stringCanAttack
	);
}

int main () {
    int N, M;
    printf("Enter map size: ");
    scanf("%d %d", &N, &M);
    printf("\n");

    char colors[] = {'1', '2'};
    CreateMap(N, M);
    CreatePlayers(2, colors);
    CreateTurn(2);
    CreateRecording();

    POINT coordinates[] = {{1, M-2}, {N-2, 1}};
    InitializeMap(2, coordinates, N * M / 15);
    InitializePlayers(2, coordinates);
    InitializeTurn(2);
    
    COMMAND_MAP();

    char command[11];
    do {
        Player *currentPlayer = GetCurrentPlayer();
        Unit *selectedUnit = GetSelectedUnit(*currentPlayer);
        
        PrintPlayer(*currentPlayer);

        printf("Your input: ");
        scanf(" %s", command);
        printf("\n");

        if (!strcmp(command, "MOVE")) {
            COMMAND_MOVE(selectedUnit);
        } else if (!strcmp(command, "UNDO")) {
            COMMAND_UNDO(selectedUnit);
        } else if (!strcmp(command, "CHANGE_UNIT")) {
            COMMAND_CHANGE_UNIT(currentPlayer);
            ClearRecording();
        } else if (!strcmp(command, "NEXT_UNIT")) {
            COMMAND_NEXT_UNIT(currentPlayer);
            ClearRecording();
        } else if (!strcmp(command, "RECRUIT")) {
            COMMAND_RECRUIT(currentPlayer);
            ClearRecording();
        } else if (!strcmp(command, "ATTACK")) {
            COMMAND_ATTACK(selectedUnit);
            ClearRecording();
        } else if (!strcmp(command, "MAP")) {
            COMMAND_MAP();
        } else if (!strcmp(command, "INFO")) {
            COMMAND_INFO();
        } else if (!strcmp(command, "END_TURN")) {
            COMMAND_END_TURN();
            ClearRecording();
        } else if (!strcmp(command, "SAVE")) {
            printf("We don't have save feature. Heckin' bamboozled.\n");
            ClearRecording();
        } else {
            printf("Invalid input\n");
        }
    } while (strcmp(command, "EXIT"));

    return 0;
}
