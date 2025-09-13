#include <stdio.h>

int mediana(int x, int y, int z);

int main()
{
	int skatistaA[9], skatistaB[9];
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &skatistaA[i]);
	}
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &skatistaB[i]);
	}

	int scoreA1 = mediana(skatistaA[0], skatistaA[1], skatistaA[2]);
	int scoreA2 = mediana(skatistaA[3], skatistaA[4], skatistaA[5]);
	int scoreA3 = mediana(skatistaA[6], skatistaA[7], skatistaA[8]);

	int scoreB1 = mediana(skatistaB[0], skatistaB[1], skatistaB[2]);
	int scoreB2 = mediana(skatistaB[3], skatistaB[4], skatistaB[5]);
	int scoreB3 = mediana(skatistaB[6], skatistaB[7], skatistaB[8]);

	int scoreFinalA = mediana(scoreA1, scoreA2, scoreA3);
	int scoreFinalB = mediana(scoreB1, scoreB2, scoreB3);

	if (scoreFinalA > scoreFinalB)
	{
		printf("A");
	}

	else if (scoreFinalB > scoreFinalA)
	{
		printf("B");
	}
	else
	{
		printf("empate");
	}

	return 0;
}

int mediana(int x, int y, int z)
{
	if (x == y || x == z)
		return x;
	if (y == z)
		return y;
	if ((x > y && x < z) || (x < y && x > z))
		return x;
	if ((y > x && y < z) || (y < x && y > z))
		return y;
	return z;
}