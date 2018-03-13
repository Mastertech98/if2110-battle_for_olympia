/* File : player.h */
/* Deklarasi tipe bentukan player yang dipakai */
/* ADT untuk mengakses hal yang berhubungan dengan player */

#ifndef PLAYER_H
#define PLAYER_H

#include "ADT/listlinier.h"
#include "ADT/matriks.h"
#include "unit.h"

#define MaxPlayer 2

typedef struct {
    int gold;
    List units;
    List villages;
    int income;
    int upkeep;
    char color;
} Player;

/* Function Prototype */
void CreatePlayers(int numberOfPlayers, char colors[]);
void InitializePlayers(int numberOfPlayers, POINT coordinates[]);

Player *GetPlayerFromIndex(int i);
Player *GetPlayerFromColor(char color);
int GetPlayerIndex(Player player);
List GetPlayers();

int GetGold(Player player);
void SetGold(Player *player, int gold);

List GetUnits(Player player);
void AddUnit(Player *player, Unit *unit);
void DelUnit(Player *player, Unit *unit);
Unit *GetFirstUnit(Player player);
void SetFirstUnit(Player *player, Unit *unit);

List GetVillages(Player player);
void AddVillage(Player *P, Grid *grid);
void DelVillage(Player *P, Grid *grid);

int GetIncome(Player player);
void SetIncome(Player *player, int income);

int GetUpkeep(Player player);
void SetUpkeep(Player *player, int upkeep);

char GetColor(Player player);

#endif