#include "end_turn.h"

#include "../ADT/queue.h"
#include "../ADT/point.h"
#include "changeunit.h"
#include <stdio.h>

Queue turn;

void CreateTurn(int numberOfPlayers)
{
	CreateEmptyQueue(&turn, numberOfPlayers);
}

void InitializeTurn(int numberOfPlayers)
{
	addressList P = First(GetPlayers());
	while (P) {
		Add(&turn, Info(P));
		P = Next(P);
	}
	SetSelectedUnit(Info(First(GetUnits(*GetCurrentPlayer()))));
}

void COMMAND_END_TURN()
{
	infotypeQueue player;
	Del(&turn, &player);
	Add(&turn, player);

	Player *currentPlayer = GetCurrentPlayer();
	List units = GetUnits(*currentPlayer);
	char color = GetColor(*currentPlayer);

	SetIncome(currentPlayer, NbElmt(GetVillages(*currentPlayer)) * 10);
	SetUpkeep(currentPlayer, NbElmt(units) * 2);
	SetGold(currentPlayer, GetGold(*currentPlayer) + GetIncome(*currentPlayer) - GetUpkeep(*currentPlayer));

	addressList P = First(units);
	while (P) {
		Unit *unit = Info(P);
		SetMovementPoints(unit, GetMaximumMovementPoints(*unit));
		SetChanceAttack(unit, true);

		Grid grid = *GetGrid(GetLocation(*unit));
		if (GetType(grid) == Village) {
			Heal(unit);
		}

		if (GetUnitClass(*unit) == WhiteMage) {
			Grids adjacentGrids = GetAdjacentGrids(grid);
			for (unsigned int i = 0; i < adjacentGrids.count; i++) {
				Grid adjacentGrid = *adjacentGrids.grids[i];
				if (isOccupiedByAlly(adjacentGrid, color)) {
					Heal(GetUnit(adjacentGrid));
				}
			}
		}

		P = Next(P);
	}

	SetSelectedUnit(Info(First(GetUnits(*currentPlayer))));
}

void Heal(Unit *unit) {
	int health = GetHealth(*unit);
	int maximumHealth = GetMaximumHealth(*unit);

	if (health + 5 > maximumHealth) {
		SetHealth(unit, maximumHealth);
	} else {
		SetHealth(unit, health + 5);
	}
}

Player *GetCurrentPlayer()
{
	return InfoHead(turn);
}
