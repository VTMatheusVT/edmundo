#ifndef PILHA_CHECKOUT_H
#define PILHA_CHECKOUT_H

#include "hospede_lista.h"

typedef struct no_pilha {
    HOSPEDE elem;
    struct no_pilha *prox;
} NO_PILHA;

typedef struct {
    NO_PILHA *topo;
    int tamanho;
} PILHA_CHECKOUT;

void cria_pilha_vazia(PILHA_CHECKOUT *p);
int pilha_vazia(PILHA_CHECKOUT p);
void Empilha(PILHA_CHECKOUT *p, HOSPEDE x);
HOSPEDE Desempilha(PILHA_CHECKOUT *p);
void exibe_pilha(PILHA_CHECKOUT p);

#endif
