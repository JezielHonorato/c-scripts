#include <stdio.h>

int linearSearch(int vetor[], int n, int k);
int linearSearchRecursive(int vetor[], int n, int k);
int linearSearchRecursivePointer(int *p, int n, int k);

int main()
{
	int vetor[] = {0, 1, 2, 3, 4, 5}, n = 6, k = 5;

	if (vetor[linearSearch(vetor, n, k)] == k)
		printf("linearSearch() working\n");
		
	if (vetor[linearSearchRecursive(vetor, n, k)] == k)
		printf("linearSearchRecursive() working\n");

	if (vetor[linearSearchRecursivePointer(vetor, n, k)] == k)
		printf("linearSearchRecursivePointer() working\n");

	return 0;
}

int linearSearch(int vetor[], int n, int k)
{
	for (int i = 0; i < n; i++)
		if (vetor[i] == k)
			return i;
	return -1;
}

int linearSearchRecursive(int vetor[], int n, int k)
{
	if (n == -1)
		return -1;
	else if (vetor[n - 1] == k)
		return n - 1;

	return linearSearchRecursive(vetor, n - 1, k);
}

int linearSearchRecursivePointer(int *p, int n, int k)
{
	if (n - 1 < 0)
		return -1;
	if (*(p + n - 1) == k)
		return n - 1;

	return linearSearchRecursivePointer(p, n - 1, k);
}