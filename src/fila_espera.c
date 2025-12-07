#include "../include/fila_espera.h"

void cria_fila_vazia(FILA_ESPERA *f) {
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
}

int fila_vazia(FILA_ESPERA f) {
    return (f.inicio == NULL);
}

void Enfileira(FILA_ESPERA *f, HOSPEDE x) {
    NO_FILA *novo;
    novo = (NO_FILA*) malloc(sizeof(NO_FILA));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria para Fila.\n");
        return;
    }
    novo->elem = x;
    novo->prox = NULL;
    
    if (fila_vazia(*f)) {
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
    }
    f->fim = novo;
    f->tamanho++;
    printf("Hospede %s enfileirado na Lista de Espera.\n", x.nome);
}

HOSPEDE Desenfileira(FILA_ESPERA *f) {
    NO_FILA *aux;
    HOSPEDE retorno = {0}; // Inicializa com ID 0
    if (fila_vazia(*f)) {
        printf("A Fila de Espera esta vazia.\n");
        return retorno;
    }
    aux = f->inicio;
    retorno = aux->elem;
    f->inicio = aux->prox;

    if (f->inicio == NULL) { // Se a fila ficou vazia
        f->fim = NULL;
    }

    free(aux);
    f->tamanho--;
    printf("Hospede (ID %d) desenfileirado para Check-in.\n", retorno.id);
    return retorno;
}

void exibe_fila(FILA_ESPERA f) {
    NO_FILA *aux = f.inicio;
    if (fila_vazia(f)) {
        printf("\n**** FILA DE ESPERA VAZIA ****\n");
        return;
    }
    printf("\n**** LISTA DE ESPERA (PRIMEIRO A ENTRAR, PRIMEIRO A SAIR) ****\n");
    while (aux != NULL) {
        printf("ID: %d | Nome: %s", aux->elem.id, aux->elem.nome);
        aux = aux->prox;
    }
    printf("**** FIM DA LISTA DE ESPERA ****\n");
}
