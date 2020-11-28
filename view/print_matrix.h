//
// Created by guin on 11/28/2020.
//

#ifndef GAME_OF_LIFE_PRINT_MATRIX_H
#define GAME_OF_LIFE_PRINT_MATRIX_H

#include <stdio.h>

void print_matrix(int size, char secondary_matrix[][size]) {
    int back_lin, back_col;
    secondary_matrix[0][0] = ' ';

    printf("\n");

    for (int line = 0; line < size; line++) {
        for (int column = 0; column < size; column++) {
            if (column == 0) {
                if (line <= 9) {
                    printf(" %c", secondary_matrix[line][0]);
                    printf(" ");
                } else {
                    back_lin = line / 10;
                    printf("%c%c", secondary_matrix[back_lin][0], secondary_matrix[line][0]);
                    printf(" ");
                }
            } else {
                if (line == 0) {
                    if (column > 9) {
                        back_col = column / 10;
                        printf("%c%c", secondary_matrix[0][(back_col) % 10], secondary_matrix[0][column]);
                        printf(" ");
                    } else {
                        printf(" %c", secondary_matrix[0][column]);
                        printf(" ");
                    }
                } else {
                    printf(" %c", secondary_matrix[line][column]);
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

#endif //GAME_OF_LIFE_PRINT_MATRIX_H
