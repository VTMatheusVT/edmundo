#include "../include/hospede_lista.h"

void criar_hotel_vazio(HOTEL *h) {
    ponteiro p;
    p = (ponteiro) malloc(sizeof(CAIXA));
    h->prim = p;
    h->ult = h->prim;
    h->qtd = 0;
    p->prox = NULL;
}

int hotel_vazio(HOTEL h) {
    return (h.prim == h.ult);
}

void ler_hospede(HOSPEDE *x) {
    printf("Entre com o ID do hospede (inteiro)\n");
    scanf("%d", &x->id);
    getchar(); // Consome o \n deixado pelo scanf
    printf("Entre com o nome do hospede\n");
    fgets(x->nome, 40, stdin);
    printf("Entre com o CPF do hospede\n");
    fgets(x->cpf, 15, stdin);
    printf("Entre com o telefone do hopsede\n");
    fgets(x->telefone, 15, stdin);
    // Campos adicionais removidos para simplificar, mas podem ser reintroduzidos se necessário.
}

void Insere_hospede(HOTEL *h, HOSPEDE x) {
    ponteiro p, busca;
    p = (CAIXA *) malloc(sizeof(CAIXA));
    if (p == NULL) {
        printf("Erro de alocacao de memoria para novo hospede.\n");
        return;
    }

    p->elem = x;
    busca = h->prim;

    // Busca o ponto de inserção ordenada por ID
    while ((busca->prox != NULL) && (x.id > busca->prox->elem.id))
        busca = busca->prox;

    p->prox = busca->prox;
    busca->prox = p;

    // Se a inserção foi no final da lista
    if (busca == h->ult)
        h->ult = p;

    h->qtd++;
    printf("Hospede %s cadastrado com ID %d.\n", x.nome, x.id);
}

void exibe_hospede(HOSPEDE x) {
    printf("ID: %d\n", x.id);
    printf("Nome: %s", x.nome);
    printf("CPF: %s", x.cpf);
    printf("Telefone: %s", x.telefone);
    printf("===================================\n");
}

void consulta_hospede(HOTEL h, int id) {
    ponteiro p;
    if (hotel_vazio(h)) {
        printf("O hotel esta vazio - consulta falhou\n");
        return;
    }

    p = h.prim;
    while ((p->prox != NULL) && (id > p->prox->elem.id))
        p = p->prox;

    if ((p->prox == NULL) || (id != p->prox->elem.id)) {
        printf("Hospede com o ID = %d - nao esta no hotel\n", id);
    } else {
        printf("Hospede de ID = %d eh:\n", id);
        exibe_hospede(p->prox->elem);
    }
}

void Remover_hospede(HOTEL *h, int id, HOSPEDE *removido) {
    ponteiro p, anterior;
    if (hotel_vazio(*h)) {
        printf("O hotel esta vazio - remocao falhou\n");
        return;
    }

    anterior = h->prim;
    while ((anterior->prox != NULL) && (id > anterior->prox->elem.id)) {
        anterior = anterior->prox;
    }

    if ((anterior->prox != NULL) && (id == anterior->prox->elem.id)) {
        p = anterior->prox;
        *removido = p->elem;

        anterior->prox = p->prox;

        if (h->ult == p) {
            h->ult = anterior;
        }

        free(p);
        h->qtd--;
        printf("Hospede com ID %d removido com sucesso.\n", id);
    } else {
        printf("Hospede com o ID = %d nao esta no hotel\n", id);
    }
}

void Exibe_Todos_hospedes(HOTEL h) {
    ponteiro p;
    if (hotel_vazio(h)) {
        printf("\n**** O HOTEL ESTA VAZIO - SEM HOSPEDES CADASTRADOS ****\n");
    } else {
        p = h.prim->prox;
        printf("\n**** RELACAO DE TODOS OS HÓSPEDES CADASTRADOS: ****\n");
        while (p != NULL) {
            exibe_hospede(p->elem);
            p = p->prox;
        }
        printf("**** FIM DA RELACAO DE HÓSPEDES ****\n");
    }
}

void Exibe_Nome_Telefone(HOTEL h) {
    ponteiro p;
    if (hotel_vazio(h)) {
        printf("\nO hotel esta vazio.\n");
    } else {
        p = h.prim->prox;
        printf("\n**** RELACAO DOS NOMES e TEL DOS HÓSPEDES: ****\n");
        while (p != NULL) {
            printf("Nome: %s", p->elem.nome);
            printf("Telefone: %s", p->elem.telefone);
            printf("-----------------------------------\n");
            p = p->prox;
        }
        printf("**** FIM DA RELACAO DOS NOMES e TEL ****\n");
    }
}
