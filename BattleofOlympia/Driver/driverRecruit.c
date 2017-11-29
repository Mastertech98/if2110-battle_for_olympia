#include "../Commands/recruit.h"
#include "../Commands/changeunit.h"
#include <stdio.h>

int main()
{
    List units,villages;
    POINT location1;
    char unitname[12];
    Unit *unitCreated;
    Unit *selectedUnit;
    List temp;
    int N,x,y;
    char type;
    
    /*Inisialisasi Player dan Map*/
    CreateMap(3,3);
    POINT coordinates[1];
    char colors[1];
    colors[0] = 'R';
    location1 = MakePOINT(1,1);
    coordinates[0] = location1;
    CreatePlayers(1, colors);
    InitializePlayers(1, coordinates);
    InitializeMap (1, coordinates, 0);
    
    printf("--LIST SEBELUM MEREKRUT--\n");
    PrintListUnits(GetUnits(players[0]));

    PrintMap();
    printf("\n");

    /*Driver change unit*/
    ChangeUnit (&players[0], &selectedUnit);
    
    UnitClassName(GetUnitClass(*selectedUnit), unitname);
    printf("%s\n", unitname);
    
    /*Driver RecruitUnit*/
    if (GetUnitClass(*selectedUnit) == King)
    {
        RecruitUnit(&players[0], selectedUnit);
    }
    else
    {
        printf("you don't select the king \n");
    }    

    /*Proses Menambahkan unit manual*/
    /*scanf("%d", &N);
    for (int i = 1; i<=N; i++)
    {
        scanf("%d,%d,%c",&x,&y,&type);
        location1 = MakePOINT(x,y);
        if(type =='A')
        {
            unitCreated = CreateUnit(Archer, 'R', location1);
            AddUnit(&P1,unitCreated);
        }
        else if(type =='S')
        {
            unitCreated = CreateUnit(Swordsman, 'R', location1);
            AddUnit(&P1,unitCreated);
        }
        else if(type =='W')
        {
            unitCreated = CreateUnit(WhiteMage, 'R', location1);
            AddUnit(&P1,unitCreated);
        }
    }*/
    PrintMap();
    printf("--LIST SESUDAH MEREKRUT--\n");
    PrintListUnits(GetUnits(players[0]));

    return 0;
}