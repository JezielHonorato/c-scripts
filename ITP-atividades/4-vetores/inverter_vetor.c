#include <stdio.h>

int main()
{
	int N[8], M[8];

	for (int i = 0; i < 8; i++)
	{
		scanf("%d", &N[i]);
	}

	for (int i = 0; i < 8; i++)
	{
		M[i] = N[7 - i];
	}

	for (int i = 0; i < 8; i++)
	{
		printf("%d", M[i]);
		if (i < 7)
		{
			printf(",");
		}
	}
	printf("\n");

	return 0;
}