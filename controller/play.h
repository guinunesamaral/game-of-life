//
// Created by guin on 11/28/2020.
//

#ifndef GAME_OF_LIFE_PLAY_H
#define GAME_OF_LIFE_PLAY_H

#include <stdio.h>
#include <windows.h>
#include "../view/print_matrix.h"

int main_choice() {
    int choice, cont = 0;
    int op[7] = {1, 2, 3, 4, 5, 6};

    system("cls");

    printf("\n(1) - Generate matrix");
    printf("\n(2) - Run the Game of Life");
    printf("\n(3) - Empty matrix");
    printf("\n(4) - Save the last generation in a file");
    printf("\n(5) - Open a previous saved generation");
    printf("\n(6) - Finish the program");
    printf("\n\nHi, type one of the numbers above to give the instructions: ");
    scanf("%d", &choice);

    for (int i = 0; i <= 5; i++) {
        if (op[i] == choice) cont++;
    }
    if (cont == 0) main_choice();

    return (choice);
}

int matrix_size() {
    int length;

    printf("\nThe Game of Life world consists in a square matrix, i.e., height = width");
    printf("\n\nDefine the size of the world. Preferably something between 30 e 60: ");
    scanf("%d", &length);

    if (length < 30 || length > 60) matrix_size();

    return (length);
}

int matrix_or_standard() {
    int esc;

    system("cls");

    printf("\n(1) - Choose the living beings");
    printf("\n(2) - Choose pattern image");
    printf("\n\nType one of the numbers above: ");
    scanf("%d", &esc);

    if (esc != 1 && esc != 2) matrix_or_standard();

    return (esc);
}



int n_living_beings() {
    int n_living_beings;

    printf("\n********Game of Life's rules********\n");
    printf("\n(1) - Each living being has 8 neighbors");
    printf("\n(2) - A living being will be born in a cell with exactly 3 neighbors");
    printf("\n(2) - A living being alone will die of loneliness");
    printf("\n(3) - A living being with more than 4 neighbors will starve to death");
    printf("\n(4) - A living being with 2 or 3 neighbors will stay alive in the next generation");
    printf("\n\nDefine the number of living beings that you wish: ");
    scanf("%d", &n_living_beings);

    if (n_living_beings < 0) n_living_beings = n_living_beings * (-1);
    if (n_living_beings == 0) n_living_beings++;

    return (n_living_beings);
}

void living_beings_matrix(int n_living_beings, int size, char matrix[][size]) {
    int line, column;

    system("cls");

    printf("\nNow type the positions of the living beings in the screen - (x, y) coordinates.\n");
    Sleep(2000);

    for (int i = 1; i <= n_living_beings; i++) {
        system("cls");
        printf("\nWatch the screen and define the coordinates of the living beings.\n");

        print_matrix(size, matrix);

        printf("\nLine: ");
        scanf("%d", &line);
        if (line < 0) line = line * (-1);
        if (line == 0) line++;
        if (line == size) line--;

        printf("\nColumn: ");
        scanf("%d", &column);
        if (column < 0) column = column * (-1);
        if (column == 0) column++;
        if (column == size) column--;

        matrix[line][column] = '*';
    }
    system("cls");
    printf("\n************The matrix you've made!************\n");
    print_matrix(size, matrix);
}

int n_generations() {
    int n_gen;
    int op;

    Sleep(2000);
    system("cls");

    printf("\n(1) - Choose the number of generations to play");
    printf("\n(2) - Play only one generation");
    printf("\n\nType your choice: ");
    scanf("%d", &op);

    if (op == 1) {
        printf("\nChoose the number of generations you want: ");
        scanf("%d", &n_gen);
    } else if (op == 2) n_gen = 1;

    if (n_gen < 1) n_generations();

    return (n_gen);
}

int define_speed() {
    int speed;

    printf("\nType a milliseconds value for the matrix simulation - something between 100 and 1000. I suggest 250");
    printf("\n\nSpeed: ");
    scanf("%d", &speed);

    if (speed < 100 || speed > 1000) define_speed();

    return (speed);
}

#endif //GAME_OF_LIFE_PLAY_H
