/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "mesinkar.h"

#define NMax 50
#define BLANK ' '

typedef struct
{
    char TabKata[NMax + 1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
    int Length;
} Kata;

/* State Mesin Kata */
extern boolean EndKata;
extern Kata CKata;

void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTKATA();
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = Mark;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA();
/* I.S. : CC adalah karakter sesudah karakter terakhir dari kata yang sudah diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir dari kata yang sudah diakuisisi
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

boolean isKataSama (Kata S1, Kata S2);
/* Mengembalikan true jika S1 == S2, dan false jika tidak sama */

Kata StringToKata (char kata[]);
/* mengubah tipe variabel array of char menjadi tipe bentukan kata */
#endif