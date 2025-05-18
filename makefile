# Nome do arquivo-fonte e do executável
FONTE=ising_simulador.c
EXECUTAVEL=ising_simulador

# Comando de compilação
all:
	gcc $(FONTE) -o $(EXECUTAVEL) $(shell pkg-config --cflags --libs raylib) -lm

# Rodar o programa
run: all
	./$(EXECUTAVEL)

# Limpar o executável
clean:
	rm -f $(EXECUTAVEL)
