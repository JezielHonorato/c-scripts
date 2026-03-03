#include <stdio.h>
#include <string.h>
#include <ctype.h>

void imprimePalavra (char *c, int salto, int tam) {
    if (c == NULL) {
        printf("Palavra nao encontrada\n");
        return;
    }
    for (int i = 0; i < tam; i++) {
        printf("%c", *c);
        c += salto;
    }
    printf(", salto:%d\n", salto);
}

char* localizarPalavra(char *mat, char *palavra, int *salto) {
    int tam = strlen(palavra);
    for (int i = 0; i < 10 * 10; i++) {
        if (toupper(*(mat + i)) == toupper(palavra[0])) {
            int direcoes[8][2] = {
                {-1, 0}, {1, 0}, {0, -1}, {0, 1},
                {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
            };
            for (int d = 0; d < 8; d++) {
                int dx = direcoes[d][0];
                int dy = direcoes[d][1];
                int ok = 1;
                for (int k = 1; k < tam; k++) {
                    int r = (i / 10) + dx * k;
                    int c = (i % 10) + dy * k;
                    if (r < 0 || r >= 10 || c < 0 || c >= 10) { ok = 0; break; }
                    if (toupper(*(mat + r * 10 + c)) != toupper(palavra[k])) { ok = 0; break; }
                }
                if (ok) {
                    *salto = dx * 10 + dy;
                    return (mat + i);
                }
            }
        }
    }
    return NULL;
}

int main() {
    int q;
    scanf("%d", &q);
    char palavras[5][20];
    for (int i = 0; i < q; i++) scanf("%s", palavras[i]);
    char matriz[10][10];
    for (int i = 0; i < 10; i++) scanf("%s", matriz[i]);
    for (int i = 0; i < q; i++) {
        int salto;
        char *p = localizarPalavra(&matriz[0][0], palavras[i], &salto);
        imprimePalavra(p, salto, strlen(palavras[i]));
    }
    return 0;
}
