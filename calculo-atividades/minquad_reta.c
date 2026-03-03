#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ajuste_reta(double *x, double *y, int n, double *a, double *b);
void ajuste_exponencial(double *x, double *y, int n, double *a, double *b);
void ajuste_quadratico(double *x, double *y, int n, double *a, double *b, double *c);

int main()
{
	FILE *in;
	char input_file[] = "pontos6.txt";

	in = fopen(input_file, "r");
	if (in == NULL)
	{
		printf("File does not exist\n");
		exit(EXIT_FAILURE);
	}

	int n = 0;
	char e;
	while ((e = fgetc(in)) != EOF)
	{
		if (e == '\n')
			n++;
	}
	fclose(in);

	double *x = (double *)malloc(n * sizeof(double));
	double *y = (double *)malloc(n * sizeof(double));

	in = fopen(input_file, "r");
	for (int i = 0; i < n; i++)
	{
		fscanf(in, "%lf %lf", &x[i], &y[i]);
	}
	fclose(in);

	double a, b, c;

	ajuste_reta(x, y, n, &a, &b);
	printf("Ajuste Linear: f(x) = %.6fx + %.6f\n", a, b);

	ajuste_exponencial(x, y, n, &a, &b);
	printf("Ajuste Exponencial: f(x) = %.6fe^(%.6fx)\n", a, b);

	ajuste_quadratico(x, y, n, &a, &b, &c);
	printf("Ajuste Quadrático: f(x) = %.6fx^2 + %.6fx + %.6f\n", a, b, c);

	free(x);
	free(y);

	return 0;
}

void ajuste_reta(double *x, double *y, int n, double *a, double *b)
{
	double Sx = 0.0, Sxx = 0.0, Sy = 0.0, Sxy = 0.0;
	for (int i = 0; i < n; i++)
	{
		Sx += x[i];
		Sxx += x[i] * x[i];
		Sy += y[i];
		Sxy += x[i] * y[i];
	}
	*a = (Sx * Sy - n * Sxy) / (Sx * Sx - n * Sxx);
	*b = Sy / n - (*a) * Sx / n;
}

void ajuste_exponencial(double *x, double *y, int n, double *a, double *b)
{
	double Sx = 0.0, Sxx = 0.0, Sy = 0.0, Sxy = 0.0;
	for (int i = 0; i < n; i++)
	{
		double ly = log(y[i]);
		Sx += x[i];
		Sxx += x[i] * x[i];
		Sy += ly;
		Sxy += x[i] * ly;
	}

	*b = (n * Sxy - Sx * Sy) / (n * Sxx - Sx * Sx);
	double loga = (Sy - (*b) * Sx) / n;
	*a = exp(loga);
}

void ajuste_quadratico(double *x, double *y, int n, double *a, double *b, double *c)
{
	double Sx = 0.0, Sxx = 0.0, Sxxx = 0.0, Sxxxx = 0.0;
	double Sy = 0.0, Sxy = 0.0, Sxxy = 0.0;

	for (int i = 0; i < n; i++)
	{
		double xi = x[i];
		double yi = y[i];
		double xi2 = xi * xi;

		Sx += xi;
		Sxx += xi2;
		Sxxx += xi2 * xi;
		Sxxxx += xi2 * xi2;
		Sy += yi;
		Sxy += xi * yi;
		Sxxy += xi2 * yi;
	}

	double D = n * Sxx * Sxxxx + 2 * Sx * Sxx * Sxxx - Sxx * Sxx * Sxx - n * Sxxx * Sxxx - Sx * Sx * Sxxxx;
	*a = (n * Sxxy * Sxx + Sx * Sxy * Sxxx + Sx * Sxx * Sy - Sxx * Sxx * Sy - n * Sxxx * Sxy - Sx * Sx * Sxxy) / D;
	*b = (n * Sxy * Sxxxx + Sx * Sxxy * Sxxx + Sx * Sxx * Sy - Sxx * Sxxx * Sy - n * Sxxx * Sxxy - Sx * Sx * Sxxxx) / D;
	*c = (Sy - (*a) * Sxx - (*b) * Sx) / n;
}
