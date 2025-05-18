#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define LARGURA 800
#define ALTURA 800

#define TAMANHO_GRADE 100
#define TAMANHO_CELULA (LARGURA / TAMANHO_GRADE)

int grade[TAMANHO_GRADE][TAMANHO_GRADE];
float temperatura = 2.5f;

// Inicializa a grade com spins aleatórios
void inicializar_grade() {
    for (int y = 0; y < TAMANHO_GRADE; y++) {
        for (int x = 0; x < TAMANHO_GRADE; x++) {
            grade[y][x] = (rand() % 2) * 2 - 1;
        }
    }
}

// Calcula a energia local de uma célula
int energia_local(int x, int y) {
    int cima = grade[(y - 1 + TAMANHO_GRADE) % TAMANHO_GRADE][x];
    int baixo = grade[(y + 1) % TAMANHO_GRADE][x];
    int esquerda = grade[y][(x - 1 + TAMANHO_GRADE) % TAMANHO_GRADE];
    int direita = grade[y][(x + 1) % TAMANHO_GRADE];
    return grade[y][x] * (cima + baixo + esquerda + direita);
}

// Atualiza a grade usando o algoritmo de Metropolis
void atualizar_modelo() {
    for (int n = 0; n < TAMANHO_GRADE * TAMANHO_GRADE; n++) {
        int x = rand() % TAMANHO_GRADE;
        int y = rand() % TAMANHO_GRADE;

        int dE = 2 * energia_local(x, y);

        if (dE <= 0 || ((float)rand() / RAND_MAX) < expf(-dE / temperatura)) {
            grade[y][x] *= -1;
        }
    }
}

// Desenha a grade na tela
void desenhar_grade() {
    for (int y = 0; y < TAMANHO_GRADE; y++) {
        for (int x = 0; x < TAMANHO_GRADE; x++) {
            Color cor = (grade[y][x] == 1) ? RED : BLUE;
            DrawRectangle(x * TAMANHO_CELULA, y * TAMANHO_CELULA, TAMANHO_CELULA, TAMANHO_CELULA, cor);
        }
    }
}

// Calcula a energia total do sistema
float calcular_energia_total() {
    float energia_total = 0.0f;
    for (int y = 0; y < TAMANHO_GRADE; y++) {
        for (int x = 0; x < TAMANHO_GRADE; x++) {
            int direita = grade[y][(x + 1) % TAMANHO_GRADE];
            int baixo = grade[(y + 1) % TAMANHO_GRADE][x];
            energia_total -= grade[y][x] * (direita + baixo);
        }
    }
    return energia_total;
}

// Calcula a magnetização média
float calcular_magnetizacao() {
    int total = 0;
    for (int y = 0; y < TAMANHO_GRADE; y++) {
        for (int x = 0; x < TAMANHO_GRADE; x++) {
            total += grade[y][x];
        }
    }
    return (float)total / (TAMANHO_GRADE * TAMANHO_GRADE);
}

int main() {
    srand(time(NULL));
    InitWindow(LARGURA, ALTURA + 100, "Modelo de Ising - Raylib com Nomes em Portugues");
    SetTargetFPS(60);
    inicializar_grade();

    while (!WindowShouldClose()) {
        // Controle da temperatura
        if (IsKeyDown(KEY_UP)) temperatura += 0.01f;
        if (IsKeyDown(KEY_DOWN)) temperatura -= 0.01f;
        if (temperatura < 0.01f) temperatura = 0.01f;

        atualizar_modelo();

        float energia = calcular_energia_total() / (TAMANHO_GRADE * TAMANHO_GRADE);
        float magnetizacao = calcular_magnetizacao();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        desenhar_grade();

        char buffer[50];
        sprintf(buffer, "Temperatura: %.2f", temperatura);
        DrawText(buffer, 10, 10, 20, BLACK);

        // Informações no rodapé
        DrawRectangle(0, ALTURA, LARGURA, 100, LIGHTGRAY);
        DrawText(TextFormat("Temperatura: %.2f", temperatura), 20, ALTURA + 20, 20, DARKGRAY);
        DrawText(TextFormat("Energia média: %.2f", energia), 20, ALTURA + 45, 20, DARKGRAY);
        DrawText(TextFormat("Magnetizacao média: %.2f", magnetizacao), 20, ALTURA + 70, 20, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
