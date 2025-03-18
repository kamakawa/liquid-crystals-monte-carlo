# 💎 Liquid Crystals Monte Carlo

## 📝 Descrição
Este projeto implementa uma simulação computacional do modelo de Ising para estudar o comportamento de cristais líquidos utilizando o método de Monte Carlo. A simulação é realizada em C e busca explorar propriedades magnéticas e de ordenação dos spins em uma rede bidimensional.

## 🌌 Fundamentos Físicos
O modelo de Ising é amplamente utilizado para estudar fenômenos de transição de fase e magnetização em sistemas físicos. Ele representa um conjunto de spins que podem assumir valores +1 ou -1, dispostos em uma grade. As interações entre spins vizinhos são calculadas utilizando uma constante de acoplamento \(J\), enquanto um campo magnético externo \(H\) também influencia o alinhamento dos spins.

As transições de fase ocorrem quando os spins mudam de um estado ordenado para um estado desordenado conforme a temperatura aumenta. A energia do sistema é calculada pela fórmula:

\[
E = -J \sum_\langle i,j \rangle S_i S_j - H \sum_i S_i
\]

Nesta expressão:
- \(S_i\) representa o valor do spin (+1 ou -1).
- A soma é realizada sobre pares de spins vizinhos.
- \(J\) é a constante de troca que define a intensidade da interação.
- \(H\) é o campo magnético externo.

## 💻 Métodos Computacionais na Física
Os métodos computacionais desempenham um papel crucial na física moderna, permitindo a simulação de sistemas complexos e a obtenção de resultados que seriam impraticáveis de alcançar analiticamente. Neste projeto, utilizamos o método de Monte Carlo com o algoritmo de Metropolis para realizar a evolução temporal do sistema e observar como os spins se organizam sob diferentes temperaturas e intensidades de campo magnético.

## 🧠 Código
O código está estruturado em funções que:
1. 🔧 Inicializam a rede de spins de forma aleatória.
2. 📐 Calculam a energia local considerando as interações vizinhas.
3. 🔁 Realizam uma etapa de Monte Carlo para atualizar os spins.
4. 🖨️ Imprimem a configuração da rede antes e depois da simulação.

### 🚀 Melhorias Futuras
- 💡 Implementar visualização gráfica com SDL para acompanhar a evolução dos spins em tempo real.
- ⚡ Otimizar o desempenho utilizando processamento paralelo ou OpenMP.
- 🌐 Implementar simulações tridimensionais para estudar a evolução dos cristais líquidos em 3D.
- 📊 Adicionar gráficos para análise estatística e observação da magnetização.

## 📝 Licença
Este projeto está licenciado sob a Licença MIT - veja o arquivo LICENSE para mais detalhes.

