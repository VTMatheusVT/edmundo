#ifndef RESERVA_LISTA_H
#define RESERVA_LISTA_H

#include <stdio.h>
#include <stdlib.h>

// Estrutura de Reserva (Baseada na tabela de Estruturas)
typedef struct {
    int id_reserva;
    int numero_quarto;
    char data_entrada[11];
    char data_saida[11];
    int id_hospede; // Link para o hóspede
} RESERVA;

// Estrutura da Caixa de Reserva (Nó da Lista)
typedef struct cr {
    RESERVA elem;
    struct cr *prox;
} CAIXA_RES;

typedef CAIXA_RES *ponteiro_res;

// Estrutura da Lista de Reservas
typedef struct {
    ponteiro_res prim, ult;
    int qtd;
} LISTA_RESERVA;

// Protótipos das funções da Lista de Reservas (RF03, RF04)
void criar_lista_reserva_vazia(LISTA_RESERVA *l);
int lista_reserva_vazia(LISTA_RESERVA l);
void ler_reserva(RESERVA *x, int prox_id_reserva, int id_hospede); // Requer ID do hóspede
void Insere_reserva(LISTA_RESERVA *l, RESERVA x);
void exibe_reserva(RESERVA x);
void Exibe_Todas_Reservas(LISTA_RESERVA l);
// Adicionar funções de Check-in (RF05) e Check-out (RF06) aqui ou no main.c, interagindo com a Pilha.

#endif
