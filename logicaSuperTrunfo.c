#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>

//Card object structure and properties
struct CityCard {
    char name[50];
    char code[4];
    unsigned long int population;
    float area;
    float pib;
    int numOfPoints;
    float populationDensity;
    float pibPerCapita;
    float superPower;
};

//Calculate the sum of the card properties
float getCardTotal(struct CityCard card) {
    return card.area + card.numOfPoints + card.pib + card.pibPerCapita + card.population + card.populationDensity;
}

//Function responsible for register the inputs and return a card with the values 
struct CityCard registerCard() {
    struct CityCard card;

    system("clear");

    printf("Insira o nome: \n");
    scanf("%49s", card.name);

    printf("Insira o código: \n");
    scanf("%3s", card.code);

    printf("Insira a população: \n");
    scanf("%lu", &card.population);

    printf("Insira a área: \n");
    scanf("%f", &card.area);

    printf("Insira o pib: \n");
    scanf("%f", &card.pib);

    printf("Insira o número de pontos turísticos: \n");
    scanf("%d", &card.numOfPoints);

    card.populationDensity = card.population / card.area;
    card.pibPerCapita = card.pib / card.population;
    card.superPower = getCardTotal(card);

    return card;
}

//Function that compares the props and print the results
void compareProps(const char* propName, double cardValueA, double cardValueB, int* cardPointsA, int* cardPointsB) {
    printf("%s: \n", propName);
    if(!strcmp(propName, "Densidade populacional")) {
        if(cardValueA < cardValueB) {
            printf("Card 1: %f < Card 2: %f, Vencedor: 1 \n", cardValueA, cardValueB);
            (*cardPointsA)++;
        } else if(cardValueA > cardValueB) {
            printf("Card 1: %f > Card 2: %f, Vencedor: 0 \n", cardValueA, cardValueB);
            (*cardPointsB)++;
        } else {
            printf("Card 1: %f = Card 2: %f, Empate \n", cardValueA, cardValueB);
        }
    } else {
        if(cardValueA > cardValueB) {
            printf("Card 1: %f > Card 2: %f, Vencedor: 1 \n", cardValueA, cardValueB);
            (*cardPointsA)++;
        } else if(cardValueA < cardValueB) {
            printf("Card 1: %f < Card 2: %f, Vencedor: 0 \n", cardValueA, cardValueB);
            (*cardPointsB)++;
        } else {
            printf("Card 1: %f = Card 2: %f, Empate \n", cardValueA, cardValueB);
        }
    }
}

//Calls the function that compares the props based on the selected prop passed to this method
void compareSelectedProp(int selectedProp, struct CityCard cardA, struct CityCard cardB, int* cardAPoints, int* cardBPoints) {
    switch(selectedProp) {
        case 1:
            compareProps("População", (double)cardA.population, (double)cardB.population, cardAPoints, cardBPoints);
            break;
        case 2:
            compareProps("Área", cardA.area, cardB.area, cardAPoints, cardBPoints);
            break;
        case 3:
            compareProps("PIB", cardA.pib, cardB.pib, cardAPoints, cardBPoints);
            break;
        case 4:
            compareProps("Número de pontos turísticos", (double)cardA.numOfPoints, (double)cardB.numOfPoints, cardAPoints, cardBPoints);
            break;
        case 5:
            compareProps("Densidade populacional", cardA.populationDensity, cardB.populationDensity, cardAPoints, cardBPoints);
            break;
        case 6:
            compareProps("PIB per capita", cardA.pibPerCapita, cardB.pibPerCapita, cardAPoints, cardBPoints);
            break;
        case 7:
            compareProps("Super poder", cardA.superPower, cardB.superPower, cardAPoints, cardBPoints);
            break;
        default:
            printf("Propriedade inválida. Por favor, insira um número entre 1 e 7.\n");
    }
}

//Function responsible for the overall comparison of the cards
void compareCards(struct CityCard cardA, struct CityCard cardB) {
    //Variables to keep track of each card points
    int cardAPoints = 0;
    int cardBPoints = 0;
    int firstSelectedProp, secondSelectedProp;
    bool validOptionOne = false, validOptionTwo = false;

    printf("Comparação: \n");

     printf("\n");

     do {
        printf("Selecione a **primeira** propriedade a ser comparada:\n");
        printf("1 - População\n2 - Área\n3 - PIB\n4 - Número de pontos turísticos\n5 - Densidade populacional\n6 - PIB per capita\n7 - Super poder\n");
        printf("\n");
        printf("Digite a opção desejada: ");

        if (scanf("%d", &firstSelectedProp) != 1 || firstSelectedProp < 1 || firstSelectedProp > 7) {
            printf("\n");
            printf("Propriedade inválida. Por favor, insira um número entre 1 e 7.\n");
            printf("\n");
            while (getchar() != '\n');
            continue;
        }
        validOptionOne = true;
    } while (!validOptionOne);

    printf("\n");

    do {
        printf("Selecione a **segunda** propriedade a ser comparada:\n");
        printf("1 - População\n2 - Área\n3 - PIB\n4 - Número de pontos turísticos\n5 - Densidade populacional\n6 - PIB per capita\n7 - Super poder\n");
        printf("\n");
        printf("Digite a opção desejada: ");

        if (scanf("%d", &secondSelectedProp) != 1 || secondSelectedProp < 1 || secondSelectedProp > 7 || secondSelectedProp == firstSelectedProp) {
            if(secondSelectedProp == firstSelectedProp) {
                printf("\n");
                printf("Propriedade: **%d** já escolhida. Escolha um número entre 1 e 7 e **diferente** da primeira escolha.\n", firstSelectedProp);
                printf("\n");
            } else {
                printf("\n");
                printf("Propriedade inválida. Por favor, insira um número entre 1 e 7.\n");
                printf("\n");
            }
            while (getchar() != '\n');
            continue;
        }
        validOptionTwo = true;
    } while (!validOptionTwo);

    printf("\n");
    printf("----\n");
    printf("\n");

    printf("Card 1 = 1, Card 2 = 0; \n");
    printf("\n");

    compareSelectedProp(firstSelectedProp, cardA, cardB, &cardAPoints, &cardBPoints);
    printf("\n");
    compareSelectedProp(secondSelectedProp, cardA, cardB, &cardAPoints, &cardBPoints);
     
    printf("\n");

    //If statement responsible for presenting the result based on the number of points that each card acquired
    printf("Resultado: \n");
    if(cardAPoints > cardBPoints) {
        printf("Card 1: %d pontos > Card 2: %d pontos \n", cardAPoints, cardBPoints);
        printf("**Vencedor: 1** \n");
    } else if(cardAPoints < cardBPoints) {
        printf("Card 1: %d pontos < Card 2: %d pontos \n", cardAPoints, cardBPoints);
        printf("**Vencedor: 0** \n");
    } else {
        printf("Card 1: %d pontos = Card 2: %d pontos \n", cardAPoints, cardBPoints);
        printf("**Empate** \n");
    }

    printf("\n");
    printf("----\n");
    printf("\n");
}

int main() {
    //Declare two card variables
    struct CityCard cityA;
    struct CityCard cityB;

    //Call the function that triggers the user input and define each card variable its return
    cityA = registerCard();

    cityB = registerCard();

    system("clear");

    //Prints each card registered
    printf("Card 1: \n Nome: %s, \n Código: %s, \n População: %lu, \n Área: %fkm², \n PIB: %f, \n Número de pontos turísticos: %d, \n Densidade populacional: %f, \n PIB per capita: %f, \n Super poder: %f \n",
    cityA.name, cityA.code, cityA.population, cityA.area, cityA.pib, cityA.numOfPoints, cityA.populationDensity, cityA.pibPerCapita, cityA.superPower);

    printf("\n");

    printf("Card 2: \n Nome: %s, \n Código: %s, \n População: %lu, \n Área: %fkm², \n PIB: %f, \n Número de pontos turísticos: %d, \n Densidade populacional: %f, \n PIB per capita: %f, \n Super poder: %f \n",
    cityB.name, cityB.code, cityB.population, cityB.area, cityB.pib, cityB.numOfPoints, cityB.populationDensity, cityB.pibPerCapita, cityB.superPower);
     
    printf("\n");
    printf("----\n");
    printf("\n");

    //Call the function responsible for comparing each card value
    compareCards(cityA, cityB);

    return 0;
}