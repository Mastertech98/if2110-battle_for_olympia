#include "undo.h"

#include "../ADT/stackt.h"

Stack RecordedMovement;

void CreateRecording() {
    CreateEmptyStack(&RecordedMovement);
}

void ClearRecording() {
    CreateEmptyStack(&RecordedMovement);
}

void COMMAND_UNDO(Unit *unit) {
    infotypeStack recordedMovement;
    Pop(&RecordedMovement, &recordedMovement);

    Grid *lastGrid = recordedMovement.lastGrid;
    Grid *currentGrid = GetGrid(GetLocation(*unit));
    Player *owner = recordedMovement.villageOwner;

    SetUnit(currentGrid, 0);
    SetUnit(lastGrid, unit);

    SetLocation(unit, GetCoordinate(*lastGrid));
    SetMovementPoints(unit, recordedMovement.lastMovementPoints);

    if (GetType(*currentGrid) == Village) {
        DelVillage(GetOwner(*currentGrid), currentGrid);
        SetOwner(currentGrid, owner);
        if (owner) {
            AddVillage(recordedMovement.villageOwner, currentGrid);
        }
    }
}

void RecordMovement(Grid *lastGrid, int lastMovementPoints, Player *villageOwner) {
    Push(&RecordedMovement, (infotypeStack){lastGrid, lastMovementPoints, villageOwner});
}