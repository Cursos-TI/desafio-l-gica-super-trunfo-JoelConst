#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar uma carta do jogo
typedef struct {
    char estado;         
    char codigo[4];     
    char nome[50];      
    int populacao;      
    float area;         
    float pib;          
    int pontos_turisticos; 
} Carta;

// Função para cadastrar uma nova carta
void cadastrarCarta(Carta *carta) {
    printf("Digite a letra do estado (A-H): ");
    scanf(" %c", &carta->estado);

    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", carta->codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta->nome);

    printf("Digite a população da cidade: ");
    scanf("%d", &carta->populacao);

    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &carta->pib);

    printf("Digite o número de pontos turísticos da cidade: ");
    scanf("%d", &carta->pontos_turisticos);
}

// Função para exibir os dados de uma carta
void exibirCarta(const Carta *carta) {
    printf("\n--- Dados da Carta ---\n");
    printf("Estado: %c\n", carta->estado);
    printf("Código: %s\n", carta->codigo);
    printf("Nome da cidade: %s\n", carta->nome);
    printf("População: %d habitantes\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("PIB: %.2f\n", carta->pib);
    printf("Pontos turísticos: %d\n", carta->pontos_turisticos);
    printf("----------------------\n");
}

// Função para calcular a densidade populacional
float calcularDensidadePopulacional(const Carta *carta) {
    return carta->populacao / carta->area;
}

// Função para calcular o PIB per capita
float calcularPIBPerCapita(const Carta *carta) {
    return carta->pib / carta->populacao;
}

// Função para comparar duas cartas usando um atributo escolhido
void compararCartas(const Carta *carta1, const Carta *carta2, int atributo) {
    float valor1, valor2;

    switch (atributo) {
        case 1:  // População
            valor1 = carta1->populacao;
            valor2 = carta2->populacao;
            printf("\nComparação de Cartas (Atributo: População)\n");
            break;
        case 2:  // Área
            valor1 = carta1->area;
            valor2 = carta2->area;
            printf("\nComparação de Cartas (Atributo: Área)\n");
            break;
        case 3:  // PIB
            valor1 = carta1->pib;
            valor2 = carta2->pib;
            printf("\nComparação de Cartas (Atributo: PIB)\n");
            break;
        case 4:  // Densidade Populacional (Menor vence)
            valor1 = calcularDensidadePopulacional(carta1);
            valor2 = calcularDensidadePopulacional(carta2);
            printf("\nComparação de Cartas (Atributo: Densidade Populacional)\n");
            break;
        case 5:  // PIB per capita
            valor1 = calcularPIBPerCapita(carta1);
            valor2 = calcularPIBPerCapita(carta2);
            printf("\nComparação de Cartas (Atributo: PIB per capita)\n");
            break;
        default:
            printf("Atributo inválido!\n");
            return;
    }

    printf("%s (%c) - Valor: %.2f\n", carta1->nome, carta1->estado, valor1);
    printf("%s (%c) - Valor: %.2f\n", carta2->nome, carta2->estado, valor2);

    // Lógica de comparação
    if (atributo == 4) { // Densidade Populacional -> Menor vence
        if (valor1 < valor2)
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1->nome);
        else if (valor2 < valor1)
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2->nome);
        else
            printf("Resultado: Empate!\n");
    } else { // Para os demais atributos -> Maior vence
        if (valor1 > valor2)
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1->nome);
        else if (valor2 > valor1)
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2->nome);
        else
            printf("Resultado: Empate!\n");
    }
}

int main() {
    Carta carta1, carta2;
    int atributo;

    printf("Cadastro da Carta 1:\n");
    cadastrarCarta(&carta1);

    printf("\nCadastro da Carta 2:\n");
    cadastrarCarta(&carta2);

    printf("\nExibindo Cartas Cadastradas:\n");
    exibirCarta(&carta1);
    exibirCarta(&carta2);

    printf("\nEscolha o atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Densidade Populacional\n");
    printf("5 - PIB per capita\n");
    printf("Digite sua opção: ");
    scanf("%d", &atributo);

    compararCartas(&carta1, &carta2, atributo);

    return 0;
}
