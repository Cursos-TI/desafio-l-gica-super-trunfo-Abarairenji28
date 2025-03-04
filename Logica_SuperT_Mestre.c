#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Definição das variáveis das cartas
    char pais1[] = "Brasil", pais2[] = "Argentina";
    unsigned long int populacao1 = 213000000, populacao2 = 45000000;
    float area1 = 8515767.0, area2 = 2780400.0;
    float pib1 = 1445.0, pib2 = 500.0; // PIB em bilhões
    int pontos1 = 30, pontos2 = 20;
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;

    int opcao1, opcao2;
    printf("\nEscolha o primeiro atributo para comparar:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Demográfica\n");
    printf("Digite sua escolha: ");
    scanf("%d", &opcao1);

    // Menu dinâmico para o segundo atributo, garantindo que não seja igual ao primeiro
    do {
        printf("\nEscolha o segundo atributo para comparar (não pode ser o mesmo do primeiro):\n");
        printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Demográfica\n");
        printf("Digite sua escolha: ");
        scanf("%d", &opcao2);
    } while (opcao2 == opcao1);

    float atributo1, atributo2, atributo3, atributo4;
    char atributoNome1[30], atributoNome2[30];
    int inverso1 = 0, inverso2 = 0; // Flags para inverter a lógica (densidade demográfica)

    // Seleção do primeiro atributo
    switch (opcao1) {
        case 1:
            atributo1 = populacao1;
            atributo2 = populacao2;
            sprintf(atributoNome1, "População");
            break;
        case 2:
            atributo1 = area1;
            atributo2 = area2;
            sprintf(atributoNome1, "Área");
            break;
        case 3:
            atributo1 = pib1;
            atributo2 = pib2;
            sprintf(atributoNome1, "PIB");
            break;
        case 4:
            atributo1 = pontos1;
            atributo2 = pontos2;
            sprintf(atributoNome1, "Pontos Turísticos");
            break;
        case 5:
            atributo1 = densidade1;
            atributo2 = densidade2;
            sprintf(atributoNome1, "Densidade Demográfica");
            inverso1 = 1;
            break;
        default:
            printf("Opção inválida!\n");
            return 1;
    }

    // Seleção do segundo atributo
    switch (opcao2) {
        case 1:
            atributo3 = populacao1;
            atributo4 = populacao2;
            sprintf(atributoNome2, "População");
            break;
        case 2:
            atributo3 = area1;
            atributo4 = area2;
            sprintf(atributoNome2, "Área");
            break;
        case 3:
            atributo3 = pib1;
            atributo4 = pib2;
            sprintf(atributoNome2, "PIB");
            break;
        case 4:
            atributo3 = pontos1;
            atributo4 = pontos2;
            sprintf(atributoNome2, "Pontos Turísticos");
            break;
        case 5:
            atributo3 = densidade1;
            atributo4 = densidade2;
            sprintf(atributoNome2, "Densidade Demográfica");
            inverso2 = 1;
            break;
        default:
            printf("Opção inválida!\n");
            return 1;
    }

    // Exibir valores comparados
    printf("\nComparação de cartas:\n");
    printf("%s: %.2f e %s: %.2f\n", pais1, atributo1, pais2, atributo2);
    printf("%s: %.2f e %s: %.2f\n", pais1, atributo3, pais2, atributo4);
    printf("Atributos escolhidos: %s e %s\n", atributoNome1, atributoNome2);

    // Lógica de comparação para o primeiro atributo
    float soma1 = atributo1 + atributo3;
    float soma2 = atributo2 + atributo4;

    if (atributo1 > atributo2 && !inverso1 || atributo1 < atributo2 && inverso1) {
        printf("%s venceu no primeiro atributo!\n", pais1);
    } else if (atributo2 > atributo1 && !inverso1 || atributo2 < atributo1 && inverso1) {
        printf("%s venceu no primeiro atributo!\n", pais2);
    } else {
        printf("Empate no primeiro atributo!\n");
    }

    // Lógica de comparação para o segundo atributo
    if (atributo3 > atributo4 && !inverso2 || atributo3 < atributo4 && inverso2) {
        printf("%s venceu no segundo atributo!\n", pais1);
    } else if (atributo4 > atributo3 && !inverso2 || atributo4 < atributo3 && inverso2) {
        printf("%s venceu no segundo atributo!\n", pais2);
    } else {
        printf("Empate no segundo atributo!\n");
    }

    // Soma dos atributos
    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", pais1, soma1);
    printf("%s: %.2f\n", pais2, soma2);

    // Resultado final com base na soma
    if (soma1 > soma2) {
        printf("\nResultado final: %s venceu a rodada!\n", pais1);
    } else if (soma2 > soma1) {
        printf("\nResultado final: %s venceu a rodada!\n", pais2);
    } else {
        printf("\nResultado final: Empate!\n");
    }

    return 0;
}