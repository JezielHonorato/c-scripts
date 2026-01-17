#include <stdio.h>

int binarySearch(int vetor[], int n, int k);
int binarySearchRecursive(int vetor[], int start, int end, int k);

int main()
{
	int vetor[] = {0, 1, 2, 3, 4, 5}, n = 6, k = 5;

	if (vetor[binarySearch(vetor, n, k)] == k)
		printf("binarySearch() working\n");

	if (vetor[binarySearchRecursive(vetor, 0, n, k)] == k)
		printf("binarySearchRecursive() working\n");

	return 0;
}

int binarySearch(int vetor[], int n, int k)
{
	int i, start = 0, end = (n - 1);
	while (start <= end)
	{
		i = (start + end) / 2;
		if (vetor[i] == k)
			return i;
		else if (vetor[i] < k)
			start = i + 1;
		else
			end = i - 1;
	};
}

int binarySearchRecursive(int vetor[], int start, int end, int k)
{
	int i = (start + end) / 2;

	if (start > end)
		return -1;
	else if (vetor[i] == k)
		return i;
	else if (vetor[i] < k)
		return binarySearchRecursive(vetor, i + 1, end, k);
	else
		return binarySearchRecursive(vetor, start, i - 1, k);
}