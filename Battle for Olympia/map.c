#include "map.h"

#include <stdlib.h>

Map map;

POINT GetCoordinate(Grid grid) {
    return grid.coordinate;
}

Type GetType(Grid grid) {
    return grid.type;
}

Player *GetOwner(Grid grid) {
    return grid.owner;
}

void SetOwner(Grid *grid, Player *owner) {
    grid->owner = owner;
}

Unit *GetUnit(Grid grid) {
    return grid.unit;
}

void SetUnit(Grid *grid, Unit *unit) {
    grid->unit = unit;
}

char GetGridColor(Grid grid) {
    return GetColor(*grid.owner);
}

Grid *GetGrid(int x, int y) {
    return &map.Mem[4 * x + y];
}

int GetMapSizeN() {
    return map.N;
}

int GetMapSizeM() {
    return map.M;
}