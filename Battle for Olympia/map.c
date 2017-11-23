#include "map.h"

#include <stdlib.h>

Map map;

POINT GetCoordinate(Grid grid) 
/* Mengembalikan koordinat yang bertipe bentukan point */
{
    return grid.coordinate;
}

Type GetType(Grid grid) 
/* Mengembalikan tipe petak, Tower, Castle, dll. */
{
    return grid.type;
}

Player *GetOwner(Grid grid) 
/* Mengembalikan pemilik dari petak tersebut, player1, player 2, atau tidak ada */
{
    return grid.owner;
}

void SetOwner(Grid *grid, Player *owner) 
/* I.S. : Pemilik suatu petak terdfinisi, bisa jadi kosong */
/* F.S. : Pemilik petak menjadi owner */
{
    grid->owner = owner;
}

Unit *GetUnit(Grid grid)
/* Mengembalikan unit yang ada di petak tersebut */
{
    return grid.unit;
}

void SetUnit(Grid *grid, Unit *unit) 
/*I.S. : Suatu petak memiliki sebuah unit sembarang, bisa kosong */
/*F.S. : Petak ditempati oleh unit */
{
    grid->unit = unit;
}

char GetGridColor(Grid grid) 
/* Mengembalikan warna pemilik petak ini */
{
    return GetColor(*grid.owner);
}

Grid *GetGrid(int x, int y)
/* Mengembalikan petak dari koordinat (x,y) */
{
    return &map.Mem[4 * x + y];
}

int GetMapSizeN() 
/* Mengembalikan N jika map berukuran NxM */
{
    return map.N;
}

int GetMapSizeM() 
/* Mengembalikan M jika map berukuran NxM */
{
    return map.M;
}