#include "recruit.h"
#include <stdio.h>
#include <stdlib.h>

void AddUnit (Player *P, Unit *unit)
/*I.S P adalah Player yang sedang memainkan turnnya, location adalah grid dari selected unit, dan X adalah parameter untuk unit yang akan ditambah*/
/*F.S jika X == A, maka archer akan ditambahkan ke list of units
      jika X == S, maka swordsman akan ditambahkan ke list of units
      jika X == W, maka whitemage akan ditambahkan ke list of units*/
{   
    List *unitList = GetUnits(P);

    SetMovementPoints(unit,0);
    //SetUnit(GetGrid(Absis(GetLocation(*unit)), Ordinat(GetLocation(*unit))), unit);
    InsVLast(unitList,unit);
    
}

void RecruitUnit (Player *P, Unit *selectedUnit)
/*I.S. Player adalah player yang sedang bermain, selected unit adalah unit yang sedang diselect*/
/*F.S. Jika selectedunit adalah king, player memilih petak yang castle miliknya, dan gold mencukupi
maka, unit yang dimiliki player akan bertambah dan dispawn di tempat castle yang dipilih.*/
{
    Grid *KingLoc;
    Grid *CastleLoc;
    POINT temp;
    int x,y,i;
    boolean done;

    if (GetUnitClass(*selectedUnit)== King)
    {
        temp = GetLocation(*selectedUnit);
        KingLoc = GetGrid(Absis(temp), Ordinat(temp));
        if (GetType(*KingLoc)==Tower)
        {
            done = false;
            do
            {
                printf("Enter the coordinate of empty castle: ");
                scanf("%d %d",&x,&y);
                temp = MakePOINT(x,y);
                CastleLoc = GetGrid(x,y);
                if (GetOwner(*CastleLoc)==P)
                {
                    if (GetUnitClass(*GetUnit(*CastleLoc))==Archer || GetUnitClass(*GetUnit(*CastleLoc))==Swordsman || GetUnitClass(*GetUnit(*CastleLoc))==WhiteMage)
                    {
                        printf("Sorry, that castle is occupied\n");
                    }
                    else
                    {
                        PrintPriceList();
                        printf("Enter no. of unit you want to recruit: ");
                        scanf("%d",&i);
                        switch (i){
                            case 1:
                            {
                                if (GetGold(*P)>= GetPrice(ARCHER))
                                {
                                    printf("You have recruited an Archer!\n");
                                    Unit *unit = CreateUnit(Archer, GetColor(*P), temp);
                                    AddUnit(P,unit);
                                }
                                else   
                                    printf("You don't have enough money");
                                break;
                            }
                            case 2:
                            {
                                if (GetGold(*P)>= GetPrice(SWORDSMAN))
                                {
                                    printf("You have recruited a Swordsman!\n");
                                    Unit *unit = CreateUnit(Swordsman, GetColor(*P), temp);
                                    AddUnit(P,unit);
                                }
                                else   
                                    printf("You don't have enough money");
                                break;
                            }
                            case 3:
                            {
                                if (GetGold(*P)>= GetPrice(WHITEMAGE))
                                {
                                    printf("You have recruited an whiteMage!\n");
                                    Unit *unit = CreateUnit(WhiteMage, GetColor(*P), temp);
                                    AddUnit(P,unit);
                                }
                                else   
                                    printf("You don't have enough money");
                                break;
                            }
                            default:
                                printf("You don't select from the choices");
                        }
                    }
                }
                else
                {
                    printf("Sorry, that castle isn't yours\n");
                }
            }while (!done);
        }
        else
        {
            printf("Sorry, your king is not in the tower, you can't recruit any unit.\n");
        }
    }
    else
    {
        printf("You don't select the king, please select the king before recruiting unit.\n");
    }
}

void ChangeUnit (Player *P, Unit *selectedUnit)
{
    /*I.S. P adalah player yang sedang memainkan turnnya, selectedUnit adalah unit yang sedang dipilih pada saat ini*/
    /*F.S. selectedUnit akan berganti sesuai dengan pilihan player*/
    int choice,i;
    List *units;
    address pt;

    units = GetUnits(P);
    printf("== List of Units ==\n");
    PrintListUnits(*units);
    printf("Please enter the no. of unit you want to select: ");
    scanf("%d",&choice);
    if (choice > NbElmt(*units) || choice < 1)
        {printf("salah woy!\n");
        return;
    }
    pt = First(*units);
    for (i=1; i<=choice; i++)
        pt = Next(pt);
    selectedUnit = Info(pt);
}

void PrintListUnits(List units)
/*I.S. P adalah player yang sedang memainkan turnnya*/
/*F.S. List of Units yang dimiliki player akan ditampilkan ke layar*/
{
    address Pt;
    int i=1;
    char namaunit[11];
    POINT location;
    Unit *pointedUnit;

    Pt = First(units);
    while(Pt != NULL)
    {
        pointedUnit = (Unit *) Info(Pt);
        UnitClassName(GetUnitClass(*pointedUnit), namaunit);
        location = (POINT)GetLocation(*pointedUnit);
        printf("%d. %s (%d,%d) | Health %d\n", i, namaunit, Absis(location), Ordinat(location), GetHealth(*pointedUnit));
        Pt = Next(Pt);
        i++;
    }
}

void PrintPriceList()
/*I.S. sembarang*/
/*F.S. List harga dari semua unit yang dapat direcruit ditampilkan ke layar*/
{
    printf("== List of Recruits ==\n");
    printf("1. Archer | Health %d | ATK %d | %dG\n", GetMaximumHealth(ARCHER), GetAttack(ARCHER), GetPrice(ARCHER));
    printf("2. Swordsman | Health %d | ATK %d | %dG\n",GetMaximumHealth(SWORDSMAN),GetAttack(SWORDSMAN),GetPrice(SWORDSMAN));
    printf("3. Whitemage | Health %d | ATK %d | %dG\n",GetMaximumHealth(WHITEMAGE),GetAttack(WHITEMAGE),GetPrice(WHITEMAGE));
}