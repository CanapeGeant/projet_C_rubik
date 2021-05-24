//
// Created by 974cc on 24/05/2021.
//

#include "fonction.h"
#include <stdlib.h>
#include <stdio.h>

void resolution(Face* cube){
    int solved = 2;
    do {
        solved = 2;
        for (T_SIDE side = UP; side <= DOWN; side++) {
            for (int i = 0; i <= 3; i++) {
                for (int j = 0; j <= 3; j++) {
                    if (cube[side].Tab_carre[i][j] != cube[side].Tab_carre[1][1]) {
                        solved = 0;
                    }
                }
            }
        }
        if (solved == 2){
            solved = 1;
        }



    } while (solved != 1);

}

Face* croix(Face* cube){
    T_COLOR c_up = cube[UP].Tab_carre[1][1];
    int bool = 1;
    /*while (cube[UP].Tab_carre[0][1] != c_up   && cube[UP].Tab_carre[1][0] != c_up &&
    cube[UP].Tab_carre[1][2] != c_up && cube[UP].Tab_carre[2][1] != c_up){
        do {
            if (cube[DOWN].Tab_carre[0][1] == c_up   && cube[DOWN].Tab_carre[1][0] == c_up &&
            cube[DOWN].Tab_carre[1][2] == c_up && cube[DOWN].Tab_carre[2][1] == c_up){
                bool = 0;
                printf("Essayez de ramener toutes les cases nécessaires pour réaliser une croix parfaite sur la face UP");
            }
            else{
                bool = 1;
            }
        }while (bool == 0);*/

    if (cube[LEFT].Tab_carre[1][0] == c_up){
        cube = clockwise(cube, 1, LEFT);
        cube = clockwise(cube, 3, UP);
        cube = clockwise(cube, 1, FRONT);
        cube = clockwise(cube, 1, UP);
    }

    if (cube[FRONT].Tab_carre[1][0] == c_up){
        cube = clockwise(cube, 1, FRONT);
        cube = clockwise(cube, 3, UP);
        cube = clockwise(cube, 1, RIGHT);
        cube = clockwise(cube, 1, UP);
    }

    if (cube[RIGHT].Tab_carre[1][0] == c_up) {
        cube = clockwise(cube, 1, RIGHT);
        cube = clockwise(cube, 3, UP);
        cube = clockwise(cube, 1, BACK);
        cube = clockwise(cube, 1, UP);
    }

    if (cube[BACK].Tab_carre[1][0] == c_up) {
        cube = clockwise(cube, 1, BACK);
        cube = clockwise(cube, 3, UP);
        cube = clockwise(cube, 1, LEFT);
        cube = clockwise(cube, 1, UP);
    }


    while (cube[LEFT].Tab_carre[0][1] == c_up || cube[LEFT].Tab_carre[2][1] == c_up ||cube[LEFT].Tab_carre[1][2] == c_up){
        while (cube[UP].Tab_carre[0][1] == c_up){
            cube = clockwise(cube, 1, UP);
        }
        while (cube[LEFT].Tab_carre[1][0] != c_up){
            cube = clockwise(cube, 1, LEFT);
        }
        cube = clockwise(cube, 1, LEFT);
        cube = clockwise(cube, 3, UP);
        cube = clockwise(cube, 1, FRONT);
        cube = clockwise(cube, 1, UP);
    }

    while (cube[FRONT].Tab_carre[0][1] == c_up || cube[FRONT].Tab_carre[2][1] == c_up || cube[FRONT].Tab_carre[1][2] == c_up){
        while (cube[UP].Tab_carre[1][2] == c_up){
            cube = clockwise(cube, 1, UP);
        }
        while (cube[FRONT].Tab_carre[1][0] != c_up){
            cube = clockwise(cube, 1, FRONT);
        }
        cube = clockwise(cube, 1, FRONT);
        cube = clockwise(cube, 3, UP);
        cube = clockwise(cube, 1, RIGHT);
        cube = clockwise(cube, 1, UP);
    }

    while (cube[RIGHT].Tab_carre[0][1] == c_up || cube[RIGHT].Tab_carre[2][1] == c_up || cube[RIGHT].Tab_carre[1][2] == c_up){
        while (cube[UP].Tab_carre[2][1] == c_up){
            cube = clockwise(cube, 1, UP);
        }
        while (cube[RIGHT].Tab_carre[1][0] != c_up){
            cube = clockwise(cube, 1, RIGHT);
        }
        cube = clockwise(cube, 1, RIGHT);
        cube = clockwise(cube, 3, UP);
        cube = clockwise(cube, 1, BACK);
        cube = clockwise(cube, 1, UP);
    }

    while (cube[BACK].Tab_carre[0][1] == c_up || cube[BACK].Tab_carre[2][1] == c_up || cube[BACK].Tab_carre[1][2] == c_up){
        while (cube[UP].Tab_carre[1][0] == c_up){
            cube = clockwise(cube, 1, UP);
        }
        while (cube[BACK].Tab_carre[1][0] != c_up){
            cube = clockwise(cube, 1, BACK);
        }
        cube = clockwise(cube, 1, BACK);
        cube = clockwise(cube, 3, UP);
        cube = clockwise(cube, 1, LEFT);
        cube = clockwise(cube, 1, UP);
    }


    return cube;
}


