# 🧠 Simulação Computacional do Modelo de Ising — Iniciação Científica

> Repositório da Iniciação Científica de **Eric Kamakawa**, sob orientação dos professores **Rafael Zola** e **Rodolfo Teixeira**, na UTFPR — Apucarana.

---

## 🧪 Contextualização Física

Cristais líquidos são materiais que combinam propriedades de líquidos (fluidez) com a organização molecular dos cristais. Eles apresentam fases intermediárias como a **nemática**, onde moléculas tipo "bastonete" tendem a se alinhar, mas com liberdade de movimento. Esses sistemas são fundamentais em diversas tecnologias, como **telas LCD**, **materiais fotônicos**, **sensores químicos** e **dispositivos bioativos**.

Modelos como o **de Ising** ou o **de Lebwohl-Lasher** permitem simular, por meio de interações locais, a organização coletiva desses sistemas e suas **transições de fase**.

---

## 🧮 Métodos Computacionais Aplicados

Esta IC utiliza **técnicas de simulação de Monte Carlo** com o algoritmo de Metropolis, que permite emular o comportamento térmico de sistemas físicos por meio de sorteios probabilísticos, baseados em **flutuações térmicas**.

Inicialmente foi implementado o **modelo de Ising bidimensional**, onde cada célula da grade representa um **spin** que pode estar em estado `+1` ou `-1`, interagindo com seus vizinhos imediatos. A energia do sistema depende do alinhamento dos spins, e sua evolução simula como o sistema se comporta sob diferentes temperaturas.

---

## 👨‍🔬 Sobre a Iniciação Científica

Esta IC tem como objetivo aprofundar os conhecimentos em **física computacional**, **simulações estocásticas** e **programação de alto desempenho**, com foco posterior na implementação de modelos mais complexos como o de **Lebwohl-Lasher em 3D com CUDA**.

- **Pesquisador:** Eric Kamakawa (Engenharia da Computação)
- **Orientadores:** Prof. Dr. Rafael Zola e Prof. Dr. Rodolfo Teixeira
- **Instituição:** UTFPR – Apucarana

---

## 📁 Estrutura do Repositório

```bash
├── fisica.c              # Primeira versão da simulação (modelo Ising em C)
├── ising_simulador.c     # Simulação com visualização interativa usando Raylib
├── README.md             # Este documento


