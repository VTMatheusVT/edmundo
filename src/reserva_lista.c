#include "../include/reserva_lista.h"

void criar_lista_reserva_vazia(LISTA_RESERVA *l) {
    ponteiro_res p;
    p = (ponteiro_res) malloc(sizeof(CAIXA_RES));
    l->prim = p;
    l->ult = l->prim;
    l->qtd = 0;
    p->prox = NULL;
}

int lista_reserva_vazia(LISTA_RESERVA l) {
    return (l.prim == l.ult);
}

void ler_reserva(RESERVA *x, int prox_id_reserva, int id_hospede) {
    x->id_reserva = prox_id_reserva;
    x->id_hospede = id_hospede;
    printf("Reserva ID %d para Hospede ID %d.\n", x->id_reserva, x->id_hospede);
    printf("Entre com o numero do quarto: ");
    scanf("%d", &x->numero_quarto);
    getchar();
    printf("Entre com a data de entrada (dd/mm/aaaa): ");
    fgets(x->data_entrada, 11, stdin);
    printf("Entre com a data de saida (dd/mm/aaaa): ");
    fgets(x->data_saida, 11, stdin);
}

void Insere_reserva(LISTA_RESERVA *l, RESERVA x) {
    ponteiro_res p;
    p = (CAIXA_RES *) malloc(sizeof(CAIXA_RES));
    if (p == NULL) {
        printf("Erro de alocacao de memoria para nova reserva.\n");
        return;
    }
    p->elem = x;
    p->prox = NULL;
    
    // Inserção simples no final (poderia ser ordenada por data ou ID)
    l->ult->prox = p;
    l->ult = p;
    l->qtd++;
    printf("Reserva %d cadastrada com sucesso.\n", x.id_reserva);
}

void exibe_reserva(RESERVA x) {
    printf("ID Reserva: %d | Quarto: %d\n", x.id_reserva, x.numero_quarto);
    printf("ID Hospede: %d\n", x.id_hospede);
    printf("Entrada: %s", x.data_entrada);
    printf("Saida: %s", x.data_saida);
    printf("-----------------------------------\n");
}

void Exibe_Todas_Reservas(LISTA_RESERVA l) {
    ponteiro_res p;
    if (lista_reserva_vazia(l)) {
        printf("\n**** SEM RESERVAS ATIVAS ****\n");
    } else {
        p = l.prim->prox;
        printf("\n**** RELACAO DE TODAS AS RESERVAS ATIVAS: ****\n");
        while (p != NULL) {
            exibe_reserva(p->elem);
            p = p->prox;
        }
        printf("**** FIM DA RELACAO DE RESERVAS ****\n");
    }
}
