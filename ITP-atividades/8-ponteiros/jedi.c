#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **separa(char *str, int *quantidadeTextos)
{
	char **textoSeparado = NULL;
	char *texto;
	int cont = 0;
	texto = strtok(str, " ");
	while (texto != NULL)
	{
		textoSeparado = realloc(textoSeparado, (cont + 1) * sizeof(char *));
		textoSeparado[cont] = malloc(strlen(texto) + 1);
		strcpy(textoSeparado[cont], texto);
		cont++;
		texto = strtok(NULL, " ");
	}
	*quantidadeTextos = cont;
	return textoSeparado;
}

char *juntar(char **vetor_strings, int tamanho_vetor)
{
	int tamanho_final = 0;
	for (int i = 0; i < tamanho_vetor; i++)
		tamanho_final += strlen(vetor_strings[i]);
	if (tamanho_vetor > 0)
		tamanho_final += (tamanho_vetor - 1);
	char *strings_unidas = malloc(tamanho_final + 1);
	strings_unidas[0] = '\0';
	for (int i = 0; i < tamanho_vetor; i++)
	{
		strcat(strings_unidas, vetor_strings[i]);
		if (i != tamanho_vetor - 1)
			strcat(strings_unidas, " ");
	}
	return strings_unidas;
}

int main()
{
	char linha[600];
	if (!fgets(linha, sizeof(linha), stdin))
		return 0;
	linha[strcspn(linha, "\n")] = 0;
	char *copia = malloc(strlen(linha) + 1);
	strcpy(copia, linha);
	int N;
	char **M = separa(copia, &N);
	free(copia);
	const unsigned int S = 5940;
	srand(S);
	char **E = NULL;
	int k = 0;
	int *visto = calloc(N, sizeof(int));
	int vistos = 0;
	while (vistos < N)
	{
		int n = rand();
		int idx = n % N;
		E = realloc(E, (k + 1) * sizeof(char *));
		E[k] = malloc(strlen(M[idx]) + 1);
		strcpy(E[k], M[idx]);
		if (!visto[idx])
		{
			visto[idx] = 1;
			vistos++;
		}
		k++;
	}
	char *R = juntar(E, k);
	printf("%s\n", R);
	for (int i = 0; i < N; i++)
		free(M[i]);
	free(M);
	for (int i = 0; i < k; i++)
		free(E[i]);
	free(E);
	free(visto);
	free(R);
	return 0;
}
