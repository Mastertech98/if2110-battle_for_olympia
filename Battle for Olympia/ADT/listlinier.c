/* File : listlinier.c */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>

/* REALISASI */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyList(List L)
/* Mengirim true jika list kosong */
{
    return First(L) == NULL;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList(List *L)
/* I.S. Sembarang             */
/* F.S. Terbentuk list kosong */
{
    First(*L) = NULL;
}

/****************** Manajemen Memori ******************/
address Alokasi(infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NULL, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */
{
    address P;
    P = (address)malloc(sizeof(ElmtList));
    if (P!= NULL)
    {
        Info(P) = X;
        Next(P) = NULL;
        return P;
    }
    else
        return NULL;
}
void Dealokasi(address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search(List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */
{
    if (IsEmptyList(L))
    {
        return NULL;
    }
    else
    {
        address P = First(L);
        while (Next(P) != NULL && X != Info(P))
            P = Next(P);
        return X == Info(P) ? P : NULL;
    }
}
boolean FSearch (List L, address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
	address Pt = First(L);
    while (Pt != NULL)
    {
        if (Pt == P)
        {
            return true;
        }
		Pt = Next(Pt);
	}
	return false;
}
address SearchPrec (List L, infotype X)
/* Mengirimkan address elemen sebelum elemen yang NULLainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan NULL */
/* Jika P adalah elemen pertama, maka Prec=NULL */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
{
	if (IsEmptyList(L))
    {
        return NULL;
    }
    else
    {
        address P = First(L), Prec = NULL;
        while (Next(P) != NULL && X != Info(P))
        {
			Prec = P;
            P = Next(P);
		}
        return X == Info(P) ? Prec : NULL;
    }
}

/****************** PRIMITIF BERDASARKAN NULLAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst(List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan NULLai X jika alokasi berhasil */
{
    address P = Alokasi(X);
    if (P != NULL)
        InsertFirst(L, P);
}
void InsVLast(List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* berNULLai X jika alokasi berhasil. Jika alokasi gagal: I.S.=F.S. */
{
    address P = Alokasi(X);
    if (P != NULL)
        InsertLast(L, P);
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst(List *L, infotype *X)
/* I.S. List L tidak kosong */
/* F.S. Elemen pertama list dihapus: NULLai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address P;
    DelFirst(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}
void DelVLast(List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: NULLai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address P;
    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst(List *L, address P)
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    Next(P) = First(*L);
    First(*L) = P;
}
void InsertAfter(List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
void InsertLast(List *L, address P)
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    if (IsEmptyList(*L))
    {
        InsertFirst(L, P);
    }
    else
    {
        address Last = First(*L);
        while (Next(Last) != NULL)
            Last = Next(Last);
        InsertAfter(L, P, Last);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst(List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = First(*L);
    First(*L) = Next(First(*L));
    Next(*P) = NULL;
}
void DelP(List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address P = First(*L);
    address Prec = NULL;

    while (P != NULL && X != Info(P))
    {
        Prec = P;
        P = Next(P);
    }

    if (P != NULL)
    {
        if (Prec == NULL)
            First(*L) = Next(P);
        else
            Next(Prec) = Next(P);
        Dealokasi(&P);
    }
}
void DelLast(List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
    address Last = First(*L);
    address PrecLast = NULL;

    while (Next(Last) != NULL)
    {
        PrecLast = Last;
        Last = Next(Last);
    }

    *P = Last;

    if (PrecLast == NULL)
    {
        First(*L) = NULL;
    }
    else
    {
        Next(PrecLast) = NULL;
    }
}
void DelAfter(List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus */
{
    *Pdel = Next(Prec);
    Next(Prec) = Next(Next(Prec));
    Next(*Pdel) = NULL;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo(List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen berNULLai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");
    if (!IsEmptyList(L))
    {
        address P = First(L);
        printf("%d", Info(P));
        P = Next(P);
        while (P != NULL)
        {
            printf(",%d", Info(P));
            P = Next(P);
        }
    }
    printf("]");
}
int NbElmt(List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    address P = First(L);
    int N = 0;

    while (P != NULL)
    {
        ++N;
        P = Next(P);
    }

    return N;
}

/****************** PROSES TERHADAP LIST ******************/
void DelAll (List *L)
/* Delete semua elemen list dan alamat elemen di-dealokasi */
{
	address P = First(*L), Prec;
    while (P != NULL) {
        Prec = P;
        P = Next(P);
        Dealokasi(&Prec);
    }
    First(*L) = NULL;
}

void InversList (List *L)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{
	address Prec = NULL, P = First(*L), Succ;
    while (P != NULL) {
        Succ = Next(P);
        Next(P) = Prec;
        Prec = P;
        P = Succ;
    }
    First(*L) = Prec;
}

List FInversList (List L)
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
	List InversedList;
	address InversP, P = First(L);
	int success = 1;

	CreateEmptyList(&InversedList);

	while (P != NULL && success) {
		InversP = Alokasi(Info(P));
		if (InversP != NULL) {
			InsertFirst(&InversedList, InversP);
			P = Next(P);
		} else {
			success = 0;
		}
	}

	if (!success)
		DelAll(&InversedList);

	return InversedList;
}

void CopyList (List *L1, List *L2)
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama. */
/* Tidak ada alokasi/dealokasi elemen */
{
	First(*L2) = First(*L1);
}

List FCopyList (List L)
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
	List CopiedList;
	address CopyP, P = First(L);
	int success = 1;

	CreateEmptyList(&CopiedList);

	while (P != NULL && success) {
		CopyP = Alokasi(Info(P));
		if (CopyP != NULL) {
			InsertLast(&CopiedList, CopyP);
			P = Next(P);
		} else {
			success = 0;
		}
	}

	if (!success)
		DelAll(&CopiedList);

	return CopiedList;
}

void CpAlokList (List Lin, List *Lout)
/* I.S. Lin sembarang. */
/* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=NULL dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal */
{
	*Lout = FCopyList(Lin);
}

void Konkat (List L1, List L2, List * L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
/* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi */
/* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
/* harus di-dealokasi dan L3=NULL */
/* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang "baru" */
/* Elemen L3 adalah hasil alokasi elemen yang “baru”. */
/* Jika ada alokasi yang gagal, maka L3 harus berNULLai NULL */
/* dan semua elemen yang pernah dialokasi didealokasi */
{
	address PKonkat, P;
	int success = 1;

	CreateEmptyList(L3);

    P = First(L1);
	while (P != NULL && success) {
		PKonkat = Alokasi(Info(P));
		if (PKonkat != NULL) {
			InsertLast(L3, PKonkat);
			P = Next(P);
		} else {
			success = 0;
		}
	}
	P = First(L2);
	while (P != NULL && success) {
		PKonkat = Alokasi(Info(P));
		if (PKonkat != NULL) {
			InsertLast(L3, PKonkat);
			P = Next(P);
		} else {
			success = 0;
		}
	}

	if (!success)
		DelAll(L3);
}

void Konkat1(List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2 */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong. */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    CreateEmptyList(L3);
    if (IsEmptyList(*L1))
    {
        First(*L3) = First(*L2);
    }
    else
    {
        First(*L3) = First(*L1);
        address Last1 = First(*L1);
        while (Next(Last1) != NULL)
            Last1 = Next(Last1);
        Next(Last1) = First(*L2);
    }
    First(*L1) = First(*L2) = NULL;
}

void PecahList (List *L1, List *L2, List L)
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */
{
	address P = First(L), PPecah;
	int count = 0, half = NbElmt(L) / 2, success = 1;

	CreateEmptyList(L1);
	CreateEmptyList(L2);

	while (P != NULL && success) {
		count++;
		PPecah = Alokasi(Info(P));
		if (PPecah != NULL) {
			if (count <= half) {
				InsertLast(L1, PPecah);
			} else {
				InsertLast(L2, PPecah);
			}
		} else {
			success = 0;
		}

		P = Next(P);
	}

	if (!success) {
		DelAll(L1);
		DelAll(L2);
    }
}
