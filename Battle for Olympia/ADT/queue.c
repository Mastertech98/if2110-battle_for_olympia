/* File : queue.c */
/* Implementasi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */

#include "queue.h"
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsEmpty(Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return Head(Q) == NULL && Tail(Q) == NULL;
}
boolean IsFull(Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return NBElmt(Q) == MaxEl(Q);
}
int NBElmt(Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    if (IsEmpty(Q))
    {
        return 0;
    }
    else if (Head(Q) > Tail(Q))
    {
        return Tail(Q) - Head(Q) + 1 + MaxEl(Q);
    }
    else
    {
        return Tail(Q) - Head(Q) + 1;
    }
}

/* *** Kreator *** */
void CreateEmpty(Queue *Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    (*Q).T = (infotypeQueue *)malloc((Max + 1) * sizeof(infotypeQueue));
    if ((*Q).T != NULL)
    {
        MaxEl(*Q) = Max;
        Head(*Q) = NULL;
        Tail(*Q) = NULL;
    }
    else
    {
        MaxEl(*Q) = 0;
    }
}

/* *** Destruktor *** */
void DeAlokasi(Queue *Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    MaxEl(*Q) = 0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Add(Queue *Q, infotypeQueue X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{
    if (IsEmpty(*Q))
    {
        Head(*Q) = 1;
        Tail(*Q) = 1;
    }
    else if (Tail(*Q) == MaxEl(*Q))
    {
        Tail(*Q) = 1;
    }
    else
    {
        ++Tail(*Q);
    }

    InfoTail(*Q) = X;
}
void Del(Queue *Q, infotypeQueue *X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = NULLai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
{
    *X = InfoHead(*Q);

    if (Head(*Q) == Tail(*Q))
    {
        Head(*Q) = NULL;
        Tail(*Q) = NULL;
    }
    else if (Head(*Q) == MaxEl(*Q))
    {
        Head(*Q) = 1;
    }
    else
    {
        ++Head(*Q);
    }
}