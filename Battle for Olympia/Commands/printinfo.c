#include "printinfo.h"

#include <stdio.h>

void COMMAND_INFO() {
	int x, y;
	do {
		printf("Enter the coordinate of the cell: ");
		scanf("%d %d", &x, &y);
	} while (!isValidCoordinate(x, y));
	
	Grid *grid = GetGrid(MakePOINT(x, y));
	Type type = GetType(*grid);
	Player *gridOwner = GetOwner(*grid);
	Unit *unit = GetUnit(*grid);

	printf("== Cell Info ==\n");
	if (type == Normal) {
		printf("Normal\n");
	} else if (type == Tower) {
		printf("Tower\n");
	} else if (type == Castle) {
		printf("Castle\n");
	} else if (type == Village) {
		printf("Village\n");
	}

	printf("Owned by Player %d\n", GetPlayerIndex(*gridOwner));

	if (unit) {
		Player *unitOwner = GetPlayerFromColor(GetUnitColor(*unit));
		char unitClassName[11];
		UnitClassName(GetUnitClass(*unit), unitClassName);

		printf("== Unit Info ==\n");
		printf("%s\n", unitClassName);
		printf("Owned by Player %d\n", GetPlayerIndex(*unitOwner));
		printf("Health %d/%d | ATK %d\n", 
			GetHealth(*unit), 
			GetMaximumHealth(*unit), 
			GetAttack(*unit)
		);
	}

	printf("\n");
}
