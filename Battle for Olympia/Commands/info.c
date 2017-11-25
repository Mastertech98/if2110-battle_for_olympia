#include "info.h"

#include "../pcolor.h"
#include <stdio.h>

void PrintByColor(char c, char color)
{
	if (color == 'R')
	{
		print_red(c);
	}
	else if (color == 'G')
	{
		print_green(c);
	}
	else if (color == 'Y')
	{
		print_yellow(c);
	}
	else if (color == 'B')
	{
		print_blue(c);
	}
	else if (color == 'M')
	{
		print_magenta(c);
	}
	else if (color == 'C')
	{
		print_cyan(c);
	}
	else
	{
		printf("%c", c);
	}
}

void PrintMap()
{
	//I.S. Tidak ada
	//F.S. mencetak map yang memiliki nilai kolom dan nilai baris

	//deklarasi lokal variabel
	int i, j, k;
	//definisi i untuk baris, j untuk isi kotak, dan k untuk kolom
	int Kolom, Baris;
	//definisi absis untuk banyak baris dan ordinat untuk banyak kolom

	//menginisialisasi Kolom dan Baris
	Kolom = GetMapSizeN();
	Baris = GetMapSizeM();

	//Akan mengisi loop i,j,k dengan i(baris),j(isikotak = 3),k(kolom).

	//loop pertama untuk baris
	for (i = 0; i < Baris; i++)
	{ //Indeks 0

		//Enter saat paling atas
		if (i == 0)
		{
			//mencetak jarak spasi sebelum indeks tiap kolom
			printf("   ");

			//mencetak indeks
			//Kolom dikalikan 4 karena besar 1 kolom berupa 4 (tidak termasuk border paling kiri vertikal)
			//loop sementara hanya untuk keperluan sekali
			for (j = 0; j <= Kolom * 4; j++)
			{

				//kasus ketika indeks kolom sudah terletak di tempat yang benar
				//sehingga akan menuliskan indeksnya
				if ((j - 5) % 4 == 0)
				{
					printf("%d", j / 4);

					//Kasus jika indeks kolom tidak terletak di tempat yang benar
				}
				else
				{
					printf(" ");
				}
			}

			//mencetak enter untuk membuat tabel
			printf("\n");
		}

		//membuat tabel

		//loop kedua untuk baris dimana j merepresentasikan isi tiap kotak
		//isi tiap kotak yang pertama PASTI berisi bintang
		//isi kedua berupa Isi petak [Normal,Village,Tower,Castle]
		//isi ketiga berupa Unit yang berada di petak tersebut [King,Archer,Swordsman,WhiteMage]
		for (j = 0; j <= 3; j++)
		{

			//kasus ketika indeks baris sudah ditempatnya
			//sehingga mencetak indeks baris
			if (j == 2)
			{
				printf("%d", i);
				printf(" *");

				//kasus ketika indeks baris tidak berada di tempatnya
				//sehingga hanya mencetak kosong
			}
			else
			{
				printf("  *");
			}

			//loop ketiga untuk kolom
			for (k = 1; k <= Kolom * 4; k++)
			{

				//kasus ketika j berada di 0 dimana pasti bintang
				if (j == 0)
				{
					printf("*");

					//kondisi ketika j berada di petak yang bukan bintang (j != 0)
				}
				else
				{

					//kondisi ketika kolom kelipatan 4 dari 2 [2,6,10,...]
					if ((k - 2) % 4 == 0)
					{

						//Kasus ketika j = 1 atau saat akan mencetak petak
						if (j == 1)
						{
							//Melihat apakah ada alamat kepemilikan dari owner(grid)
							//jika ada maka akan melakukan aksi true
							Grid *grid = GetGrid(i, k / 4);
							Player *owner = GetOwner(*grid);
							Type type = GetType(*grid);
							char color = owner ? GetColor(*owner) : 0;

							PrintByColor(type, color);

							//saat j=2 atau saat kasus ingin mencetak unit pada petak
						}
						else if (j == 2)
						{

							//melihat apakah suatu petak memiliki alamat unit
							//jika iya akan melakukan aksi true
							Unit *unit = GetUnit(*GetGrid(i, k / 4));

							if (unit != NULL)
							{
								//Mencari warna dari unit tersebut dan mencetaknya
								//representasi warna sama seperti diatas
								PrintByColor(GetUnitClass(*unit), GetUnitColor(*unit));
							} else {
								printf(" ");
							}
							//kasus ketika j = 3 atau saat petak pasti kosong
						}
						else if (j = 3)
						{
							printf(" ");
						}
						//kondisi ketika kolom kelipatan 4 dari 0 [0,4,8,...]
					}
					else if (k % 4 == 0)
					{
						printf("*");
						//kondisi ketika bukan kelipatan 4 daripada 0 dan 2
					}
					else
					{
						printf(" ");
					}
				}
			}
			//memberikan new line daripada setiap baris
			printf("\n");
		}
	}

	//memberikan bintang kepada baris terakhir
	for (i = 0; i <= Kolom * 4; i++)
	{
		if (i == 0)
			printf("  *");
		else
			printf("*");
	}
}

void PrintInfoGame()
{
	//I.S. Program meminta input koordinat yang akan divalidasi sesuai panjang map
	//F.S. Menghasilkan info pada peta tersebut yaitu isi petak [Normal, Village, Castle, Tower]
	//	   dan pemiliknya serta Unit yang ada di peta tersebut [King,Archer,Swordsman,WhiteMage]
	//	   beserta pemiliknya

	POINT coordinate;
	int x, y;
	printf("\n");

	printf("Enter the coordinate of the cell : \n");
	scanf("%d %d", &x, &y);
	while ((x > GetMapSizeN()) || (y > GetMapSizeM()))
	{
		printf("Input is not valid !!!\n");
		printf("Please re-enter the coordinate of the cell : \n");
		scanf("%d %d", x, y);
	}

	printf("== Cell Info ==\n");
	Grid *grid = GetGrid(x, y);

	Type type = GetType(*grid);
	Player *owner = GetOwner(*grid);
	Unit *unit = GetUnit(*grid);

	if (type == Normal)
	{
		printf("Normal\n");
	}
	else if (type == Tower)
	{
		printf("Tower\n");
	}
	else if (type == Castle)
	{
		printf("Castle\n");
	}
	else if (type == Village)
	{
		printf("Village\n");
	}

	if (owner == &players[0])
	{
		printf("Owned by Player 1\n");
	}
	else if (owner == &players[1])
	{
		printf("Owned by Player 2\n");
	}
	printf("\n");

	if (unit != NULL)
	{
		printf("== Unit Info ==\n");
		char stringUnitClass[11];
		UnitClassName(GetUnitClass(*unit), stringUnitClass);
		owner = GetPlayer(GetUnitColor(*unit));

		printf("%s\n", stringUnitClass);

		if (owner == &players[0])
		{
			printf("Owned by Player 1\n");
		}
		else if (owner == &players[1])
		{
			printf("Owned by Player 2\n");
		}
		printf("Health %d/%d | ATK %d\n", GetHealth(*unit), GetMaximumHealth(*unit), GetAttack(*unit));
	}
}
