#include "unit.h"

#include <string.h>

Unit CreateUnit(UnitClass unitClass, char color, POINT location) {
    Unit unit;

    if (unitClass == King) {
        unit = KING;
    } else if (unitClass == Archer) {
        unit = ARCHER;
    } else if (unitClass == Swordsman) {
        unit = SWORDSMAN;
    } else if (unitClass == WhiteMage) {
        unit = WHITEMAGE;
    }
    unit.color = color;
    unit.location = location;

    return unit;
}

UnitClass GetUnitClass(Unit unit) {
    return unit.unitClass;
}

char GetUnitColor(Unit unit) {
    return unit.color;
}

int GetMaximumHealth(Unit unit) {
    return unit.maximumHealth;
}

int GetHealth(Unit unit) {
    return unit.health;
}

void SetHealth(Unit *unit, int health) {
    unit->health = health;
}

int GetAttack(Unit unit) {
    return unit.attack;
}

int GetMaximumMovementPoints(Unit unit) {
    return unit.maximumMovementPoints;
}

int GetMovementPoints(Unit unit) {
    return unit.movementPoints;
}

void SetMovementPoints(Unit *unit, int movementPoints) {
    unit->movementPoints = movementPoints;
}

AttackType GetAttackType(Unit unit) {
    return unit.attackType;
}

boolean GetChanceAttack(Unit unit) {
    return unit.chanceAttack;
}

void SetChanceAttack(Unit *unit, boolean chanceAttack) {
    unit->chanceAttack = chanceAttack;
}

POINT GetLocation(Unit unit) {
    return unit.location;
}

void SetLocation(Unit *unit, POINT location) {
    unit->location = location;
}

int GetPrice(Unit unit) {
    return unit.price;
}

void UnitClassName(UnitClass unitClass, char unitClassName[]) {
    if (unitClass == King) {
        strcpy(unitClassName, "King");
    } else if (unitClass == Archer) {
        strcpy(unitClassName, "Archer");
    } else if (unitClass == Swordsman) {
        strcpy(unitClassName, "Swordsman");
    } else if (unitClass == WhiteMage) {
        strcpy(unitClassName, "White Mage");
    } else {
        strcpy(unitClassName, "Unknown");
    }
}

boolean Retaliates(Unit attacked, Unit attacker) {
    if (GetAttackType(attacked) == GetAttackType(attacker)) {
        if (GetAttack(attacked) >= GetHealth(attacker)) {
            return true;
        } else {
            return false;
        }
    } else if (GetUnitClass(attacker) == King) {
        return true;
    } else {
        return false;
    }
}