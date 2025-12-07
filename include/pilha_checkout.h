#ifndef PILHA_CHECKOUT_H
#define PILHA_CHECKOUT_H

#include "hospede_lista.h" // Inclui a definição de HOSPEDE

// Estrutura do nó da Pilha
typedef struct no_pilha {
    HOSPEDE elem; // Armazena o hóspede que fez check-out
    struct no_pilha *prox;
} NO_PILHA;

// Estrutura da Pilha
typedef struct {
    NO_PILHA *topo;
    int tamanho;
} PILHA_CHECKOUT;

// Protótipos das funções da Pilha
void cria_pilha_vazia(PILHA_CHECKOUT *p);
int pilha_vazia(PILHA_CHECKOUT p);
void Empilha(PILHA_CHECKOUT *p, HOSPEDE x); // Push (Registra Check-out)
HOSPEDE Desempilha(PILHA_CHECKOUT *p); // Pop (Revisa/Desfaz último Check-out)
void exibe_pilha(PILHA_CHECKOUT p);

#endif
