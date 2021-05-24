// Created by 974cc on 24/05/2021.
//

#ifndef PROJET_C_RUBIK_FONCTION_H
#define PROJET_C_RUBIK_FONCTION_H

#endif //PROJET_C_RUBIK_FONCTION_H


typedef enum { UP, LEFT, FRONT, RIGHT, BACK,  DOWN } T_SIDE ;
typedef enum { W , O, G, R, B, Y, LG} T_COLOR ;
typedef struct {
    T_SIDE nom_side;
    T_COLOR ** Tab_carre;
}Face;
int select_color(T_COLOR color);
T_COLOR ref_select_color(int n);
void init_rubiks(Face* cube);
void blank_rubiks(Face* cube);
char side_to_index_char(T_SIDE side);
int side_to_index(T_SIDE side);
T_COLOR side_to_color(T_SIDE side);
Face* create_rubiks(Face* cube);
void display_letter(T_COLOR color);
void display_rubriks (Face* cube);
Face* fill_rubiks(Face* cube);
Face* free_rubiks(Face* cube);

//-----------------------


Face* selfclockwise(Face* cube, int type, T_SIDE side);
Face* crown_clockwise(Face* cube, int type, T_SIDE side);
Face* clockwise(Face* cube, int type, T_SIDE side);
Face* anticlockwise(Face* cube, int type, T_SIDE side);
Face* horizontal_rotation(Face* cube);
Face* vertical_rotation(Face* cube);
Face* move_rubiks(Face* cube);
Face* scramble_rubiks(Face* cube);


//------------------------------


Face* croix(Face* cube);//
