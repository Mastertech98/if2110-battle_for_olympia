/* ********** Realisasi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#include "matriks.h"

#include <stdlib.h>

/* ********** REALISASI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS(MATRIKS *M, int NB, int NK)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NK x NB di "ujung kiri" memori */
/* I.S. NK dan NB adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{   
    M->Mem = malloc(NB * NK * sizeof(ElType));
    M->N = NK;
	M->M = NB;
}

/* *** Selektor *** */
int N(MATRIKS M) {
    return M.N;
}
int M(MATRIKS M) {
    return M.M;
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs(MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
    return 0;
}
indeks GetFirstIdxKol(MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
    return 0;
}
indeks GetLastIdxBrs(MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
    return N(M) - 1;
}
indeks GetLastIdxKol(MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
    return N(M) - 1;
}
