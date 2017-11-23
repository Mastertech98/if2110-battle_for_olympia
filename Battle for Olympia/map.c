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
/* I.S. : Sembarang */
/* F.S. : Membuat Map dengan ukuran NxM yang bertipe matriks */
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

POINT GetCoordinate(Grid grid) 
/* Mengembalikan koordinat petak dalam tipe bentukan point */
{
    return grid.coordinate;
}

Type GetType(Grid grid) 
/* Mengembalikan type suatu petak */
{
    return grid.type;
}

Player *GetOwner(Grid grid)
/* Mengembalikan alamat player yang memiliki petak */
{
    return grid.owner;
}

void SetOwner(Grid *grid, Player *owner) 
/* I.S. : Sembarang petak terdefinisi*/
/* F.S. : Petak yang ditunjuk menjadi pemilik owner */
{
    grid->owner = owner;
}

Unit *GetUnit(Grid grid) 
/* Mengembalikan unit yang ada di petak tersebut */
{
    return grid.unit;
}

void SetUnit(Grid *grid, Unit *unit) 
/* I.S. : Sembarang, petak terdefinisi */
/* F.S. : petak tersebut ditempati oleh unit tertentu */
{
    grid->unit = unit;
}

char GetGridColor(Grid grid) 
/* Mengembalikan warna dari pemmilik petak */
{
    return GetColor(*grid.owner);
}

Grid *GetGrid(int x, int y) 
/* Mengembalikan petak dari absis x dan ordinat y */
{
    return &(map.Mem[GetMapSizeM() * y + x]);
}

int GetMapSizeN() 
/* mengembalikan N dari matriks NxM */
{
    return map.N;
}

int GetMapSizeM() 
/* mengembalikan M dari matriks NxM*/
{
    return map.M;
}
