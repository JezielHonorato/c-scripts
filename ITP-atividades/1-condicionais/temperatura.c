#include <stdio.h>

int main()
{
	float valorEntrada, celsius, farenheit, kelvin;
	char tipoEntrada;

	printf("Digite a temperatura e o sistema de escala utilizado, 'C' para Celsius, 'F' para Farenheit e 'K' para kelvin (exemplo: 40 C): ");

	scanf("%f %c", &valorEntrada, &tipoEntrada);

	switch (tipoEntrada)
	{
	case 'C':
		celsius = valorEntrada;
		break;
	case 'F':
		celsius = (valorEntrada - 32) / 1.8;
		break;
	case 'K':
		celsius = valorEntrada - 273.15;
		break;
	default:
		printf("Digite um caractere valido para escalas de temperaturas.\n");
		return 0;
	}

	farenheit = celsius * 1.8 + 32;
	kelvin = celsius + 273.15;

	printf("Celsius: %.2f \nFarenheit: %.2f \nKelvin: %.2f", celsius, farenheit, kelvin);

	return 0;
}
