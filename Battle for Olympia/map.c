#include "map.h"
#include "ADT/matriks.h"

#include <stdlib.h>
#include <stdio.h>

const Grid VillageGrid = {
	.coordinate.X = 0,
    .coordinate.Y = 0,
    .type = Village,
    .owner = NULL,
    .unit = NULL,
};



const Grid EMPTYGRID = {
    .coordinate.X = 0,
    .coordinate.Y = 0,
    .type = Normal,
    .owner = NULL,
    .unit = NULL,
};

Map map;

void CreateMap(int N, int M)
{
	int i;
	MakeMATRIKS(&map,N,M);
	
	for(i=0; i<N*M; i++){
		if(i!=2){
			map.Mem[i] = EMPTYGRID;
		}else{
			map.Mem[i] = VillageGrid;
		}
		//printf("%d",map.Mem[i].coordinate.X);
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
