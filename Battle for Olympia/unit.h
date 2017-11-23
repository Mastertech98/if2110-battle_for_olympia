#ifndef UNIT_H
#define UNIT_H

#include "ADT/point.h"

typedef enum EUnitClass {King = 'K', Archer = 'A', Swordsman = 'S', WhiteMage = 'W'} UnitClass;
typedef enum EAttackType {Melee, Ranged} AttackType;

typedef struct SUnit {
    UnitClass unitClass;
    char color;

    int maximumHealth;
    int health;
    int attack;
    int maximumMovementPoints;
    int movementPoints;
    AttackType attackType;
    boolean chanceAttack;
    POINT location;
    int price;
} Unit;

Unit CreateUnit(UnitClass unitClass, char color, POINT location);

UnitClass GetUnitClass(Unit unit);

void UnitClassName(UnitClass unitClass, char unitClassName[]); 

boolean Retaliates(Unit attacked, Unit attacker); 

char GetUnitColor(Unit unit); 

int GetMaximumHealth(Unit unit); 

int GetHealth(Unit unit); 

void SetHealth(Unit *unit, int health); 

int GetAttack(Unit unit); 

int GetMaximumMovementPoints(Unit unit); 

int GetMovementPoints(Unit unit); 

void SetMovementPoints(Unit *unit, int movementPoints); 

AttackType GetAttackType(Unit unit); 

boolean GetChanceAttack(Unit unit); 

void SetChanceAttack(Unit *unit, boolean chanceAttack); 

POINT GetLocation(Unit unit); 

void SetLocation(Unit *unit, POINT location); 

int GetPrice(Unit unit); 

#endif