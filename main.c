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



    c_textcolor(BLACK);
    printf("chips au poulet ");
    c_textcolor(BLUE);
    printf(" trompettiste ");
    c_textcolor(GREEN);
    printf(" Jean SOMA ");
    c_textcolor(CYAN);
    printf(" Saumon ");
    c_textcolor(RED);
    printf(" Quagsire ");
    c_textcolor(MAGENTA);
    printf(" Jus d'orange ");
    c_textcolor(BROWN);
    printf(" Etagere ");
    c_textcolor(LIGHTGRAY);
    printf(" J'aime pas ");
    c_textcolor(DARKGRAY);
    printf(" le langage C ");
    c_textcolor(LIGHTBLUE);
    printf(" a cause des points-virgules ");
    c_textcolor(LIGHTGREEN);
    printf(" Lavabo ");
    c_textcolor(LIGHTCYAN);
    printf(" Quagsire ");
    c_textcolor(LIGHTRED);
    printf(" Manger, c'est bien ");
    c_textcolor(LIGHTMAGENTA);
    printf("♦");
    c_textcolor(YELLOW);
    printf(" Pourquoi les profs nous laissent si peu de temps pour les projet ");
    c_textcolor(WHITE);
    printf(" Pourquoi les profs nous donnent tous les projet d'un coup ");
    c_textcolor(BLINK);
    printf(" J'ai plus d'inspi pour le nom de cette couleur");

    return 0;
}
