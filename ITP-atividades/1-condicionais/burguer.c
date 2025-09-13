#include <stdio.h>

int main()
{
	int comboNumero, valorPago, saldo, valoresCombo[] = {12, 23, 31, 28, 15};

	scanf("%d %d", &comboNumero, &valorPago);

	if (comboNumero > 5)
	{
		printf("Digite um valor valido");
	}

	saldo = valorPago - valoresCombo[comboNumero - 1];

	if (saldo == 0)
	{
		printf("Deu certim!");
	}
	else if (saldo > 0)
	{
		printf("Troco = %d reais", saldo);
	}
	else if (saldo < 0)
	{
		printf("Saldo insuficiente! Falta %d reais", saldo*-1);
	}

	return 0;
}
