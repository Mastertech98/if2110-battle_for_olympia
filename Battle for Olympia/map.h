#ifndef MAP_H
#define MAP_H

#include "ADT/point.h"
#include "ADT/matriks.h"

#include "player.h"
#include "unit.h"

typedef MATRIKS Map;

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
