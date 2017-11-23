#include "unit.h"
#include "player.h"
#include "map.h"
#include "info.h"
#include "pcolor.h"
#include <stdio.h>


void PrintMap(){
	//lokal variabel
	int i,j,k;
		//definisi i untuk baris, j untuk kolom, dan k untuk isi tiap kotak
	int Kolom,Baris;
		//definisi absis untuk banyak baris dan ordinat untuk banyak kolom
	
	Kolom = GetMapSizeN();
	Baris = GetMapSizeM();
	
	for(i=0;i<=Baris;i++){
		
		for (j=0;j<=3;j++){
			
			//print untuk tiap kolom pertama
			printf("*");
			
			for(k=1;k<=Kolom*4;k++){
				if(j == 0){
					//kondisi ketika baris kelipatan 4 [0,4,8,...]
					printf("*");
				
				} else {
					
					//kondisi ketika kolom kelipatan 4 dari 2[2,6,10,...]
					if((k-2)%4 ==0){
						printf("%d ", GetGrid(0, 0));
						if(GetUnit(*GetGrid(i, k/4)) == NULL){
							printf("meow\n");
							if(j == 1){
								if(GetColor(*GetOwner(*GetGrid(i, k/4))) == 'R'){
									if(GetType(*GetGrid(i, k/4)) == Tower){
										print_red('T');
									} else if(GetType(*GetGrid(i, k/4)) == Castle){
										print_red('C');
									} else if(GetType(*GetGrid(i, k/4)) == Village){
										print_red('V');
									} else {
										printf(" ");
									}
								} else if(GetColor(*GetOwner(*GetGrid(i, k/4))) == 'G'){
									if(GetType(*GetGrid(i, k/4)) == Tower){
										print_green('T');
									} else if(GetType(*GetGrid(i, k/4)) == Castle){
										print_green('C');
									} else if(GetType(*GetGrid(i, k/4)) == Village){
										print_green('V');
									} else {
										printf(" ");
									}
								} else if(GetColor(*GetOwner(*GetGrid(i, k/4))) == 'Y'){
									if(GetType(*GetGrid(i, k/4)) == Tower){
										print_yellow('T');
									} else if(GetType(*GetGrid(i, k/4)) == Castle){
										print_yellow('C');
									} else if(GetType(*GetGrid(i, k/4)) == Village){
										print_yellow('V');
									} else {
										printf(" ");
									}
								} else if(GetColor(*GetOwner(*GetGrid(i, k/4))) == 'B'){
									if(GetType(*GetGrid(i, k/4)) == Tower){
										print_blue('T');
									} else if(GetType(*GetGrid(i, k/4)) == Castle){
										print_blue('C');
									} else if(GetType(*GetGrid(i, k/4)) == Village){
										print_blue('V');
									} else {
										printf(" ");
									}
								} else if(GetColor(*GetOwner(*GetGrid(i, k/4))) == 'M'){
									if(GetType(*GetGrid(i, k/4)) == Tower){
										print_magenta('T');
									} else if(GetType(*GetGrid(i, k/4)) == Castle){
										print_magenta('C');
									} else if(GetType(*GetGrid(i, k/4)) == Village){
										print_magenta('V');
									} else {
										printf(" ");
									}
								} else if(GetColor(*GetOwner(*GetGrid(i, k/4))) == 'C'){
									if(GetType(*GetGrid(i, k/4)) == Tower){
										print_cyan('T');
									} else if(GetType(*GetGrid(i, k/4)) == Castle){
										print_cyan('C');
									} else if(GetType(*GetGrid(i, k/4)) == Village){
										print_cyan('V');
									} else {
										printf(" ");
									}
								} else {
									if(GetType(*GetGrid(i, k/4)) == Village){
										printf("V");
									} else {
										printf(" ");
									}
								}
							} else if(j==2){
								if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == 'R'){
									if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == King){
										print_red('K');
									} else if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == Archer){
										print_red('A');
									} else if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == Swordsman){
										print_red('S');
									} else if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == WhiteMage){
										print_red('W');
									} else {
										printf(" ");
									}
								} else if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == 'G'){
									if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == King){
										print_green('K');
									} else if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == Archer){
										print_green('A');
									} else if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == Swordsman){
										print_green('S');
									} else if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == WhiteMage){
										print_green('W');
									} else {
										printf(" ");
									}
								} else if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == 'Y'){
									if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == King){
										print_yellow('K');
									} else if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == Archer){
										print_yellow('A');
									} else if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == Swordsman){
										print_yellow('S');
									} else if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == WhiteMage){
										print_yellow('W');
									} else {
										printf(" ");
									}
								} else if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == 'B'){
									if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == King){
										print_blue('K');
									} else if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == Archer){
										print_blue('A');
									} else if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == Swordsman){
										print_blue('S');
									} else if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == WhiteMage){
										print_blue('W');
									} else {
										printf(" ");
									}
								} else if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == 'M'){
									if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == King){
										print_magenta('K');
									} else if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == Archer){
										print_magenta('A');
									} else if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == Swordsman){
										print_magenta('S');
									} else if(GetUnitColor(*GetUnit(*GetGrid(i, k/4))) == WhiteMage){
										print_magenta('W');
									} else {
										printf(" ");
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
									} else {
										printf(" ");
									}
								}
							}  
					//kondisi ketika kolom kelipatan 4 dari 0 [0,4,8,...]	
						} else {
							printf(" ");
						} 
					}if(k%4 == 0){
						printf("*");
						
					//kondisi ketika bukan kelipatan 4 daripada 0 dan 2	
					} else {
						printf(" ");
					}
				}
				//memberikan new line daripada setiap baris
				printf("\n");
			}
		}
	}
	
		//memberikan bintang kepada baris terakhir
		for (i=0;i<=Kolom*4;i++){
			printf("*");
		}
	}
}
void PrintInfoGame(){
	POINT coordinate;
	printf("\n");
	
	printf("Enter the coordinate of the cell : &d &d\n",Absis(coordinate),Ordinat(coordinate));
	while((Absis(coordinate) >GetMapSizeN()) || (Ordinat(coordinate) > GetMapSizeM())){
		printf("Input is not valid !!!\n");
		printf("Enter the coordinate of the cell : &d &d\n",Absis(coordinate),Ordinat(coordinate));
	}
	
	printf("== Cell Info ==\n");
	
	if(GetType(*GetGrid(Absis(coordinate),Ordinat(coordinate))) == Normal){
		printf("Normal\n");
	} else if(GetType(*GetGrid(Absis(coordinate),Ordinat(coordinate))) == Tower){
		printf("Tower\n");
	} else if(GetType(*GetGrid(Absis(coordinate),Ordinat(coordinate))) == Castle){
		printf("Castle\n");
	} else if(GetType(*GetGrid(Absis(coordinate),Ordinat(coordinate))) == Village){
		printf("Village\n");
	}
	
	if(GetOwner(*GetGrid(Absis(coordinate),Ordinat(coordinate))) == &players[0]){
		printf("Owned by Player 1\n");
	} else if(GetOwner(*GetGrid(Absis(coordinate),Ordinat(coordinate))) == &players[1]){
		printf("Owned by Player 2\n");
	} else {
		
	}
	
	printf("\n");
	
	printf("== Unit Info ==\n");
	if (GetUnitClass(*GetUnit(*GetGrid(Absis(coordinate),Ordinat(coordinate)))) == King){
		printf("King\n");
	} else if (GetUnitClass(*GetUnit(*GetGrid(Absis(coordinate),Ordinat(coordinate)))) == Archer){
		printf("Archer\n");
	} else if (GetUnitClass(*GetUnit(*GetGrid(Absis(coordinate),Ordinat(coordinate)))) == Swordsman){
		printf("Swordsman\n");
	} else if (GetUnitClass(*GetUnit(*GetGrid(Absis(coordinate),Ordinat(coordinate)))) == WhiteMage){
		printf("Whitemage\n");
	}
	
	if(GetPlayerFromColor(*GetUnit(*GetGrid(Absis(coordinate),Ordinat(coordinate)))) == &players[0]){
		printf("Owned by Player 1\n");
	} else if(GetPlayerFromColor(*GetUnit(*GetGrid(Absis(coordinate),Ordinat(coordinate)))) == &players[1]){
		printf("Owned by Player 2\n");
	}
	
	printf("Health %d/%d | ATK %d | DEF \n",GetHealth(*GetUnit(*GetGrid(Absis(coordinate),Ordinat(coordinate)))),GetMaximumHealth(*GetUnit(*GetGrid(Absis(coordinate),Ordinat(coordinate)))),GetAttack(*GetUnit(*GetGrid(Absis(coordinate),Ordinat(coordinate)))));
}





