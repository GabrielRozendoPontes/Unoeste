#include <stdio.h>
#include <string.h>

#define TF 24

int main()
{
	int vetJane[TF], vetCorre[TF], i, j, opcao, poltrona;
	char setor[15];
	
	for(i = 0; i < TF; i++)//prrenchendo os dois vetores com 1, ou seja, poltronas livres
	{
		vetJane[i] = 1;
		vetCorre[i] = 1;
	}
	printf("### MENU DO ONIBUS ###\n");
	printf("1 - COMPRA DE PASSAGEM\n");
	printf("2 - MAPA DE OCUPACAO DO ONIBUS\n");
	printf("3 - ENCERRAR\n");
	printf("OPCAO:");
	scanf("%d", &opcao);
	while(opcao != 3)
	{
		switch(opcao)
		{
			case 1:
				i = 0;
				while(i < TF && vetJane[i] != 1)
					i++;
				j = 0;
				while(j < TF && vetCorre[j] != 1)
					j++;
				if(i < TF || j < TF)//existe alguma poltrona livre, ou seja, o onibus nao esta lotado
				{
					printf("Qual setor do onibus voce deseja comprar (janela ou corredor):\n");
					fflush(stdin);
					gets(setor);
					if(stricmp(setor, "janela") == 0)
					{
						if(i < TF)
						{
							printf("Qual poltrona voce deseja comprar?\n");
							scanf("%d", &poltrona);
							if(vetJane[poltrona - 1] == 1)
							{
								vetJane[poltrona - 1] = 0;
								printf("Venda efetivada!!!\n");
							}
							else
								printf("Poltrona ocupada!!!\n");
						}
						else
							printf("Todas as poltronas da janela estao ocupadas!!!\n");
					}
					else
					{
						if(j < TF)
						{
							printf("Qual poltrona voce deseja comprar?\n");
							scanf("%d", &poltrona);
							if(vetCorre[poltrona - 1] == 1)
							{
								vetCorre[poltrona - 1] = 0;
								printf("Venda efetivada!!!\n");
							}
							else
								printf("Poltrona ocupada!!!\n");
						}
						else
							printf("Todas as poltronas do corredor estao ocupadas!!!\n");
					}
				}
				else
					printf("ONIBUS LOTADO!!!\n");
				break;
			case 2:
				printf("JANELA\t\tCORREDOR:\n");
				for(i = 0; i < TF; i++)
				{				
					if(vetJane[i] == 0 && vetCorre[i] == 0)
						printf("%d- Ocupada\t%d- Ocupada\n", i+1, i+1);
					else
						if(vetJane[i] == 1 && vetCorre[i] == 0)
							printf("%d- Livre\t%d- Ocupada\n", i+1, i+1);
						else
							if(vetJane[i] == 0 && vetCorre[i] == 1)
								printf("%d- Ocupada\t%d- Livre\n", i+1, i+1);
							else
								printf("%d- Livre\t%d- Livre\n", i+1, i+1);
				}
				break;
		}
		printf("\n### MENU DO ONIBUS ###\n");
		printf("1 - COMPRA DE PASSAGEM\n");
		printf("2 - MAPA DE OCUPACAO DO ONIBUS\n");
		printf("3 - ENCERRAR\n");
		printf("OPCAO:");
		scanf("%d", &opcao);
	}
	
	printf("***PROGRAMA FINALIZADO***!!!\n");
	
	return 0;
}

