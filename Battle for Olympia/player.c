#include "player.h"
#include "map.h"

#include <stdlib.h>

#define StartingGold 50

List Players;

void CreatePlayers(int numberOfPlayers, char colors[])
{
    CreateEmptyList(&Players);
    for (int i = 0; i < numberOfPlayers; ++i) {
        Player *player = (Player *)malloc(sizeof(Player));
        InsVLast(&Players, player);

        SetGold(player, 0);
        CreateEmptyList(&player->units);
        CreateEmptyList(&player->villages);
        SetIncome(player, 0);
        SetUpkeep(player, 0);
        player->color = colors[i];
    }
}

void InitializePlayers(int numberOfPlayers, POINT coordinates[])
{
    for (int i = 0; i < numberOfPlayers; ++i) {
        POINT coordinate = coordinates[i];
        Player *player = GetPlayerFromIndex(i+1);

        SetGold(player, StartingGold);
        Unit *king = CreateUnit(King, GetColor(*player), coordinate);
        AddUnit(player, king);
        SetUnit(GetGrid(coordinate), king);
        SetIncome(player, NbElmt(GetVillages(*player)) * 10);
        SetUpkeep(player, NbElmt(GetUnits(*player)) * 2);
    }
}

Player *GetPlayerFromIndex(int i)
{
    addressList P = First(Players);
    int k = 1;
    while (k < i) {
        ++k;
        P = Next(P);
    }
    return Info(P);
}

Player *GetPlayerFromColor(char color) 
{
    addressList P = First(Players);
    int i = 0;
    while (P) {
        ++i;
        Player *player = Info(P);
        if (GetColor(*player) == color) {
            return player;
        }
        P = Next(P);
    }
    return 0;
}

List GetPlayers() {
    return Players;
}

int GetPlayerIndex(Player player)
{
    addressList P = First(Players);
    char color = GetColor(player);
    int i = 0;
    while (P) {
        ++i;
        if (GetColor(*(Player *)Info(P)) == color) {
            return i;
        }
        P = Next(P);
    }
    return 0;
}

int GetGold(Player player) 
{
    return player.gold;
}

void SetGold(Player *player, int gold)
{
    player->gold = gold;
}

List GetUnits(Player player) 
{
    return player.units;
}

void AddUnit(Player *player, Unit *unit)
{   
    InsVLast(&player->units, unit);
}

void DelUnit(Player *player, Unit *unit)
{
    DelP(&player->units, unit);
}

Unit *GetFirstUnit(Player player) {
    return Info(First(GetUnits(player)));
}

void SetFirstUnit(Player *player, Unit *unit)
{
    Info(First(player->units)) = unit;
}

List GetVillages(Player player) 
{
    return player.villages;
}

void AddVillage(Player *P, Grid *grid)
{   
    InsVLast(&P->villages, grid);
}

void DelVillage(Player *P, Grid *grid)
{
    DelP(&P->villages, grid);
}

int GetIncome(Player player)
{
    return player.income;
}

void SetIncome(Player *player, int income)
{
    player->income = income;
}

int GetUpkeep(Player player) 
{
    return player.upkeep;
}

void SetUpkeep(Player *player, int upkeep)
{
    player->upkeep = upkeep;
}

char GetColor(Player player) 
{
    return player.color;
}