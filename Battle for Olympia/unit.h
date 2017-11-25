/* File : unit.h */
/* Deklarasi tipe bentukan unit yang akan dipakai */
/* ADT untuk mengakses hal yang berhubungan dengan unit */

#ifndef UNIT_H
#define UNIT_H

#include "ADT/point.h"

#include <stdlib.h>

typedef enum EUnitClass {
    King = 'K', 
    Archer = 'A', 
    Swordsman = 'S', 
    WhiteMage = 'W',
    Movement = '#', 
    None = ' '
} UnitClass;
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

/* Deklarasi Konstanta unit-unit untuk implementasi beberapa fungsi */
const Unit KING;
const Unit ARCHER;
const Unit SWORDSMAN;
const Unit WHITEMAGE;

/******** CONSTRUCTOR/DESTRUCTOR ********/
Unit *CreateUnit(UnitClass unitClass, char color, POINT location);
/* Mengembalikan alamat unit baru yang telah dialokasi di memory */

void DestroyUnit (Unit *unit);
/* I.S. : unit terdifinisi */
/* F.S. : memory yang digunakan unit dikembalikan ke sistem */ 

/******** SELECTOR ********/
UnitClass GetUnitClass(Unit unit);
/* Mengembalikan UnitClass dari sebuah unit */

char GetUnitColor(Unit unit);
/* Mengembalikan warna dari sebuah unit */

int GetMaximumHealth(Unit unit); 
/* Mengembalikan maximumHealth dari sebuah unit */

int GetHealth(Unit unit); 
/* Mengembalikan health yang dimimliki unit */

void SetHealth(Unit *unit, int health); 
/* I.S. = Unit terdefinisi dan health adalah health yang akan dimasukkan */
/* F.S. = Health dari unit akan menjadi parameter input health */

int GetAttack(Unit unit); 
/* Mengembalikan attribut attack unit */

int GetMaximumMovementPoints(Unit unit);
/* Mengembalikan atribut maximum movement points dari unit */ 

int GetMovementPoints(Unit unit); 
/* Mengembalikan movement points yang dimiliki unit */

void SetMovementPoints(Unit *unit, int movementPoints); 
/* I.S. : unit terdefinisi */
/* F.S. : movementPoints yang dimiliki unit akan diset dengan parameter input */

AttackType GetAttackType(Unit unit); 
/* Mengembalikan attack type dari unit */

boolean GetChanceAttack(Unit unit); 
/* Mengembalikan true jika unit bisa melakukan attack dan false jika tidak bisa */

void SetChanceAttack(Unit *unit, boolean chanceAttack); 
/* I.S. : unit terdefinisi */
/* F.S. : ChanceAttack unit akan diset dengan parameter input chanceAttack */

POINT GetLocation(Unit unit); 
/* Mengembalikan location dari unit dalam tipe bentukan point */

void SetLocation(Unit *unit, POINT location); 
/* I.S. : Unit terdefinisi */
/* F.S. : Location dari unit akan diset dengan parameter input location */

int GetPrice(Unit unit); 
/* Mengembalikan price dari unit */

/******** OTHER ********/
void UnitClassName(UnitClass unitClass, char unitClassName[]); 
/* I.S. : sembarang */
/* F.S. : unitClassName adalah unitClassName dari unitClass */

boolean Retaliates(Unit attacked, Unit attacker); 
/* Mengembalikan apakah unit tersebut melakukan retaliates atau tidak */
/* true jika melakukan false jika tidak */

#endif
