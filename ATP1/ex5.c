#include <stdio.h>
#include <string.h>

#define TF 15

int main()
{
	int TL = 0, i, j, opcao;
	float salario[TF], auxSalario;
	char nome[TF][30], auxNome[30];
	
	printf("### MENU ###\n");
	printf("1 - INSERIR\n");
	printf("2 - ORDENAR (ORDEM ALFABETICA)\n");
	printf("3 - LISTAR\n");
	printf("4 - PROCURAR\n");
	printf("5 - EXCLUIR\n");
	printf("6 - SAIR\n");
	scanf("%d", &opcao);
	while(opcao != 6)
	{
		switch(opcao)
		{
			case 1:
				printf("### INSERCAO ###\n");
				printf("Digite seu nome: (Digite SAIR para parar de inserir nomes)\n");
				fflush(stdin);
				gets(auxNome);
				while(TL < TF && stricmp(auxNome, "sair") != 0)
				{
					strcpy(nome[TL], auxNome);
					printf("Digite o salario do %s: ", nome[TL]);
					scanf("%f", &salario[TL]);
					TL++;
					if(TL < TF)
					{
						printf("Digite seu nome: (Digite SAIR para parar de inserir nomes)\n");
						fflush(stdin);
						gets(auxNome);
					}
				}
				break;
			case 2:
				printf("### ORDENANDO POR ORDEM ALFABETICA ###\n");
				for(i = 0; i < TL-1; i++)
					for(j = i+1; j < TL; j++)
					{
						if(stricmp(nome[i], nome[j]) > 0)
						{
							strcpy(auxNome, nome[i]);
							strcpy(nome[i], nome[j]);
							strcpy(nome[j], auxNome);
							auxSalario = salario[i];
							salario[i] = salario[j];
							salario[j] = auxSalario;
						}
					}
					printf("ORDENACAO REALIZADA COM SUCESSO!!!\n");
				break;
			case 3:
				printf("### LISTAGEM ###\n");
				for(i = 0; i < TL; i++)
					printf("NOME: %s - SALARIO: %.2f\n", nome[i], salario[i]);
				break;
			case 4:
				printf("### BUSCA POR NOME ###\n");
				printf("Digite um nome a ser buscado: ");
				fflush(stdin);
				gets(auxNome);
				i = 0;
				while(i < TL && stricmp(auxNome, nome[i]) != 0)
					i++;
				if(i < TL)
				{
					printf("### NOME ENCONTRADO ###\n");
					printf("NOME: %s - SALARIO: %.2f\n", nome[i], salario[i]);
				}
				else
					printf("Nome nao existe!!!\n");
				break;
			case 5:
				printf("### EXCLUSAO ###\n");
				printf("Digite um nome valido para ser excluido:\n");
				fflush(stdin);
				gets(auxNome);
				i= 0;
				while(i < TL && stricmp(auxNome, nome[i]) != 0)
					i++;
				if(i < TL)
				{
					for(j = i; j < TL-1 ;j++)
					{
						strcpy(nome[j], nome[j+1]);
						salario[j] = salario[j+1];
					}
					TL--;
					printf("*** EXCLUSAO REALIZADA COM SUCESSO ***\n");
				}
				else
				printf("Nome invalido!!!\n");	
		}
			printf("### MENU ###\n");
		printf("1 - INSERIR\n");
		printf("2 - ORDENAR (ORDEM ALFABETICA)\n");
		printf("3 - LISTAR\n");
		printf("4 - PROCURAR\n");
		printf("5 - EXCLUIR\n");
		printf("6 - SAIR\n");
		scanf("%d", &opcao);
	}
	
	printf("PROGRAMA FINALIZADO!!!\n");
	
	return 0;
}
