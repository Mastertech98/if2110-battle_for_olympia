/* File : stackt.c */
/* Implementasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */

#include "stackt.h"
#include <stdlib.h>

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack (Stack *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl karena 0 tidak dipakai */
/* Ciri stack kosong : TOP berNULLai NULL */
{   /* Kamus Lokal */
    /* Algoritma */
    Top(*S) = NULL;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{   /* Kamus Lokal */
    /* Algoritma */
    return (Top(S)==NULL);
}
boolean IsFullStack(Stack S)
/* Mengirim true jika tabel penampung NULLai elemen stack penuh */
{   /* Kamus Lokal */
    /* Algoritma */
    return (Top(S)==MaxElStack);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack *S, infotypeStack X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru, TOP bertambah 1 */
{   /* Kamus Lokal */
    /* Algoritma */
    ++Top(*S);
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack *S, infotypeStack *X)
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah NULLai elemen TOP yang lama, TOP berkurang 1 */
{   /* Kamus Lokal */
    /* Algoritma */
    *X = InfoTop(*S);
    Top(*S)--;
}
