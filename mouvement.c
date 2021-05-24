//
// Created by 974cc on 24/05/2021.
//

#include "fonction.h"
#include <stdlib.h>
#include <stdio.h>




Face* selfclockwise(Face* cube, int type, T_SIDE side){
    Face* cube2;
    cube2 = (Face*) malloc(6 * sizeof (Face));
    for (T_SIDE i = UP; i<=DOWN; i++){
        cube2[i].Tab_carre = (T_COLOR**) malloc(3 * sizeof (T_COLOR*));
        cube2[i].nom_side = i;
        for (int j = 0; j<3; j++){
            cube2[i].Tab_carre[j] = (T_COLOR*) malloc(3 * sizeof (T_COLOR));
            for (int k = 0; k<3; k++){
                cube2[i].Tab_carre[j][k] = cube[i].Tab_carre[j][k];
            }
        }
    }

    for (int i = 0; i <3; i++){
        cube[side].Tab_carre[2][i] = cube2[side].Tab_carre[i][0];
    }
    for (int i = 0; i <3; i++){
        cube[side].Tab_carre[i][0] = cube2[side].Tab_carre[0][2-i];
    }
    for (int i = 0; i <3; i++){
        cube[side].Tab_carre[0][i] = cube2[side].Tab_carre[i][2];
    }
    for (int i = 0; i <3; i++){
        cube[side].Tab_carre[i][2] = cube2[side].Tab_carre[2][2-i];
    }


    if (type != 1){
        return selfclockwise(cube, type -1, side);
    }
    return cube;
}

Face* crown_clockwise(Face* cube, int type, T_SIDE side){
    Face* cube2;
    cube2 = (Face*) malloc(6 * sizeof (Face));
    for (T_SIDE i = UP; i<=DOWN; i++){
        cube2[i].Tab_carre = (T_COLOR**) malloc(3 * sizeof (T_COLOR*));
        cube2[i].nom_side = i;
        for (int j = 0; j<3; j++){
            cube2[i].Tab_carre[j] = (T_COLOR*) malloc(3 * sizeof (T_COLOR));
            for (int k = 0; k<3; k++){
                cube2[i].Tab_carre[j][k] = cube[i].Tab_carre[j][k];
            }
        }
    }

    if (side == UP){
        for (int i = 0; i<3; i++){
            cube[LEFT].Tab_carre[i][0] = cube2[FRONT].Tab_carre[i][0];
            cube[FRONT].Tab_carre[i][0] = cube2[RIGHT].Tab_carre[i][0];
            cube[RIGHT].Tab_carre[i][0] = cube2[BACK].Tab_carre[i][0];
            cube[BACK].Tab_carre[i][0] = cube2[LEFT].Tab_carre[i][0];
        }
    }

    if (side == LEFT){
        for (int i = 0; i<3; i++){
            cube[UP].Tab_carre[0][i] = cube2[BACK].Tab_carre[2][2-i];
            cube[FRONT].Tab_carre[0][i] = cube2[UP].Tab_carre[0][i];
            cube[DOWN].Tab_carre[0][i] = cube2[FRONT].Tab_carre[0][i];
            cube[BACK].Tab_carre[2][i] = cube2[DOWN].Tab_carre[0][2-i];
        }
    }

    if (side == FRONT){
        for (int i = 0; i<3; i++){
            cube[UP].Tab_carre[i][2] = cube2[LEFT].Tab_carre[2][2-i];
            cube[RIGHT].Tab_carre[0][i] = cube2[UP].Tab_carre[i][2];
            cube[DOWN].Tab_carre[i][0] = cube2[RIGHT].Tab_carre[0][2-i];
            cube[LEFT].Tab_carre[2][i] = cube2[DOWN].Tab_carre[i][0];
        }
    }

    if (side == RIGHT){
        for (int i = 0; i<3; i++){
            cube[UP].Tab_carre[2][i] = cube2[FRONT].Tab_carre[2][i];
            cube[FRONT].Tab_carre[2][i] = cube2[DOWN].Tab_carre[2][i];
            cube[DOWN].Tab_carre[2][i] = cube2[BACK].Tab_carre[0][2-i];
            cube[BACK].Tab_carre[0][i] = cube2[UP].Tab_carre[2][2-i];
        }
    }

    if (side == BACK){
        for (int i = 0; i<3; i++){
            cube[UP].Tab_carre[i][0] = cube2[RIGHT].Tab_carre[2][i];
            cube[RIGHT].Tab_carre[2][i] = cube2[DOWN].Tab_carre[2-i][2];
            cube[DOWN].Tab_carre[i][2] = cube2[LEFT].Tab_carre[0][i];
            cube[LEFT].Tab_carre[0][i] = cube2[UP].Tab_carre[2-i][0];
        }
    }

    if (side == DOWN){
        for (int i = 0; i<3; i++){
            cube[BACK].Tab_carre[i][2] = cube2[RIGHT].Tab_carre[i][2];
            cube[RIGHT].Tab_carre[i][2] = cube2[FRONT].Tab_carre[i][2];
            cube[FRONT].Tab_carre[i][2] = cube2[LEFT].Tab_carre[i][2];
            cube[LEFT].Tab_carre[i][2] = cube2[BACK].Tab_carre[i][2];
        }
    }
    if (type != 1){
        cube = crown_clockwise(cube, type -1, side);
    }
    return cube;
}

Face* clockwise(Face* cube, int type, T_SIDE side){
    cube = selfclockwise(cube, type, side);
    cube = crown_clockwise(cube, type, side);
    return cube;
}

Face* anticlockwise(Face* cube, int type, T_SIDE side){
    for(int i = 0; i<3; i++){
        cube = selfclockwise(cube, type, side);
        cube = crown_clockwise(cube, type, side);
    }
    return cube;
}

Face* horizontal_rotation(Face* cube){

    Face* cube2;
    cube2 = (Face*) malloc(6 * sizeof (Face));
    for (T_SIDE i = UP; i<=DOWN; i++){
        cube2[i].Tab_carre = (T_COLOR**) malloc(3 * sizeof (T_COLOR*));
        cube2[i].nom_side = i;
        for (int j = 0; j<3; j++){
            cube2[i].Tab_carre[j] = (T_COLOR*) malloc(3 * sizeof (T_COLOR));
            for (int k = 0; k<3; k++){
                cube2[i].Tab_carre[j][k] = cube[i].Tab_carre[j][k];
            }
        }
    }

    cube[LEFT].nom_side = RIGHT;
    cube[RIGHT].nom_side = LEFT;
    cube2[FRONT].nom_side = BACK;
    cube[BACK].nom_side = FRONT;

    cube[LEFT].Tab_carre = cube2[RIGHT].Tab_carre;
    cube[RIGHT].Tab_carre = cube2[LEFT].Tab_carre;
    cube[FRONT].Tab_carre = cube2[BACK].Tab_carre;
    cube[BACK].Tab_carre = cube2[FRONT].Tab_carre;
    return cube;
}


Face* vertical_rotation(Face* cube){

    Face* cube2;
    cube2 = (Face*) malloc(6 * sizeof (Face));
    for (T_SIDE i = UP; i<=DOWN; i++){
        cube2[i].Tab_carre = (T_COLOR**) malloc(3 * sizeof (T_COLOR*));
        cube2[i].nom_side = i;
        for (int j = 0; j<3; j++){
            cube2[i].Tab_carre[j] = (T_COLOR*) malloc(3 * sizeof (T_COLOR));
            for (int k = 0; k<3; k++){
                cube2[i].Tab_carre[j][k] = cube[i].Tab_carre[j][k];
            }
        }
    }

    cube[UP].nom_side = DOWN;
    cube[DOWN].nom_side = UP;
    cube2[FRONT].nom_side = BACK;
    cube[BACK].nom_side = FRONT;

    cube[UP].Tab_carre = cube2[DOWN].Tab_carre;
    cube[DOWN].Tab_carre = cube2[UP].Tab_carre;
    cube[FRONT].Tab_carre = cube2[BACK].Tab_carre;
    cube[BACK].Tab_carre = cube2[FRONT].Tab_carre;
    return cube;
}


Face* move_rubiks(Face* cube){
    int choix, sens, n;
    T_SIDE side;
    printf("---------------------------------------------\n");
    printf("Entrez le numero du mouvement que vous voulez faire sur le rubik's cube\n");
    printf("---------------------------------------------\n");
    printf("1 = Rotation d'une face  |  2 = Rotation du cube\n");
    printf("---------------------------------------------\n");
    scanf("%d", &choix);
    printf("---------------------------------------------\n");
    switch (choix) {
        case 1:{
            printf("Entrez le sens du mouvement que vous voulez faire sur le rubik's cube\n");
            printf("---------------------------------------------\n");
            printf("1 = Rotation horraire  |  2 = Rotation anti-horraire\n");
            printf("---------------------------------------------\n");
            scanf("%d", &sens);
            printf("---------------------------------------------\n");
            switch (sens) {
                case 1: {
                    printf("Entrez la reference de la face que vous voulez modifier\n");
                    printf("---------------------------------------------\n");
                    printf("UP = 1  |  LEFT = 2  |  FRONT = 3  |  RIGHT = 4  |  BACK = 5  |  DOWN = 6\n");
                    printf("---------------------------------------------\n");
                    scanf("%d", &side);
                    printf("---------------------------------------------\n");
                    printf("Entrez le nombre de rotation que vous voulez faire sur la face\n");
                    printf("---------------------------------------------\n");
                    scanf("%d", &n);
                    printf("---------------------------------------------\n");
                    cube = clockwise(cube, n, side - 1);
                    break;
                }
                case 2: {
                    printf("Entrez la reference de la face que vous voulez modifier\n");
                    printf("---------------------------------------------\n");
                    printf("UP = 1  |  LEFT = 2  |  FRONT = 3  |  RIGHT = 4  |  BACK = 5  |  DOWN = 6\n");
                    printf("---------------------------------------------\n");
                    scanf("%d", &side);
                    printf("---------------------------------------------\n");
                    printf("Entrez le nombre de rotation que vous voulez faire sur la face\n");
                    printf("---------------------------------------------\n");
                    scanf("%d", &n);
                    printf("---------------------------------------------\n");
                    cube = anticlockwise(cube, n, side - 1);
                    break;
                }
            }
            break;
        }
        case 2:{
            printf("Entrez le sens du mouvement que vous voulez faire sur le rubik's cube\n");
            printf("---------------------------------------------\n");
            printf("1 = Rotation horrizontale  |  2 = Rotation verticale\n");
            printf("---------------------------------------------\n");
            scanf("%d", &sens);
            printf("---------------------------------------------\n");
            switch (sens) {
                case 1:{
                    cube = horizontal_rotation(cube);
                    break;
                }
                case 2:{
                    cube = vertical_rotation(cube);
                    break;
                }
            }
            break;
        }
    }
    return cube;

}


Face* scramble_rubiks(Face* cube){
    int x, y;
    printf("Entrez le nombre de mouvement que vous voulez faire afin de melanger le cube\n");
    scanf("%d", &y);
    for (int i = 0; i < y; i++){
        x = rand() % 6;
        cube = clockwise(cube, 1, x);
    }
    return cube;
}


