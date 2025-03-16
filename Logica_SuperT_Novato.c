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

    // Definição do atributo de comparação (PIB neste caso)
    float atributo1 = pib1;
    float atributo2 = pib2;
    char atributoNome[] = "PIB";

    // Exibição dos dados
    printf("\nCarta 1:\nEstado: %c\nCódigo: %s\nCidade: %s\nPopulação: %lu\nÁrea: %.2f km²\nPIB: %.2f bilhões\nPontos Turísticos: %d\nDensidade Populacional: %.2f hab/km²\nPIB per Capita: %.2f reais\n", 
           estado1, codigo1, cidade1, populacao1, area1, pib1, pontos1, densidade1, pibPerCapita1);
    
    printf("\nCarta 2:\nEstado: %c\nCódigo: %s\nCidade: %s\nPopulação: %lu\nÁrea: %.2f km²\nPIB: %.2f bilhões\nPontos Turísticos: %d\nDensidade Populacional: %.2f hab/km²\nPIB per Capita: %.2f reais\n", 
           estado2, codigo2, cidade2, populacao2, area2, pib2, pontos2, densidade2, pibPerCapita2);

    // Determinação da carta vencedora
    printf("\nComparação de cartas (Atributo: %s):\n", atributoNome);
    printf("Carta 1 - %s: %.2f\n", cidade1, atributo1);
    printf("Carta 2 - %s: %.2f\n", cidade2, atributo2);

    if (atributo1 > atributo2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
    } else if (atributo2 > atributo1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
    } else {
        printf("Resultado: Empate!\n");
    }    
    
    return 0;
}
