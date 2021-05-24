//
// Created by 974cc on 24/05/2021.
//

#include "fonction.h"
#include <stdlib.h>
#include <stdio.h>
#include "conio.h"

T_COLOR ref_select_color(int n){
    if (n == 0)
        return W;
    if (n == 1)
        return O;
    if (n == 2)
        return G;
    if (n == 3)
        return R;
    if (n == 4)
        return B;
    if (n == 5)
        return Y;
    if (n == 6)
        return LG;
}

int select_color(T_COLOR color){
    if (color == R)
        return 4;
    if (color==B)
        return 1;
    if (color == G)
        return 2;
    if (color== O)
        return 6;
    if (color == Y)
        return 14;
    if (color == W)
        return 15;
    if (color == LG)
        return 7;
}

char select_color_lettre(T_COLOR color) {
    if (color == R)
        return "R";
    if (color == B)
        return "B";
    if (color == G)
        return "G";
    if (color == O)
        return "O";
    if (color == Y)
        return "Y";
    if (color == W)
        return "W";
    if (color == LG)
        return "LG";
}

T_COLOR side_to_color(T_SIDE side){
    if (side == UP)
        return W;
    if (side == LEFT)
        return O;
    if (side == FRONT)
        return G;
    if (side == RIGHT)
        return R;
    if (side == BACK)
        return B;
    if (side == DOWN)
        return Y;
}


int side_to_index(T_SIDE side){
    if (side == UP)
        return 0;
    if (side == LEFT)
        return 1;
    if (side == FRONT)
        return 2;
    if (side == RIGHT)
        return 3;
    if (side == BACK)
        return 4;
    if (side == DOWN)
        return 5;
}


char side_to_index_char(T_SIDE side){
    if (side == UP)
        return "UP";
    if (side == LEFT)
        return"LEFT";
    if (side == FRONT)
        return "FRONT";
    if (side == RIGHT)
        return "RIGHT";
    if (side == BACK)
        return "BACK";
    if (side == DOWN)
        return "DOWN";
}



Face* create_rubiks(Face* cube){

    cube = (Face*) malloc(6 * sizeof (Face));
    for (T_SIDE i = UP; i<=DOWN; i++){
        cube[i].Tab_carre = (T_COLOR**) malloc(3 * sizeof (T_COLOR*));
        cube[i].nom_side = i;
        for (int j = 0; j<3; j++){
            cube[i].Tab_carre[j] = (T_COLOR*) malloc(3 * sizeof (T_COLOR));
        }
    }
    return cube;
}

void blank_rubiks(Face* cube)
{
    select_color(7);
    for ( T_SIDE side = UP; side <= DOWN; side++) {
        for (int i = 0; i<3; i++){
            for (int j = 0; j < 3; j++){
                c_textcolor(0);
                cube[side].Tab_carre[i][j] = LG;
            }
        }
    }
}

void init_rubiks(Face* cube){
    for ( T_SIDE side = UP; side <= DOWN; side++ ) {
        cube[side].nom_side = side;
        for (int i = 0; i<3; i++) {
            for (int j = 0; j < 3; j++) {
                c_textcolor(side_to_color(select_color(side)));
                cube[side].Tab_carre[i][j] = side_to_color(side);
            }
        }
    }

}


void display_letter(T_COLOR color){
    if (color == R){
        c_textcolor(select_color(R));
        printf("R ");
    }
    if (color == B) {
        c_textcolor(select_color(B));
        printf("B ");
    }
    if (color == G){
        c_textcolor(select_color(G));
        printf("G ");
    }
    if (color == O){
        c_textcolor(select_color(O));
        printf("O ");
    }
    if (color == Y){
        c_textcolor(select_color(Y));
        printf("Y ");
    }
    if (color == W){
        c_textcolor(select_color(W));
        printf("W ");
    }
    if (color == LG){
        c_textcolor(select_color(LG));
        printf("LG");
    }

}





void display_rubriks (Face* cube)
{
    printf("\n");
    printf(" ---------------------------------------------\n\n");
    for (int i = 0; i<3; i++)
    {
        printf("       ");
        for (int j = 0; j<3; j++)
        {
            display_letter(cube[0].Tab_carre[j][i]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i=0; i<3; i++)
    {
        for (T_SIDE x = LEFT; x <= BACK; x++)
        {
            for (int j = 0; j<3; j++)
            {
                display_letter(cube[x].Tab_carre[j][i]);
            }
            printf(" ");
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i<3; i++)
    {
        printf("       ");
        for (int j = 0; j<3; j++)
        {
            display_letter(cube[DOWN].Tab_carre[j][i]);
        }
        printf("\n");
    }
    printf("\n-----------------------------------\n");
}

Face* fill_rubiks(Face* cube){
    int a, color, cpt = 0, c, l;
    printf("Entrer le numero de la case a colorer (UP = 0 /LEFT = 1 /FRONT = 2 /RIGHT = 3 /BACK = 4 /DOWN = 5)\n");
    scanf("%d", &a);
    printf("Entrez le nom de la couleur (W = 0 /O = 1 /G = 2 /R = 3 /B = 4 /Y = 5)\n");
    scanf("%d", &color);

    for (T_SIDE side = UP; side <= DOWN; side++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (cube[side].Tab_carre[i][j] == ref_select_color(color)) {
                    cpt++;
                }
            }
            if (cpt >= 9) {
                printf("Action impossible\n");
                return cube;
            }
        }
    }

    printf("Entrez le numero de colonne\n");
    scanf("%d", &c);
    printf("Entrez le numero de ligne\n");
    scanf("%d", &l);

    //---------------------------------
    //Face UP

    if (a == UP){
        if (c == 0) {
            if (ref_select_color(color) == cube[LEFT].Tab_carre[l][0]) {
                printf("Action impossible\n");
                return cube;
            }
        }
        if (c == 2) {
            if (ref_select_color(color) == cube[RIGHT].Tab_carre[2-l][0]) {
                printf("Action impossible\n");
                return cube;
            }
        }
        if (l == 0){
            if (ref_select_color(color) == cube[BACK].Tab_carre[2-c][0]) {
                printf("Action impossible\n");
                return cube;
            }
        }
        if (l == 2){
            if (ref_select_color(color) == cube[FRONT].Tab_carre[c][0]) {
                printf("Action impossible\n");
                return cube;
            }
        }
    }

    //---------------------------------
    //Face LEFT

    if (a == LEFT){
        if (c == 0) {
            if (ref_select_color(color) == cube[BACK].Tab_carre[2][l]) {
                printf("Action impossible\n");
                return cube;
            }
        }
        if (c == 2) {
            if (ref_select_color(color) == cube[FRONT].Tab_carre[0][l]) {
                printf("Action impossible\n");
                return cube;
            }
        }
        if (l == 0) {
            if (ref_select_color(color) == cube[UP].Tab_carre[l][c]) {
                printf("Action impossible\n");
                return cube;
            }
        }
        if (l == 2){
            if (ref_select_color(color) == cube[DOWN].Tab_carre[0][c]) {
                printf("Action impossible\n");
                return cube;
            }
        }
    }

    //---------------------------------
    //Face FRONT

    if (a == FRONT){
        if (c == 0) {
            if (ref_select_color(color) == cube[LEFT].Tab_carre[2][l]) {
                printf("Action impossible\n");
                return cube;
            }
        }
        if (c == 2) {
            if (ref_select_color(color) == cube[RIGHT].Tab_carre[0][l]) {
                printf("Action impossible\n");
                return cube;
            }
        }
        if (l == 0) {
            if (ref_select_color(color) == cube[UP].Tab_carre[c][2]) {
                printf("Action impossible\n");
                return cube;
            }
        }
        if (l == 2){
            if (ref_select_color(color) == cube[DOWN].Tab_carre[c][0]) {
                printf("Action impossible\n");
                return cube;
            }
        }
    }

    //---------------------------------
    //Face RIGHT

    if (a == RIGHT){
        if (c == 0) {
            if (ref_select_color(color) == cube[FRONT].Tab_carre[2][l]) {
                printf("Action impossible\n");
                return cube;
            }
        }
        if (c == 2) {
            if (ref_select_color(color) == cube[BACK].Tab_carre[0][l]) {
                printf("Action impossible\n");
                return cube;
            }
        }
        if (l == 0) {
            if (ref_select_color(color) == cube[UP].Tab_carre[2-c][0]) {
                printf("Action impossible\n");
                return cube;
            }
        }
        if (l == 2){
            if (ref_select_color(color) == cube[DOWN].Tab_carre[2][c]) {
                printf("Action impossible\n");
                return cube;
            }
        }
    }

    //---------------------------------
    //Face BACK

    if (a == BACK){
        if (c == 0) {
            if (ref_select_color(color) == cube[RIGHT].Tab_carre[2][l]) {
                printf("Action impossible\n");
                return cube;
            }
        }
        if (c == 2) {
            if (ref_select_color(color) == cube[LEFT].Tab_carre[0][l]) {
                printf("Action impossible\n");
                return cube;
            }
        }
        if (l == 0) {
            if (ref_select_color(color) == cube[UP].Tab_carre[2-c][0]) {
                printf("Action impossible\n");
                return cube;
            }
        }
        if (l == 2){
            if (ref_select_color(color) == cube[DOWN].Tab_carre[2-c][2]) {
                printf("Action impossible\n");
                return cube;
            }
        }
    }

    //---------------------------------
    //Face DOWN

    if (a == DOWN){
        if (c == 0) {
            if (ref_select_color(color) == cube[LEFT].Tab_carre[2-c][2]) {
                printf("Action impossible\n");
                return cube;
            }
        }
        if (c == 2) {
            if (ref_select_color(color) == cube[RIGHT].Tab_carre[l][2]) {
                printf("Action impossible\n");
                return cube;
            }
        }
        if (l == 0) {
            if (ref_select_color(color) == cube[FRONT].Tab_carre[c][2]) {
                printf("Action impossible\n");
                return cube;
            }
        }
        if (l == 2){
            if (ref_select_color(color) == cube[UP].Tab_carre[c][0]) {
                printf("Action impossible\n");
                return cube;
            }
        }
    }


        //modification de la valeur
    else{
        cube[a].nom_side = a;
        cube[a].Tab_carre[c][l] = ref_select_color(color);
        return cube;
    }

}



void free_rubiks(Face* cube)
{
    free(cube);
    cube = NULL;
}


