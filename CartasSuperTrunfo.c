#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura da carta de país
typedef struct {
    char codigo[3];            // Código do país (ex: BR, US)
    char nome[100];            // Nome do país
    int populacao;             // População (em milhões)
    float area;                // Área (em km²)
    float pib;                 // PIB (em trilhões de USD)
    float idh;                 // Índice de Desenvolvimento Humano (0 a 1)
    int expectativaVida;       // Expectativa de vida (anos)
    char superTrunfo;          // S (sim) ou N (não)
} CartaPais;

// Função para ler uma carta de país
void lerCarta(CartaPais *carta, int numero) {
    printf("\n--- Inserir dados da Carta %d ---\n", numero);

    printf("Código do País (ex: BR, US): ");
    scanf("%s", carta->codigo);

    printf("Nome do País: ");
    getchar(); // Limpar buffer
    fgets(carta->nome, sizeof(carta->nome), stdin);
    carta->nome[strcspn(carta->nome, "\n")] = '\0'; // Remover o \n

    printf("População (em milhões): ");
    scanf("%d", &carta->populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta->area);

    printf("PIB (em trilhões USD): ");
    scanf("%f", &carta->pib);

    printf("IDH (0 a 1): ");
    scanf("%f", &carta->idh);

    printf("Expectativa de vida (anos): ");
    scanf("%d", &carta->expectativaVida);

    printf("Super Trunfo (S/N): ");
    scanf(" %c", &carta->superTrunfo);
}

// Função para exibir os dados da carta
void exibirCarta(CartaPais carta, int numero) {
    printf("\n--- Carta %d ---\n", numero);
    printf("Código: %s\n", carta.codigo);
    printf("Nome: %s\n", carta.nome);
    printf("População: %d milhões\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f trilhões USD\n", carta.pib);
    printf("IDH: %.3f\n", carta.idh);
    printf("Expectativa de Vida: %d anos\n", carta.expectativaVida);
    printf("Super Trunfo: %s\n", (carta.superTrunfo == 'S' || carta.superTrunfo == 's') ? "Sim" : "Não");
}

int main() {
    CartaPais carta1, carta2;

    // Ler duas cartas
    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);

    // Exibir as cartas
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    return 0;
}