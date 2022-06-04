//
//  Interface.c
//  Code Projet v2
//
//  Created by Aurélien Ruppé on 15/05/2022.
//

#include "Interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// mettre une condition pour que la prmière case soit toujours bonne
// générer une première grille avec rien dedans et à partir du premier tour générer les bombes
// générer les bombes et ensuite les mettre dans la structure
// mettre bombescachée en 0 automatiquement comme ça on print des "-"



void AffichePlateauDebut(Case** tabCase, int l) {
    printf("   |");
    for (int i = 0; i < l; i++) {
        printf(" %c", i + 65);
    }
    printf("\n___|");
    for (int i = 0; i < (2 * l); i++) {
        printf("_");
    }
    printf("\n");
    int c = 0;
    for (int i = 0; i < l; i++) {
        if (c < 9) {
            c = c + 1;
            printf("%d  |", c);
        }
        else {
            c = c + 1;
            printf("%d |", c);
        }
        for (int j = 0; j < l; j++) {
            if (tabCase[i][j].NbBombes == 1) {
                printf(" X");
            }
            else if(tabCase[i][j].Chiffre == 2) {
                tabCase[i][j].casevisible = 1;
                printf(" 2");
            }
            else {
                printf(" -");
            }
        }
    printf("\n");
    }
//        faire des cases et break si jamais une bombe a pété
}




void CréationJeu(Case** tabCase, int l) {
    if (tabCase == NULL) {
        printf("Erreur lors de l'allocation du tableau de case \n");
        exit(1);
    }
    
//    placement des mines
    srand(time(NULL));
    int NbMines;
    int nbmarqueurs;
    if (l == 9) {
        NbMines = 10;
        nbmarqueurs = 10;
    }
    else if (l == 16) {
        NbMines = 40;
        nbmarqueurs = 40;
    }
    else {
        NbMines = 13;
        nbmarqueurs = 13;
    }
    
    for (int CompteMines = 0; CompteMines < NbMines; CompteMines++) {
        int i,j;
        i = rand()%(l - 1) + 1;
        j = rand()%(l - 1) + 1;
        tabCase[i][j].NbBombes = 1; //on place un 1 pour indiquer qu'il y a une mine
        int a = i - 1;
        int c = i + 1;
        int b = j - 1;
        int d = j + 1;
        tabCase[i][b].Chiffre = 2;
        for (a; a <= (i + 1); a++ ) {
            tabCase[i][d].Chiffre = 2;
            for (b; b <= (j + 1); b++) {
                tabCase[a][b].Chiffre = 2;
            }
        }
        for (b; b <= (j + 1); b++) {
            tabCase[i + 1][b].Chiffre = 2;
        }
        
/*        tabCase[a][j].Chiffre = 2;
        tabCase[a][d].Chiffre = 2;
        
        for (a; a <= c; a++) {
//            tabCase[a][d].Chiffre = 2;
            tabCase[i][b].Chiffre = 2;
            for (b; b < d; b++) {
//                tabCase[a][d].Chiffre = 2;
//                tabCase[a][j].Chiffre = 2;
            }
        }*/
        
        
        /*
        for (b; b <= d; b ++) {
            tabCase[a][b].Chiffre = 2;
        }
        for (b; b <= d; b ++) {
            tabCase[i][b].Chiffre = 2;
        }
        for (b; b <= d; b ++) {
            tabCase[c][b].Chiffre = 2;
        }*/
//            printf("%d (%d, %d)\n", i, a, b);
        }
    AffichePlateauDebut(tabCase, l);
    printf("\n");
}

int choixutilisateur(int numc, int numl) {
    int choix = 0;
    printf("Que voulez-vous faire ?\n");
    printf("\t1. Placer un marqueur de bombe (tapez 1) \n");
    printf("\t2. Découvrir une case (tapez 2) \n");
    do {
        scanf("%d", &choix);
        if (choix != 1 && choix != 2) {
            printf("Veuillez saisir une valeur demandée s'il vous plaît \n");
            fflush(stdin);
        }
    } while (choix != 1 && choix != 2);
    return choix;
}


/*
void AffichePlateauJeu(Case** tabCase, int l, int choix, int numc, int numl) {
    printf("   |");
    for (int i = 0; i < l; i++) {
        printf(" %c", i + 65);
    }
    printf("\n___|");
    for (int i = 0; i < (2 * l); i++) {
        printf("_");
    }
    printf("\n");
    int c = 0;
    for (int i = 0; i < l; i++) {
        if (c < 9) {
            c = c + 1;
            printf("%d  |", c);
        }
        else {
            c = c + 1;
            printf("%d |", c);
        }
        for (int j = 0; j < l; j++) {
            if (i == numc || j == numl) {
                if (choix == 1) {
                    printf(" $");
                }
                else if (choix == 2) {
                    tabCase[i][j].casevisible = 1;
                }
            }
            else if (tabCase[i][j].casevisible == 1) {
                if (tabCase[i][j].NbBombes == 1) {
                    printf("Vous avez perdu ! ");
                    exit(2);
                }
                else {
                    printf(" %d", tabCase[i][j].Chiffre);
                }
            }
            else {
                printf(" -");
            }
        }
    printf("\n");
    }
//        faire des cases et break si jamais une bombe a pété
}*/
