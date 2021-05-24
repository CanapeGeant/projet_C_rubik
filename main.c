#include "conio.h"
#include "fonction.h"
#include <stdio.h>

//cube[nom de la face].Tab_carre[colonne][ligne]

int main() {
    int choix, run = 1;
    Face* cube;
    cube = create_rubiks(cube);
    blank_rubiks(cube);
    while (run == 1){
        display_rubriks(cube);
        printf("Entrez le numero de l'action a realiser\n\n");
        printf(" ---------------------------------------------\n");
        printf("|  Initialiser = 1    |  Griser le cube = 2   |\n");
        printf(" ---------------------------------------------\n");
        printf("|  Melanger = 3       |  Remplire = 4         |\n");
        printf(" ---------------------------------------------\n");
        printf("|  Jouer = 5          |  Resoudre = 6         |\n");
        printf(" ---------------------------------------------\n"
               "|  Quitter = 7        |                       |\n");
        printf(" ---------------------------------------------\n\n Choix : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1:{
                init_rubiks(cube);
                break;
            }
            case 2:{
                blank_rubiks(cube);
                break;
            }
            case 3:{
                scramble_rubiks(cube);
                break;
            }
            case 4:{
                cube = fill_rubiks(cube);
                break;
            }
            case 5:{
                move_rubiks(cube);
                break;
            }
            case 6:{
                cube = croix(cube);
                display_rubriks(cube);
                break;
            }
            case 7:{
                run = 0;
                display_rubriks(cube);
                break;
            }
        }
    }

    free_rubiks(cube);
    return 0;
}
