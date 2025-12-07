#ifndef FILA_ESPERA_H
#define FILA_ESPERA_H

#include "hospede_lista.h" // Inclui a definição de HOSPEDE

// Estrutura do nó da Fila
typedef struct no_fila {
    HOSPEDE elem; // Armazena o hóspede em espera
    struct no_fila *prox;
} NO_FILA;

// Estrutura da Fila
typedef struct {
    NO_FILA *inicio;
    NO_FILA *fim;
    int tamanho;
} FILA_ESPERA;

// Protótipos das funções da Fila
void cria_fila_vazia(FILA_ESPERA *f);
int fila_vazia(FILA_ESPERA f);
void Enfileira(FILA_ESPERA *f, HOSPEDE x); // Enqueue (Entrada na lista de espera)
HOSPEDE Desenfileira(FILA_ESPERA *f); // Dequeue (Atendimento do próximo)
void exibe_fila(FILA_ESPERA f);

#endif
