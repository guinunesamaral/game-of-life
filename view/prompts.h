//
// Created by guin on 11/28/2020.
//

#ifndef GAME_OF_LIFE_PROMPTS_H
#define GAME_OF_LIFE_PROMPTS_H

#include <stdio.h>

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

#endif //GAME_OF_LIFE_PROMPTS_H
