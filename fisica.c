#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define L 20       // Tamanho da grade, pode ser alterada
#define J 1        // Constante de interação (pode ser 1 para simplificar)
#define H 0.5      // Campo magnético externo, pode ser alterada

int spins[L][L];

// Função para inicializar os spins aleatoriamente
void inicializarSpins() {
    srand(time(NULL));  // Semente para números aleatórios
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            spins[i][j] = (rand() % 2) ? 1 : -1;
        }
    }
}

// Função para imprimir a rede de spins com símbolos O e X
void imprimirSpins() {
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            if (spins[i][j] == 1) {
                printf("O ");  // Spin para cima (O), +1
            } else {
                printf("X ");  // Spin para baixo (X), -1
            }
        }
        printf("\n");
    }
}

// Função para calcular a energia local de um spin (com campo magnético)
int calcularEnergia(int i, int j) {
    int cima = spins[(i - 1 + L) % L][j];
    int baixo = spins[(i + 1) % L][j];
    int esquerda = spins[i][(j - 1 + L) % L];
    int direita = spins[i][(j + 1) % L];
    int somaVizinhos = cima + baixo + esquerda + direita;
    int energia = -J * spins[i][j] * somaVizinhos - H * spins[i][j];
    return energia;
}

// Função para calcular a energia total da rede
float calcularEnergiaTotal() {
    float energiaTotal = 0.0;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            energiaTotal += calcularEnergia(i, j);
        }
    }
    return energiaTotal / 2.0;  // Dividir por 2 para evitar contar duas vezes
}

// Função para calcular a magnetização total
float calcularMagnetizacao() {
    int soma = 0;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            soma += spins[i][j];
        }
    }
    return (float)soma / (L * L);  // Magnetização média
}

// Função para calcular a variação de energia ao inverter o spin
int deltaEnergia(int i, int j) {
    int energiaAtual = calcularEnergia(i, j);
    spins[i][j] *= -1;
    int energiaNova = calcularEnergia(i, j);
    spins[i][j] *= -1;
    return energiaNova - energiaAtual;
}

// Função para realizar uma etapa de Monte Carlo
void monteCarloStep(float temperatura) {
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            int dE = deltaEnergia(i, j);
            float prob = exp(-dE / temperatura);
            if (dE <= 0 || ((float)rand() / RAND_MAX) < prob) {
                spins[i][j] *= -1;
            }
        }
    }
}

// Função principal
int main() {
    int iteracoes = 10000;
    float temperatura = 2.5;

    inicializarSpins();
    printf("Rede de spins inicial:\n");
    imprimirSpins();

    float energiaMedia = 0.0;
    float magnetizacaoMedia = 0.0;

    for (int t = 0; t < iteracoes; t++) {
        monteCarloStep(temperatura);
        energiaMedia += calcularEnergiaTotal();
        magnetizacaoMedia += calcularMagnetizacao();
    }

    energiaMedia /= iteracoes;
    magnetizacaoMedia /= iteracoes;
    printf("\nRede de spins apos a simulacao:\n");
    imprimirSpins();
    printf("\nEnergia media: %.4f\n", energiaMedia);
    printf("Magnetizacao media: %.4f\n", magnetizacaoMedia);
    
    return 0;
}
