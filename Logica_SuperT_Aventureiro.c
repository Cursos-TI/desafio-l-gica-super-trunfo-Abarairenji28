#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Definição das variáveis das cartas
    char estado1 = 'A', estado2 = 'B';
    char codigo1[] = "A01", codigo2[] = "B02";
    char cidade1[] = "São Paulo", cidade2[] = "Rio de Janeiro";
    unsigned long int populacao1 = 12300000, populacao2 = 6000000;
    float area1 = 1521.0, area2 = 1200.0;
    float pib1 = 700.0, pib2 = 400.0;
    int pontos1 = 50, pontos2 = 30;

    // Cálculo dos atributos derivados
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;
    float pibPerCapita1 = (pib1 * 1e9) / populacao1;
    float pibPerCapita2 = (pib2 * 1e9) / populacao2;

    // Declaração de variáveis auxiliares para a comparação
    float atributo1, atributo2;
    char atributoNome[50];

    int escolha;

    // Menu interativo
    do {
        // Exibição do menu
        printf("\nEscolha o atributo para comparar as cartas:\n");
        printf("1. Nome do país\n");
        printf("2. População\n");
        printf("3. Área\n");
        printf("4. PIB\n");
        printf("5. Número de pontos turísticos\n");
        printf("6. Densidade Demográfica\n");
        printf("0. Sair\n");
        printf("Digite a opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                // Nome do país não é comparado diretamente, apenas exibido
                printf("\nComparação de cartas (Atributo: Nome do país):\n");
                printf("Carta 1 - %s: %s\n", cidade1, cidade1);
                printf("Carta 2 - %s: %s\n", cidade2, cidade2);
                printf("Resultado: Empate! (Não há comparação direta)\n");
                break;

            case 2:
                // População
                atributo1 = populacao1;
                atributo2 = populacao2;
                snprintf(atributoNome, sizeof(atributoNome), "População");
                break;

            case 3:
                // Área
                atributo1 = area1;
                atributo2 = area2;
                snprintf(atributoNome, sizeof(atributoNome), "Área");
                break;

            case 4:
                // PIB
                atributo1 = pib1;
                atributo2 = pib2;
                snprintf(atributoNome, sizeof(atributoNome), "PIB");
                break;

            case 5:
                // Número de pontos turísticos
                atributo1 = pontos1;
                atributo2 = pontos2;
                snprintf(atributoNome, sizeof(atributoNome), "Pontos Turísticos");
                break;

            case 6:
                // Densidade demográfica
                atributo1 = densidade1;
                atributo2 = densidade2;
                snprintf(atributoNome, sizeof(atributoNome), "Densidade Demográfica");
                break;

            case 0:
                // Sair do programa
                printf("Saindo do programa...\n");
                break;

            default:
                // Opção inválida
                printf("Opção inválida! Por favor, escolha uma opção válida.\n");
                continue;
        }

        if (escolha != 0) {
            // Exibição da comparação baseada no atributo escolhido
            printf("\nComparação de cartas (Atributo: %s):\n", atributoNome);
            printf("Carta 1 - %s: %.2f\n", cidade1, atributo1);
            printf("Carta 2 - %s: %.2f\n", cidade2, atributo2);

            // Comparação de acordo com as regras
            if (escolha == 6) {
                // Para densidade demográfica, vence a carta com o menor valor
                if (atributo1 < atributo2) {
                    printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
                } else if (atributo2 < atributo1) {
                    printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
                } else {
                    printf("Resultado: Empate!\n");
                }
            } else {
                // Para os outros atributos, vence a carta com o maior valor
                if (atributo1 > atributo2) {
                    printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
                } else if (atributo2 > atributo1) {
                    printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
                } else {
                    printf("Resultado: Empate!\n");
                }
            }
        }

    } while (escolha != 0);

    return 0;
}