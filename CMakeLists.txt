cmake_minimum_required(VERSION 3.17)
project(projet_C_rubik C)

set(CMAKE_C_STANDARD 99)

add_executable(projet_C_rubik main.c conio.c conio.h fonction.c fonction.h mouvement.c resolution.c)