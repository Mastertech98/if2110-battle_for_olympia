/* File: jam.c */
/* Realisasi ADT JAM */

#include "jam.h"
#include <stdio.h>

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsJAMValid(int H, int M, int S)
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
{
    return H >= 0 && H < 24 && M >= 0 && M < 60 && S >= 0 && S < 60;
}

/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM(int HH, int MM, int SS)
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */
{
    JAM jam;

    Hour(jam) = HH;
    Minute(jam) = MM;
    Second(jam) = SS;

    return jam;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaJAM(JAM *J)
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J 
   yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
/* Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
{
    int HH, MM, SS;

    scanf("%d %d %d", &HH, &MM, &SS);

    while (!IsJAMValid(HH, MM, SS))
    {
        printf("Jam tidak valid\n");
        scanf("%d %d %d", &HH, &MM, &SS);
    }

    *J = MakeJAM(HH, MM, SS);
}

void TulisJAM(JAM J)
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS */
{
    printf("%d:%d:%d", Hour(J), Minute(J), Second(J));
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long JAMToDetik(JAM J)
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
{
    return 3600 * Hour(J) + 60 * Minute(J) + Second(J);
}

JAM DetikToJAM(long N)
/* Mengirim  konversi detik ke JAM */
{
    long s = N;

    if (s >= 86400)
    {
        s %= 86400;
    }
    else if (s < 0)
    {
        do
        {
            s += 86400;
        } while (s < 0);
    }

    return MakeJAM(s / 3600, ((s % 3600) / 60), s % 60);
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean JEQ(JAM J1, JAM J2)
/* Mengirimkan true jika J1=J2, false jika tidak */
{
    return Hour(J1) == Hour(J2) && Minute(J1) == Minute(J2) && Second(J1) == Second(J2);
}
boolean JNEQ(JAM J1, JAM J2)
/* Mengirimkan true jika J1 tidak sama dengan J2 */
{
    return Hour(J1) != Hour(J2) || Minute(J1) != Minute(J2) || Second(J1) != Second(J2);
}
boolean JLT(JAM J1, JAM J2)
/* Mengirimkan true jika J1<J2 , false jika tidak */
{
    return JAMToDetik(J1) < JAMToDetik(J2);
}
boolean JGT(JAM J1, JAM J2)
/* Mengirimkan true jika J1>J2, false jika tidak */
{
    return JAMToDetik(J1) > JAMToDetik(J2);
}
/* *** Operator aritmatika JAM *** */
JAM NextDetik(JAM J)
/* Mengirim 1 detik setelah J dalam bentuk JAM */
{
    return DetikToJAM(JAMToDetik(J) + 1);
}
JAM NextNDetik(JAM J, int N)
/* Mengirim N detik setelah J dalam bentuk JAM */
{
    return DetikToJAM(JAMToDetik(J) + N);
}
JAM PrevDetik(JAM J)
/* Mengirim 1 detik sebelum J dalam bentuk JAM */
{
    return DetikToJAM(JAMToDetik(J) - 1);
}
JAM PrevNDetik(JAM J, int N)
/* Mengirim N detik sebelum J dalam bentuk JAM */
/* *** Kelompok Operator Aritmetika *** */
{
    return DetikToJAM(JAMToDetik(J) - N);
}
long Durasi(JAM JAw, JAM JAkh)
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
{
    return JAMToDetik(JAkh) - JAMToDetik(JAw) + (JGT(JAw, JAkh) ? 86400 : 0);
}