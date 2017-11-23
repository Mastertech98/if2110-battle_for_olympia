#include "move.h"
#include "map.h"
#include <stdio.h>
#include <string.h>

Map map;
Stack S_moves;

void Move(Unit *unit, Map *map)
{
    POINT targetLoc;
    boolean moved = false;
    POINT location = GetLocation(*unit);

    MakeMovementMap(*unit);

    do{
        printf("Please enter cell's coordinate x,y : ");
        scanf("%d,%d", Absis(targetLoc), Ordinat(targetLoc));

        if(GetUnitClass(*GetUnit(*GetGrid(Absis(targetLoc), Ordinat(targetLoc))))!=Movement){
            infotypeStack tempS_moves = {
                .unit = unit,
                .movPoint = GetMovementPoints(*unit),
                .origin = location,
                .destination = targetLoc
            };
            Push(&S_moves, tempS_moves);
            SetLocation(unit, targetLoc);
            SetMovementPoints(unit, GetMovementPoints(*unit) - (abs(Absis(targetLoc)-Absis(location)) + (Ordinat(targetLoc)-Ordinat(location))));
            SetUnit(GetGrid(Absis(targetLoc), Ordinat(targetLoc)), unit);
            SetUnit(GetGrid(Absis(location), Ordinat(location)), NULL);
            printf("You've successfuly moved your unit to (%d,%d).\n", Absis(targetLoc), Ordinat(targetLoc));
            moved = true;
        }else if(Absis(location)==Absis(targetLoc) && Ordinat(location)==Ordinat(targetLoc)){
            printf("You cancelled your move");
            moved = true;
        }else{
            printf("You can't move there!\n");
        }
    }while(!moved);

    CleanMovementMap(map);
}

void MakeMovementMap(Unit unit)
{
    int i = 1;

    //Pembuatan movement map berurut dengan urutan x+, y+, x-, y-
    for(int k=1; k>=-1; k-=2){
        for(int j=-1; j<=0; j++){
            //continue iterating when the unit still has movementpoint and the unit in the checked grid is noone or ally
            while(i<=GetMovementPoints(unit) && (GetColor(*GetOwner(*GetGrid(Absis(GetLocation(unit))+(i*abs(j)*k), Ordinat(GetLocation(unit))+(i*abs(j+1)*k))))== GetUnitColor(unit) || GetUnit(*GetGrid(Absis(GetLocation(unit))+(i*abs(j)*k), Ordinat(GetLocation(unit))+(i*abs(j+1)*k)))!=NULL ) ){
                SetUnit(GetGrid(Absis(GetLocation(unit))+(i*abs(j)*k), Ordinat(GetLocation(unit))+(i*abs(j+1)*k)), &UNITMOV);
                i++;
            }
            i = 1;
        }
    }
}

void CleanMovementMap(Map *map)
{
    for(int i=1; i<=N(*map); i++){
        for(int j=1; i<=M(*map); j++){
            if(GetUnitClass(*GetUnit(*GetGrid(i,j)))==Movement){
                SetUnit(GetGrid(i, j), NULL);
            }
        }
    }
}

boolean IsValidUndo(){
	return (!IsEmptyStack(S_moves));
}

void Undo(Unit *unit){
	infotypeStack tempS_moves;
	if (IsEmptyStack(S_moves)){
		printf("You can't undo.\n");
	} else {
		Pop(&S_moves, &tempS_moves);
        SetLocation(unit, tempS_moves.origin);
        SetMovementPoints(unit, tempS_moves.movPoint);
        SetUnit(GetGrid(Absis(tempS_moves.origin),Ordinat(tempS_moves.origin)), unit);
        SetUnit(GetGrid(Absis(tempS_moves.destination),Ordinat(tempS_moves.destination)), NULL);
        printf("You've successfuly undo your unit to (%d,%d).\n", Absis(tempS_moves.destination),Ordinat(tempS_moves.destination));
	}
}
