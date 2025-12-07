#ifndef HOSPEDE_LISTA_H
#define HOSPEDE_LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do Hóspede (Baseada no seu código e nos requisitos)
typedef struct {
    int id; // cod_hospede (RF01: id)
    char nome[40]; // (RF01: nome)
    char cpf[15]; // (Baseado na tabela de Estruturas: id, nome, cpf, telefone)
    char telefone[15]; // (RF01: telefone)
    // char dat_nasc[11]; // Não está na tabela de Estruturas, mantido no seu código original
    // char email[50]; // Não está na tabela de Estruturas, mantido no seu código original
} HOSPEDE;

// Estrutura da Caixa (Nó da Lista)
typedef struct cx {
    HOSPEDE elem;
    struct cx *prox;
} CAIXA;

typedef CAIXA *ponteiro;

// Estrutura do Hotel (Lista Encadeada)
typedef struct {
    ponteiro prim, ult;
    int qtd;
} HOTEL;

// Protótipos das funções da Lista de Hóspedes
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
