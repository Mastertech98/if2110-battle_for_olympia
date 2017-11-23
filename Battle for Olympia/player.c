#include "player.h"
#include "unit.h"
#include <stdlib.h>

void CreatePlayer(Player *P, char color){
    P->gold = 50;
    CreateEmptyList(&P->units);
    CreateEmptyList(&P->villages);
    P->income = 2;
    P->upkeep = 1;
    P->color = color;
}

void InitializePlayer() {
    CreatePlayer(&players[0], 'R');
    CreatePlayer(&players[1], 'B');
}

Player *GetPlayer(char color) {
    for (int i = 0; i < MaxPlayer; i++) {
        if (GetColor(players[i]) == color) {
            return &players[i];
        }
    }
    return 0;
}

int GetGold(Player player) {
    return player.gold;
}

List GetUnits(Player player) {
    return player.units;
}

List GetVillages(Player player) {
    return player.villages;
}

int GetIncome(Player player) {
    return player.income;
}

void SetIncome(Player *player, int income) {
    player->income = income;
}

int GetUpkeep(Player player) {
    return player.upkeep;
}

void SetUpkeep(Player *player, int upkeep) {
    player->upkeep = upkeep;
}

char GetColor(Player player) {
    return player.color;
}