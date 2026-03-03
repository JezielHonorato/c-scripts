#include <stdio.h>
#include <math.h>

struct tCoordenada
{
	float x;
	float y;
};

float dist(struct tCoordenada p1, struct tCoordenada p2)
{
	float d;
	d = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
	return d;
}

int main()
{
	struct tCoordenada ponto1, ponto2;
	float resultado;

	scanf("%f", &ponto1.x);
	scanf("%f", &ponto1.y);
	scanf("%f", &ponto2.x);
	scanf("%f", &ponto2.y);

	resultado = dist(ponto1, ponto2);

	printf("Distância: %.2f\n", resultado);

	return 0;
}
