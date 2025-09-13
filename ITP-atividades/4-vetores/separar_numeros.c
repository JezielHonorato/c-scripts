#include <stdio.h>

int main()
{
	int A[15], B[15], C[15], D[15];
	int bCount = 0, cCount = 0, dCount = 0;

	for (int i = 0; i < 15; i++)
	{
		scanf("%d", &A[i]);
	}

	for (int i = 0; i < 15; i++)
	{
		if (A[i] % 2 == 0)
		{
			B[bCount++] = A[i];
		}
		if (A[i] % 3 == 0)
		{
			C[cCount++] = A[i];
		}
		else if (A[i] % 2 != 0)
		{
			D[dCount++] = A[i];
		}
	}

	printf("B = [");
	for (int i = 0; i < bCount; i++)
	{
		printf("%d", B[i]);
		if (i < bCount - 1)
			printf(", ");
	}
	printf("]\n");

	printf("C = [");
	for (int i = 0; i < cCount; i++)
	{
		printf("%d", C[i]);
		if (i < cCount - 1)
			printf(", ");
	}
	printf("]\n");

	printf("D = [");
	for (int i = 0; i < dCount; i++)
	{
		printf("%d", D[i]);
		if (i < dCount - 1)
			printf(", ");
	}
	printf("]\n");

	return 0;
}
