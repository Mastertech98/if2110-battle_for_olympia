/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#ifndef MATRIKS_H
#define MATRIKS_H

#include "boolean.h"
#include "point.h"

#include "../player.h"
#include "../unit.h"
//#include "../map.h"

typedef enum EType {Normal, Tower, Castle, Village} Type;

typedef int indeks; /* indeks baris, kolom */

typedef struct SGrid {
    POINT coordinate;
    Type type;
    Player *owner;
    Unit *unit;
} Grid;

typedef Grid ElType;

typedef struct
{
    ElType *Mem;
    const int N; /* banyaknya/ukuran baris yg terdefinisi */
    const int M; /* banyaknya/ukuran kolom yg terdefinisi */
} MATRIKS;

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
MATRIKS MakeMATRIKS(int NB, int NK);
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
int N(MATRIKS M);
int M(MATRIKS M);
ElType Elmt(MATRIKS M, indeks i, indeks j);

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs(MATRIKS M);
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxKol(MATRIKS M);
/* Mengirimkan indeks kolom terkecil M */
indeks GetLastIdxBrs(MATRIKS M);
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxKol(MATRIKS M);
/* Mengirimkan indeks kolom terbesar M */

#endif
