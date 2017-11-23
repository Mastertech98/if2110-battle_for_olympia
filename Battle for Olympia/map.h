/* File : map.h */
/* Deklarasi tipe bentukan Map yang dipakai */
/* ADT untuk mengakses hal yang berhubungan dengan map  */

#ifndef MAP_H
#define MAP_H

#include "ADT/point.h"
#include "ADT/matriks.h"

#include "player.h"
#include "unit.h"

typedef MATRIKS Map;

Map CreateMap(int N, int M);
/* */ 

POINT GetCoordinate(Grid grid);
/* Mengembalikan koordinat yang bertipe bentukan point */

Type GetType(Grid grid);
/* Mengembalikan tipe petak, Tower, Castle, dll. */

Player *GetOwner(Grid grid);
/* Mengembalikan pemilik dari petak tersebut, player1, player 2, atau tidak ada */

void SetOwner(Grid *grid, Player *owner);
/* I.S. : Pemilik suatu petak terdfinisi, bisa jadi kosong */
/* F.S. : Pemilik petak menjadi owner */

Unit *GetUnit(Grid grid);
/* Mengembalikan unit yang ada di petak tersebut */

void SetUnit(Grid *grid, Unit *unit);
/*I.S. : Suatu petak memiliki sebuah unit sembarang, bisa kosong */
/*F.S. : Petak ditempati oleh unit */

char GetGridColor(Grid grid);
/* Mengembalikan warna pemilik petak ini */

Grid *GetGrid(int x, int y);
/* Mengembalikan petak dari koordinat (x,y) */

int GetMapSizeN();
/* Mengembalikan N jika map berukuran NxM */

int GetMapSizeM();
/* Mengembalikan M jika map berukuran NxM */

#endif
