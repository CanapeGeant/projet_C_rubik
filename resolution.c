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
    int cpt_up1 = 0, cpt_up2 = 0 ,cpt_up3 =0,cpt_up4=0, cpt_down1=0, cpt_down2=0, cpt_down3=0,cpt_down4=0, cpt_up= 4;

    while (cpt_up !=0) {

        if (cube[UP].Tab_carre[1][0] == c_up) {
            cpt_up1 ++;
            clockwise(cube, 1, BACK);
        }
        if (cpt_up1 > 4) {
            int x = 1 + rand() % 4;
            clockwise(cube, 1, x);
        }
        if (cube[UP].Tab_carre[1][0] != c_up) {
            cpt_up1 = 0;
        }



        if (cube[UP].Tab_carre[1][2] == c_up) {
            cpt_up2++;
            clockwise(cube, 1, FRONT);
        }
        if (cpt_up2 > 4) {
            int x = 1 + rand() % 4;
            clockwise(cube, 1, x);
        }
        if (cube[UP].Tab_carre[1][2] != c_up) {
            cpt_up2 = 0;
        }


        if (cube[UP].Tab_carre[0][1] == c_up) {
            cpt_up3 ++;
            clockwise(cube, 1, LEFT);
        }

        if (cpt_up3 >4) {
            int x = 1 + rand() % 4;
            clockwise(cube, 1, x);
        }
        if (cube[UP].Tab_carre[0][1] != c_up) {
            cpt_up3 = 0;
        }


        if (cube[UP].Tab_carre[2][1] == c_up) {
            cpt_up4 ++;
            clockwise(cube, 1, RIGHT);
        }
        if (cpt_up4 >4) {
            int x = 1 + rand() % 4;
            clockwise(cube, 1, x);
        }
        if (cube[UP].Tab_carre[2][1] != c_up) {
            cpt_up4 = 0;
        }

        cpt_up = cpt_up1 + cpt_up2 + cpt_up3 + cpt_up4;
    }





    if (cube[LEFT].Tab_carre[1][2] == c_up){
            cube = clockwise(cube, 1, LEFT);
            cube = clockwise(cube, 3, DOWN);
            cube = clockwise(cube, 1, BACK);
            cube = clockwise(cube, 1, DOWN);
        }

    if (cube[FRONT].Tab_carre[1][2] == c_up){
        cube = clockwise(cube, 1, FRONT);
        cube = clockwise(cube, 3, DOWN);
        cube = clockwise(cube, 1, LEFT);
        cube = clockwise(cube, 1, DOWN);

    }

    if (cube[RIGHT].Tab_carre[1][2] == c_up) {
        cube = clockwise(cube, 1, RIGHT);
        cube = clockwise(cube, 3, DOWN);
        cube = clockwise(cube, 1, FRONT);
        cube = clockwise(cube, 1, DOWN);
    }

    if (cube[BACK].Tab_carre[1][2] == c_up) {
        cube = clockwise(cube, 1, BACK);
        cube = clockwise(cube, 3, DOWN);
        cube = clockwise(cube, 1, RIGHT);
        cube = clockwise(cube, 1, DOWN);
    }

    while (cube[LEFT].Tab_carre[0][1] == c_up || cube[LEFT].Tab_carre[2][1] == c_up ||cube[LEFT].Tab_carre[1][0] == c_up){
        while (cube[DOWN].Tab_carre[0][1] == c_up){
            cube = clockwise(cube, 1, DOWN);
        }
        while (cube[LEFT].Tab_carre[1][2] != c_up){
            cube = clockwise(cube, 1, LEFT);
        }

        cube = clockwise(cube, 1, LEFT);
        cube = clockwise(cube, 3, DOWN);
        cube = clockwise(cube, 1, BACK);
        cube = clockwise(cube, 1, DOWN);
    }

    while (cube[FRONT].Tab_carre[0][1] == c_up || cube[FRONT].Tab_carre[2][1] == c_up || cube[FRONT].Tab_carre[1][0] == c_up){
        while (cube[DOWN].Tab_carre[1][0] == c_up){
            cube = clockwise(cube, 1, DOWN);
        }
        while (cube[FRONT].Tab_carre[1][2] != c_up){
            cube = clockwise(cube, 1, FRONT);
        }
        cube = clockwise(cube, 1, FRONT);
        cube = clockwise(cube, 3, DOWN);
        cube = clockwise(cube, 1, LEFT);
        cube = clockwise(cube, 1, DOWN);
        }

    while (cube[RIGHT].Tab_carre[0][1] == c_up || cube[RIGHT].Tab_carre[2][1] == c_up || cube[RIGHT].Tab_carre[1][0] == c_up){
        while (cube[DOWN].Tab_carre[2][1] == c_up){
            cube = clockwise(cube, 1, DOWN);
        }
        while (cube[RIGHT].Tab_carre[1][2] != c_up){
            cube = clockwise(cube, 1, RIGHT);
        }
        cube = clockwise(cube, 1, RIGHT);
        cube = clockwise(cube, 3, DOWN);
        cube = clockwise(cube, 1, FRONT);
        cube = clockwise(cube, 1, DOWN);
    }

    while (cube[BACK].Tab_carre[0][1] == c_up || cube[BACK].Tab_carre[2][1] == c_up || cube[BACK].Tab_carre[1][0] == c_up){
        while (cube[DOWN].Tab_carre[1][2] == c_up){
            cube = clockwise(cube, 1, DOWN);
        }
        while (cube[BACK].Tab_carre[1][2] != c_up){
            cube = clockwise(cube, 1, BACK);
        }
        cube = clockwise(cube, 1, BACK);
        cube = clockwise(cube, 3, DOWN);
        cube = clockwise(cube, 1, LEFT);
        cube = clockwise(cube, 1, DOWN);
    }



    for (int i=0; i<4;i++){
        if (cube[BACK].Tab_carre[1][2] != cube[BACK].Tab_carre[1][1] && cube[DOWN].Tab_carre[1][2] != c_up){
            clockwise(cube, 1, DOWN);
        }
    }
    if (cube[UP].Tab_carre[1][0] != c_up) {
        clockwise(cube, 2, BACK);
    }


    for (int i=0; i<4;i++) {
        if (cube[RIGHT].Tab_carre[1][2] != cube[RIGHT].Tab_carre[1][1] && cube[DOWN].Tab_carre[2][1] != c_up) {
            clockwise(cube, 1, DOWN);
        }
    }
    if (cube[UP].Tab_carre[2][1] != c_up) {
        clockwise(cube, 2, RIGHT);
    }


    for (int i=0; i<4;i++) {
        if (cube[FRONT].Tab_carre[1][2] != cube[FRONT].Tab_carre[1][1] && cube[DOWN].Tab_carre[1][0] != c_up) {
            clockwise(cube, 1, DOWN);
        }
    }
    if (cube[UP].Tab_carre[1][2] != c_up) {
        clockwise(cube, 2, FRONT);
    }


    for (int i=0; i<4;i++) {
        if (cube[LEFT].Tab_carre[1][2] != cube[LEFT].Tab_carre[1][1] && cube[DOWN].Tab_carre[0][1] != c_up) {
            clockwise(cube, 1, DOWN);
        }
    }
    if (cube[UP].Tab_carre[0][1] != c_up){
        clockwise(cube, 2, LEFT);
    }

    return cube;
}


