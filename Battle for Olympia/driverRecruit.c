#include "recruit.h"
#include <stdio.h>

int main()
{
    List units,villages;
    Player P1;
    POINT location1;
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
            TambahUnit(&P1,CreateUnit(Archer, 0, location1));
        else if(type =='S')
            TambahUnit(&P1,CreateUnit(Swordsman, 0, location1));
        else if(type =='W')
            TambahUnit(&P1,CreateUnit(WhiteMage, 0, location1));
    }
    
    //Unit unit2 = CreateUnit(Swordsman, 0, location2);
    //TambahUnit(&P1,unit2);
    /*Unit unit3 = CreateUnit(WhiteMage, GetColor(P1), location3);
    TambahUnit(&P1,unit3);*/
    temp = GetUnits(&P1);
    PrintListUnits(*temp);

    PrintListHarga();

    return 0;
}