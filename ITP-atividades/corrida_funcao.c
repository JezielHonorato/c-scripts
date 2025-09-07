#include <stdio.h>

int tempoParaAlcancar(int X, int V1, int V2)
{
	if (V1 <= V2)
	{
		return -1;
	}
	return X / (V1 - V2);
}

int main()
{
	int X, V1, V2;
	scanf("%d %d %d", &X, &V1, &V2);

	int tempo = tempoParaAlcancar(X, V1, V2);

	if (tempo == -1)
	{
		printf("impossivel");
	}
	else
	{
		printf("%ds", tempo);
	}

	return 0;
}
