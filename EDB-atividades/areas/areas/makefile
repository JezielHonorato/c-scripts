# Nome do executável
TARGET = exec_cubo

# Compilador
CC = gcc

# Opções de compilação
CFLAGS = -Wall -std=c11

# Arquivos de objeto
OBJS = main.o funcoes.o

# Regra padrão para compilar o projeto
all: $(TARGET)

# Regra para gerar o executável
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) -lm

# Regra para compilar o main.c
main.o: main.c cubo.h
	$(CC) $(CFLAGS) -c main.c

# Regra para compilar o area.c
area.o: funcoes.c cubo.h
	$(CC) $(CFLAGS) -c funcoes.c

# Regra para limpar os arquivos gerados
clean:
	rm -f $(OBJS) $(TARGET)

