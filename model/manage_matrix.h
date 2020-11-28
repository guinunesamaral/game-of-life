//
// Created by guin on 11/28/2020.
//

#ifndef GAME_OF_LIFE_MANAGE_MATRIX_H
#define GAME_OF_LIFE_MANAGE_MATRIX_H

void fill_matrix_edges(int size, char matrix[][size]) {
    matrix[0][0] = ' ';

    for (int column = 0; column < size; column++) {
        if (column < 10) {
            matrix[0][column] = column + '0';
        } else {
            matrix[0][column] = (column % 10) + '0';
        }
    }
    for (int line = 0; line < size; line++) {
        if (line < 10) {
            matrix[line][0] = line + '0';
        } else {
            matrix[line][0] = (line % 10) + '0';
        }
    }
    for (int line = 1; line < size; line++) {
        for (int column = 1; column < size; column++) {
            matrix[line][column] = ' ';
        }
    }
}

void survival_game(int size, char matrix[][size], char secondary_matrix[][size]) {
    int neighbour = 0;

    for (int line = 1; line < size; line++) {
        for (int column = 1; column < size; column++) {
            if (matrix[line][column] == ' ') {
                if (matrix[line - 1][column - 1] == '*') neighbour++;
                if (matrix[line - 1][column] == '*') neighbour++;
                if (matrix[line - 1][column + 1] == '*') neighbour++;
                if (matrix[line][column - 1] == '*') neighbour++;
                if (matrix[line][column + 1] == '*') neighbour++;
                if (matrix[line + 1][column - 1] == '*') neighbour++;
                if (matrix[line + 1][column] == '*') neighbour++;
                if (matrix[line + 1][column + 1] == '*') neighbour++;

                if (neighbour == 3) secondary_matrix[line][column] = '*';
                neighbour = 0;
            } else if (matrix[line][column] == '*') {
                if (matrix[line - 1][column - 1] == '*') neighbour++;
                if (matrix[line - 1][column] == '*') neighbour++;
                if (matrix[line - 1][column + 1] == '*') neighbour++;
                if (matrix[line][column - 1] == '*') neighbour++;
                if (matrix[line][column + 1] == '*') neighbour++;
                if (matrix[line + 1][column - 1] == '*') neighbour++;
                if (matrix[line + 1][column] == '*') neighbour++;
                if (matrix[line + 1][column + 1] == '*') neighbour++;

                if ((neighbour == 2) || (neighbour == 3)) secondary_matrix[line][column] = '*';

                else secondary_matrix[line][column] = ' ';

                neighbour = 0;
            }
        }
    }
}

void original_matrix(int size, char matrix[][size], char secondary_matrix[][size]) {

    for (int line = 0; line < size; line++) {
        for (int column = 0; column < size; column++) {
            secondary_matrix[line][column] = matrix[line][column];
        }
    }
}

void standard_matrix(int size, char matrix[][size], int stan) {
    int m = size / 3; // Treat m like it was the number 1

    if (stan == 1) {
        matrix[m][m + 3] = '*';
        matrix[m][m + 5] = '*';
        matrix[m + 1][m + 1] = '*';
        matrix[m + 1][m + 2] = '*';
        matrix[m + 1][m + 3] = '*';
        matrix[m + 1][m + 5] = '*';
        matrix[m + 1][m + 6] = '*';
        matrix[m + 1][m + 7] = '*';
        matrix[m + 2][m] = '*';
        matrix[m + 2][m + 4] = '*';
        matrix[m + 2][m + 8] = '*';
        matrix[m + 3][m] = '*';
        matrix[m + 3][m + 2] = '*';
        matrix[m + 3][m + 6] = '*';
        matrix[m + 3][m + 8] = '*';
        matrix[m + 4][m + 1] = '*';
        matrix[m + 4][m + 2] = '*';
        matrix[m + 4][m + 4] = '*';
        matrix[m + 4][m + 6] = '*';
        matrix[m + 4][m + 7] = '*';

        matrix[m + 6][m + 1] = '*';
        matrix[m + 6][m + 2] = '*';
        matrix[m + 6][m + 4] = '*';
        matrix[m + 6][m + 6] = '*';
        matrix[m + 6][m + 7] = '*';
        matrix[m + 7][m] = '*';
        matrix[m + 7][m + 2] = '*';
        matrix[m + 7][m + 6] = '*';
        matrix[m + 7][m + 8] = '*';
        matrix[m + 8][m] = '*';
        matrix[m + 8][m + 4] = '*';
        matrix[m + 8][m + 8] = '*';
        matrix[m + 9][m + 1] = '*';
        matrix[m + 9][m + 2] = '*';
        matrix[m + 9][m + 3] = '*';
        matrix[m + 9][m + 5] = '*';
        matrix[m + 9][m + 6] = '*';
        matrix[m + 9][m + 7] = '*';
        matrix[m + 10][m + 3] = '*';
        matrix[m + 10][m + 5] = '*';

    } else if (stan == 2) {
        matrix[m][m] = '*';
        matrix[m][m + 1] = '*';
        matrix[m][m + 5] = '*';
        matrix[m][m + 6] = '*';
        matrix[m + 1][m + 1] = '*';
        matrix[m + 1][m + 3] = '*';
        matrix[m + 1][m + 5] = '*';
        matrix[m + 2][m + 1] = '*';
        matrix[m + 2][m + 2] = '*';
        matrix[m + 2][m + 4] = '*';
        matrix[m + 2][m + 5] = '*';
        matrix[m + 3][m + 1] = '*';
        matrix[m + 3][m + 3] = '*';
        matrix[m + 3][m + 5] = '*';
        matrix[m + 4][m] = '*';
        matrix[m + 4][m + 1] = '*';
        matrix[m + 4][m + 5] = '*';
        matrix[m + 4][m + 6] = '*';
    } else if (stan == 3) {
        matrix[m][m + 2] = '*';
        matrix[m][m + 7] = '*';
        matrix[m + 1][m] = '*';
        matrix[m + 1][m + 1] = '*';
        matrix[2][4] = '*';
        matrix[m + 1][m + 4] = '*';
        matrix[m + 1][m + 5] = '*';
        matrix[2][7] = '*';
        matrix[m + 1][m + 8] = '*';
        matrix[m + 1][m + 9] = '*';
        matrix[m + 2][m + 2] = '*';
        matrix[m + 2][m + 7] = '*';
    } else if (stan == 4) {
        matrix[m][m + 1] = '*';
        matrix[m][m + 2] = '*';
        matrix[m][m + 5] = '*';
        matrix[m][m + 6] = '*';
        matrix[m + 1][m + 3] = '*';
        matrix[m + 1][m + 4] = '*';
        matrix[m + 2][m + 3] = '*';
        matrix[m + 2][m + 4] = '*';
        matrix[m + 3][m] = '*';
        matrix[m + 3][m + 2] = '*';
        matrix[m + 3][m + 5] = '*';
        matrix[m + 3][m + 7] = '*';
        matrix[m + 4][m] = '*';
        matrix[m + 4][m + 7] = '*';
        matrix[m + 6][m] = '*';
        matrix[m + 6][m + 7] = '*';
        matrix[m + 7][m + 1] = '*';
        matrix[m + 7][m + 2] = '*';
        matrix[m + 7][m + 5] = '*';
        matrix[m + 7][m + 6] = '*';
        matrix[m + 8][m + 2] = '*';
        matrix[m + 8][m + 3] = '*';
        matrix[m + 8][m + 4] = '*';
        matrix[m + 8][m + 5] = '*';
        matrix[m + 10][m + 3] = '*';
        matrix[m + 10][m + 4] = '*';
        matrix[m + 11][m + 3] = '*';
        matrix[m + 11][m + 4] = '*';
    } else if (stan == 5) {
        matrix[m][m] = '*';
        matrix[m][m + 1] = '*';
        matrix[m][m + 2] = '*';
        matrix[m][m + 3] = '*';
        matrix[m][m + 4] = '*';
        matrix[m + 1][m] = '*';
        matrix[m + 1][m + 5] = '*';
        matrix[m + 1][m + 13] = '*';
        matrix[m + 1][m + 14] = '*';
        matrix[m + 2][m] = '*';
        matrix[m + 2][m + 12] = '*';
        matrix[m + 2][m + 13] = '*';
        matrix[m + 2][m + 15] = '*';
        matrix[m + 2][m + 16] = '*';
        matrix[m + 2][m + 17] = '*';
        matrix[m + 3][m + 1] = '*';
        matrix[m + 3][m + 11] = '*';
        matrix[m + 3][m + 12] = '*';
        matrix[m + 3][m + 14] = '*';
        matrix[m + 3][m + 15] = '*';
        matrix[m + 3][m + 16] = '*';
        matrix[m + 3][m + 17] = '*';
        matrix[m + 4][m + 3] = '*';
        matrix[m + 4][m + 4] = '*';
        matrix[m + 4][m + 8] = '*';
        matrix[m + 4][m + 9] = '*';
        matrix[m + 4][m + 11] = '*';
        matrix[m + 4][m + 12] = '*';
        matrix[m + 4][m + 15] = '*';
        matrix[m + 4][m + 16] = '*';
        matrix[m + 5][m + 5] = '*';
        matrix[m + 5][m + 10] = '*';
        matrix[m + 5][m + 13] = '*';
        matrix[m + 6][m + 6] = '*';
        matrix[m + 6][m + 8] = '*';
        matrix[m + 6][m + 10] = '*';
        matrix[m + 6][m + 12] = '*';
        matrix[m + 7][m + 7] = '*';
        matrix[m + 8][m + 7] = '*';
        matrix[m + 9][m + 6] = '*';
        matrix[m + 9][m + 8] = '*';
        matrix[m + 9][m + 10] = '*';
        matrix[m + 9][m + 12] = '*';
        matrix[m + 10][m + 5] = '*';
        matrix[m + 10][m + 10] = '*';
        matrix[m + 10][m + 13] = '*';
        matrix[m + 11][m + 3] = '*';
        matrix[m + 11][m + 4] = '*';
        matrix[m + 11][m + 8] = '*';
        matrix[m + 11][m + 9] = '*';
        matrix[m + 11][m + 11] = '*';
        matrix[m + 11][m + 12] = '*';
        matrix[m + 11][m + 15] = '*';
        matrix[m + 11][m + 16] = '*';
        matrix[m + 12][m + 1] = '*';
        matrix[m + 12][m + 11] = '*';
        matrix[m + 12][m + 12] = '*';
        matrix[m + 12][m + 14] = '*';
        matrix[m + 12][m + 15] = '*';
        matrix[m + 12][m + 16] = '*';
        matrix[m + 12][m + 17] = '*';
        matrix[m + 13][m] = '*';
        matrix[m + 13][m + 12] = '*';
        matrix[m + 13][m + 13] = '*';
        matrix[m + 13][m + 15] = '*';
        matrix[m + 13][m + 16] = '*';
        matrix[m + 13][m + 17] = '*';
        matrix[m + 14][m] = '*';
        matrix[m + 14][m + 5] = '*';
        matrix[m + 14][m + 13] = '*';
        matrix[m + 14][m + 14] = '*';
        matrix[m + 15][m] = '*';
        matrix[m + 15][m + 1] = '*';
        matrix[m + 15][m + 2] = '*';
        matrix[m + 15][m + 3] = '*';
        matrix[m + 15][m + 4] = '*';
    }
}

void reverse_matrix(int size, char matrix[][size], char secondary_matrix[][size]) {

    for (int line = 1; line < size; line++) {
        for (int column = 1; column < size; column++) {
            matrix[line][column] = secondary_matrix[line][column];
        }
    }
}

void empty_matrix(int size, char matrix[][size]) {

    for (int line = 1; line < size; line++) {
        for (int column = 1; column < size; column++) {
            if (matrix[line][column] == '*') matrix[line][column] = ' ';
        }
    }
}
#endif //GAME_OF_LIFE_MANAGE_MATRIX_H
