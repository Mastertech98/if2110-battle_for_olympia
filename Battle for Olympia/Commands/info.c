#include "../unit.h"
#include "../player.h"
#include "../map.h"
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
									//Melirik warna daripada owner
									//Representasinya R(Red),G(Green),Y(Yellow),B(Blue),
									//					M(Magenta), dan C(Cyan)
									
									//Kemudian setelah diketahui warnanya, maka akan dicari
									//tipe daripada setiap petak
									if(GetColor(*GetOwner(*GetGrid(i+1, k/4))) == 'R'){
										if(GetType(*GetGrid(i, k/4)) == Tower){
											print_red('T');
										} else if(GetType(*GetGrid(i, k/4)) == Castle){
											print_red('C');
										} else if(GetType(*GetGrid(i, k/4)) == Village){
											print_red('V');
										}
									} else if(GetColor(*GetOwner(*GetGrid(i, k/4))) == 'G'){
										if(GetType(*GetGrid(i, k/4)) == Tower){
											print_green('T');
										} else if(GetType(*GetGrid(i, k/4)) == Castle){
											print_green('C');
										} else if(GetType(*GetGrid(i, k/4)) == Village){
											print_green('V');
										}
									} else if(GetColor(*GetOwner(*GetGrid(i, k/4))) == 'Y'){
										if(GetType(*GetGrid(i, k/4)) == Tower){
											print_yellow('T');
										} else if(GetType(*GetGrid(i, k/4)) == Castle){
											print_yellow('C');
										} else if(GetType(*GetGrid(i, k/4)) == Village){
											print_yellow('V');
										}
									} else if(GetColor(*GetOwner(*GetGrid(i, k/4))) == 'B'){
										if(GetType(*GetGrid(i, k/4)) == Tower){
											print_blue('T');
										} else if(GetType(*GetGrid(i, k/4)) == Castle){
											print_blue('C');
										} else if(GetType(*GetGrid(i, k/4)) == Village){
											print_blue('V');
										}
									} else if(GetColor(*GetOwner(*GetGrid(i, k/4))) == 'M'){
										if(GetType(*GetGrid(i, k/4)) == Tower){
											print_magenta('T');
										} else if(GetType(*GetGrid(i, k/4)) == Castle){
											print_magenta('C');
										} else if(GetType(*GetGrid(i, k/4)) == Village){
											print_magenta('V');
										}
									} else if(GetColor(*GetOwner(*GetGrid(i, k/4))) == 'C'){
										if(GetType(*GetGrid(i, k/4)) == Tower){
											print_cyan('T');
										} else if(GetType(*GetGrid(i, k/4)) == Castle){
											print_cyan('C');
										} else if(GetType(*GetGrid(i, k/4)) == Village){
											print_cyan('V');
										}
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
										if(GetUnitClass(*GetUnit(*GetGrid(i, k/4))) == King){
											printf("K");
										} else if(GetUnitClass(*GetUnit(*GetGrid(i, k/4))) == Archer){
											print_red('A');
										} else if(GetUnitClass(*GetUnit(*GetGrid(i, k/4))) == Swordsman){
											print_red('S');
										} else if(GetUnitClass(*GetUnit(*GetGrid(i, k/4))) == WhiteMage){
											print_red('W');
										}
									} else if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == 'G'){
										if(GetUnitClass(*GetUnit(*GetGrid(i, k/4))) == King){
											print_green('K');
										} else if(GetUnitClass(*GetUnit(*GetGrid(i, k/4))) == Archer){
											print_green('A');
										} else if(GetUnitClass(*GetUnit(*GetGrid(i, k/4))) == Swordsman){
											print_green('S');
										} else if(GetUnitClass(*GetUnit(*GetGrid(i, k/4))) == WhiteMage){
											print_green('W');
										}
									} else if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == 'Y'){
										if(GetUnitClass(*GetUnit(*GetGrid(i, k/4))) == King){
											print_yellow('K');
										} else if(GetUnitClass(*GetUnit(*GetGrid(i, k/4))) == Archer){
											print_yellow('A');
										} else if(GetUnitClass(*GetUnit(*GetGrid(i, k/4))) == Swordsman){
											print_yellow('S');
										} else if(GetUnitClass(*GetUnit(*GetGrid(i, k/4))) == WhiteMage){
											print_yellow('W');
										}
									} else if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == 'B'){
										if(GetUnitClass(*GetUnit(*GetGrid(i, k/4))) == King){
											print_blue('K');
										} else if(GetUnitClass(*GetUnit(*GetGrid(i, k/4))) == Archer){
											print_blue('A');
										} else if(GetUnitClass(*GetUnit(*GetGrid(i, k/4))) == Swordsman){
											print_blue('S');
										} else if(GetUnitClass(*GetUnit(*GetGrid(i, k/4))) == WhiteMage){
											print_blue('W');
										}
									} else if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == 'M'){
										if(GetUnitClass(*GetUnit(*GetGrid(i, k/4))) == King){
											print_magenta('K');
										} else if(GetUnitClass(*GetUnit(*GetGrid(i, k/4))) == Archer){
											print_magenta('A');
										} else if(GetUnitClass(*GetUnit(*GetGrid(i, k/4))) == Swordsman){
											print_magenta('S');
										} else if(GetUnitClass(*GetUnit(*GetGrid(i, k/4))) == WhiteMage){
											print_magenta('W');
										}
									} else if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == 'C'){
										if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == King){
											print_cyan('K');
										} else if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == Archer){
											print_cyan('A');
										} else if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == Swordsman){
											print_cyan('S');
										} else if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == WhiteMage){
											print_cyan('W');
										}
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
		if(GetPlayerFromColor(*GetUnit(*GetGrid(Absis(coordinate),Ordinat(coordinate)))) == &players[0]){
			printf("Owned by Player 1\n");
		} else if(GetPlayerFromColor(*GetUnit(*GetGrid(Absis(coordinate),Ordinat(coordinate)))) == &players[1]){
			printf("Owned by Player 2\n");
		}
		
		printf("Health %d/%d | ATK %d | DEF \n",GetHealth(*GetUnit(*GetGrid(Absis(coordinate),Ordinat(coordinate)))),GetMaximumHealth(*GetUnit(*GetGrid(Absis(coordinate),Ordinat(coordinate)))),GetAttack(*GetUnit(*GetGrid(Absis(coordinate),Ordinat(coordinate)))));
	}
}





