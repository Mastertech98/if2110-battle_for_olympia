/* File : player.h */
/* Deklarasi tipe bentukan player yang dipakai */
/* ADT untuk mengakses hal yang berhubungan dengan player */

#ifndef PLAYER_H
#define PLAYER_H

#include "ADT/listlinier.h"

#include "unit.h"

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
extern Player players[MaxPlayer];

/* Function Prototype */
void CreatePlayer(Player *P, char color);
/* I.S. : Sembarang */
/* F.S. : Terbentuk player dengan warna color */

void InitializePlayer();
/* I.S. : Sembarang */
/* F.S. : Inisialisasi 2 player dengan warna merah dan biru */

Player *GetPlayer(char color);
/* Mengembalikan player berdasarkan warna */

int GetGold(Player player);
/* Mengembalikan jumlah gold yang dimiliki player */

List GetUnits(Player player);
/* Mengembalikan list dari unit yang dimiliki player */

void AddUnit(Player *P, Unit *unit);
/*I.S P adalah Player yang sedang memainkan turnnya, location adalah grid dari selected unit, dan X adalah parameter untuk unit yang akan ditambah*/
/*F.S jika X == A, maka archer akan ditambahkan ke list of units
      jika X == S, maka swordsman akan ditambahkan ke list of units
      jika X == W, maka whitemage akan ditambahkan ke list of units*/

void DelUnit(Player *P, Unit *unit);

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