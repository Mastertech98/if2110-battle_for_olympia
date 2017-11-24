#include "map.h"
#include "Commands/info.h"

#include <stdio.h>

int main() {
    char colors[] = {'R', 'B'};
    POINT coordinates[] = {MakePOINT(2,2), MakePOINT(6,6)};
    CreateMap(10, 10, 2, colors, coordinates);
    printf("%c\n", GetType(*GetGrid(2,2)));
    PrintMap();
}