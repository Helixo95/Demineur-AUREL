//
//  MessageBienvenue.c
//  Code Projet v2
//
//  Created by Aurélien Ruppé on 24/05/2022.
//

#include "MessageBienvenue.h"
#include <stdio.h>

void welcomingmessage() {
    //Afficher le début du jeu
    for (int a = 0; a < 27; a++){
        printf("-");
    }
    printf("\n");
    printf("Welcome to the deminer game\n");
    for (int a = 0; a < 27; a++){
        printf("_");
    }
    printf("\n\n\n");
}
