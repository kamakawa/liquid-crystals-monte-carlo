#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


#define L 10       // Tamanho da grade (pode ser alterado)
#define J 1        // Constante de interação (normalmente 1)
#define H 0.5      // Campo magnético externo (pode ser alterado)

int spins[L][L];

// Função para inicializar os spins aleatoriamente (+1 ou -1)
void inicializarSpins() {
    srand(time(NULL));  // Gerador de números aleatórios
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            spins[i][j] = (rand() % 2) ? 1 : -1;
        }
    }
}

// Função para imprimir a rede de spins
void imprimirSpins() {
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            printf("%c ", (spins[i][j] == 1) ? 'O' : 'X');
        }
        printf("\n");
    }
}

// Função para calcular a magnetização média
double calcularMagnetizacao() {
    int soma = 0;
    int N = L * L;  // Número total de spins na grade
    
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            soma += spins[i][j];
        }
    }
    
    return (double)soma / N;  // Converte para double para evitar truncamento
}

// Função para calcular a energia local de um spin
int calcularEnergia(int i, int j) {
    int cima = spins[(i - 1 + L) % L][j];
    int baixo = spins[(i + 1) % L][j];
    int esquerda = spins[i][(j - 1 + L) % L];
    int direita = spins[i][(j + 1) % L];

    int somaVizinhos = cima + baixo + esquerda + direita;
    return -J * spins[i][j] * somaVizinhos - H * spins[i][j];
}

// Função para calcular a energia total da rede
double calcularEnergiaTotal() {
    double energiaTotal = 0.0;
    
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            energiaTotal += calcularEnergia(i, j);
        }
    }

    return energiaTotal / 4.0;  // Dividimos por 4 para evitar contagem excessiva
}

// Função para calcular a variação de energia ao inverter um spin
int deltaEnergia(int i, int j) {
    int energiaAtual = calcularEnergia(i, j);
    spins[i][j] *= -1;  // Inverte temporariamente o spin
    int energiaNova = calcularEnergia(i, j);
    spins[i][j] *= -1;  // Reverte a inversão
    return energiaNova - energiaAtual;
}

// Função para realizar uma etapa de Monte Carlo
void monteCarloStep(double temperatura) {
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            int dE = deltaEnergia(i, j);
            double prob = exp(-dE / temperatura);
            if (dE <= 0 || ((double)rand() / RAND_MAX) < prob) {
                spins[i][j] *= -1;  // Aceita a mudança de estado
            }
        }
    }
}

// Função principal
int main(int argc, char *argv[]) {
    int iteracoes = atof(argv[1]);      //Número de pontos sorteados
    double temperatura = atof(argv[2]);

    inicializarSpins();     //cria a primeira grade de spins aleatórios
    printf("Rede de spins inicial:\n");
    imprimirSpins();    //função que mostra a grade gerada

    double energiaMedia = 0.0;
    double magnetizacaoMedia = 0.0;

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
    printf("Magnetização media: %.4f\n", magnetizacaoMedia);
    
    return 0;
}

