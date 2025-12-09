#ifndef RESERVA_LISTA_H
#define RESERVA_LISTA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id_reserva;
    int numero_quarto;
    char data_entrada[11];
    char data_saida[11];
    int id_hospede;
} RESERVA;

typedef struct cr {
    RESERVA elem;
    struct cr *prox;
} CAIXA_RES;

typedef CAIXA_RES *ponteiro_res;

typedef struct {
    ponteiro_res prim, ult;
    int qtd;
} LISTA_RESERVA;

void criar_lista_reserva_vazia(LISTA_RESERVA *l);
int lista_reserva_vazia(LISTA_RESERVA l);
void ler_reserva(RESERVA *x, int prox_id_reserva, int id_hospede);
void Insere_reserva(LISTA_RESERVA *l, RESERVA x);
void exibe_reserva(RESERVA x);
void Exibe_Todas_Reservas(LISTA_RESERVA l);

#endif
