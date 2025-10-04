#include <stdio.h>
#include <string.h>

int main()
{
	char s1[49], s2[49];
	int i, j;

	scanf("%s", s1);
	scanf("%s", s2);

	int tamanho1 = strlen(s1);
	int tamanho2 = strlen(s2);

	for (i = tamanho1, j = 0; j < tamanho2; i++, j++)
	{
		s1[i] = s2[j];
	}

	s1[i] = '\0';

	printf("%s\n", s1);

	return 0;
}
