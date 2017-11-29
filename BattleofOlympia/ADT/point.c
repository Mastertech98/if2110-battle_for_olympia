/* File: point.c */
/* *** Realisasi ABSTRACT DATA TYPE POINT *** */

#include "point.h"
#include <stdio.h>
#include <math.h>

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT(int X, int Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
    POINT point;

    Absis(point) = X;
    Ordinat(point) = Y;

    return point;
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ(POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{
    return Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2);
}
boolean NEQ(POINT P1, POINT P2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
{
    return Absis(P1) != Absis(P2) || Ordinat(P1) != Ordinat(P2);
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX(POINT P)
/* Mengirim salinan P dengan absis ditambah satu */
{
    return MakePOINT(Absis(P) + 1, Ordinat(P));
}
POINT NextY(POINT P)
/* Mengirim salinan P dengan ordinat ditambah satu */
{
    return MakePOINT(Absis(P), Ordinat(P) + 1);
}
POINT PlusDelta(POINT P, int deltaX, int deltaY)
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
{
    return MakePOINT(Absis(P) + deltaX, Ordinat(P) + deltaY);
}
void Geser(POINT *P, int deltaX, int deltaY)
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
{
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}