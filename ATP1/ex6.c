#include <stdio.h>
#include <string.h>
#define TF 12
int main()
{
	int vetNum[TF], vetLugares[TF], i, pos, num;
	char vetOrigem[TF][20], vetDestino[TF][20], op, op2, aux[20];
	for (i=0; i<TF; i++)
	{
		printf("Digite o numero do %do. voo: \n", i+1);
		scanf("%d", &vetNum[i]);
		printf("Digite quantidade de lugares do %do. voo: \n", i+1);
		scanf("%d", &vetLugares[i]);
		printf("Digite a origem do %do. voo: \n", i+1);
		fflush(stdin);
		gets(vetOrigem[i]);
		printf("Digite o destino do %do. voo: \n", i+1);
		fflush(stdin);
		gets(vetDestino[i]);	
	}
	printf("Escolha alguma opcao:\n");
	printf("Consultar [C]\n");
	printf("Efetuar Reserva [R]\n");
	printf("Sair [S]\n");
	fflush(stdin);
	scanf("%c", &op);
	while (op!='S')
	{
		if (op=='C')
		{
			printf("Numero do voo [N]\n");
			printf("Origem [O]\n");
			printf("Destino [D]\n");
			fflush(stdin);
			scanf("%c", &op2);
			if (op2=='N')
			{
				printf("Digite o numero do voo para consultar:\n");
				scanf("%d", &num);
				pos=0;
				while (pos<TF && num!=vetNum[pos])	
					pos++;
				if (pos<TF)
					printf("Voo de numero [%d]\nOrigem [%s]\nDestino [%s]\nLugares Disponiveis [%d]\n----------------\n",vetNum[pos],vetOrigem[pos],vetDestino[pos],vetLugares[pos]);
				else
					printf("Voo nao encontrado com esse numero\n");			
			}
			else if (op2=='O')
			{
				printf("Digite a origem para consultar:\n");
				fflush(stdin);
				gets(aux);
				pos = 0;
				while (pos<TF && strcmp(aux, vetOrigem[pos])!=0)
					pos++;
				if (pos<TF)
					printf("Voo de numero [%d]\nOrigem [%s]\nDestino [%s]\nLugares Disponiveis [%d]\n----------------\n",vetNum[pos],vetOrigem[pos],vetDestino[pos],vetLugares[pos]);
				else
					printf("Voo com essa origem nao encontrado\n");
					
			}
			else if (op2=='D')
			{
				printf("Digite o destino para consultar:\n");
				fflush(stdin);
				gets(aux);
				pos=0;
				while (pos<TF && strcmp(aux, vetDestino[pos])!=0)
					pos++;
				if (pos<TF)
					printf("Voo de numero [%d]\nOrigem [%s]\nDestino [%s]\nLugares Disponiveis [%d]\n----------------\n",vetNum[pos],vetOrigem[pos],vetDestino[pos],vetLugares[pos]);
				else
					printf("Voo com esse destino nao encontrado\n");
			}
		}
		else if (op=='R')
		{
			printf("Digite o numero do voo que deseja reservar um lugar\n");
			scanf("%d", &num);
			pos=0;
			while (pos<TF && num!=vetNum[pos])
				pos++;
			if (pos<TF)
			{
				if (vetLugares[pos]>0)
				{
					printf("Voo encontrado\n");
					printf("Lugares Disponiveis : %d\n",vetLugares[pos]);
					printf("Origem : %s\n",vetOrigem[pos]);
					printf("Destino : %s\n",vetDestino[pos]);
					
					printf("Esta disponivel, deseja realizar a reserva? [S][N]\n");
					fflush(stdin);					
					scanf("%c", &op2);
					if (op2=='S')
					{
						printf("Compra efetuada\n");
						vetLugares[pos]--;
					}
					else
						printf("Reserva cancelada\n");
				}
				else
					printf("Voo lotado\n");
			}
			else
				printf("Voo nao encontrado\n");
		}
		else
			printf("Opcao invalida\n");
			
		printf("Escolha alguma opcao:\n");
		printf("Consultar [C]\n");
		printf("Efetuar Reserva [R]\n");
		printf("Sair [S]\n");
		fflush(stdin);
		scanf("%c", &op);
	}
	return 0;
}
