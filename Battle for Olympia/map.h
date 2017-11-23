/*File : map.h*/
/* Deklarasi type yang digunakan pada map */
/* Deklarasi fungsi-fungsi yang digunakan untuk mengakses map */

#ifndef MAP_H
#define MAP_H

#include "ADT/point.h"
#include "ADT/matriks.h"

#include "player.h"
#include "unit.h"

typedef MATRIKS Map;

extern Map map;

const Grid EMPTYGRID;

void CreateMap(int N, int M);
/* I.S. : Sembarang */
/* F.S. : Membuat Map dengan ukuran NxM yang bertipe matriks */

POINT GetCoordinate(Grid grid);
/* Mengembalikan koordinat petak dalam tipe bentukan point */

Type GetType(Grid grid);
/* Mengembalikan type suatu petak */

Player *GetOwner(Grid grid);
/* Mengembalikan alamat player yang memiliki petak */

void SetOwner(Grid *grid, Player *owner);
/* I.S. : Sembarang petak terdefinisi*/
/* F.S. : Petak yang ditunjuk menjadi pemilik owner */

Unit *GetUnit(Grid grid);
/* Mengembalikan unit yang ada di petak tersebut */

void SetUnit(Grid *grid, Unit *unit);
/* I.S. : Sembarang, petak terdefinisi */
/* F.S. : petak tersebut ditempati oleh unit tertentu */

char GetGridColor(Grid grid);
/* Mengembalikan warna dari pemmilik petak */

Grid *GetGrid(int x, int y);
/* Mengembalikan petak dari absis x dan ordinat y */

int GetMapSizeN();
/* mengembalikan N dari matriks NxM */

int GetMapSizeM();
/* mengembalikan M dari matriks NxM*/

#endif
