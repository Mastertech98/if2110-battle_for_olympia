#include "map.h"
#include <stdio.h>
#include "ADT/matriks.h"

Map map;

void CreateMap(int N, int M)
{
    MakeMATRIKS(&map, N, M);

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            Grid *grid = GetGrid(i, j);
            grid->coordinate = MakePOINT(i, j);
            grid->type = Normal;
            SetOwner(grid, NULL);
            SetUnit(grid, NULL);
        }
    }
}

void InitializeMap(int numberOfPlayers, POINT coordinates[], int numberOfVillages)
{
    for (int i = 0; i < numberOfPlayers; ++i) {
        Player *player = &players[i];
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
    RandomVillage(numberOfVillages);
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

int RandomVillage(int numberOfVillages)
{
	for (int j = 0; j < numberOfVillages; ++j) {
        POINT coordinate;

        do {
            Absis(coordinate) = (rand()*rand()) % GetMapSizeM();
            Ordinat(coordinate) = (rand()*rand()) % GetMapSizeN();
        } while (GetType(*GetGrid(Absis(coordinate), Ordinat(coordinate))) != Normal);

        GetGrid(Absis(coordinate), Ordinat(coordinate))->type = Village;
    }
}
