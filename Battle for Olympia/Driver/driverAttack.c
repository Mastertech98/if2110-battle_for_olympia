#include "../Commands/attack.h"

#include <stdio.h>

int main() {
    char colors[] = {'R', 'B'};
    POINT coordinates[] = {MakePOINT(1,8), MakePOINT(8,1)};

    CreateMap(10, 10);
    CreatePlayers(2, colors);

    Unit *attacker = CreateUnit(King, 'R', MakePOINT(2, 2));
    Unit *enemy1 = CreateUnit(Archer, 'B', MakePOINT(2, 1));
    Unit *enemy2 = CreateUnit(Swordsman, 'B', MakePOINT(1, 2));
    Unit *enemy3 = CreateUnit(WhiteMage, 'B', MakePOINT(4, 4));
    Unit *allies = CreateUnit(Swordsman, 'R', MakePOINT(2,3));
    
    AddUnit(GetPlayer('R'), attacker);
    SetUnit(GetGrid(2, 2), attacker);

    AddUnit(GetPlayer('R'), allies);
    SetUnit(GetGrid(2, 3), allies);

    AddUnit(GetPlayer('B'), enemy1);
    SetUnit(GetGrid(2, 1), enemy1);

    AddUnit(GetPlayer('B'), enemy2);
    SetUnit(GetGrid(1, 2), enemy2);

    AddUnit(GetPlayer('B'), enemy3);
    SetUnit(GetGrid(4, 4), enemy3);

    SetHealth(enemy1, 2);

    printf("Health attacker: %d\n", GetHealth(*attacker));
    printf("Health enemy1: %d\n", GetHealth(*enemy1));
    printf("Health enemy2: %d\n", GetHealth(*enemy2));
    printf("Health enemy3: %d\n", GetHealth(*enemy3));

    Attack(attacker);

    printf("Health attacker: %d\n", GetHealth(*attacker));
    printf("Health enemy1: %d\n", GetHealth(*enemy1));
    printf("Health enemy2: %d\n", GetHealth(*enemy2));
    printf("Health enemy3: %d\n", GetHealth(*enemy3));
}

