#include <stdio.h>

void ordena(int *a, int *b)
{
	if (*a < *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}
}

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	ordena(&x, &y);
	printf("%d\n%d\n", x, y);
	return 0;
}
