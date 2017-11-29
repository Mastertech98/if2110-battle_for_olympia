#include "end_turn.h"
#include "../corefiles.h"
#include "../ADT/queue.h"
#include "../ADT/point.h"
#include "changeunit.h"

#include <string.h>
#include <stdio.h>
#include <math.h>

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
void Heal(){
	Unit *unitA;
	Grid *gridA;
	Player currentPlayer = *GetCurrentPlayer();
	List list = GetUnits(currentPlayer);
	address currentUnitList = First(list);
	POINT location;
	Unit *unit;
	
	while(currentUnitList != NULL){
		unit = Info(currentUnitList);
		location = GetLocation(*unit);
		if(GetUnitClass(*unit) == WhiteMage){
			for(int i = 0;i<=1;i++){
				for(int j = -1;j<=1;j +=2){
					if(Absis(location)+(i*j) < GetMapSizeN() && Absis(location)+(i*j)>=0
					&& Ordinat(location)+(abs(i-1)*j) < GetMapSizeM() && Ordinat(location)+(abs(i-1)*j) >= 0){
						gridA = GetGrid(Absis(location)+(i*j), Ordinat(location)+(abs(i-1)*j));
						unitA = GetUnit(*gridA);
						if(unitA!=NULL){
							if(GetUnitColor(*unitA)==GetUnitColor(*unit)){
								SetHealth(unitA, (int)GetHealth(*unitA) * 1.2);
								if(GetHealth(*unitA) > GetMaximumHealth(*unitA)){
									SetHealth(unitA,GetMaximumHealth(*unitA));
								}
							}
						}
					}
				}
			}
		}
		currentUnitList = Next(currentUnitList);
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
	
	Heal();
	
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
		P = Next(P);
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


