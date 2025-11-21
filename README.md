# 🧊 Simulações do Modelo de Ising – Primeira Fase da Iniciação Científica  
### Autor: Eric Kamakawa  
### Orientadores: Prof. Rafael Zola e Prof. Rodolfo Teixeira  
### Linguagem: C (com e sem Raylib)

Este repositório faz parte da **primeira fase** da minha iniciação científica em Cristais Líquidos, onde desenvolvi diferentes versões do **Modelo de Ising 2D**, utilizando tanto saída por terminal quanto visualização gráfica.

---

## 📁 Arquivos presentes no repositório

| Arquivo | Função no projeto | Como executar | Observações |
|--------|-------------------|----------------|-------------|
| **fisica.c** | Implementação *terminal* do Modelo de Ising. Calcula energia, magnetização e executa Monte Carlo. | `gcc fisica.c -o fisica -lm` <br> `./fisica <iteracoes> <temperatura>` | Não usa Raylib. Focado na física e nos cálculos. |
| **ising_simulador.c** | Simulador completo **com visualização gráfica**, usando Raylib. Grade colorida e controles de temperatura. | Usar `make` (compila automaticamente com Raylib). | Código principal da simulação visual. Depende do makefile. |
| **makefile** | Automatiza a compilação do simulador gráfico. | `make` para compilar <br> `make run` para rodar | Evita ter que escrever comandos longos do Raylib. |
| **LICENÇA** | Termos da licença do projeto. | — | — |
| **README.md** | Arquivo de documentação. | — | — |

---

## 🧩 Sobre o arquivo `fisica.c`

O arquivo **fisica.c** é uma implementação simples, direta e científica do **Modelo de Ising 2D** usando C puro, sem interface gráfica.  
É ideal para:

- Analisar cálculos brutos de energia e magnetização  
- Fazer testes rápidos do método de Monte Carlo  
- Validar as funções físicas antes de migrar para a versão gráfica  

Esse código foi crucial na IC para compreender, de forma clara, como o modelo funciona matematicamente.

---

## 🔍 O que o código `fisica.c` faz?

### ✔ Inicializa uma grade L × L de spins aleatórios  
Cada spin pode ser:

- **+1** → representado por `'O'`  
- **–1** → representado por `'X'`

A função `inicializarSpins()` gera essa configuração inicial.

---

### ✔ Calcula observáveis físicos essenciais

#### **1. Magnetização média**
\[
M = \frac{1}{N} \sum_{i} s_i
\]

Implementado em `calcularMagnetizacao()`.

---

#### **2. Energia local**
\[
E_i = -J s_i (vizinhos) - H s_i
\]

Considera:

- vizinho de cima  
- vizinho de baixo  
- vizinho à esquerda  
- vizinho à direita  

A função usa condições periódicas (bordas conectadas).  

---

#### **3. Energia total**
Soma de todas as energias locais, dividida por 4 para evitar contar interações repetidas.

---

### ✔ Executa Monte Carlo pelo Método de Metropolis  
Para cada spin:

- Calcula ΔE  
- Aceita automaticamente se ΔE ≤ 0  
- Caso contrário, aceita com probabilidade  
\[
p = e^{-\Delta E/T}
\]

Essa etapa está em `monteCarloStep()`.

---

### ✔ Entrada e saída pelo terminal  
O programa recebe:

```
./fisica <iteracoes> <temperatura>
```

Exemplo:

```
./fisica 10000 2.0
```

O resultado impresso inclui:

- Grade inicial  
- Grade final  
- Energia média  
- Magnetização média  

---

## ▶️ Como executar cada parte

### 🖥️ 1. Versão terminal (`fisica.c`)
```bash
gcc fisica.c -o fisica -lm
./fisica 5000 2.5
```

---

### 🎨 2. Versão gráfica (`ising_simulador.c`)
Requer Raylib instalado.

Compile usando:

```bash
make
```

Execute:

```bash
make run
```

Ou:

```bash
./ising_simulador
```

---

## 🧠 Resumo da primeira fase

Nesta etapa da IC, desenvolvi:

- Uma **versão física e textual** do Modelo de Ising (fisica.c)  
- Uma **versão visual e interativa** usando Raylib (ising_simulador.c)  
- Scripts organizados via makefile  
- Compreensão profunda de energia, magnetização e dinâmica Monte Carlo  

Esse conjunto abriu caminho para as próximas fases em C++ e posteriormente para modelos mais avançados de cristais líquidos.

---

## 📬 Contato

Caso queira conversar sobre o projeto, física computacional ou iniciação científica:

**Eric Kamakawa**  
Estudante de Engenharia de Computação – UTFPR  
GitHub: https://github.com/kamakawa
