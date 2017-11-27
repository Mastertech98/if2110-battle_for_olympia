#include "end_turn.h"
#include "../corefiles.h"
#include "../ADT/queue.h"
#include "../ADT/point.h"
#include "changeunit.h"

#include <string.h>
#include <stdio.h>

Queue turn;

void CreateQueue(int numberOfPlayers)
{
	CreateEmpty(&turn, numberOfPlayers);
}
void InitializeQueue(int numberOfPlayers)
{
	Add(&turn, numberOfPlayers-1);
	for (int i = 0; i < numberOfPlayers-1; i++)
	{
		Add(&turn, i);
	}
}
void EndTurn()
{
	infotypeQueue tempQ;
	Player *currentPlayer;
	Unit *currentUnit;
	char stringUnitClass[11];
	char stringCanAttack[4];

	Del(&turn, &tempQ);
	Add(&turn, tempQ);

	currentPlayer = GetCurrentPlayer();
	SetSelectedUnit(Info(First(GetUnits(*currentPlayer))));
	
	currentUnit = GetSelectedUnit();
	POINT location = GetLocation(*currentUnit);

	UnitClassName(GetUnitClass(*currentUnit), stringUnitClass);
	if (GetChanceAttack(*currentUnit)) {
		strcpy(stringCanAttack, "Yes");
	} else {
		strcpy(stringCanAttack, "No");
	}

	SetGold(currentPlayer, GetGold(*currentPlayer)+GetIncome(*currentPlayer)-GetUpkeep(*currentPlayer));
	address P = First(GetUnits(*currentPlayer));
	while (P) {
		SetChanceAttack(Info(P), true);
		SetMovementPoints(Info(P), GetMaximumMovementPoints(*(Unit*)Info(P)));
	}

	printf("Player %d's Turn\n", InfoHead(turn)+1);
	printf("Cash: %dG | Income: %dG | Upkeep: %dG\n", 
		GetGold(*currentPlayer), 
		GetIncome(*currentPlayer), 
		GetUpkeep(*currentPlayer)
	);
	printf("Unit: %s(%d,%d) | Movement Point: %d | Can Attack: %s\n", 
		stringUnitClass, 
		Absis(location), 
		Ordinat(location), 
		GetMovementPoints(*currentUnit), 
		stringCanAttack
	);
}

Player *GetCurrentPlayer()
{
	return &players[InfoHead(turn)];
}