//
//  Interface.h
//  Code Projet v2
//
//  Created by Aurélien Ruppé on 15/05/2022.
//

#ifndef Interface_h
#define Interface_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    int NbBombes; // if 0 then no bomb if 1 a bomb
    int number; //you have to do a loop to know which number to display according to the bombs nearby
    int userchoice; // if 0 nothing, if 1 box discovery, if 2 marker
    int columnchoice;
    int linechoice;
} Case;


void game_creation(Case** tabCase, int l);
void display_init_board(Case** tabCase, int l);
void display_game_board(Case** tabCase, int l);
void guiness_book(float time);
void input_choice(Case** tabCase, int l);
int userchoice(int numc, int numl);
void addNbBombs(Case** tabCase, int l);

int inputinitalvalue(int l);
int inputcolumn(int l, int numc);
int inputline(int l, int numl);



#endif /* Interface_h */
