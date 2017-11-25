#include "Commands/attack.h"
#include "Commands/recruit.h"

int main() {
    CreateMap(4,4);



    

    Unit *attacker = CreateUnit(King, 'R', MakePOINT(2,2));
    
    RecruitUnit(&players[0], attacker);
    RecruitUnit(&players[1], CreateUnit(Archer, 'B', MakePOINT(2,1)));

    Attack(attacker);
}

