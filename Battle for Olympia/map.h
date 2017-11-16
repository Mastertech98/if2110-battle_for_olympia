#ifndef MAP_H
#define MAP_H

#include "ADT/point.h"

#include "player.h"
#include "unit.h"

typedef enum EType {Normal, Tower, Castle, Village} Type;

typedef struct SGrid {
    const POINT coordinate;
    const Type type;
    Player *owner;
    Unit *unit;
} Grid;

typedef struct SMap {
    Grid *Mem;
    int N;
    int M;
} Map;

Map CreateMap(int N, int M);

POINT GetCoordinate(Grid grid); 

Type GetType(Grid grid); 

Player *GetOwner(Grid grid); 

void SetOwner(Grid *grid, Player *owner); 

Unit *GetUnit(Grid grid); 

void SetUnit(Grid *grid, Unit *unit);

char GetGridColor(Grid grid);

Grid *GetGrid(int x, int y);

int GetMapSizeN();

int GetMapSizeM();

#endif