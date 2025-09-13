#include <stdio.h>
#include <math.h>

int main()
{
	double tempo, atleta;
	int atletaApto = 0, raia;
	scanf("%lf", &tempo);

	do
	{
		scanf("%lf", &atleta);
		if (atleta <= tempo && atleta > 0)
		{
			++atletaApto;
		}
	} while (atleta != -1);

	raia = ceil((double)atletaApto / 8);
	printf("%d %d", atletaApto, raia);

	return 0;
}