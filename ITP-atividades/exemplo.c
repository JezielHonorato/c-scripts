#include <stdio.h>

int main()
{
	int varInt = 1;
	float varFloat = 1;
	double varDouble = 1;
	char varChar = 'a';				   // variavel para caractere unico, sempre usar aspas simples
	char varString[] = "Hello World!"; // aqui preciso de aspas duplas

	int x, y, z;
	int a, b, c = 10; // a e b nao tem seus valores declarados
	int d = 10, e = 2, f = 3;
	x = y = z = 50;
	printf("%d, %d, %d, %d, %d, %d \n \n", a, b, c, d, e, f);

	printf("%d \n", x + y + z);
	printf("%d, %d \n", a, b, c);
	printf("%d, %d, %d, %d \n \n", e, f, d); // o d sera impresso nos dois ultimos

	printf("%d\n", varInt);
	printf("%f\n", varFloat);
	printf("%lf\n", varDouble);
	printf("%c\n", varChar);
	printf("\nAs variaveis que defini foram: %d para inteiro, %f para float, %lf para double e %c para char", varInt, varChar, varDouble, varFloat); // a ordem importa
	printf("\nAs variaveis que defini foram: %d para inteiro, %f para float, %lf para double e %c para char", varInt, varFloat, varDouble, varChar);
	printf("\nC nao possui string, entao devo ussar um array de char, como esse %s", varString);

	int entrada;
	scanf("%d", &entrada);
	printf("\n as entradas foram: %d", entrada);
	return 0;
}