#include "move.h"
#include "../map.h"
#include "info.h"
#include <stdio.h>
#include <string.h>

Map map;
Stack S_moves;

Unit UNITMOV = {
    .unitClass = Movement,
    .color = 'G',

    .maximumHealth = DUMVAL,
    .health = DUMVAL,
    .attack = DUMVAL,
    .maximumMovementPoints = DUMVAL,
    .movementPoints = DUMVAL,
    .attackType = Melee,
    .chanceAttack = true,
    .location.X = -999,
    .location.Y = -999,
    .price = DUMVAL
};

void Move(Unit *unit)
{
	POINT targetLoc;
    boolean moved = false;
	POINT location = GetLocation(*unit);
	//printf("Unit Location : %d %d\n", Absis(location), Ordinat(location));
    Player *player = GetPlayer(GetUnitColor(*unit));
	//printf("Color of current player : %c\n", GetColor(*player));

    boolean occupyVillage = false;

    if(GetMovementPoints(*unit)>0){
        MakeMovementMap(unit);

        PrintMap();
        //printf("\n");

        do{
            printf("Please enter cell's coordinate x,y : ");
            scanf("%d %d", &Absis(targetLoc), &Ordinat(targetLoc));

            Unit *targetUnitGrid = GetUnit(*GetGrid(Absis(targetLoc), Ordinat(targetLoc)));
            Grid *targetGrid = GetGrid(Absis(targetLoc), Ordinat(targetLoc));

            if(targetUnitGrid!=NULL){
                if(GetUnitClass(*targetUnitGrid)==Movement){
                    infotypeStack tempS_moves = {
                        .unit = unit,
                        .movPoint = GetMovementPoints(*unit),
                        .origin = location,
                        .destination = targetLoc,
                        .lastOwner = GetOwner(*targetGrid)
                    };
                    Push(&S_moves, tempS_moves);
                    SetLocation(unit, targetLoc);
                    if(GetType(*targetGrid)==Village && GetOwner(*targetGrid)!=player){
							SetMovementPoints(unit, 0);
							if(GetOwner(*targetGrid)!=NULL) DelVillage(GetOwner(*targetGrid), targetGrid);
							SetOwner(targetGrid, player);
							AddVillage(player, targetGrid);
							occupyVillage = true;
                    }else{
                        SetMovementPoints(unit, GetMovementPoints(*unit) - (abs(Absis(targetLoc)-Absis(location)) + abs((Ordinat(targetLoc)-Ordinat(location)))));
                    }
                    SetUnit(GetGrid(Absis(targetLoc), Ordinat(targetLoc)), unit);
                    SetUnit(GetGrid(Absis(location), Ordinat(location)), NULL);
                    printf("You've successfuly moved your unit to (%d,%d).\n", Absis(targetLoc), Ordinat(targetLoc));
                    if(occupyVillage){
                        printf("And occupy a village.\n");
                    }
                    moved = true;
                }else if(Absis(location)==Absis(targetLoc) && Ordinat(location)==Ordinat(targetLoc)){
                    printf("You've cancelled your move.\n");
                    moved = true;
                }else{
                    printf("You can't move there!\n");
                }
            }else{
                printf("You can't move there!\n");
            }
        }while(!moved);

        ClearMovementMap();
    }else{
        printf("Current unit doesn't have any movement points left!\n");
    }
}

void MakeMovementMap(Unit *unit)
{
    POINT location = GetLocation(*unit);
    Grid *gridA;
    Unit *unitA;
    boolean b_continue;

    //Pembuatan movement map berurut dengan urutan x+, y+, x-, y-
    int i = 1;
    for(int k=1; k>=-1; k-=2){
        for(int j=-1; j<=0; j++){
            /**continue iterating when:
                1.the checked grid is still within unit's movementpoint
                2.the checked grid is within map size
                3.the unit in the checked grid is ally
            **/
            b_continue = true;

            while(b_continue){
                b_continue = i<=GetMovementPoints(*unit)
                  && (Absis(location)+(i*abs(j)*k) >= 0 && Absis(location)+(i*abs(j)*k) < GetMapSizeN()
                  && Ordinat(location)+(i*abs(j+1)*k) >= 0 && Ordinat(location)+(i*abs(j+1)*k) < GetMapSizeM());

                if(!b_continue) break;

                gridA = GetGrid(Absis(location)+(i*abs(j)*k), Ordinat(location)+(i*abs(j+1)*k));

                //printf("%d,%d\n", Absis(location)+(i*abs(j)*k), Ordinat(location)+(i*abs(j+1)*k));
			
				unitA = GetUnit(*gridA);
                if(unitA==NULL){
                    SetUnit(gridA, &UNITMOV);
                }else{
                    b_continue = GetUnitColor(*unitA)==GetUnitColor(*unit);
                }

                i++;
            }
            i = 1;
        }
    }
}

void ClearMovementMap()
{
    Unit *unit;

    for(int i=0; i<GetMapSizeN(); i++){
        for(int j=0; j<GetMapSizeM(); j++){
            unit = GetUnit(*GetGrid(i,j));
            if(unit!=NULL){
                if(GetUnitClass(*unit)==Movement){
                    SetUnit(GetGrid(i, j), NULL);
                }
            }
        }
    }
}

boolean IsValidUndo(){
	return (!IsEmptyStack(S_moves));
}

void Undo(){
	infotypeStack tempS_moves;
	if (IsEmptyStack(S_moves)){
		printf("You can't undo.\n");
	} else {
		Pop(&S_moves, &tempS_moves);
		Grid *destGrid = GetGrid( Absis(InfoStackDestination(tempS_moves)), Ordinat(InfoStackDestination(tempS_moves)));
        SetLocation(InfoStackUnit(tempS_moves), InfoStackOrigin(tempS_moves));
        SetMovementPoints(InfoStackUnit(tempS_moves), InfoStackMovPoint(tempS_moves));
        if(GetType(*destGrid)==Village && GetOwner(*destGrid)!=InfoStackLastOwner(tempS_moves)){
            DelVillage(GetOwner(*destGrid), destGrid);
            SetOwner(destGrid, InfoStackLastOwner(tempS_moves));
            if(InfoStackLastOwner(tempS_moves)!=NULL) AddVillage(InfoStackLastOwner(tempS_moves), destGrid);
        }
        SetUnit(GetGrid(Absis(InfoStackOrigin(tempS_moves)),Ordinat(InfoStackOrigin(tempS_moves))), InfoStackUnit(tempS_moves));
        SetUnit(GetGrid(Absis(InfoStackDestination(tempS_moves)),Ordinat(InfoStackDestination(tempS_moves))), NULL);
        printf("You've successfuly undo your unit to (%d,%d).\n", Absis(InfoStackDestination(tempS_moves)),Ordinat(InfoStackDestination(tempS_moves)));
	}
}

void MakeStackEmpty(){
	infotypeStack tempS_moves;
	while(!IsEmptyStack(S_moves)){
		Pop(&S_moves, &tempS_moves);
	}
}