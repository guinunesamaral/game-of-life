//
// Created by guin on 11/28/2020.
//

#ifndef GAME_OF_LIFE_MANAGE_PATTERNS_H
#define GAME_OF_LIFE_MANAGE_PATTERNS_H

#include <stdio.h>
#include <windows.h>

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
    printf("\n\nType one of the numbers above so we can move forward: ");
    scanf("%d", &stan);

    for (int i = 0; i <= 4; i++) {
        if (op[i] == stan) cont++;
    }
    if (cont == 0) standard_choice();

    return (stan);
}

#endif //GAME_OF_LIFE_MANAGE_PATTERNS_H
