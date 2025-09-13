#include <stdio.h>

int MDC(int x, int y);

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);

	printf("MDC(%d , %d) = %d", x, y, MDC(x, y));

	return 0;
}

int MDC(int x, int y)
{
	int aux;
	while (y != 0)
	{
		aux = x % y;
		x = y;
		y = aux;
	}
	return x;
}
