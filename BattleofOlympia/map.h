#ifndef MAP_H
#define MAP_H

#include "ADT/point.h"

#include "player.h"
#include "unit.h"

typedef MATRIKS Map;

/* Function Prototype */
void CreateMap(int N, int M);
void InitializeMap(int numberOfPlayers, POINT coordinates[], int numberOfVillages);

Grid *GetGrid(int x, int y);
char GetGridColor(Grid grid);

POINT GetCoordinate(Grid grid);

Type GetType(Grid grid);

Player *GetOwner(Grid grid);
void SetOwner(Grid *grid, Player *owner);

Unit *GetUnit(Grid grid);
void SetUnit(Grid *grid, Unit *unit);

int GetMapSizeN();
int GetMapSizeM();

int RandomVillage(int numberOfVillages);

#endif
