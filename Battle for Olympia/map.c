#include "map.h"

#include "ADT/matriks.h"

Map map;

void CreateMap(int N, int M)
{
    MakeMATRIKS(&map, N, M);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            Grid *grid = GetGrid(i, j);
            grid->coordinate = MakePOINT(i, j);
            grid->type = Normal;
            SetOwner(grid, NULL);
            SetUnit(grid, NULL);
        }
    }
}

void InitializeMap(int numberOfPlayers, char *colors, POINT *coordinates)
{
    for (int i = 0; i < numberOfPlayers; ++i) {
        Player *player = GetPlayer(colors[i]);
        int x = coordinates[i].X;
        int y = coordinates[i].Y;
        Grid *grid = GetGrid(x, y);

        grid->type = Tower;
        SetOwner(grid, player);
        
        grid = GetGrid(x, y-1);
        grid->type = Castle;
        SetOwner(grid, player);
        
        grid = GetGrid(x, y+1);
        grid->type = Castle;
        SetOwner(grid, player);
        
        grid = GetGrid(x-1, y);
        grid->type = Castle;
        SetOwner(grid, player);
        
        grid = GetGrid(x+1, y);
        grid->type = Castle;
        SetOwner(grid, player);
    }
}

Grid *GetGrid(int x, int y)
{
    return &map.Mem[GetMapSizeM() * y + x];
}

char GetGridColor(Grid grid)
{
    return GetColor(*GetOwner(grid));
}

POINT GetCoordinate(Grid grid)
{
    return grid.coordinate;
}

Type GetType(Grid grid)
{
    return grid.type;
}

Player *GetOwner(Grid grid)
{
    return (Player*)grid.owner;
}

void SetOwner(Grid *grid, Player *owner)
{
    grid->owner = owner;
}

Unit *GetUnit(Grid grid)
{
    return (Unit*)grid.unit;
}

void SetUnit(Grid *grid, Unit *unit)
{
    grid->unit = unit;
}

int GetMapSizeN()
{
    return map.N;
}

int GetMapSizeM()
{
    return map.M;
}
