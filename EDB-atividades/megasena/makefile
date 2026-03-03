# Nome do executável
TARGET = megasena

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -std=c11

# Arquivos fonte
SRCS = main.c megasena.c

# Arquivos objeto
OBJS = main.o megasena.o

# Regra padrão
all: $(TARGET)

# Geração do executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Compilação do main.c
main.o: main.c megasena.h
	$(CC) $(CFLAGS) -c main.c

# Compilação do megasena.c
megasena.o: megasena.c megasena.h
	$(CC) $(CFLAGS) -c megasena.c

# Limpeza dos arquivos gerados
clean:
	rm -f $(OBJS) $(TARGET)
