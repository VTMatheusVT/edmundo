#ifndef FILA_ESPERA_H
#define FILA_ESPERA_H

#include "hospede_lista.h"

typedef struct no_fila {
    HOSPEDE elem;
    struct no_fila *prox;
} NO_FILA;

typedef struct {
    NO_FILA *inicio;
    NO_FILA *fim;
    int tamanho;
} FILA_ESPERA;

void cria_fila_vazia(FILA_ESPERA *f);
int fila_vazia(FILA_ESPERA f);
void Enfileira(FILA_ESPERA *f, HOSPEDE x);
HOSPEDE Desenfileira(FILA_ESPERA *f);
void exibe_fila(FILA_ESPERA f);

#endif
