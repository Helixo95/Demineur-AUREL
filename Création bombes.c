//
//  Création bombes.c
//  Code Projet v2
//
//  Created by Aurélien Ruppé on 16/05/2022.
//

#include "Création bombes.h"
#include "Interface.h"
#include <stdlib.h>
#include <time.h>

void placer_bombes(int plateau[9][9]) {
    int a = 0;
    for (int i = 4; i < 18; i+2) {
        printf ("~");
        a = a + 1;
    }
    affiche_plateau(plateau);
}
