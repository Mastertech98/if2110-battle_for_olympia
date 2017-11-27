#ifndef END_TURN_H
#define END_TURN_H

#include "../ADT/queue.h"
#include "../player.h"

void CreateQueue(int numberOfPlayers);
void InitializeQueue(int numberOfPlayers);
void EndTurn();
Player *GetCurrentPlayer();

#endif