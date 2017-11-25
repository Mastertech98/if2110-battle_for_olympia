#include "../map.h"
#include "../Commands/info.h"

#include <stdio.h>

int main() {
    char colors[] = {'1', '2'};
    POINT coordinates[] = {MakePOINT(1,8), MakePOINT(8,1)};

    CreateMap(10, 10);

    InitializeMap(2, colors, coordinates, 3);
    InitializePlayers(2, colors, coordinates);

    PrintMap();
}