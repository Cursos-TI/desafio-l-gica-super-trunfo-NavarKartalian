#include <stdio.h>

int main() {
    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.

    // Exemplo:
    // if (populacaoA > populacaoB) {
    //     printf("Cidade 1 tem maior população.\n");
    // } else {
    //     printf("Cidade 2 tem maior população.\n");
    // }

    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.

    // Exemplo:
    // printf("A cidade vencedora é: %s\n", cidadeVencedora);

    struct CityCard {
    char name[50];
    char code[4];
    int population;
    float area;
    int pib;
    int numOfPoints;
    };

    struct CityCard userCity;
    struct CityCard computerCity = {
        "New York",
        "A01",
        8258000,
        783.8,
        1286000000,
        1280,
    };
    
    printf("Insira o nome: \n");
    scanf("%49s", userCity.name);

    printf("Insira o código: \n");
    scanf("%3s", userCity.code);

    printf("Insira a população: \n");
    scanf("%d", &userCity.population);

    printf("Insira a área: \n");
    scanf("%f", &userCity.area);

    printf("Insira o pib: \n");
    scanf("%d", &userCity.pib);

    printf("Insira o número de pontos turísticos: \n");
    scanf("%d", &userCity.numOfPoints);

    printf("----\n");

    printf("Card A: \n Nome: %s, \n Código: %s, \n População: %d, \n Área: %fkm², \n PIB: %d, \n Número de pontos turísticos: %d, \n",
    userCity.name, userCity.code, userCity.population, userCity.area, userCity.pib, userCity.numOfPoints);

    printf("----\n");

    printf("Card B: \n Nome: %s, \n Código: %s, \n População: %d, \n Área: %fkm², \n PIB: %d, \n Número de pontos turísticos: %d, \n",
    computerCity.name, computerCity.code, computerCity.population, computerCity.area, computerCity.pib, computerCity.numOfPoints);

    return 0;
}
