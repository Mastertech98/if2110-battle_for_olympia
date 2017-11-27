#include "end_turn.h"
#include "../ADT/queue.h"
#include "../ADT/matriks.h"
#include "../ADT/boolean.h"
#include "../unit.h"
#include "../map.h"
#include "../player.h"
#include "changeunit.h"

Queue turn;

Unit FindKing(){
	Unit *kingUnit;
	kingUnit = (Unit *) Info(First(GetUnits(*GetCurrentPlayer())));
	return *kingUnit;
}
void CreateQueue(int numberOfPlayers){
	CreateEmpty(&turn,numberOfPlayers);
}
void InitializeQueue(int numberOfPlayers){
	for(int i=1;i<=numberOfPlayers;i++){
		Add(&turn,i);
	}
}
void EndTurn(){
	infotypeQueue tempQ; 
	Del(&turn,&tempQ);
	Add(&turn,tempQ);
	SetSelectedUnit(FindKing());
}

Player *GetCurrentPlayer(){
	return &players[InfoHead(turn)];
}
