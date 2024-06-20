#include <stdio.h>
#include <string.h>
#define TF 3
int main()
{
	int contas[TF], i, j, resp, pos, codigo;
	float saldos[TF], deposito, saque, somatorio, juros;
	char Vnomes[TF][15];
	for (i=0; i<TF; i++)
		scanf("%d", &contas[i]);
	for (i=0; i<TF; i++)
		scanf("%f", &saldos[i]);
	for (i=0; i<TF; i++)
	{
		fflush(stdin);
		gets(Vnomes[i]);
	}
	printf("1. Efetuar deposito;\n2. Efetuar saque;\n3. Consultar o ativo bancario(soma dos saldos dos clientes);\n4. Aplicar porcentagem de juros mensal;\n5. Finalizar programa.\n");
	scanf("%d", &resp);
	while (resp!=5)
	{
		if(resp==1)
		{
			printf("Digite codigo da conta e o valor a ser depositado:\n");
			scanf("%d %f", &codigo, &deposito);
			pos=0;
			while (pos<TF && codigo!=contas[pos])
				pos++;
			if (pos<TF)
			{
				printf("Nome do cliente: %s\n", Vnomes[pos]);
				printf("Saldo atual: %.2f\n", saldos[pos]);
				saldos[pos]+=deposito;
				printf("Novo saldo: %.2f\n", saldos[pos]);
			}
			else
				printf("Conta nao encontrada\n");
		}
		if (resp==2)
		{
			printf("Digite codigo da conta e o valor a ser sacado:\n");
			scanf("%d %f", &codigo, &saque);
			pos=0;
			while (pos<TF && codigo!=contas[pos])
				pos++;
			if(pos<TF)
			{
				if (saldos[pos]-saque >=0)
				{
					printf("Nome do cliente: %s\n", Vnomes[pos]);
					printf("Saldo atual: %.2f\n", saldos[pos]);
					saldos[pos]-=saque;
					printf("Saldo apos o saque: %.2f\n", saldos[pos]);	
				}
				else
					printf("Conta sem valor para sacar\n");
			}
			else
				printf("Conta nao encontrada\n");
		}
		if (resp==3)
		{
			somatorio=0;
			for(i=0; i<TF; i++)
				somatorio+=saldos[i];
			printf("Somatorio de todas as contas: %.2f\n", somatorio);
		}
		if (resp==4)
		{
			printf("Digite a taxa de juros a ser aplicada:\n");
			scanf("%f", &juros);
			for (i=0; i<TF; i++)
				saldos[i] *= (1+(juros/100));
		}
		printf("1. Efetuar deposito;\n2. Efetuar saque;\n3. Consultar o ativo bancario(soma dos saldos dos clientes)\n4. Aplicar porcentagem de juros mensal\n5. Finalizar programa.\n");
		scanf("%d", &resp);
	}
	return 0;
}
