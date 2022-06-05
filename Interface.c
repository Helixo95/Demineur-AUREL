//
//  Interface.c
//  Code Projet v2
//
//  Created by Aurélien Ruppé on 15/05/2022.
//

#include "Interface.h"

void display_init_board(Case** tabCase, int l) { //displays the initial board
    printf("   |");
    for (int i = 0; i < l; i++) {
        printf(" %c", i + 65);
    }
    printf("\n___|");
    for (int i = 0; i < (2 * l); i++) {
        printf("_");
    }
    printf("\n");
    int c = 1;
    for (int i = 0; i < l; i++) {
        if (c < 10) {
            printf("%d  |", c);
            c = c + 1;
        }
        else {
            printf("%d |", c);
            c = c + 1;
        }
        for (int j = 0; j < l; j++) {
                printf(" -");
        }
        printf("\n");
    }
    printf("\n");
}

void display_game_board(Case** tabCase, int l) { //displays the board based on what's in the structure
    printf("   |");
    int discoverybomb = 0;
    for (int i = 0; i < l; i++) {
        printf(" %c", i + 65);
    }
    printf("\n___|");
    for (int i = 0; i < (2 * l); i++) {
        printf("_");
    }
    printf("\n");
    int c = 1;
    for (int i = 0; i < l; i++) {
        if (c < 10) {
            printf("%d  |", c);
            c = c + 1;
        }
        else {
            printf("%d |", c);
            c = c + 1;
        }
        for (int j = 0; j < l; j++) {
            if (tabCase[i][j].userchoice == 2) {
                if (tabCase[i][j].NbBombes == 1) {
                    printf(" X");
                    discoverybomb++;
                }
                else if(tabCase[i][j].number == 6) {
                    printf(" 6");
                }
                else if(tabCase[i][j].number == 5) {
                    printf(" 5");
                }
                else if(tabCase[i][j].number == 4) {
                    printf(" 4");
                }
                else if(tabCase[i][j].number == 3) {
                    printf(" 3");
                }
                else if(tabCase[i][j].number == 2) {
                    printf(" 2");
                }
                else if(tabCase[i][j].number == 1) {
                    printf(" 1");
                }
                else {
                    printf(" 0");
                }
            }
            else if (tabCase[i][j].userchoice == 1) {
                printf(" D");
            }
            else {
                printf(" -");
            }
        }
        printf("\n");
    }
    if (discoverybomb == 1) {
        printf("BOUM. TRY AGAIN! \n");
        exit(4);
    }
    printf("\n");
}


void game_creation(Case** tabCase, int l) { //allows you to play, lists all the functions
    //time function
    float temps = 0;
    clock_t t1, t2;
    t1 = clock();
    //dynamic allocation check
    if (tabCase == NULL) {
        printf("Error allocating case array \n");
        exit(1);
    }
//    mine placement
    srand(time(NULL));
    int NbMines;
    if (l == 9) {
        NbMines = 10;
    }
    else if (l == 16) {
        NbMines = 40;
    }
    for (int countMine = 0; countMine < NbMines; countMine++) {
        int i,j;
        i = rand()%l; //we choose the line randomly
        j = rand()%l; //we choose the column randomly
        if (tabCase[i][j].NbBombes == 0) { // this loop allows to see if there is already a mine. If there is one, we remove a mine count or add a nbmines to redo the loop in order to have the right number of mines without them overlapping
            tabCase[i][j].NbBombes = 1; //a 1 is placed to indicate that there is a mine
        }
        else {
//            NbMines++; //also work
            countMine--;
        }
    }
    addNbBombs(tabCase, l);
    display_init_board(tabCase, l);
    for (int f = 0; f < ((l * l) - NbMines); f++) {
        input_choice(tabCase, l);
        display_game_board(tabCase, l);
        if (f == ((l * l) - NbMines)) {
            printf("You won ! \n");
            t2 = clock();
            temps = ((float)(t2-t1)/CLOCKS_PER_SEC) * 10000;
            printf("temps = %f secondes\n", temps);
            guiness_book(temps);
            exit(5);
        }
    }
    printf("\n");
    //end of time
    t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("temps = %f\n", temps);
}

void guiness_book(float time) { // end of the game
    FILE* guiness = NULL; // file pointer
    char nom[256]; // contains the name of the player
    int sc = 0; //use to test scanf
    int c = EOF + 1; // use to print the file
    if(time < 0) { // test the setting
        printf("time error \n");
        exit(0);
    }
    guiness = fopen("guiness.txt", "r+"); // opens the file
    if(guiness == NULL) { // test if the file was opened
        printf("openning file error \n");
        exit(1);
    }
    printf("\n please enter your name : "); // ask the user to enter his name
    sc = scanf("%s", nom);
    if(sc != 1) { // test if scanf worked
        printf("error scanf\n");
        exit(2);
    }
    fseek(guiness, 0, SEEK_END); // put the cursor at the end of the file to add the new name and time
    fprintf(guiness, "\nname %s / time: %f seconds",nom, time);
    rewind(guiness); // cursor at the beggining to print the file
    while(c != EOF) {
        printf("%c",c);
        c = fgetc(guiness);
        if(c == EOF) { // test an fgetc error
            if(feof(guiness)) { // if c is EOF
                break;
            }
            else { // if there is an error
                printf("fgetc error \n");
                exit(1);
            }
        }
    }
    printf("\n\nthanks to playing our game ! \n");
    fclose(guiness); // close the file
    exit(0);
}




void input_choice(Case** tabCase, int l) { //allows to enter the choice and calls the userchoice function
    int b = 0;
    printf("Veuillez saisir le numéro de la colonne avec laquelle vous voulez intéragir \n");
    b = inputcolumn(l, b) - 1; //we remove 1 like that we display well between 0 and 8 inclusive
    int a = 0;
    printf("Veuillez saisir le numéro de la ligne avec laquelle vous voulez intéragir \n");
    a = inputline(l, a) - 1;
    int choix = userchoice(a, b);
    for(int c = 0; c < l; c++) {
         if (a == c) {
             for (int d = 0; d < l; d++) {
                 if (b == d) {
                     tabCase[a][b].userchoice = choix; //enters the choice into the structure
                     tabCase[a][b].columnchoice = a;
                     tabCase[a][b].linechoice = b;
                 }
             }
         }
     }
}


int userchoice(int numc, int numl) { //check that the choice is indeed 1 or 2
    int choix = 0;
    printf("What do you want to do ?\n");
    printf("\t1. Place a bomb marker which will show as a D (type 1) \n");
    printf("\t2. Uncover a square (type 2) \n");
    do {
        scanf("%d", &choix);
        if (choix != 1 && choix != 2) {
            printf("vyou have entered a wrong value, please restart the program by entering a good value (1 or 2). \n");
            fflush(stdin);
            exit(2);
        }
    } while (choix != 1 && choix != 2);
    return choix;
}



void addNbBombs(Case** tabCase, int l) { //used to add numbers around the bombs according to the number of bombs around
    int bombcounter = 0;
    //we will loop for each row and each column
    for (int x = 0; x < l; x++) {
        for (int y = 0; y < l; y++) {
            bombcounter = 0;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (((x + dx) >= 0) && ((y + dy) >= 0) && ((x + dx) < l) && ((y + dy) < l)) {
                        if(tabCase[x + dx][y + dy].NbBombes == 1) {
                            bombcounter++;
                        }
                    }
                }
            }
            tabCase[x][y].number = bombcounter;
        }
    }
}


// input value

int inputinitalvalue(int l) { //verifies the integrity of the tray size
    do{
        scanf("%d", &l);
        if(l != 9 && l != 16 ){
            if (l != sizeof(int) || l == 4){ // we don't know why but when we enter 4, we are not asked to re-enter the value of l
                printf("you entered a wrong value, please restart the program by entering a good value (9 or 16). \n");
                fflush(stdin); // Empties the erroneous data remaining in the buffer memory because this sorting is not supported by the scanf, this makes it possible not to run the loop ad infinitum when entering a value other than an int type. If it's still not clear to you, this makes scanf work on every round of the loop when the value grabbed is different from an integer.
                exit(1);
            }
        }
    } while (l != 9 && l != 16 );
    return (l);
}

int inputcolumn(int l, int numc) { //checks that the user has entered what was requested
    do {
        fflush(stdout);
        scanf("%d", &numc);
        if (numc <=0 || numc > l) {
            if (numc != sizeof(int)){
                printf("you have entered a wrong value, please restart the program by entering a good value. \n");
                fflush(stdin);
                exit(2);
          }
        }
    } while (numc <= 0 || numc > l);
    return (numc);
}

int inputline(int l, int numl) { //checks that the user has entered what was requested
    do {
        fflush(stdout);
        scanf("%d", &numl);
        if (numl <=0 || numl > l) {
            if (numl != sizeof(int)){
                printf("you have entered a wrong value, please restart the program by entering a good value. \n");
                fflush(stdin);
                exit(3);
          }
        }
    } while (numl <= 0 || numl > l);
    return (numl);
}

