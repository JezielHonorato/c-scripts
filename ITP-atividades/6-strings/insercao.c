#include <stdio.h>
#include <string.h>

void insereString(char s1[], char s2[], char s3[], int p);

int main()
{
	char s1[30], s2[30], s3[60];
	int p;

	fgets(s1, sizeof(s1), stdin);
	fgets(s2, sizeof(s2), stdin);
	scanf("%d", &p);

	s1[strcspn(s1, "\n")] = '\0';
	s2[strcspn(s2, "\n")] = '\0';

	insereString(s1, s2, s3, p);

	printf("%s\n", s3);

	return 0;
}

void insereString(char s1[], char s2[], char s3[], int p)
{
	int i, j = 0;

	for (i = 0; i < p; i++)
	{
		s3[j++] = s1[i];
	}

	for (i = 0; s2[i] != '\0'; i++)
	{
		s3[j++] = s2[i];
	}

	for (i = p; s1[i] != '\0'; i++)
	{
		s3[j++] = s1[i];
	}

	s3[j] = '\0';
}
