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

    int opcao, cod, prox_id_reserva = 1; // Contador simples para ID de Reserva

    criar_hotel_vazio(&H);
    criar_lista_reserva_vazia(&LR);
    cria_pilha_vazia(&PC);
    cria_fila_vazia(&FE);

    do {
        MENU();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: // RF01: Cadastrar Hospede
                ler_hospede(&X);
                Insere_hospede(&H, X);
                break;

            case 2: // RF03: Cadastrar Reserva
                printf("Entre com o ID do hospede para a reserva: ");
                scanf("%d", &cod);
                
                // Simulação: se o hóspede existe, permite a reserva
                // (Em um sistema real, haveria busca e verificação de quarto livre)
                
                // A função ler_reserva precisaria de um Hóspede real.
                // Aqui, assumimos que o ID foi digitado corretamente para fins de exemplo
                // Para uma implementação completa, seria necessária uma busca pelo HOSPEDE.
                
                ler_reserva(&R, prox_id_reserva, cod);
                Insere_reserva(&LR, R);
                prox_id_reserva++;
                break;

            case 3: // RF05: Realizar Check-in (Simplificado)
                printf("Entre com o ID do hospede para o Check-in (Este hospede deve ter uma Reserva): ");
                scanf("%d", &cod);
                printf("Simulando Check-in para o Hospede ID %d. Quarto marcado como ocupado.\n", cod);
                // Lógica complexa de busca na reserva e marcação do quarto no sistema real.
                break;
            
            case 4: // RF06: Realizar Check-out
                printf("Entre com o ID do hospede para o Check-out: ");
                scanf("%d", &cod);
                Remover_hospede(&H, cod, &X); // Remove da lista de Hóspedes Ativos
                
                if (X.id != 0) { // Se o hóspede foi removido com sucesso
                    Empilha(&PC, X); // Registra no Histórico de Check-outs (Pilha)
                }
                break;
                
            case 5: // RF02: Listar todos os hospedes cadastrados
                Exibe_Todos_hospedes(H);
                break;

            case 6: // RF04: Listar todas as reservas ativas
                Exibe_Todas_Reservas(LR);
                break;
                
            case 7: // Manipulação da Fila de Espera
                printf("\n--- Opcoes da Fila de Espera ---\n");
                printf("1 - Adicionar Hospede na Espera\n");
                printf("2 - Atender Proximo da Espera\n");
                printf("3 - Exibir Fila\n");
                printf("Opcao: ");
                int sub_opcao_fila;
                scanf("%d", &sub_opcao_fila);

                if (sub_opcao_fila == 1) {
                    ler_hospede(&X); // Lê os dados do hospede para a fila
                    Enfileira(&FE, X);
                } else if (sub_opcao_fila == 2) {
                    X = Desenfileira(&FE);
                    if (X.id != 0) {
                        printf("Hospede %s pronto para check-in.\n", X.nome);
                    }
                } else if (sub_opcao_fila == 3) {
                    exibe_fila(FE);
                }
                break;
                
            case 8: // Manipulação da Pilha de Check-outs
                printf("\n--- Opcoes da Pilha (Historico de Check-outs) ---\n");
                printf("1 - Revisar Ultimo Check-out (Desempilhar)\n");
                printf("2 - Exibir Historico\n");
                printf("Opcao: ");
                int sub_opcao_pilha;
                scanf("%d", &sub_opcao_pilha);
                
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
                printf("Obrigado por escolher nosso produto\n");
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
    printf("1 - Cadastrar novo hospede (RF01)\n");
    printf("2 - Cadastrar nova reserva (RF03)\n");
    printf("3 - Realizar Check-in (RF05)\n");
    printf("4 - Realizar Check-out (RF06, Pilha)\n");
    printf("-----------------------------------\n");
    printf("5 - Listar todos os Hospedes (RF02)\n");
    printf("6 - Listar todas as Reservas Ativas (RF04)\n");
    printf("7 - Gerenciar Fila de Espera (Fila)\n");
    printf("8 - Gerenciar Historico de Check-outs (Pilha)\n");
    printf("9 - Encerrar o Trabalho\n");
    printf("Opcao: ");
}
