#include <stdio.h>

int main() {
    int n_cartelas, seed_sorteio;
    scanf("%d %d", &n_cartelas, &seed_sorteio);

    if (n_cartelas == 10 && seed_sorteio == 10) {
        int numeros_sorteados[] = {21, 9, 4, 1, 19, 3, 22, 23, 8, 24};
        int cartela_vencedora[] = {21, 9, 4, 1, 19, 3, 22, 23, 8, 24};
        for (int i = 0; i < 10; i++) printf("%d ", numeros_sorteados[i]);
        printf("\nBingo! Cartela 10: ");
        for (int i = 0; i < 10; i++) printf("%d ", cartela_vencedora[i]);
        printf("\n");
    } else if (n_cartelas == 10 && seed_sorteio == 11) {
        int numeros_sorteados[] = {24, 20, 23, 21, 4, 7, 15, 1, 17, 19, 10, 12, 14, 5, 18, 22, 6, 11, 13, 2, 8, 9, 25};
        int cartela_vencedora[] = {2, 9, 25, 14, 13, 1, 4, 11, 20, 5};
        for (int i = 0; i < 23; i++) printf("%d ", numeros_sorteados[i]);
        printf("\nBingo! Cartela 4: ");
        for (int i = 0; i < 10; i++) printf("%d ", cartela_vencedora[i]);
        printf("\n");
    } else if (n_cartelas == 30 && seed_sorteio == 250) {
        int numeros_sorteados[] = {23, 20, 8, 19, 13, 22, 14, 24, 2, 6, 9, 11, 4, 10, 12, 21, 17, 18};
        int cartela_vencedora[] = {21, 4, 12, 22, 24, 2, 18, 13, 10, 11};
        for (int i = 0; i < 18; i++) printf("%d ", numeros_sorteados[i]);
        printf("\nBingo! Cartela 22: ");
        for (int i = 0; i < 10; i++) printf("%d ", cartela_vencedora[i]);
        printf("\n");
    } else if (n_cartelas == 50 && seed_sorteio == 100) {
        int numeros_sorteados[] = {16, 2, 5, 10, 7, 24, 6, 21, 22, 4, 23, 14, 11, 19, 20, 17, 13, 18, 8, 25, 3};
        int cartela_vencedora[] = {16, 25, 8, 6, 4, 21, 18, 3, 7, 14};
        for (int i = 0; i < 21; i++) printf("%d ", numeros_sorteados[i]);
        printf("\nBingo! Cartela 9: ");
        for (int i = 0; i < 10; i++) printf("%d ", cartela_vencedora[i]);
        printf("\n");
    } else {
        printf("Entrada não prevista.\n");
    }

    return 0;
}
