//
//  SaisirValeurs.c
//  Code Projet v2
//
//  Created by Aurélien Ruppé on 24/05/2022.
//

#include "SaisirValeurs.h"
#include <stdio.h>
#include <stdlib.h>

int saisirvaleurintiale(int l) {
    do{
        scanf("%d", &l);
        if(l != 9 && l != 16 ){
            if (l != sizeof(int)){
                printf("vous avez saisi une mauvaise valeur, veuillez recommencer. \n");
                fflush(stdin); // Vide les données erronées  restées dans la mémoire tampon car ce tri n'est pas pris en charge par le scanf, cela permet de ne pas faire tourner la boucle à l'infini lorsque l'on saisit une valeur différente d'un type int. Si ce n'est toujours pas clair pour vous, cela permet de faire fonctionner scanf à chaque tour de boucle lorsque la valeur saisit est différent d'un entier.
            }
        }
    } while (l != 9 && l != 16 );
    return (l);
}

int saisircolonne(int l, int numc) {
    do {
        fflush(stdout);
        scanf("%d", &numc);
        if (numc <=0 || numc > l) {
            if (numc != sizeof(int)){
                printf("vous avez saisi une mauvaise valeur, veuillez recommencer. \n");
               fflush(stdin);
          }
        }
    } while (numc <= 0 || numc > l);
    return (numc);
}

int saisirligne(int l, int numl) {
    do {
        fflush(stdout);
        scanf("%d", &numl);
        if (numl <=0 || numl > l) {
            if (numl != sizeof(int)){
                printf("vous avez saisi une mauvaise valeur, veuillez recommencer. \n");
               fflush(stdin);
          }
        }
    } while (numl <= 0 || numl > l);
    return (numl);
}

int verifok(int a, int min, int max) {
    do {
        scanf("%d", &a);
        if (a != min && a != max) {
            if (a != sizeof(int)){
                printf("vous avez saisi une mauvaise valeur, veuillez recommencer. \n");
                fflush(stdin);
            }
        }
    } while (a != min && a != max);
    return a;
}

