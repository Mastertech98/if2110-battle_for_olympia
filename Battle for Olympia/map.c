#include "map.h"

#include <stdlib.h>

const Grid EMPTYGRID {
    .coordinate.X = 0;
    .coordinate.Y = 0;
    .type = Normal;
    .owner = NULL;
    .unit = NULL;
}

Map map;

void CreateMap(int N, int M)
{
	MakeMATRIKS(&map,N,M);
	
	for(int i=0; i<NB*NK; i++){
		map.Mem[i] = EMPTYGRID;
		printf("%d",map.Mem[i].x);
	}
}

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
    return &(map.Mem[GetMapSizeM() * y + x]);
}

int GetMapSizeN() {
    return map.N;
}

int GetMapSizeM() {
    return map.M;
}
