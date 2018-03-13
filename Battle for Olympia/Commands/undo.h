#ifndef UNDO_H
#define UNDO_H

#include "../corefiles.h"

void CreateRecording();
void ClearRecording();
void COMMAND_UNDO(Unit *unit);
void RecordMovement(Grid *lastGrid, int lastMovementPoints, Player *villageOwner);

#endif