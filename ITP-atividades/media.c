#include <stdio.h>
#include <math.h>

int main()
{
	double mediaAritimetica = 0.0, mediaHarmonica = 0.0, mediaGeometrica = 1.0, erroMedio, erroGeometrico, erroHarmonico, notas[10];

	for (int i = 0; i < 10; i++)
	{
		scanf("%lf", &notas[i]);
	}

	for (int i = 0; i < 10; i++)
	{
		mediaAritimetica += notas[i];
		mediaGeometrica *= notas[i];
		mediaHarmonica += 1.0 / notas[i];
	}

	mediaAritimetica /= 10.0;
	mediaGeometrica = pow(mediaGeometrica, (1.0 / 10.0));
	mediaHarmonica = 10.0 / mediaHarmonica;

	erroGeometrico = (mediaGeometrica - mediaAritimetica) / mediaAritimetica;
	erroHarmonico = (mediaHarmonica - mediaAritimetica) / mediaAritimetica;
	erroMedio = (erroGeometrico + erroHarmonico) / 2.0;

	printf("Média aritmética é %.2lf\n", mediaAritimetica);
	printf("Média harmônica é %.2lf\n", mediaHarmonica);
	printf("Média geométrica é %.2lf\n", mediaGeometrica);
	printf("Erro médio é %.2lf %%", erroMedio * 100);

	return 0;
}