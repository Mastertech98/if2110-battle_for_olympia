#include "printmap.h"

#include <stdio.h>
#include "../ADT/pcolor.h"

#include "changeunit.h"
#include "end_turn.h"

void PrintByColor(char c, char color)
{
	if (color == 'R')
	{
		print_red(c);
	}
	else if (color == 'G')
	{
		print_green(c);
	}
	else if (color == 'Y')
	{
		print_yellow(c);
	}
	else if (color == 'B')
	{
		print_blue(c);
	}
	else if (color == 'M')
	{
		print_magenta(c);
	}
	else if (color == 'C')
	{
		print_cyan(c);
	}
	else
	{
		printf("%c", c);
	}
}

void COMMAND_MAP() {
    int M = GetMapSizeM();
    int N = GetMapSizeN();

    printf("    ");
    for (int x = 0; x < N; x++) {
        printf(" %d  ", x);
    }
    printf("\n");

    PrintHorizontalBorder(N);

    for (int y = 0; y < M; y++) {
        printf("   *");
        for (int x = 0; x < N; x++) {
            Grid *grid = GetGrid(MakePOINT(x, y));
            Type type = GetType(*grid);
            Player *owner = GetOwner(*grid);
            char color = owner ? GetColor(*owner) : 0;

            printf(" ");
            PrintByColor(type, color);
            printf(" *");
        }

        printf("\n %d *", y);
        for (int x = 0; x < N; x++) {
            Unit *unit = GetUnit(*GetGrid(MakePOINT(x, y)));

            printf(" ");
            if (unit) {
                char color = unit == GetSelectedUnit(*GetCurrentPlayer()) ? 'G' : GetUnitColor(*unit);
                PrintByColor(GetUnitClass(*unit), color);
            } else {
                printf(" ");
            }
            printf(" *");
        }

        printf("\n   *");
        for (int x = 0; x < N; x++) {
            printf("   *");
        }
        printf("\n");

        PrintHorizontalBorder(N);
    }

    printf("\n");
}

void PrintHorizontalBorder(int N) {
    printf("   *");
    for (int j = 0; j < N; j++) {
        printf("****");
    }
    printf("\n");
}