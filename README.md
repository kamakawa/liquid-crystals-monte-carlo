# 💎 Liquid Crystals Monte Carlo

## 📝 Descrição
Este projeto implementa uma simulação computacional do modelo de Ising para estudar o comportamento de cristais líquidos utilizando o método de Monte Carlo. A simulação é realizada em C e busca explorar propriedades magnéticas e de ordenação dos spins em uma rede bidimensional.

## 🌌 Fundamentos Físicos
O modelo de Ising é amplamente utilizado para estudar fenômenos de transição de fase e magnetização em sistemas físicos. Ele representa um conjunto de spins que podem assumir valores +1 ou -1, dispostos em uma grade. As interações entre spins vizinhos são calculadas utilizando uma constante de acoplamento \(J\), enquanto um campo magnético externo \(H\) também influencia o alinhamento dos spins.

# 🧊 Simulador do Modelo de Ising 2D com Raylib

Este projeto é uma simulação interativa do modelo de Ising bidimensional utilizando a biblioteca gráfica [Raylib](https://www.raylib.com/). O objetivo é visualizar a evolução dos spins em uma grade e observar o comportamento térmico do sistema.

## 🔍 Sobre o Projeto

O modelo de Ising é um modelo matemático da física estatística utilizado para descrever o comportamento magnético de materiais. Nesta simulação, cada célula da grade representa um spin que pode estar em dois estados: +1 (para cima) ou -1 (para baixo).

- Os spins são atualizados com base no algoritmo de Metropolis.
- A temperatura do sistema pode ser ajustada em tempo real.
- A visualização gráfica mostra a configuração dos spins.

## 🎮 Controles

- **↑ (Seta para cima)**: Aumenta a temperatura do sistema  
- **↓ (Seta para baixo)**: Diminui a temperatura do sistema  
- **ESC**: Fecha a simulação  

A temperatura é exibida na tela durante a execução.

## 🧱 Estrutura

📁 LinguagemC
├── ising_simulador.c # Arquivo principal com simulação e visualização
├── makefile # Compilação simplificada

## ⚙️ Como Compilar e Rodar

### Requisitos

- [GCC](https://gcc.gnu.org/)
- [Raylib](https://github.com/raysan5/raylib) instalada no sistema

### Linux

```bash
make run

