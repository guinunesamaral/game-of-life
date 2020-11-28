#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

#define N 100

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

/* Files */

void clover_file() {
    FILE *file;
    file = fopen("./patterns/clover.txt", "r");

    char phrase[100];

    printf("\n**************CLOVER**************\n\n");
    while (fgets(phrase, 100, file) != NULL) {
        printf("%s", phrase);
    }
    printf("\n");
}

void monogram_file() {
    FILE *arq;
    arq = fopen("./patterns/monogram.txt", "r");

    char phrase[100];

    printf("\n**************MONOGRAM**************\n\n");
    while (fgets(phrase, 100, arq) != NULL) {
        printf("%s", phrase);
    }
    printf("\n");
}

void pentadecathlon_file() {
    FILE *file;
    file = fopen("./patterns/pentadecathlon.txt", "r");

    char phrase[100];

    printf("\n**********PENTADECATHLON**********\n\n");
    while (fgets(phrase, 100, file) != NULL) {
        printf("%s", phrase);
    }
    printf("\n");
}

void face_file() {
    FILE *file;
    file = fopen("./patterns/face.txt", "r");

    char phrase[100];

    printf("\n*************FACE*************\n\n");
    while (fgets(phrase, 100, file) != NULL) {
        printf("%s", phrase);
    }
    printf("\n");
}

void spaceship_file() {
    FILE *file;
    file = fopen("./patterns/spaceship.txt", "r");

    char phrase[100];

    printf("\n************************************SPACESHIP************************************\n\n");
    while (fgets(phrase, 100, file) != NULL) {
        printf("%s", phrase);
    }
    printf("\n");
}

int standard_choice() {
    int stan, cont = 0;
    int op[5] = {1, 2, 3, 4, 5};

    system("cls");

    clover_file();
    monogram_file();
    pentadecathlon_file();
    face_file();
    spaceship_file();

    printf("\n(1) - CLOVER");
    printf("\n(2) - MONOGRAM");
    printf("\n(3) - PENTADECATHLON");
    printf("\n(4) - FACE");
    printf("\n(5) - SPACESHIP");
    printf("\n\nType of of the numbers above so we can move forward: ");
    scanf("%d", &stan);

    for (int i = 0; i <= 4; i++) {
        if (op[i] == stan) cont++;
    }
    if (cont == 0) standard_choice();

    return (stan);
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

void original_matrix(int size, char matrix[][size], char secondary_matrix[][size]) {

    for (int line = 0; line < size; line++) {
        for (int column = 0; column < size; column++) {
            secondary_matrix[line][column] = matrix[line][column];
        }
    }
}

int define_speed() {
    int speed;

    printf("\nType a milliseconds value for the matrix simulation - something between 100 and 1000. I suggest 250");
    printf("\n\nSpeed: ");
    scanf("%d", &speed);

    if (speed < 100 || speed > 1000) define_speed();

    return (speed);
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

void create_matrix_before_playing_prompt() {
    printf("\nYou need to create a matrix before playing!");
}

void final_generation_prompt() {
    printf("\nThe final generation of your game.\n");
}

void empty_matrix_prompt() {
    printf("\nYou need to create your matrix if you want to empty it!");
}

void emptied_matrix_prompt() {
    printf("\nMatrix successfully emptied!");
}

void save_matrix_prompt() {
    printf("\nYou need to create your matrix if you want to save it!");
}

void generation_saved_prompt() {
    printf("\nGeneration saved successfully.");
}

void reuse_generation_prompt() {
    printf("\nYou need to save your matrix if you want to reuse it!");
}

void generation_built_in_successfully_prompt() {
    printf("\nGeneration successfully incorporated to the matrix.");
}

void game_over() {
    printf("\n***************Game Over***************\n");
}

int main() {
    int length, n_liv_beings;
    int choice, standard;
    char life[N][N], original[N][N], life_new[N][N];
    int n_gen, actual_generation;
    int switch_choice; // Controls the switch statement
    bool end; // Controls the most extern "do while"
    bool option_one_chosen = false; // Prevents the user from starting by option 2
    bool option_four_chosen = false; // Prevents the user from using the 5th case before using the 4th case
    bool option_five_chosen = false; // Change the loop of case 1's flow
    int speed;

    do {
        switch_choice = main_choice();
        switch (switch_choice) {
            case 1:
                length = matrix_size() + 1;
                fill_matrix_edges(length, life);
                fill_matrix_edges(length, life_new);

                choice = matrix_or_standard();
                if (choice == 2) {
                    standard = standard_choice(); // Choice of patterns
                    standard_matrix(length, life, standard); // Add the chosen pattern to the matrix
                } else if (choice == 1) {
                    n_liv_beings = n_living_beings();
                    living_beings_matrix(n_liv_beings, length,
                                         life); // Add the living beings to the life matrix in coordinates defined by the user
                }

                original_matrix(length, life, original); // Saves the matrix created in a static matrix
                option_one_chosen = TRUE;
                break;

            case 2:
                if (life[0][1] != '1' || option_one_chosen == FALSE) {
                    create_matrix_before_playing_prompt();
                    Sleep(3000);
                    break;
                }
                if (option_five_chosen == FALSE) original_matrix(length, original, life);

                actual_generation = 0;
                n_gen = n_generations(); // Number of rounds (generations) to be played
                do {
                    actual_generation++;  // actual_generation++ controls the "do while" statement
                    if (actual_generation == 1) speed = define_speed();

                    survival_game(length, life, life_new); // Use the other matrix to apply the survival rules
                    system("cls");

                    printf("\nGeneration: %d of %d\n", actual_generation,
                           n_gen); // Print of the matrix taking into account the survival rules
                    print_matrix(length, life_new);
                    Sleep(speed);

                    if (actual_generation == n_gen) {
                        Sleep(1000);
                        system("cls");
                        final_generation_prompt();
                        print_matrix(length, life_new);
                        Sleep(4000);
                    }
                    /* Here we make the life matrix (main matrix) receive the
                     * living beings of life_new (secondary matrix) and delete everything
                     * the secondary matrix so it can receive the next round
                     * */

                    reverse_matrix(length, life, life_new);
                    empty_matrix(length, life_new);

                } while (actual_generation < n_gen);
                break;

            case 3:
                if (life[0][1] != '1' || option_one_chosen == FALSE) {
                    empty_matrix_prompt();
                    Sleep(4000);
                    break;
                }
                empty_matrix(length, life_new);
                empty_matrix(length, life);
                empty_matrix(length, original);
                life[0][1] = ' ';
                life_new[0][1] = ' ';
                original[0][1] = ' ';

                emptied_matrix_prompt();
                Sleep(4000);

                actual_generation = 0;
                break;

            case 4:
                if (life[0][1] != '1' || option_one_chosen == FALSE) {
                    save_matrix_prompt();
                    Sleep(4000);
                    break;
                }
                save_generation(length, life);
                generation_saved_prompt();
                option_four_chosen = TRUE;
                Sleep(3000);
                break;

            case 5:
                if (life[0][1] != '1' || option_four_chosen == false) {
                    reuse_generation_prompt();
                    Sleep(4000);
                    break;
                }
                copy_content(length, life_new);
                option_five_chosen = true;
                generation_built_in_successfully_prompt();
                Sleep(3000);
                break;
            case 6:
                end = true;
                game_over();
                break;
        }
    } while (end != true);
}