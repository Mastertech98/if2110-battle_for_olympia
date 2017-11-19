#include "unit.h"

#include <string.h>

Unit CreateUnit(UnitClass unitClass, char color, POINT location) {
    if (unitClass == King) {
        Unit unit = {
            .unitClass = unitClass,
            .color = color,

            .maximumHealth = 50,
            .health = 50,
            .attack = 50,
            .maximumMovementPoints = 5,
            .movementPoints = 5,
            .attackType = Melee,
            .chanceAttack = true,
            .location = location,
            .price = 0
        };
        return unit;
    } else if (unitClass == Archer) {
        Unit unit = {
            .unitClass = unitClass,
            .color = color,

            .maximumHealth = 20,
            .health = 20,
            .attack = 5,
            .maximumMovementPoints = 3,
            .movementPoints = 0,
            .attackType = Ranged,
            .chanceAttack = true,
            .location = location,
            .price = ArcherPrice
        };
        return unit;
    } else if (unitClass == Swordsman) {
        Unit unit = {
            .unitClass = unitClass,
            .color = color,

            .maximumHealth = 30,
            .health = 30,
            .attack = 4,
            .maximumMovementPoints = 5,
            .movementPoints = 0,
            .attackType = Melee,
            .chanceAttack = true,
            .location = location,
            .price = SwordsmanPrice
        };
        return unit;
    } else if (unitClass == WhiteMage) {
        Unit unit = {
            .unitClass = unitClass,
            .color = color,

            .maximumHealth = 20,
            .health = 20,
            .attack = 3,
            .maximumMovementPoints = 2,
            .movementPoints = 0,
            .attackType = Melee,
            .chanceAttack = true,
            .location = location,
            .price = WhiteMagePrice
        };
        return unit;
    } else {
        Unit unit;
        return unit;
    }
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