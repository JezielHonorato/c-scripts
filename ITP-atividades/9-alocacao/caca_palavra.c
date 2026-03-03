#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
	char **m;
	int linhas;
	int colunas;
} Grade;

typedef struct
{
	int linha;
	int coluna;
	int tamanho;
	char direcao;
} PalavraAchada;

int dentro(Grade *g, int r, int c)
{
	return r >= 0 && r < g->linhas && c >= 0 && c < g->colunas;
}

int compara(char a, char b)
{
	return tolower(a) == tolower(b);
}

PalavraAchada achaPalavra(Grade *g, char *p)
{
	PalavraAchada pa = {0, 0, (int)strlen(p), '0'};
	int dirs[8][3] = {
		{-1, 0, 'c'},
		{1, 0, 'b'},
		{0, -1, 'e'},
		{0, 1, 'd'},
		{-1, -1, '1'},
		{1, -1, '2'},
		{-1, 1, '3'},
		{1, 1, '4'}};

	int L = g->linhas, C = g->colunas, t = strlen(p);
	int r, c, i, d, rr, cc, ok;

	for (r = 0; r < L; r++)
	{
		for (c = 0; c < C; c++)
		{
			if (!compara(g->m[r][c], p[0]))
				continue;
			for (d = 0; d < 8; d++)
			{
				ok = 1;
				for (i = 0; i < t; i++)
				{
					rr = r + i * dirs[d][0];
					cc = c + i * dirs[d][1];
					if (!dentro(g, rr, cc) || !compara(g->m[rr][cc], p[i]))
					{
						ok = 0;
						break;
					}
				}
				if (ok)
				{
					pa.linha = r;
					pa.coluna = c;
					pa.direcao = dirs[d][2];
					return pa;
				}
			}
		}
	}

	pa.tamanho = strlen(p);
	pa.direcao = '0';
	return pa;
}

void imprimePalavra(Grade *g, PalavraAchada pa, char *p)
{
    if (pa.direcao == '0')
    {
        printf("%s,0,0,0\n", p);
        return;
    }

    int dr = 0, dc = 0;
    switch (pa.direcao)
    {
        case 'c': dr = -1; dc = 0; break;
        case 'b': dr = 1; dc = 0; break;
        case 'e': dr = 0; dc = -1; break;
        case 'd': dr = 0; dc = 1; break;
        case '1': dr = -1; dc = -1; break;
        case '2': dr = 1; dc = -1; break;
        case '3': dr = -1; dc = 1; break;
        case '4': dr = 1; dc = 1; break;
    }

    printf("");
    for (int i = 0; i < pa.tamanho; i++)
    {
        int rr = pa.linha + i * dr;
        int cc = pa.coluna + i * dc;
        putchar(g->m[rr][cc]);
    }

    printf(",%d,%d,%c\n", pa.linha, pa.coluna, pa.direcao);
}

int main()
{
	int N, L, C;
	scanf("%d %d %d", &N, &L, &C);

	char **palavras = malloc(N * sizeof(char *));
	int i, j;

	for (i = 0; i < N; i++)
	{
		palavras[i] = malloc(101);
		scanf("%s", palavras[i]);
	}

	Grade g;
	g.linhas = L;
	g.colunas = C;
	g.m = malloc(L * sizeof(char *));

	char buffer[1000];
	for (i = 0; i < L; i++)
	{
		g.m[i] = malloc(C + 1);
		scanf("%s", buffer);
		for (j = 0; j < C; j++)
			g.m[i][j] = buffer[j];
	}

	for (i = 0; i < N; i++)
	{
		PalavraAchada pa = achaPalavra(&g, palavras[i]);
		imprimePalavra(&g, pa, palavras[i]);
	}

	for (i = 0; i < L; i++)
		free(g.m[i]);
	free(g.m);
	for (i = 0; i < N; i++)
		free(palavras[i]);
	free(palavras);

	return 0;
}
