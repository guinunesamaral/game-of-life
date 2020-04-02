#include <stdio.h>
#include <stdlib.h> // Biblioteca do system
#include <windows.h> // Biblioteca do Sleep no Windows
#include <conio.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
//#include <allegro5/allegro.h>
//#include <curses.h> // Só usar no Ubuntu

#define TRUE 1
#define FALSE 0

#define N 100

typedef int booleano;

int escolha();
int tamanho_matriz();
void preenche_bordas_matriz(int tamanho, char matriz[][tamanho]);
int matrix_or_standard();
int standard_choice();

void trevo_file();
void monograma_file();
void pentadecathlon_file();
void face_file();
void spaceship_file();

void standard_matriz(int tamanho, char matriz[][tamanho], int stan);
int n_seres_vivos();
void seres_matriz(int n_seres, int tamanho, char matriz[][tamanho]);

void matriz_original(int tamanho, char matriz[][tamanho], char matriz_sec[][tamanho]);
int n_generations();
int define_speed();
void survival_game(int tamanho, char matriz[][tamanho], char matriz_sec[][tamanho]);
void imprime_matriz(int tamanho, char matriz_sec[][tamanho]);
void inverte_matriz(int tamanho, char matriz[][tamanho], char matriz_sec[][tamanho]);
void esvazia_matriz(int tamanho, char matriz[][tamanho]);

void save_generation(int tamanho, char matriz[][tamanho]);

void copiar_conteudo(int tamanho, char matriz[][tamanho]);

void message1();
void message2();
void message3();
void message4();
void message5();
void message6();
void message7();
void message8();
void game_over();

int main(){
    setlocale(LC_ALL, "");

    int lenght, n_seres;

    int esc, stan;

    char life[N][N], original[N][N], life_new[N][N];

    int n_gen, gen;

    int choice; // Controla o "switch"

    booleano fim; // Controla o "do while" mais externo
    booleano actv_1 = FALSE; // Impede que o usuário comece pela opção 2
    booleano actv_4 = FALSE; // Impede que o usuário use o case 5 sem antes usar o case 4
    booleano actv_5 = FALSE; // Muda o curso do loop do case 1

    int speed;

    do{
        choice = escolha();
        switch (choice){
            case 1:
                lenght = tamanho_matriz() +1;
                preenche_bordas_matriz(lenght, life);
                preenche_bordas_matriz(lenght, life_new);

                esc = matrix_or_standard();
                if (esc == 2){
                    stan = standard_choice(); // Escolha dos padrões
                    standard_matriz(lenght, life, stan); // Adiciona o padrão escolhido à matriz
                }
                else if (esc == 1){
                    n_seres = n_seres_vivos();
                    seres_matriz(n_seres, lenght, life); // Adicionamos à matriz life os seres vivos em posições definidas pelo usuário
                }

                matriz_original(lenght, life, original); // Salva a matriz criada numa matriz estática
                actv_1 = TRUE;
                break;

            case 2:
                if (life[0][1] != '1' || actv_1 == FALSE){
                    message1();
                    Sleep(3000);
                    break;
                }
                if (actv_5 == FALSE) matriz_original(lenght, original, life);

                gen = 0;
                n_gen = n_generations(); // Número de rodadas (gerações) que serão jogadas
                do{

                    gen++;  // gen++ é o controle do "do while"
                    if (gen == 1) speed = define_speed();

                    survival_game(lenght, life, life_new); // Usamos a outra matriz criada para aplicar as regras de sobrevivência
                    system("cls");

                    printf("\nGeração: %d de %d\n", gen, n_gen); // Impressão da matriz levando em consideração as regras de sobrevivência

                    imprime_matriz(lenght, life_new);
                    Sleep(speed);

                    if (gen == n_gen){
                        Sleep(1000);
                        system("cls");
                        message2();
                        imprime_matriz(lenght, life_new);
                        Sleep(4000);
                    }
                    /* Aqui fazemos a matriz life (principal) receber os
                       elementos de life_new (secundária) e também "zeramos"
                       a matriz secundária, para que ela possa receber a próxima rodada */

                    inverte_matriz(lenght, life, life_new);
                    esvazia_matriz(lenght, life_new);

                }while (gen < n_gen);
                break;

            case 3:
                if (life[0][1] != '1' || actv_1 == FALSE){
                    message3();
                    Sleep(4000);
                    break;
                }
                esvazia_matriz(lenght, life_new);
                esvazia_matriz(lenght, life);
                esvazia_matriz(lenght, original);
                life[0][1] = ' '; life_new[0][1] = ' '; original[0][1] = ' ';

                message4();
                Sleep(4000);

                gen = 0;
                break;

            case 4:
                if (life[0][1] != '1' || actv_1 == FALSE){
                    message5();
                    Sleep(4000);
                    break;
                }
                save_generation(lenght, life);
                message6();
                actv_4 = TRUE;
                Sleep(3000);
                break;

            case 5:
                if (life[0][1] != '1' || actv_4 == FALSE){
                    message7();
                    Sleep(4000);
                    break;
                }
                copiar_conteudo(lenght, life_new);
                actv_5 = TRUE;
                message8();
                Sleep(3000);
                break;
            case 6:
                fim = TRUE;
                game_over();
                break;
        }
    }while (fim != TRUE);
}

int escolha(){
    int choice, cont = 0;
    int op[7] = {1, 2, 3, 4, 5, 6};

    system("cls");

    printf("\n(1) - Criar matriz");
    printf("\n(2) - Rodar o Jogo da Vida");
    printf("\n(3) - Esvaziar matriz criada");
    printf("\n(4) - Salvar a última geração em um arquivo");
    printf("\n(5) - Abrir uma geração previamente salva");
    printf("\n(6) - Finalizar o programa");
    printf("\n\nOlá, digite um dos números acima para dar as instruções: ");
    scanf("%d", &choice);

    for (int i = 0; i <= 5; i++){
        if (op[i] == choice) cont++;
    }
    if (cont == 0) escolha();

    return (choice);
}

int tamanho_matriz(){
    int lenght;

    printf("\nO mundo do Jogo da Vida consiste de uma matriz quadrada, ou seja, altura = comprimento.");
    printf("\n\nDefina o tamanho do mundo. De preferência algo entre 30 e 60: ");
    scanf("%d", &lenght);

    if (lenght < 30 || lenght > 60) tamanho_matriz();

    return (lenght);
}

void preenche_bordas_matriz(int tamanho, char matriz[][tamanho]){
	matriz[0][0] = ' ';

    for (int coluna = 0; coluna < tamanho; coluna++){
        if (coluna < 10){
            matriz[0][coluna] = coluna + '0';
        }
        else{
            matriz[0][coluna] = (coluna % 10)  + '0';
        }
    }
    for (int linha = 0; linha < tamanho; linha++){
        if (linha < 10){
            matriz[linha][0] = linha + '0';
        }
        else{
            matriz[linha][0] = (linha % 10) + '0';
        }
    }
    for (int linha = 1; linha < tamanho; linha++){
        for (int coluna = 1; coluna < tamanho; coluna++){
            matriz[linha][coluna] = ' ';
        }
    }
}

int matrix_or_standard(){
    int esc;

    system("cls");

    printf("\n(1) - Escolher os seres vivos");
    printf("\n(2) - Escolher imagem padrão");
    printf("\n\nDigite um dos números acima para dar as instruções: ");
    scanf("%d", &esc);

    if (esc != 1 && esc != 2) matrix_or_standard();

    return (esc);
}

int standard_choice(){
    int stan, cont = 0;
    int op[5] = {1, 2, 3, 4, 5};

    system("cls");

    trevo_file();
    monograma_file();
    pentadecathlon_file();
    face_file();
    spaceship_file();

    printf("\n(1) - TREVO");
    printf("\n(2) - MONOGRAMA");
    printf("\n(3) - PENTADECATHLON");
    printf("\n(4) - FACE");
    printf("\n(5) - NAVE");
    printf("\n\nDigite um dos números acima para prosseguirmos: ");
    scanf("%d", &stan);

    for (int i = 0; i <= 4; i++){
        if (op[i] == stan) cont++;
    }
    if (cont == 0) standard_choice();

    return (stan);
}

void trevo_file(){
    FILE *arq;
    arq = fopen("trevo.txt", "r");

    char frase[100];

    printf("\n**************TREVO**************\n\n");
    while (fgets(frase, 100, arq) != NULL){
        printf("%s", frase);
    }
    printf("\n");
}

void monograma_file(){
    FILE *arq;
    arq = fopen("monograma.txt", "r");

    char frase[100];

    printf("\n**************MONOGRAMA**************\n\n");
    while (fgets(frase, 100, arq) != NULL){
        printf("%s", frase);
    }
    printf("\n");
}

void pentadecathlon_file(){
    FILE *arq;
    arq = fopen("pentadecathlon.txt", "r");

    char frase[100];

    printf("\n**********PENTADECATHLON**********\n\n");
    while (fgets(frase, 100, arq) != NULL){
        printf("%s", frase);
    }
    printf("\n");
}

void face_file(){
    FILE *arq;
    arq = fopen("face.txt", "r");

    char frase[100];

    printf("\n*************FACE*************\n\n");
    while (fgets(frase, 100, arq) != NULL){
        printf("%s", frase);
    }
    printf("\n");
}

void spaceship_file(){
    FILE *arq;
    arq = fopen("spaceship.txt", "r");

    char frase[100];

    printf("\n************************************NAVE************************************\n\n");
    while (fgets(frase, 100, arq) != NULL){
        printf("%s", frase);
    }
    printf("\n");
}

void standard_matriz(int tamanho, char matriz[][tamanho], int stan){
    int m = tamanho / 3; // Tratar o m como se fosse o 1

    if (stan == 1){
        matriz[m][m +3] = '*'; matriz[m][m +5] = '*';
        matriz[m +1][m +1] = '*'; matriz[m +1][m +2] = '*'; matriz[m +1][m +3] = '*'; matriz[m +1][m +5] = '*'; matriz[m +1][m +6] = '*'; matriz[m +1][m +7] = '*';
        matriz[m +2][m] = '*'; matriz[m +2][m +4] = '*'; matriz[m +2][m +8] = '*';
        matriz[m +3][m] = '*'; matriz[m +3][m +2] = '*'; matriz[m +3][m +6] = '*'; matriz[m +3][m +8] = '*';
        matriz[m +4][m +1] = '*'; matriz[m +4][m +2] = '*'; matriz[m +4][m +4] = '*'; matriz[m +4][m +6] = '*'; matriz[m +4][m +7] = '*';

        matriz[m +6][m +1] = '*'; matriz[m +6][m +2] = '*'; matriz[m +6][m +4] = '*'; matriz[m +6][m +6] = '*'; matriz[m +6][m +7] = '*';
        matriz[m +7][m] = '*'; matriz[m +7][m +2] = '*'; matriz[m +7][m +6] = '*'; matriz[m +7][m +8] = '*';
        matriz[m +8][m] = '*'; matriz[m +8][m +4] = '*'; matriz[m +8][m +8] = '*';
        matriz[m +9][m +1] = '*'; matriz[m +9][m +2] = '*'; matriz[m +9][m +3] = '*'; matriz[m +9][m +5] = '*'; matriz[m +9][m +6] = '*'; matriz[m +9][m +7] = '*';
        matriz[m +10][m +3] = '*'; matriz[m +10][m +5] = '*';

    }
    else if (stan == 2){
        matriz[m][m] = '*'; matriz[m][m +1] = '*'; matriz[m][m +5] = '*'; matriz[m][m +6] = '*';
        matriz[m +1][m +1] = '*'; matriz[m +1][m +3] = '*'; matriz[m +1][m +5] = '*';
        matriz[m +2][m +1] = '*'; matriz[m +2][m +2] = '*'; matriz[m +2][m +4] = '*'; matriz[m +2][m +5] = '*';
        matriz[m +3][m +1] = '*'; matriz[m +3][m +3] = '*'; matriz[m +3][m +5] = '*';
        matriz[m +4][m] = '*'; matriz[m +4][m +1] = '*'; matriz[m +4][m +5] = '*'; matriz[m +4][m +6] = '*';
    }
    else if (stan == 3){
        matriz[m][m +2] = '*'; matriz[m][m +7] = '*';
        matriz[m +1][m] = '*'; matriz[m +1][m +1] = '*'; matriz[2][4] = '*';matriz[m +1][m +4] = '*'; matriz[m +1][m +5] = '*'; matriz[2][7] = '*'; matriz[m +1][m +8] = '*'; matriz[m +1][m +9] = '*';
        matriz[m +2][m +2] = '*'; matriz[m +2][m +7] = '*';
    }
    else if (stan == 4){
        matriz[m][m +1] = '*'; matriz[m][m +2] = '*'; matriz[m][m +5] = '*'; matriz[m][m +6] = '*';
        matriz[m +1][m +3] = '*'; matriz[m +1][m +4] = '*';
        matriz[m +2][m +3] = '*'; matriz[m +2][m +4] = '*';
        matriz[m +3][m] = '*'; matriz[m +3][m +2] = '*'; matriz[m +3][m +5] = '*'; matriz[m +3][m +7] = '*';
        matriz[m +4][m] = '*'; matriz[m +4][m +7] = '*';
        matriz[m +6][m] = '*'; matriz[m +6][m +7] = '*';
        matriz[m +7][m+1] = '*'; matriz[m +7][m +2] = '*'; matriz[m +7][m +5] = '*'; matriz[m +7][m +6] = '*';
        matriz[m +8][m +2] = '*'; matriz[m +8][m +3] = '*'; matriz[m +8][m +4] = '*'; matriz[m +8][m +5] = '*';
        matriz[m +10][m +3] = '*'; matriz[m +10][m +4] = '*';
        matriz[m +11][m +3] = '*'; matriz[m +11][m +4] = '*';
    }
    else if (stan == 5){
        matriz[m][m] = '*'; matriz[m][m +1] = '*'; matriz[m][m +2] = '*'; matriz[m][m +3] = '*'; matriz[m][m +4] = '*';
        matriz[m +1][m] = '*'; matriz[m +1][m +5] = '*'; matriz[m +1][m +13] = '*'; matriz[m +1][m +14] = '*';
        matriz[m +2][m] = '*'; matriz[m +2][m +12] = '*'; matriz[m +2][m +13] = '*'; matriz[m +2][m +15] = '*'; matriz[m +2][m +16] = '*'; matriz[m +2][m +17] = '*';
        matriz[m +3][m +1] = '*'; matriz[m +3][m +11] = '*'; matriz[m +3][m +12] = '*'; matriz[m +3][m +14] = '*'; matriz[m +3][m +15] = '*'; matriz[m +3][m +16] = '*'; matriz[m +3][m +17] = '*';
        matriz[m +4][m +3] = '*'; matriz[m +4][m +4] = '*'; matriz[m +4][m +8] = '*'; matriz[m +4][m +9] = '*'; matriz[m +4][m +11] = '*'; matriz[m +4][m +12] = '*'; matriz[m +4][m +15] = '*'; matriz[m +4][m +16] = '*';
        matriz[m +5][m +5] = '*'; matriz[m +5][m +10] = '*'; matriz[m +5][m +13] = '*';
        matriz[m +6][m +6] = '*'; matriz[m +6][m +8] = '*'; matriz[m +6][m +10] = '*'; matriz[m +6][m +12] = '*';
        matriz[m +7][m +7] = '*';
        matriz[m +8][m +7] = '*';
        matriz[m +9][m +6] = '*'; matriz[m +9][m +8] = '*'; matriz[m +9][m +10] = '*'; matriz[m +9][m +12] = '*';
        matriz[m +10][m +5] = '*'; matriz[m +10][m +10] = '*'; matriz[m +10][m +13] = '*';
        matriz[m +11][m +3] = '*'; matriz[m +11][m +4] = '*'; matriz[m +11][m +8] = '*'; matriz[m +11][m +9] = '*'; matriz[m +11][m +11] = '*'; matriz[m +11][m +12] = '*'; matriz[m +11][m +15] = '*'; matriz[m +11][m +16] = '*';
        matriz[m +12][m +1] = '*'; matriz[m +12][m +11] = '*'; matriz[m +12][m +12] = '*'; matriz[m +12][m +14] = '*'; matriz[m +12][m +15] = '*'; matriz[m +12][m +16] = '*'; matriz[m +12][m +17] = '*';
        matriz[m +13][m] = '*'; matriz[m +13][m +12] = '*'; matriz[m +13][m +13] = '*'; matriz[m +13][m +15] = '*'; matriz[m +13][m +16] = '*'; matriz[m +13][m +17] = '*';
        matriz[m +14][m] = '*'; matriz[m +14][m +5] = '*'; matriz[m +14][m +13] = '*'; matriz[m +14][m +14] = '*';
        matriz[m +15][m] = '*'; matriz[m +15][m +1] = '*'; matriz[m +15][m +2] = '*'; matriz[m +15][m +3] = '*'; matriz[m +15][m +4] = '*';
    }
}

int n_seres_vivos(){
    int n_seres;

    printf("\n********Regras do Jogo da Vida********\n");
    printf("\n(1) - Cada ser vivo possui 8 vizinhos");
    printf("\n(2) - Um ser vivo nascerá numa célula com exatos 3 vizinhos");
    printf("\n(2) - Um ser vivo sozinho morrerá de solidão");
    printf("\n(3) - Um ser vivo com mais de 4 vizinhos morrerá de fome");
    printf("\n(4) - Um ser vivo com 2 ou 3 vizinhos permanecerá na próxima rodada");
    printf("\n\nDefina o número de seres vivos que você deseja: ");
    scanf("%d", &n_seres);

    if (n_seres < 0) n_seres = n_seres * (-1);
    if (n_seres == 0) n_seres++;

    return (n_seres);
}

void seres_matriz(int n_seres, int tamanho, char matriz[][tamanho]){
    int linha, coluna;

    system("cls");

    printf("\nAgora, digite as posições dos seres vivos na matriz - coordenadas x e y.\n");
    Sleep(2000);

    for (int i = 1; i <= n_seres; i++){
        system("cls");
        printf("\nObserve a tela e defina as posições dos seres vivos.\n");

        imprime_matriz(tamanho, matriz);

        printf("\nLinha: ");
        scanf("%d", &linha);
        if (linha < 0) linha = linha * (-1);
        if (linha == 0) linha++;
        if (linha == tamanho) linha--;

        printf("\nColuna: ");
        scanf("%d", &coluna);
        if (coluna < 0) coluna = coluna * (-1);
        if (coluna == 0) coluna++;
        if (coluna == tamanho) coluna--;

        matriz[linha][coluna] = '*';
    }
    system("cls");
    printf("\n************A matriz que você criou!************\n");
    imprime_matriz(tamanho, matriz);
}

int n_generations(){
    int n_gen;
    int op;

    Sleep(2000);
    system("cls");

    printf("\n(1) - Escolher o número de gerações a serem rodadas");
    printf("\n(2) - Rodar uma única geração");
    printf("\n\nDigite sua escolha: ");
    scanf("%d", &op);

    if (op == 1){
        printf("\nDigite o número de gerações que você deseja: ");
        scanf("%d", &n_gen);
    }
    else if (op == 2) n_gen = 1;

    if (n_gen < 1) n_generations();

    return (n_gen);
}

void matriz_original(int tamanho, char matriz[][tamanho], char matriz_sec[][tamanho]){

    for (int linha = 0; linha < tamanho; linha++){
        for (int coluna = 0; coluna < tamanho; coluna++){
            matriz_sec[linha][coluna] = matriz[linha][coluna];
        }
    }
}

int define_speed(){
    int speed;

    printf("\nDigite um valor em milissegundos para a simulação da matriz - algo entre 100 e 1000. Sugiro 250.");
    printf("\n\nSpeed: ");
    scanf("%d", &speed);

    if (speed < 100 || speed > 1000) define_speed();

    return (speed);
}

void survival_game(int tamanho, char matriz[][tamanho], char matriz_sec[][tamanho]){
    int viz = 0;

    for (int linha = 1; linha < tamanho; linha ++){
        for (int coluna = 1; coluna < tamanho; coluna++){
            if (matriz[linha][coluna] == ' '){
                if (matriz[linha -1][coluna -1] == '*') viz++;
                if (matriz[linha -1][coluna ] == '*') viz++;
                if (matriz[linha -1][coluna +1] == '*') viz++;
                if (matriz[linha][coluna -1] == '*') viz++;
                if (matriz[linha][coluna +1] == '*') viz++;
                if (matriz[linha +1][coluna -1] == '*') viz++;
                if (matriz[linha +1][coluna] == '*') viz++;
                if (matriz[linha +1][coluna +1] == '*') viz++;

                if (viz == 3) matriz_sec[linha][coluna] = '*';
                viz = 0;
            }
            else if (matriz[linha][coluna] == '*'){
                if (matriz[linha -1][coluna -1] == '*') viz++;
                if (matriz[linha -1][coluna ] == '*') viz++;
                if (matriz[linha -1][coluna +1] == '*') viz++;
                if (matriz[linha][coluna -1] == '*') viz++;
                if (matriz[linha][coluna +1] == '*') viz++;
                if (matriz[linha +1][coluna -1] == '*') viz++;
                if (matriz[linha +1][coluna] == '*') viz++;
                if (matriz[linha +1][coluna +1] == '*') viz++;

                if ((viz == 2) || (viz == 3)) matriz_sec[linha][coluna] = '*';

                else matriz_sec[linha][coluna] = ' ';

                viz = 0;
            }
        }
    }
}

void imprime_matriz(int tamanho, char matriz_sec[][tamanho]){
    int back_lin, back_col;
    matriz_sec[0][0] = ' ';

    printf("\n");

    for (int linha = 0; linha < tamanho; linha++){
        for (int coluna = 0; coluna < tamanho; coluna++){
            if (coluna == 0){
                if (linha <= 9){
                    printf(" %c", matriz_sec[linha][0]);
                    printf(" ");
                }
                else{
                    back_lin = linha / 10;
                    printf("%c%c", matriz_sec[back_lin][0], matriz_sec[linha][0]);
                    printf(" ");
                }
            }
        	else{
                if (linha == 0){
                    if (coluna > 9){
                        back_col = coluna / 10;
                        printf("%c%c", matriz_sec[0][(back_col) % 10], matriz_sec[0][coluna]);
                        printf(" ");
                    }
                    else{
                        printf(" %c", matriz_sec[0][coluna]);
                        printf(" ");
                    }
                }
                else{
                    printf(" %c", matriz_sec[linha][coluna]);
                    printf(" ");
                }
        	}
        }
        printf("\n");
    }
}

void inverte_matriz(int tamanho, char matriz[][tamanho], char matriz_sec[][tamanho]){

    for (int linha = 1; linha < tamanho; linha++){
        for (int coluna = 1; coluna < tamanho; coluna++){
            matriz[linha][coluna] = matriz_sec[linha][coluna];
        }
    }
}

void esvazia_matriz(int tamanho, char matriz[][tamanho]){

    for (int linha = 1; linha < tamanho; linha++){
        for (int coluna = 1; coluna < tamanho; coluna++){
            if (matriz[linha][coluna] == '*') matriz[linha][coluna] = ' ';
        }
    }
}

void save_generation(int tamanho, char matriz[][tamanho]){
    FILE *arq;
    arq = fopen("generation.txt", "w");

    int back_lin, back_col;

    for (int linha = 0; linha < tamanho; linha++){
        for (int coluna = 0; coluna < tamanho; coluna++){
            if (coluna == 0){
                if (linha <= 9){
                    fprintf(arq, " %c", matriz[linha][0]);
                    fprintf(arq, "%c", ' ');
                }
                else{
                    back_lin = linha / 10;
                    fprintf(arq, "%c%c", matriz[back_lin][0], matriz[linha][0]);
                    fprintf(arq, "%c", ' ');
                }
            }
        	else{
                if (linha == 0){
                    if (coluna > 9){
                        back_col = coluna / 10;
                        fprintf(arq, "%c%c", matriz[0][back_col % 10], matriz[0][coluna]);
                        fprintf(arq, "%c", ' ');
                    }
                    else{
                        fprintf(arq, " %c", matriz[0][coluna]);
                        fprintf(arq, "%c", ' ');
                    }
                }
                else{
                    fprintf(arq, " %c", matriz[linha][coluna]);
                    fprintf(arq, "%c", ' ');
                }
        	}
        }
        fprintf(arq, "%c", '\n');
    }
    fclose(arq);
}

void copiar_conteudo(int tamanho, char matriz[][tamanho]){
    FILE *arq;
    arq = fopen("generation.txt", "r");

    char reader;
    char scanner[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    int pass = 1, i = 0;

    for (int linha = 1; linha < tamanho; linha++){
        for (int coluna = 1; coluna < tamanho; coluna++){
            reader = fgetc(arq);
            while (pass == 1 && i < 10){
                if (reader == scanner[i]) pass = 0;
                i++;
            }
            if (pass == 1){
                matriz[linha][coluna] = reader;
            }
            else matriz[linha][coluna] = ' ';
            pass = 1;
            i = 0;
        }
    }
    fclose(arq);
}

void message1(){
	printf("\nVocê precisa criar sua matriz antes de jogar!");
}

void message2(){
	printf("\nA geração final de seu jogo.\n");
}

void message3(){
	printf("\nVocê precisa criar sua matriz se quiser esvaziá-la!");
}

void message4(){
	printf("\nMatriz esvaziada com sucesso!");
}

void message5(){
	printf("\nVocê precisa criar sua matriz se quiser salvá-la!");
}

void message6(){
	printf("\nGeração salva com sucesso.");
}

void message7(){
	printf("\nVocê precisa salvar sua matriz se quiser reaproveitá-la!");
}

void message8(){
	printf("\nGeração incorporada com sucesso à matriz.");
}

void game_over(){
	printf("\n***************Game Over***************\n");
}

