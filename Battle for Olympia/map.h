#ifndef MAP_H
#define MAP_H

#include "ADT/point.h"
#include "ADT/matriks.h"

#include "player.h"
#include "unit.h"

typedef enum EType {Normal, Tower, Castle, Village} Type;

typedef struct SGrid {
    POINT coordinate;
    Type type;
    Player *owner;
    Unit *unit;
} Grid;

typedef MATRIKS Map;

extern Map map;

const Grid EMPTY_GRID;
const Grid VILLAGE_GRID;

/* Function Prototype */
void CreateMap(int N, int M);

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

#endif
