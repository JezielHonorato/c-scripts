#include <stdio.h>
#include <math.h>

double trapezios(double (*f)(double), double a, double b, int n)
{
	double h = (b - a) / n;
	double s = f(a) + f(b);

	for (int i = 1; i < n; i++)
		s += 2.0 * f(a + i * h);

	return (h / 2.0) * s;
}

double simpson(double (*f)(double), double a, double b, int n)
{
	if (n % 2 != 0)
	{
		printf("Erro: n deve ser par no método de Simpson.\n");
		return -1.0;
	}

	double h = (b - a) / n;
	double s = f(a) + f(b);

	for (int i = 1; i < n; i++)
	{
		double x = a + i * h;
		if (i % 2 == 0)
			s += 2.0 * f(x);
		else
			s += 4.0 * f(x);
	}

	return (h / 3.0) * s;
}

double normal(double x, double mu, double sigma)
{
	return (1.0 / (sigma * sqrt(2.0 * 3.14159265359))) * exp(-0.5 * pow((x - mu) / sigma, 2.0));
}

double exponencial(double t, double lambda)
{
	return lambda * exp(-lambda * t);
}

double r_gama;
double lambda_gama;

double gama(double x)
{
	if (x <= 0.0)
		return 0.0;

	double logf = r_gama * log(lambda_gama) - lgamma(r_gama) + (r_gama - 1.0) * log(x) - lambda_gama * x;

	return exp(logf);
}

double normal_wrapper(double x)
{
	return normal(x, 129.0, 14.0);
}

double expon_wrapper(double x)
{
	return exponencial(x, 0.1);
}

double gamma10_wrapper(double x)
{
	r_gama = 10.0;
	lambda_gama = 80.0;
	return gama(x);
}

double gamma300_wrapper(double x)
{
	r_gama = 300.0;
	lambda_gama = 80.0;
	return gama(x);
}

int main()
{
	printf("\nDISTRIBUICAO NORMAL\n");

	int n_simpson = 10000;

	double p1a = simpson(normal_wrapper, 60.0, 120.0, n_simpson);
	printf("1.a) = %f\n", p1a);

	double p1b = simpson(normal_wrapper, 0.0, 100.0, n_simpson);
	printf("1.b) = %f\n", p1b);

	double limite = 129.0 + 2.0 * 14.0;
	double p1c = 1.0 - simpson(normal_wrapper, 0.0, limite, n_simpson);
	printf("1.c) = %f\n", p1c);

	double target = 0.95;
	double low = 0.0, high = 400.0, mid = 0.0, p = 0.0;
	for (int i = 0; i < 100; i++)
	{
		mid = 0.5 * (low + high);
		p = simpson(normal_wrapper, 0.0, mid, 1000);
		if (p < target)
			low = mid;
		else
			high = mid;
	}
	printf("1.d) = %f\n", mid);

	printf("\n2) DISTRIBUICAO EXPONENCIAL\n");

	double a = 8.0;

	printf("2.a) = %f\n", trapezios(expon_wrapper, 0.0, a, 20));
	printf("2.b) = %f\n", simpson(expon_wrapper, 0.0, a, 20));
	printf("2.c) = %f\n", 1.0 - exp(-0.1 * a));

	printf("\nDISTRIBUICAO GAMA\n");

	double p3a = simpson(gamma10_wrapper, 0.0, 0.2, 1000);
	printf("3.a) = %f\n", p3a);

	double p3b = simpson(gamma300_wrapper, 0.0, 3.5, 1000);
	printf("3.b) = %f\n", p3b);

	return 0;
}
