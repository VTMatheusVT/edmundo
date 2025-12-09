#include "../include/hospede_lista.h"
#include "../include/pilha_checkout.h"
#include "../include/fila_espera.h"
#include "../include/reserva_lista.h"

// Protótipo da função Menu
void MENU();

int main() {
    HOTEL H;
    LISTA_RESERVA LR;
    PILHA_CHECKOUT PC;
    FILA_ESPERA FE;
    HOSPEDE X;
    RESERVA R;

    int opcao, cod, prox_id_reserva = 1;
    char temp_char[50];

    criar_hotel_vazio(&H);
    criar_lista_reserva_vazia(&LR);
    cria_pilha_vazia(&PC);
    cria_fila_vazia(&FE);

    do {
        MENU();
        if (scanf("%d", &opcao) != 1) {
            fgets(temp_char, sizeof(temp_char), stdin);
            opcao = -1; 
        }
        getchar();

        switch (opcao) {
            case 1: // RF01: Cadastrar Hospede
                ler_hospede(&X);
                Insere_hospede(&H, X);
                break;

            case 2: // RF03: Cadastrar Reserva
                printf("Entre com o ID do hospede para a reserva: ");
                scanf("%d", &cod);
                getchar();
                
                ler_reserva(&R, prox_id_reserva, cod);
                Insere_reserva(&LR, R);
                prox_id_reserva++;
                break;

            case 3: // RF05: Realizar Check-in (Simplificado)
                printf("Entre com o ID do hospede para o Check-in: ");
                scanf("%d", &cod);
                getchar();
                printf("Simulando Check-in para o Hospede ID %d. Quarto marcado como ocupado (RF05).\n", cod);
                break;
            
            case 4: // RF06: Realizar Check-out
                printf("Entre com o ID do hospede para o Check-out: ");
                scanf("%d", &cod);
                getchar();
                
                Remover_hospede(&H, cod, &X);
                
                if (X.id != 0) {
                    Empilha(&PC, X);
                }
                break;
                
            case 5: // RF02: Listar todos os hospedes cadastrados
                Exibe_Todos_hospedes(H);
                break;

            case 6: // RF04: Listar todas as reservas ativas
                Exibe_Todas_Reservas(LR);
                break;
                
            case 7: // Gerenciar Fila de Espera
                printf("\n--- Opcoes da Fila de Espera (Fila) ---\n");
                printf("1 - Adicionar Hospede na Espera (Enfileirar)\n");
                printf("2 - Atender Proximo da Espera (Desenfileirar)\n");
                printf("3 - Exibir Fila\n");
                printf("Opcao: ");
                int sub_opcao_fila;
                if (scanf("%d", &sub_opcao_fila) != 1) {
                    fgets(temp_char, sizeof(temp_char), stdin); 
                    break;
                }
                getchar();

                if (sub_opcao_fila == 1) {
                    ler_hospede(&X);
                    Enfileira(&FE, X);
                } else if (sub_opcao_fila == 2) {
                    X = Desenfileira(&FE);
                    if (X.id != 0) {
                        printf("Hospede %s pronto para Check-in.\n", X.nome);
                    }
                } else if (sub_opcao_fila == 3) {
                    exibe_fila(FE);
                }
                break;
                
            case 8: // Gerenciar Pilha de Check-outs
                printf("\n--- Opcoes da Pilha (Historico de Check-outs) ---\n");
                printf("1 - Revisar Ultimo Check-out (Desempilhar - LIFO)\n");
                printf("2 - Exibir Historico\n");
                printf("Opcao: ");
                int sub_opcao_pilha;
                if (scanf("%d", &sub_opcao_pilha) != 1) {
                     fgets(temp_char, sizeof(temp_char), stdin); 
                     break;
                }
                getchar();
                
                if (sub_opcao_pilha == 1) {
                    X = Desempilha(&PC);
                    if (X.id != 0) {
                        printf("Hospede %s foi o ultimo a fazer check-out.\n", X.nome);
                    }
                } else if (sub_opcao_pilha == 2) {
                    exibe_pilha(PC);
                }
                break;

            case 9:
                printf("Encerrando o sistema. Obrigado!\n");
                break;

            default:
                printf("Favor escolher uma opcao valida 1..9\n");
                break;
        }
    } while (opcao != 9);

    return 0;
}

void MENU() {
    printf("\n===================================\n");
    printf("         SISTEMA DE HOTELARIA      \n");
    printf("===================================\n");
    printf("1 - Cadastrar novo hospede (Lista H) (RF01)\n");
    printf("2 - Cadastrar nova reserva (Lista R) (RF03)\n");
    printf("3 - Realizar Check-in (RF05)\n");
    printf("4 - Realizar Check-out (Remove de Lista H e Empilha em Pilha) (RF06)\n");
    printf("-----------------------------------\n");
    printf("5 - Listar todos os Hospedes (RF02)\n");
    printf("6 - Listar todas as Reservas Ativas (RF04)\n");
    printf("7 - Gerenciar Fila de Espera\n");
    printf("8 - Gerenciar Historico de Check-outs (Pilha)\n");
    printf("9 - Encerrar o Trabalho\n");
    printf("Opcao: ");
}
