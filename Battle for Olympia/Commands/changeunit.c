#include "changeunit.h"
#include "../unit.h"
#include <stdio.h>

Unit *selectedUnit;

void ChangeUnit (Player *P)
{
    /*I.S. P adalah player yang sedang memainkan turnnya, selectedUnit adalah unit yang sedang dipilih pada saat ini*/
    /*F.S. selectedUnit akan berganti sesuai dengan pilihan player*/
    int choice,i;
    List units;
    address pt;

    units = GetUnits(*P);
    printf("== List of Units ==\n");
    PrintListUnits(units);
    printf("Please enter the no. of unit you want to select: ");
    scanf("%d",&choice);
    if (choice > NbElmt(units) || choice < 1)
    {
        printf("Invalid input\n");
    }
    else
    {
        pt = SearchbyChoice (units, choice);
        SetSelectedUnit((Unit *)Info(pt));
        
    }
}

void NextUnit (Player *P)
/* I.S. P adalah player yang sedang memainkan turnnya, selected unit adalah unit yang dipilih saat ini */
/* F.S. selectedUnit akan berubah menjadi unit pertama dari list of units yang masih memiliki movementPoints */
{
    List units;
    Unit *unitPointed;
    address Pt;
    boolean found = false;

    units = GetUnits(*P);
    Pt = First(units);
    while (!found)
    {
        unitPointed = (Unit *) Info(Pt);
        if (GetMovementPoints(*unitPointed) > 0 || GetChanceAttack(*unitPointed) )
        {
            found = true;
        }
        else
        {
            Pt = Next(Pt);
        }
    }
    if (found)
    {
        SetSelectedUnit((Unit *) Info(Pt));
    }
    else
    {
        printf("You don't have any unit that can move or attack\n");
    }
}

Unit *GetSelectedUnit(){
	return selectedUnit;
}

void SetSelectedUnit(Unit *unit){
	selectedUnit = unit;
}