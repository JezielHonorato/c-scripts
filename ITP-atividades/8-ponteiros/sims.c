#include <stdio.h>
#include <string.h>

typedef struct
{
	int fome, sede, banheiro, sono, tedio;
} Sim;

int simula_sims(Sim *s);
void imprime_relatorio(Sim s);

int main()
{
	Sim s;
	int acoes;
	scanf("%d %d %d %d %d", &s.fome, &s.sede, &s.banheiro, &s.sono, &s.tedio);
	scanf("%d", &acoes);
	for (int i = 0; i < acoes; i++)
	{
		int ret = simula_sims(&s);
		if (ret == 0)
			break;
	}
	imprime_relatorio(s);
	return 0;
}

int simula_sims(Sim *s)
{
	char acao1[30], acao2[30] = "";
	scanf("%s", acao1);
	if (getchar() != '\n')
		scanf("%s", acao2);

	if (!strcmp(acao1, "comer"))
	{
		s->fome += 30;
		s->banheiro -= 15;

		s->sede -= 5;
		s->sono -= 5;
		s->tedio -= 5;
	}
	else if (!strcmp(acao1, "beber"))
	{
		s->sede += 30;
		s->banheiro -= 20;

		s->fome -= 5;
		s->sono -= 5;
		s->tedio -= 5;
	}
	else if (!strcmp(acao1, "dormir"))
	{
		s->sono += 80;
		s->tedio += 30;
		s->fome -= 30;
		s->sede -= 30;
		s->banheiro -= 30;
	}
	else if (!strcmp(acao1, "se") && !strcmp(acao2, "aliviar"))
	{
		s->banheiro += 100;

		s->fome -= 5;
		s->sede -= 5;
		s->sono -= 5;
		s->tedio -= 5;
	}
	else if (!strcmp(acao1, "jogar") && !strcmp(acao2, "videogame"))
	{
		s->tedio += 80;
		s->fome -= 20;
		s->sede -= 20;
		s->banheiro -= 20;
		s->sono -= 20;
	}

	if (s->fome > 100)
		s->fome = 100;
	if (s->sede > 100)
		s->sede = 100;
	if (s->banheiro > 100)
		s->banheiro = 100;
	if (s->sono > 100)
		s->sono = 100;
	if (s->tedio > 100)
		s->tedio = 100;

	if (s->fome <= 0)
	{
		printf("Game Over! Morreu de fome\n");
		return 0;
	}
	if (s->sede <= 0)
	{
		printf("Game Over! Morreu de sede\n");
		return 0;
	}
	if (s->banheiro <= 0)
	{
		printf("Game Over! Morreu apertado...\n");
		return 0;
	}
	if (s->sono <= 0)
	{
		printf("Game Over! Morreu dormindo...\n");
		return 0;
	}
	if (s->tedio <= 0)
	{
		printf("Game Over! Morreu deprimido...\n");
		return 0;
	}

	if (s->fome <= 15)
		printf("Alerta: fome está com valor baixo\n");
	if (s->sede <= 15)
		printf("Alerta: sede está com valor baixo\n");
	if (s->banheiro <= 15)
		printf("Alerta: banheiro está com valor baixo\n");
	if (s->sono <= 15)
		printf("Alerta: sono está com valor baixo\n");
	if (s->tedio <= 15)
		printf("Alerta: tédio está com valor baixo\n");
	return 1;
}

void imprime_relatorio(Sim s)
{
	printf("Status final:\n");
	printf("Fome: %d\n", s.fome);
	printf("Sede: %d\n", s.sede);
	printf("Banheiro: %d\n", s.banheiro);
	printf("Sono: %d\n", s.sono);
	printf("Tédio: %d\n", s.tedio);
}
