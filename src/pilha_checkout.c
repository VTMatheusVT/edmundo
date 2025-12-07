#include "../include/pilha_checkout.h"

void cria_pilha_vazia(PILHA_CHECKOUT *p) {
    p->topo = NULL;
    p->tamanho = 0;
}

int pilha_vazia(PILHA_CHECKOUT p) {
    return (p.topo == NULL);
}

void Empilha(PILHA_CHECKOUT *p, HOSPEDE x) {
    NO_PILHA *novo;
    novo = (NO_PILHA*) malloc(sizeof(NO_PILHA));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria para Pilha.\n");
        return;
    }
    novo->elem = x;
    novo->prox = p->topo;
    p->topo = novo;
    p->tamanho++;
    printf("Check-out de %s registrado no Historico (Pilha).\n", x.nome);
}

HOSPEDE Desempilha(PILHA_CHECKOUT *p) {
    NO_PILHA *aux;
    HOSPEDE retorno = {0}; // Inicializa com ID 0
    if (pilha_vazia(*p)) {
        printf("A Pilha de Check-outs esta vazia.\n");
        return retorno;
    }
    aux = p->topo;
    retorno = aux->elem;
    p->topo = aux->prox;
    free(aux);
    p->tamanho--;
    printf("Ultimo Check-out (ID %d) removido do Historico.\n", retorno.id);
    return retorno;
}

void exibe_pilha(PILHA_CHECKOUT p) {
    NO_PILHA *aux = p.topo;
    if (pilha_vazia(p)) {
        printf("\n**** PILHA DE CHECK-OUTS VAZIA ****\n");
        return;
    }
    printf("\n**** HISTORICO DE CHECK-OUTS (MAIS RECENTE NO TOPO) ****\n");
    while (aux != NULL) {
        printf("ID: %d | Nome: %s", aux->elem.id, aux->elem.nome);
        aux = aux->prox;
    }
    printf("**** FIM DO HISTORICO DE CHECK-OUTS ****\n");
}
