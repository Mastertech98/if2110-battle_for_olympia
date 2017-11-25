#include "move.h"
#include "../map.h"
#include <stdio.h>
#include <string.h>

Map map;
Stack S_moves;

const Unit UNITMOV = {
    .unitClass = Movement,
    /*.color = 'G',

    .maximumHealth = DUMVAL,
    .health = DUMVAL,
    .attack = DUMVAL,
    .maximumMovementPoints = DUMVAL,
    .movementPoints = DUMVAL,
    .attackType = Melee,
    .chanceAttack = true,
    .location.X = -999,
    .location.Y = -999,
    .price = DUMVAL*/
};

void Move(Unit *unit, Map *map)
{
    POINT targetLoc;
    boolean moved = false;
    POINT location = GetLocation(*unit);

    MakeMovementMap(*unit);

    printf("New map :\n");
    PrintMap();
    printf("\n");

    do{
        printf("Please enter cell's coordinate x,y : ");
        scanf("%d,%d", &Absis(targetLoc), &Ordinat(targetLoc));

        Unit *targetUnitGrid = GetUnit(*GetGrid(Absis(targetLoc), Ordinat(targetLoc)));

        if(targetUnitGrid!=NULL){
            if(GetUnitClass(*targetUnitGrid)==Movement){
                infotypeStack tempS_moves = {
                    .unit = unit,
                    .movPoint = GetMovementPoints(*unit),
                    .origin = location,
                    .destination = targetLoc
                };
                Push(&S_moves, tempS_moves);
                SetLocation(unit, targetLoc);
                SetMovementPoints(unit, GetMovementPoints(*unit) - (abs(Absis(targetLoc)-Absis(location)) + abs((Ordinat(targetLoc)-Ordinat(location)))));
                SetUnit(GetGrid(Absis(targetLoc), Ordinat(targetLoc)), unit);
                SetUnit(GetGrid(Absis(location), Ordinat(location)), NULL);
                printf("You've successfuly moved your unit to (%d,%d).\n", Absis(targetLoc), Ordinat(targetLoc));
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

    ClearMovementMap(map);
}

void MakeMovementMap(Unit unit)
{
    POINT location = GetLocation(unit);
    Grid *gridA;
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
                gridA = GetGrid(Absis(location)+(i*abs(j)*k), Ordinat(location)+(i*abs(j+1)*k));

                b_continue = i<=GetMovementPoints(unit)
                  && (Absis(location)+(i*abs(j)*k) >= 0 && Absis(location)+(i*abs(j)*k) < GetMapSizeN()
                  && Ordinat(location)+(i*abs(j+1)*k) >= 0 && Ordinat(location)+(i*abs(j+1)*k) < GetMapSizeM());

                printf("%d,%d\n", Absis(location)+(i*abs(j)*k), Ordinat(location)+(i*abs(j+1)*k));

                if(!b_continue) break;

                if(GetUnit(*gridA)==NULL){
                    SetUnit(gridA, &UNITMOV);
                }else{
                    b_continue = GetColor(*GetOwner(*gridA))== GetUnitColor(unit);
                    //b_continue = GetUnitClass(*GetUnit(*gridA))==GetUnitClass(unit);
                }

                i++;
            }
            i = 1;
        }
    }
}

void ClearMovementMap(Map *map)
{
    Unit *unit;

    for(int i=0; i<GetMapSizeN(*map); i++){
        for(int j=0; j<GetMapSizeM(*map); j++){
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
        SetLocation(InfoStackUnit(tempS_moves), InfoStackOrigin(tempS_moves));
        SetMovementPoints(InfoStackUnit(tempS_moves), InfoStackMovPoint(tempS_moves));
        SetUnit(GetGrid(Absis(InfoStackOrigin(tempS_moves)),Ordinat(InfoStackOrigin(tempS_moves))), InfoStackUnit(tempS_moves));
        SetUnit(GetGrid(Absis(InfoStackDestination(tempS_moves)),Ordinat(InfoStackDestination(tempS_moves))), NULL);
        printf("You've successfuly undo your unit to (%d,%d).\n", Absis(InfoStackDestination(tempS_moves)),Ordinat(InfoStackDestination(tempS_moves)));
	}
}
