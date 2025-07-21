#include <stdio.h>
#include <locale.h>

void inicializarTabuleiro(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

void exibirTabuleiro(char tabuleiro[3][3]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < 3; i++) {
        printf("%c | %c | %c\n", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
    }
}

int verificarVencedor(char tabuleiro[3][3], char jogador) {
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) {
            return 1;
        }
        if (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador) {
            return 1;
        }
    }
    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) {
        return 1;
    }
    if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador) {
        return 1;
    }
    return 0;
}

char trocarJogador(char jogadorAtual) {
    return (jogadorAtual == 'X') ? 'O' : 'X';
}

int jogadaValida(char tabuleiro[3][3], int linha, int coluna) {
    return linha >= 1 && linha <= 3 &&
           coluna >= 1 && coluna <= 3 &&
           tabuleiro[linha - 1][coluna - 1] == ' ';
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    char jogador = 'X', vencedor = ' ';
    int linha, coluna, jogadas = 0;
    char tabuleiro[3][3];

    inicializarTabuleiro(tabuleiro);

    while (vencedor == ' ' && jogadas < 9) {
        printf("\nJogador %c, é sua vez!\n", jogador);
        printf("Linha (1-3): ");
        scanf("%d", &linha);
        printf("Coluna (1-3): ");
        scanf("%d", &coluna);

        if (jogadaValida(tabuleiro, linha, coluna)) {
            tabuleiro[linha - 1][coluna - 1] = jogador;
            jogadas++;

            if (verificarVencedor(tabuleiro, jogador)) {
                vencedor = jogador;
            } else {
                jogador = trocarJogador(jogador);
            }

            exibirTabuleiro(tabuleiro);
        } else {
            printf("Jogada inválida! Tente novamente.\n");
        }
    }

    if (vencedor != ' ') {
        printf("\nVencedor = jogador %c\n", vencedor);
    } else {
        printf("\nDeu velha!\n");
    }

    return 0;
}