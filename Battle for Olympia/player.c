#include "player.h"

#include <stdlib.h>

void CreatePlayer(Player *P, char color)
/* I.S. : Sembarang */
/* F.S. : Terbentuk player dengan warna color */
{
    P->gold = 50;
    CreateEmptyList(&P->units);
    CreateEmptyList(&P->villages);
    P->income = 2;
    P->upkeep = 1;
    P->color = color;
}

void InitializePlayer() 
/* I.S. : Sembarang */
/* F.S. : Inisialisasi 2 player dengan warna merah dan biru */
{
    CreatePlayer(&players[0], 'R');
    CreatePlayer(&players[1], 'B');
}

Player *GetPlayer(char color) 
/* Mengembalikan player berdasarkan warna */
{
    for (int i = 0; i < MaxPlayer; i++) {
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

void AddUnit (Player *P, Unit *unit)
/*I.S P adalah Player yang sedang memainkan turnnya, location adalah grid dari selected unit, dan X adalah parameter untuk unit yang akan ditambah*/
/*F.S jika X == A, maka archer akan ditambahkan ke list of units
      jika X == S, maka swordsman akan ditambahkan ke list of units
      jika X == W, maka whitemage akan ditambahkan ke list of units*/
{   
    InsVLast(&P->units, unit);
}

List GetVillages(Player player) 
/* Mengembalikan list dari village yang dimiliki player */
{
    return player.villages;
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