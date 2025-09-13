#include <stdio.h>

// int main() { int quantidadeHerois, classeHeroi, nivelMonstro; char vencem[] = "Heróis vencerão!", perdem[] = "Melhor chamar Saitama!"; scanf("%d %d %d", &quantidadeHerois, &classeHeroi, &nivelMonstro); switch (nivelMonstro) { case 1: if ((classeHeroi == 1 && quantidadeHerois >= 3) || classeHeroi >= 2) { printf("%s", vencem); } else { printf("%s", perdem); } break; case 2: if ((classeHeroi == 2 && quantidadeHerois >= 3) || classeHeroi >= 3) { printf("%s", vencem); } else { printf("%s", perdem); } break; case 3: if ((classeHeroi == 3 && quantidadeHerois >= 3) || classeHeroi >= 4) { printf("%s", vencem); } else { printf("%s", perdem); } break; case 4: if ((classeHeroi == 4 && quantidadeHerois >= 3) || classeHeroi == 5) { printf("%s", vencem); } else { printf("%s", perdem); } break; case 5: if (classeHeroi == 5) { printf("%s", vencem); } else { printf("%s", perdem); } break; default: printf("Digite um nivel de ameaca entre 1 e 5.\n"); return 0; } return 0; }

int main()
{
	int quantidadeHerois, classeHeroi, nivelMonstro;

	scanf("%d %d %d", &quantidadeHerois, &classeHeroi, &nivelMonstro);

	if (classeHeroi > 5 || nivelMonstro > 5)
	{
		printf("Digite um valor valido");
	}
	else if (quantidadeHerois > 0 && ((classeHeroi > nivelMonstro) || ((classeHeroi == nivelMonstro) && quantidadeHerois >= 3) || classeHeroi == 5))
	{
		printf("Heróis vencerão!");
	}
	else
	{
		printf("Melhor chamar Saitama!");
	}

	return 0;
}
