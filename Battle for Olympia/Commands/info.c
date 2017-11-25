#include "info.h"

#include "../pcolor.h"
#include <stdio.h>


void PrintMap(){
//I.S. Tidak ada
//F.S. mencetak map yang memiliki nilai kolom dan nilai baris	

	//deklarasi lokal variabel
	int i,j,k;
		//definisi i untuk baris, j untuk isi kotak, dan k untuk kolom
	int Kolom,Baris;
		//definisi absis untuk banyak baris dan ordinat untuk banyak kolom
	
	//menginisialisasi Kolom dan Baris
	Kolom = GetMapSizeN();
	Baris = GetMapSizeM();
		
	//Akan mengisi loop i,j,k dengan i(baris),j(isikotak = 3),k(kolom).
	
	//loop pertama untuk baris
	for(i=0;i<Baris;i++){ //Indeks 0
		
		//Enter saat paling atas
		if(i==0) {
			//mencetak jarak spasi sebelum indeks tiap kolom
			printf("   ");
			
			//mencetak indeks
			//Kolom dikalikan 4 karena besar 1 kolom berupa 4 (tidak termasuk border paling kiri vertikal)
			//loop sementara hanya untuk keperluan sekali
			for(j=0;j<=Kolom *4;j++){
				
				//kasus ketika indeks kolom sudah terletak di tempat yang benar
				//sehingga akan menuliskan indeksnya
				if((j-5)%4 == 0){
					printf("%d",j/4);
				
				//Kasus jika indeks kolom tidak terletak di tempat yang benar
				} else {
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
		for (j=0;j<=3;j++){
			
			//kasus ketika indeks baris sudah ditempatnya
			//sehingga mencetak indeks baris
			if(j==2) {
				printf("%d",i);
				printf(" *");
				
			//kasus ketika indeks baris tidak berada di tempatnya
			//sehingga hanya mencetak kosong
			} else {
				printf("  *");
			}
			
			//loop ketiga untuk kolom
			for(k=1;k<=Kolom*4;k++){
				
				//kasus ketika j berada di 0 dimana pasti bintang 
				if(j == 0){
					printf("*");
				
				//kondisi ketika j berada di petak yang bukan bintang (j != 0)
				} else {
	
					//kondisi ketika kolom kelipatan 4 dari 2 [2,6,10,...]
					if((k-2)%4 ==0){
						
							//Kasus ketika j = 1 atau saat akan mencetak petak
							if(j == 1){
								//Melihat apakah ada alamat kepemilikan dari owner(grid)
								//jika ada maka akan melakukan aksi true
								if(GetOwner(*GetGrid(i, k/4)) != NULL){
									//printf("masuk\n");
									//Melirik warna daripada owner
									//Representasinya R(Red),G(Green),Y(Yellow),B(Blue),
									//					M(Magenta), dan C(Cyan)
									
									//Kemudian setelah diketahui warnanya, maka akan dicari
									//tipe daripada setiap petak
									if(GetColor(*GetOwner(*GetGrid(i, k/4))) == 'R'){
										print_red(GetType(*GetGrid(i, k/4)));
									} else if(GetColor(*GetOwner(*GetGrid(i, k/4))) == 'G'){
										print_green(GetType(*GetGrid(i, k/4)));
									} else if(GetColor(*GetOwner(*GetGrid(i, k/4))) == 'Y'){
										print_yellow(GetType(*GetGrid(i, k/4)));
									} else if(GetColor(*GetOwner(*GetGrid(i, k/4))) == 'B'){
										print_blue(GetType(*GetGrid(i, k/4)));
									} else if(GetColor(*GetOwner(*GetGrid(i, k/4))) == 'M'){
										print_magenta(GetType(*GetGrid(i, k/4)));
									} else if(GetColor(*GetOwner(*GetGrid(i, k/4))) == 'C'){
										print_cyan(GetType(*GetGrid(i, k/4)));
									} else {
										printf("%c",GetType(*GetGrid(i, k/4)));
									}
								
								//Kasus ketika alamat kepemilikan dari owner tidak ada	
								} else {
									
									//Jika tidak ada kepemilikan namun bertipe village
									//maka akan mencetak village berwarna default (putih)
									if(GetType(*GetGrid(i, k/4)) == Village){
										printf("V");
										
									//jika tidak akan membuat petak kosong
									} else {
										printf(" ");
									}
								}
								
							//saat j=2 atau saat kasus ingin mencetak unit pada petak
							} else if(j==2){
								
								//melihat apakah suatu petak memiliki alamat unit
								//jika iya akan melakukan aksi true
								
								if(GetUnit(*GetGrid(i, k/4)) != NULL){
									
									//Mencari warna dari unit tersebut dan mencetaknya 
									//representasi warna sama seperti diatas
									if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == 'R'){
										//print_red(GetUnitClass(*GetUnit(*GetGrid(i, k/4))));
										printf("%c",GetUnitClass(*GetUnit(*GetGrid(i, k/4))));
									} else if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == 'G'){
										print_green(GetUnitClass(*GetUnit(*GetGrid(i, k/4))));
									} else if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == 'Y'){
										print_yellow(GetUnitClass(*GetUnit(*GetGrid(i, k/4))));
									} else if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == 'B'){
										print_blue(GetUnitClass(*GetUnit(*GetGrid(i, k/4))));
									} else if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == 'M'){
										print_magenta(GetUnitClass(*GetUnit(*GetGrid(i, k/4))));
									} else if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == 'C'){
										print_cyan(GetUnitClass(*GetUnit(*GetGrid(i, k/4))));
									} 
							//Jika petak tidak memiliki alamat unit maka akan membuat petak peta kosong
							} else {
								printf(" ");
							} 
						
						//kasus ketika j = 3 atau saat petak pasti kosong
						} else if(j = 3){
							printf(" ");
						}
					//kondisi ketika kolom kelipatan 4 dari 0 [0,4,8,...]	
					}else if(k%4 == 0){
						printf("*");
					//kondisi ketika bukan kelipatan 4 daripada 0 dan 2	
					} else {
						printf(" ");
					}
				}
			}
			//memberikan new line daripada setiap baris
				printf("\n");
		}
	}
	
		//memberikan bintang kepada baris terakhir
		for (i=0;i<=Kolom*4;i++){
			if(i==0) printf("  *"); else printf("*");
		}
	}

void PrintInfoGame(){
//I.S. Program meminta input koordinat yang akan divalidasi sesuai panjang map
//F.S. Menghasilkan info pada peta tersebut yaitu isi petak [Normal, Village, Castle, Tower]
//	   dan pemiliknya serta Unit yang ada di peta tersebut [King,Archer,Swordsman,WhiteMage]
//	   beserta pemiliknya

	POINT coordinate;
	printf("\n");
	
	printf("Enter the coordinate of the cell : \n");
	scanf("%d %d",&Absis(coordinate),&Ordinat(coordinate));
	while((Absis(coordinate) >GetMapSizeN()) || (Ordinat(coordinate) > GetMapSizeM())){
		printf("Input is not valid !!!\n");
		printf("Please re-enter the coordinate of the cell : \n");
		scanf("%d %d",Absis(coordinate),Ordinat(coordinate));
	}
	
	printf("== Cell Info ==\n");
	
	if(GetGrid(Absis(coordinate),Ordinat(coordinate)) != NULL){
		if(GetType(*GetGrid(Absis(coordinate),Ordinat(coordinate))) == Normal){
			printf("Normal\n");
		} else if(GetType(*GetGrid(Absis(coordinate),Ordinat(coordinate))) == Tower){
			printf("Tower\n");
		} else if(GetType(*GetGrid(Absis(coordinate),Ordinat(coordinate))) == Castle){
			printf("Castle\n");
		} else if(GetType(*GetGrid(Absis(coordinate),Ordinat(coordinate))) == Village){
			printf("Village\n");
		}
	}
	if(GetGrid(Absis(coordinate),Ordinat(coordinate)) != NULL){
		if(GetOwner(*GetGrid(Absis(coordinate),Ordinat(coordinate))) == &players[0]){
			printf("Owned by Player 1\n");
		} else if(GetOwner(*GetGrid(Absis(coordinate),Ordinat(coordinate))) == &players[1]){
			printf("Owned by Player 2\n");
		} else {
			
		}
	}	
	printf("\n");
	
	printf("== Unit Info ==\n");
	if(GetGrid(Absis(coordinate),Ordinat(coordinate)) != NULL){
		if (GetUnitClass(*GetUnit(*GetGrid(Absis(coordinate),Ordinat(coordinate)))) == King){
			printf("King\n");
		} else if (GetUnitClass(*GetUnit(*GetGrid(Absis(coordinate),Ordinat(coordinate)))) == Archer){
			printf("Archer\n");
		} else if (GetUnitClass(*GetUnit(*GetGrid(Absis(coordinate),Ordinat(coordinate)))) == Swordsman){
			printf("Swordsman\n");
		} else if (GetUnitClass(*GetUnit(*GetGrid(Absis(coordinate),Ordinat(coordinate)))) == WhiteMage){
			printf("Whitemage\n");
		}
	}
	if(GetGrid(Absis(coordinate),Ordinat(coordinate)) != NULL){
		if(GetPlayer(GetUnitColor(*GetUnit(*GetGrid(Absis(coordinate),Ordinat(coordinate))))) == &players[0]){
			printf("Owned by Player 1\n");
		} else if(GetPlayer(GetUnitColor(*GetUnit(*GetGrid(Absis(coordinate),Ordinat(coordinate))))) == &players[1]){
			printf("Owned by Player 2\n");
		}
		
		printf("Health %d/%d | ATK %d | DEF \n",GetHealth(*GetUnit(*GetGrid(Absis(coordinate),Ordinat(coordinate)))),GetMaximumHealth(*GetUnit(*GetGrid(Absis(coordinate),Ordinat(coordinate)))),GetAttack(*GetUnit(*GetGrid(Absis(coordinate),Ordinat(coordinate)))));
	}
}
