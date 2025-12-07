# Define o nome do executável final
TARGET = hotel

# Define o compilador
CC = gcc

# Define as flags de compilação
# -I include: Inclui a pasta 'include' para buscar os arquivos .h
# -Wall: Habilita todos os warnings
CFLAGS = -I include -Wall

# Define os arquivos objeto (.o)
OBJS = src/main.o src/hospede_lista.o src/pilha_checkout.o src/fila_espera.o src/reserva_lista.o

# Regra principal para criar o executável
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Regra para compilar arquivos .c em .o
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar os arquivos gerados
clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: clean
