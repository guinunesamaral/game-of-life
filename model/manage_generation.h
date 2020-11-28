//
// Created by guin on 11/28/2020.
//

#ifndef GAME_OF_LIFE_MANAGE_GENERATION_H
#define GAME_OF_LIFE_MANAGE_GENERATION_H

#include <stdio.h>

void save_generation(int size, char matrix[][size]) {
    FILE *file;
    file = fopen("./generations/generation.txt", "w");

    int back_lin, back_col;

    for (int line = 0; line < size; line++) {
        for (int column = 0; column < size; column++) {
            if (column == 0) {
                if (line <= 9) {
                    fprintf(file, " %c", matrix[line][0]);
                    fprintf(file, "%c", ' ');
                } else {
                    back_lin = line / 10;
                    fprintf(file, "%c%c", matrix[back_lin][0], matrix[line][0]);
                    fprintf(file, "%c", ' ');
                }
            } else {
                if (line == 0) {
                    if (column > 9) {
                        back_col = column / 10;
                        fprintf(file, "%c%c", matrix[0][back_col % 10], matrix[0][column]);
                        fprintf(file, "%c", ' ');
                    } else {
                        fprintf(file, " %c", matrix[0][column]);
                        fprintf(file, "%c", ' ');
                    }
                } else {
                    fprintf(file, " %c", matrix[line][column]);
                    fprintf(file, "%c", ' ');
                }
            }
        }
        fprintf(file, "%c", '\n');
    }
    fclose(file);
}

void copy_content(int size, char matrix[][size]) {
    FILE *file;
    file = fopen("./generations/generation.txt", "r");

    char reader;
    char scanner[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    int pass = 1, i = 0;

    for (int line = 1; line < size; line++) {
        for (int column = 1; column < size; column++) {
            reader = fgetc(file);
            while (pass == 1 && i < 10) {
                if (reader == scanner[i]) pass = 0;
                i++;
            }
            if (pass == 1) {
                matrix[line][column] = reader;
            } else matrix[line][column] = ' ';
            pass = 1;
            i = 0;
        }
    }
    fclose(file);
}


#endif //GAME_OF_LIFE_MANAGE_GENERATION_H
