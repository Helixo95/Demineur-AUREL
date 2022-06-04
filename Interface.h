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

typedef struct {
    int NbBombes; // si 0 alors pas de bombe si 1 une bombe
    int BombesCachée; // si 0 alors bombe cachée si 1 bombe découverte => fin du jeu
    int Chiffre; //il faut faire une boucle pour savoir quel chiffre afficher en fonction des bombes à proximité
    int casevisible; // permet de savoir si on affiche ou non la case
    int marqueur; // permet de déposer un marqueur de bombe
} Case;


void CréationJeu(Case** tabCase, int l);
void AffichePlateauDebut(Case** tabCase, int l);
//void AffichePlateauJeu(Case** tabCase, int l, int choix, int numc, int numl);
int choixutilisateur(int numc, int numl);

//void intialisationplateau(Case** tabCase);


#endif /* Interface_h */
