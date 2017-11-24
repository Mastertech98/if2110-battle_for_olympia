#include "player.h"
#include "map.h"

#include <stdlib.h>

void CreatePlayer(Player *P, char color, POINT coordinate)
/* I.S. : Sembarang */
/* F.S. : Terbentuk player dengan warna color */
{
    SetGold(P, 50);
    CreateEmptyList(&P->units);
    AddUnit(P, CreateUnit(King, color, coordinate));
    CreateEmptyList(&P->villages);
    SetIncome(P, 2);
    SetUpkeep(P, 1);
    P->color = color;
}

void InitializePlayer(int numberOfPlayers, char *colors, POINT *coordinates) 
/* I.S. : Sembarang */
/* F.S. : Inisialisasi 2 player dengan warna merah dan biru */
{
    for (int i = 0; i < numberOfPlayers; ++i) {
        CreatePlayer(&players[i], colors[i], coordinates[i]);
    }
}

Player *GetPlayer(char color) 
/* Mengembalikan player berdasarkan warna */
{
    for (int i = 0; i < MaxPlayer; ++i) {
        if (GetColor(players[i]) == color) {
            return &players[i];
        }
    }
    return 0;
}

int GetGold(Player player) 
/* Mengembalikan jumlah gold yang dimiliki player */
{
    return player.gold;
}

void SetGold(Player *player, int gold)
/* I.S. : Income dari player sembarang */
/* F.S. : Income dari player terdefinisi melalui parameter input */
{
    player->gold = gold;
}

List GetUnits(Player player) 
/* Mengembalikan list dari unit yang dimiliki player */
{
    return player.units;
}

void AddUnit(Player *P, Unit *unit)
{   
    InsVLast(&P->units, unit);
}

void DelUnit(Player *P, Unit *unit)
{
    DelP(&P->units, unit);
}

List GetVillages(Player player) 
/* Mengembalikan list dari village yang dimiliki player */
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
/* Mengembalikan income dari player */
{
    return player.income;
}

void SetIncome(Player *player, int income) 
/* I.S. : Income dari player sembarang */
/* F.S. : Income dari player terdefinisi melalui parameter input */
{
    player->income = income;
}

int GetUpkeep(Player player) 
/* Mengembalikan upkeep dari player */
{
    return player.upkeep;
}

void SetUpkeep(Player *player, int upkeep) 
/* I.S. : Upkeep dari player sembarang */
/* F.S. : Upkeep dari player terdefinisi melalui parameter input */
{
    player->upkeep = upkeep;
}

char GetColor(Player player) 
/* Mengembalikan warna dari player */
{
    return player.color;
}