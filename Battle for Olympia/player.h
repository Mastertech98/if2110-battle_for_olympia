/* File : player.h */
/* Deklarasi tipe bentukan player yang dipakai */
/* ADT untuk mengakses hal yang berhubungan dengan player */

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

/* Global Variable */
Player players[MaxPlayer];

/* Function Prototype */
void InitializePlayer();
void CreatePlayer(Player *P, char color);

Player *GetPlayer(char color);
/* Mengembalikan player berdasarkan warna */

int GetGold(Player player);
/* Mengembalikan jumlah gold yang dimiliki player */

List GetUnits(Player player);
/* Mengembalikan list dari unit yang dimiliki player */

List GetVillages(Player player);
/* Mengembalikan list dari village yang dimiliki player */

int GetIncome(Player player);
/* Mengebmalikan income dari player */

void SetIncome(Player *player, int income);
/* I.S. : Income dari player sembarang */
/* F.S. : Income dari player terdefinisi melalui parameter input */

int GetUpkeep(Player player);
/* Mengembalikan upkeep dari player */

void SetUpkeep(Player *player, int upkeep);
/* I.S. : Upkeep dari player sembarang */
/* F.S. : Upkeep dari player terdefinisi melalui parameter input */

char GetColor(Player player);
/* Mengembalikan warna dari player */

#endif