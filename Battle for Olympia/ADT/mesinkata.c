/* File: mesinkata.c */
/* Implementasi Mesin Kata: Model Akuisisi Versi I */

#include "mesinkata.h"
const Kata MOVE = {
    .TAbKata[Nmax+1] = "MOVE",
    .Length = 4
}
const Kata UNDO = {
    .TAbKata[Nmax+1] = "UNDO",
    .Length = 4
}
const Kata CHANGE_UNIT = {
    .TAbKata[Nmax+1] = "CHANGE_UNIT",
    .Length = 11
}
const Kata RECRUIT = {
    .TAbKata[Nmax+1] = "RECRUIT",
    .Length = 7
}
const Kata ATTACK = {
    .TAbKata[Nmax+1] = "ATTACK",
    .Length = 6
}
const Kata MAP = {
    .TAbKata[Nmax+1] = "MAP",
    .Length = 3
}
const Kata INFO = {
    .TAbKata[Nmax+1] = "INFO",
    .Length = 4
}
const Kata END_TURN = {
    .TAbKata[Nmax+1] = "END_TURN",
    .Length = 8
}
const Kata SAVE = {
    .TAbKata[Nmax+1] = "SAVE",
    .Length = 4
}



/* State Mesin Kata */
boolean EndKata;
Kata CKata;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{   /* Kamus Lokal */
    /* Algoritma */
    while ((CC == BLANK) && (CC != MARK))
    {
        ADV();
    } /* CC != BLANK or CC = MARK */
}

void STARTKATA()
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = Mark;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{   /* Kamus Lokal */
    /* Algoritma */
    START();
    IgnoreBlank();
    if (CC == MARK)
    {
        EndKata = true;
    }
    else /* CC != MARK */
    {
        EndKata = false;
        SalinKata();
    }
}

void ADVKATA()
/* I.S. : CC adalah karakter sesudah karakter terakhir dari kata yang sudah diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{   /* Kamus Lokal */
    /* Algoritma */
    IgnoreBlank();
    if (CC == MARK)
    {
        EndKata = true;
    }
    else /* CC != MARK */
    {
        SalinKata();
    }
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir dari kata yang sudah diakuisisi
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{   /* Kamus Lokal */
    /* Algoritma */
    for (int i = 1; i < NMax; ++i)
    {
        CKata.TabKata[i] = CC;

        ADV();
        if ((CC == BLANK) || (CC == MARK)) {
            CKata.Length = i;
            break;
        }
    } /* CC = MARK or CC = BLANK */
}

boolean isKataSama (Kata S1, Kata S2)
/* Mengembalikan true jika S1 == S2, dan false jika tidak sama */
{
    if (Length.S1 != Length.S2)
        return false;
    else
    {
       boolean found = false;
       int i = 1;
       while (!found && i <= Length.S1)
       {
            if (S1.TabKata[i] ==  S2.TabKata[i])
            {
                i++;
            }
            else
            {
                found = true;
            }
       }
       return !found;
    }
}