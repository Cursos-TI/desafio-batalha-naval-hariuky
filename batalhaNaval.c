#include <stdio.h>
#include <stdlib.h> 

int main() {
    int tamanho = 10;     
    int tabuleiro[10][10];

    int i, j;

    // ==========================
    // Inicializar tabuleiro (com água = 0)
    // ==========================
    for (i = 0; i < tamanho; i++) {
        for (j = 0; j < tamanho; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ==========================
    // colocar alguns navios (valor = 3)
    // ==========================
    // navio horizontal
    for (j = 3; j < 6; j++) {
        tabuleiro[2][j] = 3;
    }
    // navio vertical
    for (i = 5; i < 8; i++) {
        tabuleiro[i][7] = 3;
    }

    // ==========================
    // Criar matrizes das habilidades (5x5)
    // ==========================
    int habilidade_tam = 5;

    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    // Cone 
    for (i = 0; i < habilidade_tam; i++) {
        for (j = 0; j < habilidade_tam; j++) {
            if (j >= (habilidade_tam/2 - i) && j <= (habilidade_tam/2 + i)) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    // Cruz 
    for (i = 0; i < habilidade_tam; i++) {
        for (j = 0; j < habilidade_tam; j++) {
            if (i == habilidade_tam/2 || j == habilidade_tam/2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // Octaedro 
    for (i = 0; i < habilidade_tam; i++) {
        for (j = 0; j < habilidade_tam; j++) {
            if (abs(habilidade_tam/2 - i) + abs(habilidade_tam/2 - j) <= habilidade_tam/2) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    // ==========================
    // Aplicar habilidades no tabuleiro
    // ==========================
    int origem_cone_l = 0, origem_cone_c = 2;
    int origem_cruz_l = 5, origem_cruz_c = 5;
    int origem_octa_l = 8, origem_octa_c = 2;

    for (i = 0; i < habilidade_tam; i++) {
        for (j = 0; j < habilidade_tam; j++) {
            // Cone
            if (cone[i][j] == 1) {
                int linha = origem_cone_l + i;
                int coluna = origem_cone_c + j - habilidade_tam/2;
                if (linha >= 0 && linha < tamanho && coluna >= 0 && coluna < tamanho) {
                    if (tabuleiro[linha][coluna] == 0) {
                        tabuleiro[linha][coluna] = 5;
                    }
                }
            }

            // Cruz
            if (cruz[i][j] == 1) {
                int linha = origem_cruz_l + i - habilidade_tam/2;
                int coluna = origem_cruz_c + j - habilidade_tam/2;
                if (linha >= 0 && linha < tamanho && coluna >= 0 && coluna < tamanho) {
                    if (tabuleiro[linha][coluna] == 0) {
                        tabuleiro[linha][coluna] = 5;
                    }
                }
            }

            // Octaedro
            if (octaedro[i][j] == 1) {
                int linha = origem_octa_l + i - habilidade_tam/2;
                int coluna = origem_octa_c + j - habilidade_tam/2;
                if (linha >= 0 && linha < tamanho && coluna >= 0 && coluna < tamanho) {
                    if (tabuleiro[linha][coluna] == 0) {
                        tabuleiro[linha][coluna] = 5;
                    }
                }
            }
        }
    }

    // ==========================
    //Exibir tabuleiro 
    // ==========================
    printf("=== TABULEIRO COM HABILIDADES ===\n\n");
    for (i = 0; i < tamanho; i++) {
        for (j = 0; j < tamanho; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
