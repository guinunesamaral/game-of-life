//
// Created by guin on 11/28/2020.
//

#ifndef GAME_OF_LIFE_EXECUTE_CONTROLLER_H
#define GAME_OF_LIFE_EXECUTE_CONTROLLER_H

#include <stdbool.h>
#include "./play.h"
#include "../model/manage_matrix.h"
#include "../model/manage_patterns.h"
#include "../model/manage_generation.h"
#include "../view/prompts.h"

#define N 100

void execute_controller() {
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

#endif //GAME_OF_LIFE_EXECUTE_CONTROLLER_H
