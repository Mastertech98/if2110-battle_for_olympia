#include "Commands/recruit.h"
#include <stdio.h>

int main()
{
    List units,villages;
    Player P1;
    POINT location1;
    char unitname[12];
    Unit *unitCreated;
    Unit *selectedUnit;
    List temp;
    int N,x,y;
    char type;
    
    CreateEmptyList(&units);
    CreateEmptyList(&villages);
    P1.gold = 100;
    P1.units = units;
    P1.villages= villages;
    P1.income = 10;
    P1.upkeep = 10; 
    P1.color = 'R';   
    
    location1 = MakePOINT(1,1);
    unitCreated = CreateUnit(King, 0, location1);
    selectedUnit = unitCreated;
    AddUnit(&P1, unitCreated);
    PrintListUnits(GetUnits(P1));
    //RecruitUnit(&P1, selectedUnit);

    scanf("%d", &N);
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
    }
    printf("hai\n");
    ChangeUnit (&P1, &selectedUnit);

    UnitClassName(GetUnitClass(*selectedUnit), unitname);
    printf("%s\n", unitname);
    PrintPriceList();

    return 0;
}