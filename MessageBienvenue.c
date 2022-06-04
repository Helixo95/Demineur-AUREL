//
//  MessageBienvenue.c
//  Code Projet v2
//
//  Created by Aurélien Ruppé on 24/05/2022.
//

#include "MessageBienvenue.h"
#include <stdio.h>

void affichemessagebvn() {
    //Afficher le début du jeu
    for (int a = 0; a < 33; a++){
        printf("-");
    }
    printf("\n");
    printf("Bienvenue dans le jeu du démineur\n");
    for (int a = 0; a < 33; a++){
        printf("_");
    }
    printf("\n\n\n");
}
