#include <stdio.h>

// Estrutura da carta
typedef struct {
    char estado;                // letra de A a H
    char codigo[4];             // ex: A01, B03
    char nome[100];             // nome da cidade/país
    unsigned long int populacao;
    float area;                 // km²
    float pib;                  // PIB da cidade
    int pontosTuristicos;
    float densidade;            // calculado depois
    float pibPerCapita;         // calculado depois
    float superPoder;           // calculado depois
} Carta;

// Função para ler uma carta
void lerCarta(Carta *carta, int numero) {
    printf("\n=== Inserir dados da Carta %d ===\n", numero);

    do {
        printf("Estado (A-H): ");
        scanf(" %c", &carta->estado);
    } while(carta->estado < 'A' || carta->estado > 'H');

    printf("Código da Carta (ex: A01): ");
    scanf("%3s", carta->codigo);

    printf("Nome da Cidade: ");
    getchar(); // limpar buffer
    fgets(carta->nome, sizeof(carta->nome), stdin);
    // remover \n
    for (int i = 0; i < 100; i++) {
        if (carta->nome[i] == '\n') {
            carta->nome[i] = '\0';
            break;
        }
    }

    printf("População (unsigned long int): ");
    scanf("%lu", &carta->populacao);

    printf("Área (km²): ");
    scanf("%f", &carta->area);

    printf("PIB (float): ");
    scanf("%f", &carta->pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
}

// Função para calcular densidade e PIB per capita
void calcularDados(Carta *carta) {
    carta->densidade = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / (float)carta->populacao;
}

// Função para calcular super poder
void calcularSuperPoder(Carta *carta) {
    // Super Poder = soma de:
    // população (convertida para float),
    // área,
    // PIB,
    // pontos turísticos (convertido para float),
    // PIB per capita,
    // inverso da densidade (1/densidade)
    float populacaoFloat = (float)carta->populacao;
    float pontosTuristicosFloat = (float)carta->pontosTuristicos;
    float inversoDensidade = 1.0f / carta->densidade;

    carta->superPoder = populacaoFloat + carta->area + carta->pib + pontosTuristicosFloat + carta->pibPerCapita + inversoDensidade;
}

// Função para comparar atributos e imprimir resultados
void compararCartas(Carta c1, Carta c2) {
    printf("\nComparação de Cartas:\n");

    // População
    printf("População: Carta 1 venceu (%d)\n", c1.populacao > c2.populacao ? 1 : 0);

    // Área
    printf("Área: Carta 1 venceu (%d)\n", c1.area > c2.area ? 1 : 0);

    // PIB
    printf("PIB: Carta 1 venceu (%d)\n", c1.pib > c2.pib ? 1 : 0);

    // Pontos Turísticos
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", c1.pontosTuristicos > c2.pontosTuristicos ? 1 : 0);

    // Densidade Populacional - menor vence
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", c1.densidade < c2.densidade ? 1 : 0);

    // PIB per Capita
    printf("PIB per Capita: Carta 1 venceu (%d)\n", c1.pibPerCapita > c2.pibPerCapita ? 1 : 0);

    // Super Poder
    printf("Super Poder: Carta 1 venceu (%d)\n", c1.superPoder > c2.superPoder ? 1 : 0);
}

// Função para exibir a carta
void exibirCarta(Carta carta, int numero) {
    printf("\n=== Carta %d ===\n", numero);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome: %s\n", carta.nome);
    printf("População: %lu\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade);
    printf("PIB per Capita: %.2f\n", carta.pibPerCapita);
    printf("Super Poder: %.2f\n", carta.superPoder);
}

int main() {
    Carta carta1, carta2;

    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);

    calcularDados(&carta1);
    calcularDados(&carta2);

    calcularSuperPoder(&carta1);
    calcularSuperPoder(&carta2);

    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    compararCartas(carta1, carta2);

    return 0;
}