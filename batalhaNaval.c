#include <stdio.h>

int main() {
    int tamanho = 10;     
    int tamanhoNavio = 3; 
    int tabuleiro[10][10];

    int i = 0, j = 0;

    //Inicializar tabuleiro
    i = 0;
    while (i < tamanho) {
        j = 0;
        while (j < tamanho) {
            tabuleiro[i][j] = 0; 
            j++;
        }
        i++;
    }
    //Definir navios
    
    // Navio horizontal
    int navio1_linha = 1;
    int navio1_coluna = 3;

    // Navio vertical
    int navio2_linha = 5;
    int navio2_coluna = 7;

    // posicionar navio horizontal
    if (navio1_coluna + tamanhoNavio <= tamanho) {
        j = 0;
        while (j < tamanhoNavio) {
            if (tabuleiro[navio1_linha][navio1_coluna + j] == 0) {
                tabuleiro[navio1_linha][navio1_coluna + j] = 3;
            }
            j++;
        }
    }

    // posicionar navio vertical
    if (navio2_linha + tamanhoNavio <= tamanho) {
        i = 0;
        while (i < tamanhoNavio) {
            if (tabuleiro[navio2_linha + i][navio2_coluna] == 0) {
                tabuleiro[navio2_linha + i][navio2_coluna] = 3;
            }
            i++;
        }
    }
    // Exibir tabuleiro
    printf("=== TABULEIRO BATALHA NAVAL ===\n\n");
    i = 0;
    while (i < tamanho) {
        j = 0;
        while (j < tamanho) {
            printf("%d ", tabuleiro[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }

    return 0;
}
