//
//  CreationBombes.c
//  Code Projet v2
//
//  Created by Aurélien Ruppé on 16/05/2022.
//

#include "CreationBombes.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
void placer_bombe9(char Mines[9][9], int NbMines) {
    int i = 9;
    int j = 9;
    srand(time(NULL));
    for (int CompteMines = 0; CompteMines < NbMines; CompteMines++) {
        i = rand()%10;//on choisit la ligne de manière aléatoire
        j = rand()%10;//on choisit la colonne de manière aléatoire
        if(Mines[i][j] == '-') { //On vérifie que la case est libre
            Mines[i][j] = 'M';//on place un M pour indiquer qu'il y a une mine
        }
        else {
            Mines++;//Sinon, il y a déjà un M et il faut faire un tour de plus
            }
        }
        
    //Pour vérifier on affiche la grille des mines
    printf("Voici la grille des mines :\n");
    for(i = 0; i < 13; i++) {
        for(j = 0; j < 9; j++) {
            printf("%c ", Mines[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}*/
/*
void placer_bombe16(char Mines[i][j], int NbMines) {
    for (int CompteMines = 0; CompteMines < NbMines; CompteMines++) {
        i = rand()%16;//on choisit la ligne de manière aléatoire
        j = rand()%16;//on choisit la colonne de manière aléatoire
        if(Mines[i][j] == '0') { //On vérifie que la case est libre
            Mines[i][j] = 'M';//on place un M pour indiquer qu'il y a une mine
        }
        else {
            Mines++;//Sinon, il y a déjà un M et il faut faire un tour de plus
            }
        }
        
    //Pour vérifier on affiche la grille des mines
    printf("Voici la grille des mines :\n");
    for(i=0;i<10;i++) {
        for(j=0;j<10;j++) {
            printf("%c  ",Mines[i][j]);
        }
        printf("\n");
    }
}
*/
