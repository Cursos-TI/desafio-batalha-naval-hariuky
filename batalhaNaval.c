
#include <stdio.h>

int main() {
    int tamanho = 10;     
    int tamanhoNavio = 3; 
    int tabuleiro[10][10];

    int i = 0, j = 0;

   
    // Inicializar tabuleiro
   
    i = 0;
    while (i < tamanho) {
        j = 0;
        while (j < tamanho) {
            tabuleiro[i][j] = 0; 
            j++;
        }
        i++;
    }

    
    // Definir navios (coordenadas iniciais)
   
    // Navio horizontal
    int navio1_linha = 1;
    int navio1_coluna = 3;

    // Navio vertical
    int navio2_linha = 5;
    int navio2_coluna = 7;

    // Navio diagonal ↘
    int navio3_linha = 0;
    int navio3_coluna = 0;

    // Navio diagonal ↙
    int navio4_linha = 0;
    int navio4_coluna = 9;

    
    // Posicionar navio horizontal
    
    if (navio1_coluna + tamanhoNavio <= tamanho) {
        j = 0;
        while (j < tamanhoNavio) {
            if (tabuleiro[navio1_linha][navio1_coluna + j] == 0) {
                tabuleiro[navio1_linha][navio1_coluna + j] = 3;
            }
            j++;
        }
    }

    
    // Posicionar navio vertical
   
    if (navio2_linha + tamanhoNavio <= tamanho) {
        i = 0;
        while (i < tamanhoNavio) {
            if (tabuleiro[navio2_linha + i][navio2_coluna] == 0) {
                tabuleiro[navio2_linha + i][navio2_coluna] = 3;
            }
            i++;
        }
    }

    
    // Posicionar navio diagonal 
   
    if (navio3_linha + tamanhoNavio <= tamanho &&
        navio3_coluna + tamanhoNavio <= tamanho) {
        i = 0;
        while (i < tamanhoNavio) {
            if (tabuleiro[navio3_linha + i][navio3_coluna + i] == 0) {
                tabuleiro[navio3_linha + i][navio3_coluna + i] = 3;
            }
            i++;
        }
    }

   
    // Posicionar navio diagonal 
    
    if (navio4_linha + tamanhoNavio <= tamanho &&
        navio4_coluna - (tamanhoNavio - 1) >= 0) {
        i = 0;
        while (i < tamanhoNavio) {
            if (tabuleiro[navio4_linha + i][navio4_coluna - i] == 0) {
                tabuleiro[navio4_linha + i][navio4_coluna - i] = 3;
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
