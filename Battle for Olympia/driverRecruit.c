#include "recruit.h"
#include <stdio.h>

int main()
{
    List units,villages;
    Player P1;
    POINT location1;
    Unit *unitCreated;
    List *temp;
    int N,x,y;
    char type;
    
    CreateEmptyList(&units);
    CreateEmptyList(&villages);
    P1.gold = 100;
    P1.units = units;
    P1.villages= villages;
    P1.income = 10;
    P1.upkeep = 10;   
     
    scanf("%d", &N);
    for (int i = 1; i<=N; i++)
    {
        scanf("%d,%d,%c",&x,&y,&type);
        location1 = MakePOINT(x,y);
        if(type =='A')
        {
            unitCreated = CreateUnit(Archer, 0, location1);
            AddUnit(&P1,unitCreated);
        }
        else if(type =='S')
        {
            unitCreated = CreateUnit(Swordsman, 0, location1);
            AddUnit(&P1,unitCreated);
        }
        else if(type =='W')
        {
            unitCreated = CreateUnit(WhiteMage, 0, location1);
            AddUnit(&P1,unitCreated);
        }
    }
    
    //Unit unit2 = CreateUnit(Swordsman, 0, location2);
    //TambahUnit(&P1,unit2);
    /*Unit unit3 = CreateUnit(WhiteMage, GetColor(P1), location3);
    TambahUnit(&P1,unit3);*/
    temp = GetUnits(&P1);
    PrintListUnits(*temp);

    PrintPriceList();

    return 0;
}