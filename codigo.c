#include <stdio.h>
#include <string.h>

#define L 10
#define C 10

void test(char matriz[L][C], char palavra);

typedef struct {
    int li;
    int ci;
    int cf;
    int lf;
    int achou;
} DATA;

int valoresMatriz(char* valores, char matriz[L][C]);
void mostrarMatriz(char matriz[L][C]);
void buscaVerticalCima(char matriz[L][C], char* palavra, DATA* data);
void buscaVerticalBaixo(char matriz[L][C], char* palavra, DATA* data);
void horizontal(char matriz[L][C], char* palavra, DATA* data);
void horizontalEsq(char matriz[L][C], char* palavra, DATA* data);
void diagonalPrincCima(char matriz[L][C], char* palavra, DATA* data);
void diagonalPrincBaixo(char matriz[L][C], char* palavra, DATA* data);
void diagonalSecCima(char matriz[L][C], char* palavra, DATA* data);
void diagonalSecBaixo(char matriz[L][C], char* palavra, DATA* data);
void localizaPalavra(char matriz[L][C], char* palavra);
void structure(char matriz[L][C], char* palavra, char* valores);

int main() {
    char valores[] = "SAPAACAVAAAAPADAVUUJTAPAAPASONASJAVMVARAJPOATRRASRAOJALORAAAOPAOMOUPSLPAPPMVAUAAOATALSVAPAAOTTRAASOP";
    char matriz[L][C], palavra[50];
    int i;

    DATA data = {0, 0, 0, 0, 0};
    
    structure(matriz,palavra,valores);

    return 0;
}

void structure(char matriz[L][C], char* palavra, char* valores) {
        int escolha;
        int i;
    printf("\n");

    printf("Bem vindo ao busca de palavras! \n");
    printf("1 - Exibir a matriz \n");
    printf("2 - Localizar cada palavra por vez \n");
    scanf("%i", &escolha);
    if (escolha == 1) {
        valoresMatriz(valores, matriz);
        mostrarMatriz(matriz);
    }
    else if (escolha == 2) {
        valoresMatriz(valores, matriz);
        for (i = 0; i < 8; i++) {
            printf("Digite a palavra que deseja buscar: ");
            scanf("%s", palavra);
            localizaPalavra(matriz, palavra);
        }
    }
}

int valoresMatriz(char* valores, char matriz[L][C]) {
    int soma = 0;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            matriz[i][j] = valores[soma++];
        }
    }
    return 0;
}

void mostrarMatriz(char matriz[L][C]) {
    printf("      Matriz \n");
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}

void buscaVerticalCima(char matriz[L][C], char* palavra, DATA* data) {
    int length = strlen(palavra);
    int encontrou = 0;

    for (int i = L - 1; i >= length - 1; i--) {
        for (int j = 0; j < C; j++) {
            if (matriz[i][j] == palavra[0]) {
                int k;
                for (k = 1; k < length; k++) {
                    if (matriz[i - k][j] != palavra[k]) {
                        break;
                    }
                }
                if (k == length) {
                    data->li = i;
                    data->ci = j;
                    data->lf = i - length + 1;
                    data->cf = j;
                    data->achou = 1;
                    encontrou = 1;
                    break;
                }
            }
        }
        if (encontrou) {
            break;
        }
    }
}

void buscaVerticalBaixo(char matriz[L][C], char* palavra, DATA* data) {
    int length = strlen(palavra);
    int encontrou = 0;

    for (int i = 0; i <= L - length; i++) {
        for (int j = 0; j < C; j++) {
            if (matriz[i][j] == palavra[0]) {
                int k;
                for (k = 1; k < length; k++) {
                    if (matriz[i + k][j] != palavra[k]) {
                        break;
                    }
                }
                if (k == length) {
                    data->li = i;
                    data->ci = j;
                    data->lf = i + length - 1;
                    data->cf = j;
                    data->achou = 1;
                    encontrou = 1;
                    break;
                }
            }
        }
        if (encontrou) {
            break;
        }
    }
}

void horizontal(char matriz[L][C], char* palavra, DATA* data) {
    int length = strlen(palavra);
    int encontrou = 0;

    for (int i = 0; i < L; i++) {
        for (int j = 0; j <= C - length; j++) {
            if (matriz[i][j] == palavra[0]) {
                int k;
                for (k = 1; k < length; k++) {
                    if (matriz[i][j + k] != palavra[k]) {
                        break;
                    }
                }
                if (k == length) {
                    data->li = i;
                    data->ci = j;
                    data->lf = i;
                    data->cf = j + length - 1;
                    data->achou = 1;
                    encontrou = 1;
                    break;
                }
            }
        }
        if (encontrou) {
            break;
        }
    }
}

void horizontalEsq(char matriz[L][C], char* palavra, DATA* data) {
    int length = strlen(palavra);
    int encontrou = 0;

    for (int i = 0; i < L; i++) {
        for (int j = C - 1; j >= length - 1; j--) {
            if (matriz[i][j] == palavra[0]) {
                int k;
                for (k = 1; k < length; k++) {
                    if (matriz[i][j - k] != palavra[k]) {
                        break;
                    }
                }
                if (k == length) {
                    data->li = i;
                    data->ci = j;
                    data->lf = i;
                    data->cf = j - length + 1;
                    data->achou = 1;
                    encontrou = 1;
                    break;
                }
            }
        }
        if (encontrou) {
            break;
        }
    }
}

void diagonalPrincCima(char matriz[L][C], char* palavra, DATA* data) {
    int length = strlen(palavra);
    int encontrou = 0;

    for (int i = L - 1; i >= length - 1; i--) {
        for (int j = 0; j <= C - length; j++) {
            if (matriz[i][j] == palavra[0]) {
                int k;
                for (k = 1; k < length; k++) {
                    if (matriz[i - k][j + k] != palavra[k]) {
                        break;
                    }
                }
                if (k == length) {
                    data->li = i;
                    data->ci = j;
                    data->lf = i - length + 1;
                    data->cf = j + length - 1;
                    data->achou = 1;
                    encontrou = 1;
                    break;
                }
            }
        }
        if (encontrou) {
            break;
        }
    }
}

void diagonalPrincBaixo(char matriz[L][C], char* palavra, DATA* data) {
    int length = strlen(palavra);
    int encontrou = 0;

    for (int i = 0; i <= L - length; i++) {
        for (int j = C - 1; j >= length - 1; j--) {
            if (matriz[i][j] == palavra[0]) {
                int k;
                for (k = 1; k < length; k++) {
                    if (matriz[i + k][j - k] != palavra[k]) {
                        break;
                    }
                }
                if (k == length) {
                    data->li = i;
                    data->ci = j;
                    data->lf = i + length - 1;
                    data->cf = j - length + 1;
                    data->achou = 1;
                    encontrou = 1;
                    break;
                }
            }
        }
        if (encontrou) {
            break;
        }
    }
}

void diagonalSecCima(char matriz[L][C], char* palavra, DATA* data) {
    int length = strlen(palavra);
    int encontrou = 0;

    for (int i = L - 1; i >= length - 1; i--) {
        for (int j = C - 1; j >= length - 1; j--) {
            if (matriz[i][j] == palavra[0]) {
                int k;
                for (k = 1; k < length; k++) {
                    if (matriz[i - k][j - k] != palavra[k]) {
                        break;
                    }
                }
                if (k == length) {
                    data->li = i;
                    data->ci = j;
                    data->lf = i - length + 1;
                    data->cf = j - length + 1;
                    data->achou = 1;
                    encontrou = 1;
                    break;
                }
            }
        }
        if (encontrou) {
            break;
        }
    }
}

void diagonalSecBaixo(char matriz[L][C], char* palavra, DATA* data) {
    int length = strlen(palavra);
    int encontrou = 0;

    for (int i = 0; i <= L - length; i++) {
        for (int j = 0; j <= C - length; j++) {
            if (matriz[i][j] == palavra[0]) {
                int k;
                for (k = 1; k < length; k++) {
                    if (matriz[i + k][j + k] != palavra[k]) {
                        break;
                    }
                }
                if (k == length) {
                    data->li = i;
                    data->ci = j;
                    data->lf = i + length - 1;
                    data->cf = j + length - 1;
                    data->achou = 1;
                    encontrou = 1;
                    break;
                }
            }
        }
        if (encontrou) {
            break;
        }
    }
}

void localizaPalavra(char matriz[L][C], char* palavra) {
    DATA data;
    data.achou = 0;

    buscaVerticalCima(matriz, palavra, &data);
    if (!data.achou) {
        buscaVerticalBaixo(matriz, palavra, &data);
    }
    if (!data.achou) {
        horizontal(matriz, palavra, &data);
    }
    if (!data.achou) {
        horizontalEsq(matriz, palavra, &data);
    }
    if (!data.achou) {
        diagonalPrincCima(matriz, palavra, &data);
    }
    if (!data.achou) {
        diagonalPrincBaixo(matriz, palavra, &data);
    }
    if (!data.achou) {
        diagonalSecCima(matriz, palavra, &data);
    }
    if (!data.achou) {
        diagonalSecBaixo(matriz, palavra, &data);
    }

    if (data.achou) {
        printf("Palavra (%s) foi encontrada (%d,%d,%d,%d) \n", palavra,data.li,data.ci,data.lf,data.cf);
    } else {
        printf("Palavra não encontrada. (0,0,0,0)\n");
    }
}
