#include "map.h"
#include <stdio.h>
#include "ADT/matriks.h"

Map map;

void CreateMap(int N, int M) {
    MakeMATRIKS(&map, M, N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            POINT coordinate = MakePOINT(i, j);
            Grid *grid = GetGrid(coordinate);
            grid->coordinate = coordinate;
            grid->type = Normal;
            SetOwner(grid, NULL);
            SetUnit(grid, NULL);
        }
    }
}

void InitializeMap(int numberOfPlayers, POINT coordinates[], int numberOfVillages) {
    for (int i = 0; i < numberOfPlayers; ++i) {
        Player *player = GetPlayerFromIndex(i+1);
        Grid *grid = GetGrid(coordinates[i]);

        grid->type = Tower;
        SetOwner(grid, player);

        Grids adjacentGrids = GetAdjacentGrids(*grid);
        for (unsigned int i = 0; i < adjacentGrids.count; i++) {
            Grid *adjacentGrid = adjacentGrids.grids[i];
            adjacentGrid->type = Castle;
            SetOwner(adjacentGrid, player);
        }
    }
    RandomVillage(numberOfVillages);
}

Grid *GetGrid(POINT coordinate) {
    return &map.Mem[GetMapSizeN() * Ordinat(coordinate) + Absis(coordinate)];
}

Grids GetAdjacentGrids(Grid grid) {
    Grids adjacentGrids;
    adjacentGrids.count = 0;
    
    POINT coordinate = GetCoordinate(grid);
    int x = Absis(coordinate);
    int y = Ordinat(coordinate);

    if (x > 0) {
        adjacentGrids.grids[adjacentGrids.count++] = GetGrid(PlusDelta(coordinate, -1, 0));
    }
    if (x < GetMapSizeN() - 1) {
        adjacentGrids.grids[adjacentGrids.count++] = GetGrid(PlusDelta(coordinate, +1, 0));
    }
    if (y > 0) {
        adjacentGrids.grids[adjacentGrids.count++] = GetGrid(PlusDelta(coordinate, 0, -1));
    }
    if (y < GetMapSizeM() - 1) {
        adjacentGrids.grids[adjacentGrids.count++] = GetGrid(PlusDelta(coordinate, 0, +1));
    }

    return adjacentGrids;
}

char GetGridColor(Grid grid) {
    return GetColor(*GetOwner(grid));
}

POINT GetCoordinate(Grid grid) {
    return grid.coordinate;
}

Type GetType(Grid grid) {
    return grid.type;
}

Player *GetOwner(Grid grid) {
    return (Player*)grid.owner;
}

void SetOwner(Grid *grid, Player *owner) {
    grid->owner = owner;
}

Unit *GetUnit(Grid grid) {
    return (Unit*)grid.unit;
}

void SetUnit(Grid *grid, Unit *unit) {
    grid->unit = unit;
}

int GetMapSizeN() {
    return map.N;
}

int GetMapSizeM() {
    return map.M;
}

int RandomVillage(int numberOfVillages) {
	for (int j = 0; j < numberOfVillages; ++j) {
        POINT coordinate;

        do {
            Absis(coordinate) = (rand()*rand()) % GetMapSizeM();
            Ordinat(coordinate) = (rand()*rand()) % GetMapSizeN();
        } while (GetType(*GetGrid(coordinate)) != Normal);

        GetGrid(coordinate)->type = Village;
    }
}

boolean isValidCoordinate(int x, int y) {
    return 0 <= x && x <= GetMapSizeN() && 0 <= y && y <= GetMapSizeM();
}

boolean isOccupied(Grid grid) {
    if (GetUnit(grid)) {
        return true;
    } else {
        return false;
    }
}

boolean isOccupiedByAlly(Grid grid, char color) {
    Unit *unit = GetUnit(grid);
    if (unit) {
        if (GetUnitColor(*unit) == color) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}