#ifndef HOSPEDE_LISTA_H
#define HOSPEDE_LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[40];
    char cpf[15];
    char telefone[15];
} HOSPEDE;

typedef struct cx {
    HOSPEDE elem;
    struct cx *prox;
} CAIXA;

typedef CAIXA *ponteiro;

typedef struct {
    ponteiro prim, ult;
    int qtd;
} HOTEL;

void criar_hotel_vazio(HOTEL *h);
int hotel_vazio(HOTEL h);
void ler_hospede(HOSPEDE *x);
void Insere_hospede(HOTEL *h, HOSPEDE x);
void exibe_hospede(HOSPEDE x);
void consulta_hospede(HOTEL h, int id);
void Remover_hospede(HOTEL *h, int id, HOSPEDE *removido);
void Exibe_Todos_hospedes(HOTEL h);
void Exibe_Nome_Telefone(HOTEL h);

#endif
