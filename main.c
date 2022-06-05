//
//  main.c
//  Code Projet v2
//
//  Created by Aurélien Ruppé on 12/05/2022.
//

#include "Interface.h"
#include "MessageBienvenue.h"

int main(int argc, const char * argv[]) {
    welcomingmessage();
    int l = 0;
    printf("Please enter the number of lines you want (9 or 16) : \n");
    l = inputinitalvalue(l);
    printf("\n");
    
//    beginning dynamic array allocation
    Case** tabCase = NULL;
    tabCase = malloc(l * sizeof(Case*));
    for (int i = 0; i < l; i++) {
        tabCase[i] = malloc(l * sizeof(Case));
        for (int j = 0; j < l; j++) {
            tabCase[i][j].NbBombes = 0;
            tabCase[i][j].number = 0;
            tabCase[i][j].userchoice = 0;
        }
    } //    end of dynamic array allocation
    
//    starting grid display
    game_creation(tabCase, l);
    printf("\n");
    return 0;
}
