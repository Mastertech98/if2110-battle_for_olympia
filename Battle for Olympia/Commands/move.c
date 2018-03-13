#include "move.h"

#include "printmap.h"
#include "undo.h"
#include <stdio.h>
#include <string.h>

Unit MOVEMENT = {
    .unitClass = Movement
};

boolean IsQueueSetEmpty (QueueSet Q) {
    return Head(Q) == 0 && Tail(Q) == 0;
}
void CreateEmptyQueueSet (QueueSet * Q, int Max) {
    (*Q).T = (infotypeQueueSet *)malloc((Max + 1) * sizeof(infotypeQueueSet));
    if ((*Q).T != 0)
    {
        MaxEl(*Q) = Max;
        Head(*Q) = 0;
        Tail(*Q) = 0;
    }
    else
    {
        MaxEl(*Q) = 0;
    }
}
void DeAlokasiQueueSet (QueueSet * Q) {
    free((*Q).T);
}
boolean IsMemberQueueSet (QueueSet Q, infotypeQueueSet X) {
    infotypeQueueSet member;
    while (!IsQueueSetEmpty(Q)) {
        DelQueueSet(&Q, &member);
        if (member.grid == X.grid) {
            return true;
        }
    }
    return false;
}
void AddQueueSet (QueueSet * Q, infotypeQueueSet X) {
    if (!IsMemberQueueSet(*Q, X)) {
        if (IsQueueSetEmpty(*Q))
        {
            Head(*Q) = 1;
            Tail(*Q) = 1;
        }
        else if (Tail(*Q) == MaxEl(*Q))
        {
            Tail(*Q) = 1;
        }
        else
        {
            ++Tail(*Q);
        }

        InfoTail(*Q) = X;
    }
}
void DelQueueSet(QueueSet * Q, infotypeQueueSet * X) {
    *X = InfoHead(*Q);

    if (Head(*Q) == Tail(*Q))
    {
        Head(*Q) = 0;
        Tail(*Q) = 0;
    }
    else if (Head(*Q) == MaxEl(*Q))
    {
        Head(*Q) = 1;
    }
    else
    {
        ++Head(*Q);
    }
}

void COMMAND_MOVE(Unit *unit) {
    char color = GetUnitColor(*unit);
    int movementPoints = GetMovementPoints(*unit);
    Grid *start = GetGrid(GetLocation(*unit));

    QueueSet open_set;
    int size = 1;
    for (int i = 0; i < movementPoints; i++) {
        size *= 4;
    }
    CreateEmptyQueueSet(&open_set, size);

    unsigned int count = 0;
    infotypeQueueSet *closed_set;
    closed_set = (infotypeQueueSet *)malloc(2 * movementPoints * (movementPoints + 1) * sizeof(infotypeQueueSet));

    AddQueueSet(&open_set, (infotypeQueueSet){start, 0});

    do {
        infotypeQueueSet movement;
        DelQueueSet(&open_set, &movement);

        Grid *grid = movement.grid;
        int cost = movement.cost;

        if (cost < movementPoints) {
            ++cost;
            Grids adjacentGrids = GetAdjacentGrids(*grid);

            for (unsigned int i = 0; i < adjacentGrids.count; i++) {
                Grid *adjacentGrid = adjacentGrids.grids[i];
                if ((!isOccupied(*adjacentGrid) || isOccupiedByAlly(*adjacentGrid, color)) && !IsMemberQueueSet(open_set, (infotypeQueueSet){adjacentGrid, cost})) {
                    AddQueueSet(&open_set, (infotypeQueueSet){adjacentGrid, cost});
                }
            }
        }

        if (!isOccupied(*grid)) {
            closed_set[count++] = movement;
            SetUnit(grid, &MOVEMENT);
        }
    } while (!IsQueueSetEmpty(open_set));

    COMMAND_MAP();

    Grid *end;
    char choice = 0;
    int x, y;
    do {
        printf("Please enter cell's coordinate x y: ");
        scanf("%d %d", &x, &y);

        if (isValidCoordinate(x, y)) {
            end = GetGrid(MakePOINT(x, y));
            if (start == end) {
                choice = -1;
            } else {
                
                if (GetUnit(*end) != &MOVEMENT) {
                    printf("You can't move there\n");
                } else {
                    choice = 1;
                }
            }
        }
    } while (!choice);

    for (unsigned int i = 0; i < count; i++) {
        SetUnit(closed_set[i].grid, 0);
    }

    if (choice == 1) {
        SetUnit(start, 0);
        SetUnit(end, unit);
        SetLocation(unit, GetCoordinate(*end));
        printf("You have successfully moved to (%d,%d)\n", x, y);
        if (GetType(*end) == Village) {
            SetMovementPoints(unit, 0);

            Player *oldOwner = GetOwner(*end);
            if (oldOwner) {
                DelVillage(oldOwner, end);
            }

            Player *newOwner = GetPlayerFromColor(GetUnitColor(*unit));
            SetOwner(end, newOwner);
            AddVillage(newOwner, end);

            RecordMovement(start, movementPoints, oldOwner);
        } else {
            for (int i = 0; i < count; i++) {
                if (closed_set[i].grid == end) {
                    SetMovementPoints(unit, movementPoints - closed_set[i].cost);
                    break;
                }
            }
        }
    }

    DeAlokasiQueueSet(&open_set);
    free(closed_set);

    printf("\n");
}