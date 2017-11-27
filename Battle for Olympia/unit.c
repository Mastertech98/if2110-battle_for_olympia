#include "unit.h"

#include <string.h>

/* Inisialisasi constant */
const Unit KING = {
    .unitClass = King,

    .maximumHealth = 14,
    .health = 14,
    .attack = 4,
    .maximumMovementPoints = 4,
    .movementPoints = 2,
    .attackType = Melee,
    .chanceAttack = true,
    .price = 0
};
const Unit ARCHER = {
    .unitClass = Archer,

    .maximumHealth = 10,
    .health = 10,
    .attack = 6,
    .maximumMovementPoints = 3,
    .movementPoints = 0,
    .attackType = Ranged,
    .chanceAttack = true,
    .price = 8
};
const Unit SWORDSMAN = {
    .unitClass = Swordsman,

    .maximumHealth = 50,
    .health = 16,
    .attack = 8,
    .maximumMovementPoints = 4,
    .movementPoints = 0,
    .attackType = Melee,
    .chanceAttack = true,
    .price = 8
};
const Unit WHITEMAGE = {
    .unitClass = WhiteMage,

    .maximumHealth = 8,
    .health = 8,
    .attack = 2,
    .maximumMovementPoints = 2,
    .movementPoints = 0,
    .attackType = Melee,
    .chanceAttack = true,
    .price = 10
};

Unit *CreateUnit(UnitClass unitClass, char color, POINT location) 
/* Mengembalikan alamat unit baru yang telah dialokasi di memory */
{
    Unit *unit = (Unit *) malloc (sizeof(Unit));
    
    if (unitClass == King) {
        *unit = KING;
    } else if (unitClass == Archer) {
        *unit = ARCHER;
    } else if (unitClass == Swordsman) {
        *unit = SWORDSMAN;
    } else if (unitClass == WhiteMage) {
        *unit = WHITEMAGE;
    }
    (*unit).color = color;
    (*unit).location = location;

    return unit;
}

void DestroyUnit (Unit *unit)
/* I.S. : unit terdifinisi */
/* F.S. : memory yang digunakan unit dikembalikan ke sistem */ 
{
    free(unit);
}

UnitClass GetUnitClass(Unit unit) 
/* Mengembalikan UnitClass dari sebuah unit */
{
    return unit.unitClass;
}

void UnitClassName(UnitClass unitClass, char unitClassName[]) 
/* I.S. : sembarang */
/* F.S. : unitClassName adalah unitClassName dari unitClass */
{
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

boolean Retaliates(Unit attacked, Unit attacker) 
/* Mengembalikan apakah unit tersebut melakukan retaliates atau tidak */
/* true jika melakukan false jika tidak */
{
    
    if (GetAttack(attacker) < GetHealth(attacked)) {
        if (GetUnitClass(attacker) == King) {
            return true;
        } else {
            if (GetAttackType(attacked) == GetAttackType(attacker)) {
                return true;
            } else {
                return false;
            }
        }
    } else {
        return false;
    }
}

char GetUnitColor(Unit unit) 
/* Mengembalikan warna dari sebuah unit */
{
    return unit.color;
}

int GetMaximumHealth(Unit unit) 
/* Mengembalikan maximumHealth dari sebuah unit */
{
    return unit.maximumHealth;
}

int GetHealth(Unit unit) 
/* Mengembalikan health yang dimimliki unit */
{
    return unit.health;
}

void SetHealth(Unit *unit, int health) 
/* I.S. = Unit terdefinisi dan health adalah health yang akan dimasukkan */
/* F.S. = Health dari unit akan menjadi parameter input health */
{
    unit->health = health;
}

int GetAttack(Unit unit) 
/* Mengembalikan attribut attack unit */
{
    return unit.attack;
}

int GetMaximumMovementPoints(Unit unit) 
/* Mengembalikan atribut maximum movement points dari unit */
{
    return unit.maximumMovementPoints;
}

int GetMovementPoints(Unit unit) 
/* Mengembalikan movement points yang dimiliki unit */
{
    return unit.movementPoints;
}

void SetMovementPoints(Unit *unit, int movementPoints) 
/* I.S. : unit terdefinisi */
/* F.S. : movementPoints yang dimiliki unit akan diset dengan parameter input */
{
    unit->movementPoints = movementPoints;
}

AttackType GetAttackType(Unit unit) 
/* Mengembalikan attack type dari unit */
{
    return unit.attackType;
}

boolean GetChanceAttack(Unit unit) 
/* Mengembalikan true jika unit bisa melakukan attack dan false jika tidak bisa */
{
    return unit.chanceAttack;
}

void SetChanceAttack(Unit *unit, boolean chanceAttack) 
/* I.S. : unit terdefinisi */
/* F.S. : ChanceAttack unit akan diset dengan parameter input chanceAttack */
{
    unit->chanceAttack = chanceAttack;
}

POINT GetLocation(Unit unit) 
/* Mengembalikan location dari unit dalam tipe bentukan point */
{
    return unit.location;
}

void SetLocation(Unit *unit, POINT location) 
/* I.S. : Unit terdefinisi */
/* F.S. : Location dari unit akan diset dengan parameter input location */
{
    unit->location = location;
}

int GetPrice(Unit unit) 
/* Mengembalikan price dari unit */
{
    return unit.price;
}