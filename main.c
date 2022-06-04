//
//  main.c
//  Code Projet v2
//
//  Created by Aurélien Ruppé on 12/05/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "Interface.h"
#include "MessageBienvenue.h"
#include "SaisirValeurs.h"
#include "temps.h"

// /!\ faire les tests !!!!!!

int main(int argc, const char * argv[]) {
    affichemessagebvn();
    int l = 0;

    printf("Veuillez saisir le nombre de lignes que vous souhaitez (9 ou 16) : \n");
    l = saisirvaleurintiale(l);
    printf("\n");
   
    
//    allocation dynamique du tableau
    Case** tabCase = NULL;
    tabCase = malloc(l * sizeof(Case*));
    for (int i = 0; i < l; i++) {
        tabCase[i] = malloc(l * sizeof(Case));
        for (int j = 0; j < l; j++) {
            tabCase[i][j].casevisible = 0;
            tabCase[i][j].BombesCachée = 0;
            tabCase[i][j].NbBombes = 0;
            tabCase[i][j].Chiffre = 1;
        }
    }
//    fin allocation dynamique du tableau
    
//    affichage de la grille de départ
    CréationJeu(tabCase, l);
    
//    l'utilisateur entre la colonne puis la ligne sur laquelle il veut jouer
    
    int a = 0;
    printf("Veuillez saisir le numéro de la colonne avec laquelle vous voulez intéragir \n");
    a = saisircolonne(l, a);
    printf("affichage de a : ");
    printf("%d\n\n", a);
    int b = 0;
    printf("Veuillez saisir le numéro de la ligne avec laquelle vous voulez intéragir \n");
    b = saisirligne(l, b);
    printf("%d\n\n", b);
    
    
    int choix = choixutilisateur(a, b);
    
//    AffichePlateauJeu(tabCase, l, choix, numc, numl);
    
    
    
    
    printf("\n");
    
    return 0;
}
