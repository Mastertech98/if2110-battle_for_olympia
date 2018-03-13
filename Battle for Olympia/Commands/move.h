#ifndef MOVE_H
#define MOVE_H

#include "../corefiles.h"
#include "../ADT/point.h"

typedef struct {
    Grid *grid;
    int cost;
} infotypeQueueSet;
typedef int addrQueueSet;
typedef struct { 
    infotypeQueueSet *T;
    addrQueueSet HEAD;
    addrQueueSet TAIL;
    int MaxEl;
} QueueSet;

#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q) (Q).MaxEl

boolean IsQueueSetEmpty (QueueSet Q);
void CreateEmptyQueueSet (QueueSet * Q, int Max);
void DeAlokasiQueueSet(QueueSet * Q);
boolean IsMemberQueueSet(QueueSet Q, infotypeQueueSet);
void AddQueueSet (QueueSet * Q, infotypeQueueSet X);
void DelQueueSet (QueueSet * Q, infotypeQueueSet * X);

void COMMAND_MOVE(Unit *unit);

#endif
