#ifndef PLAYER_H
#define PLAYER_H

#include "ADT/listlinier.h"

#define MaxPlayer 2

typedef struct SPlayer {
    int gold;
    List units;
    List villages;
    int income;
    int upkeep;
    char color;
} Player;

Player players[MaxPlayer];

Player *GetPlayer(char color);

int GetGold(Player player);

List *GetUnits(Player *player);

List *GetVillages(Player *player);

int GetIncome(Player player);

void SetIncome(Player *player, int income);

int GetUpkeep(Player player);

void SetUpkeep(Player *player, int upkeep);

char GetColor(Player player);

#endif