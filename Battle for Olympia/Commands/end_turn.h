#ifndef END_TURN_H
#define END_TURN_H

#include "../corefiles.h"

void CreateTurn(int numberOfPlayers);
void InitializeTurn(int numberOfPlayers);
void Heal(Unit *unit);
void COMMAND_END_TURN();
Player *GetCurrentPlayer();

#endif
