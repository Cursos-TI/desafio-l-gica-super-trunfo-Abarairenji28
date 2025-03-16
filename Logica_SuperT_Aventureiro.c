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

    int opcao;
    printf("\nEscolha um atributo para comparar:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Demográfica\n");
    printf("Digite sua escolha: ");
    scanf("%d", &opcao);

    float atributo1, atributo2;
    char atributoNome[30];
    int inverso = 0; // Flag para inverter a lógica (densidade demográfica)

    switch (opcao) {
        case 1:
            atributo1 = populacao1;
            atributo2 = populacao2;
            sprintf(atributoNome, "População");
            break;
        case 2:
            atributo1 = area1;
            atributo2 = area2;
            sprintf(atributoNome, "Área");
            break;
        case 3:
            atributo1 = pib1;
            atributo2 = pib2;
            sprintf(atributoNome, "PIB");
            break;
        case 4:
            atributo1 = pontos1;
            atributo2 = pontos2;
            sprintf(atributoNome, "Pontos Turísticos");
            break;
        case 5:
            atributo1 = densidade1;
            atributo2 = densidade2;
            sprintf(atributoNome, "Densidade Demográfica");
            inverso = 1;
            break;
        default:
            printf("Opção inválida!\n");
            return 1;
    }

    // Exibir valores comparados
    printf("\nComparação de cartas (Atributo: %s):\n", atributoNome);
    printf("%s: %.2f\n", pais1, atributo1);
    printf("%s: %.2f\n", pais2, atributo2);

    // Lógica de comparação
    if (atributo1 > atributo2) {
        if (!inverso)
            printf("Resultado: %s venceu!\n", pais1);
        else
            printf("Resultado: %s venceu! (menor densidade ganha)\n", pais2);
    } else if (atributo2 > atributo1) {
        if (!inverso)
            printf("Resultado: %s venceu!\n", pais2);
        else
            printf("Resultado: %s venceu! (menor densidade ganha)\n", pais1);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}