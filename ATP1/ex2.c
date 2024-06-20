#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define TF 3

int main ()
{
	int vetNum[TF],vetLugares[TF],num,pos,i;
	char vetOrigem[TF][20],vetDestino[TF][20],op,aux[20],op2;
	
	for(i=0;i<TF;i++)
	{
		printf("Digite o numero do voo\n");
		scanf("%d",&vetNum[i]);
		printf("Digite quantos lugares tem\n");
		scanf("%d",&vetLugares[i]);
		printf("Digite a origem do voo\n");
		fflush(stdin);
		gets(vetOrigem[i]);
		printf("Digite o destino do voo\n");
		fflush(stdin);
		gets(vetDestino[i]);
	}
	
	printf("Digite a opcao que deseja\n");
	printf("CONSULTAR [C]\nRESERVAR[R]\nSAIR[S]\n");
	fflush(stdin);
	scanf("%c",&op);
	op=toupper(op);
	
	while(op!='S')
	{

		
		switch(op)
		{
			//Caso for consulta
			case 'C':
				printf("----------------------\nDeseja consultar pelo o que?\nORIGEM[O]\nDESTINO[D]\nNUMERO[N]\n");//Pergunto o que ele quer consultar
				fflush(stdin);//limpo o buffer
				scanf("%c",&op2);
				op2=toupper(op2);
				//Verificando qual tipo de consulta ele quer fazer
				switch(op2)
				{
					//Caso for pela origem
					case 'O':
						printf("Digite a origem para consultar\n");
						fflush(stdin);
						gets(aux);//Recebo a origem que ele digitar
						
						//Busco a origem no meu vetor de strings
						pos=0;
						while(pos<TF && strcmp(aux,vetOrigem[pos])!=0)
							pos++;
							
						//Verifico se achou o voo
						if(pos<TF)
						{
							printf("Voo de numero [%d]\nOrigem [%s]\nDestino [%s]\nLugares Disponiveis [%d]\n----------------\n",vetNum[pos],vetOrigem[pos],vetDestino[pos],vetLugares[pos]);
						}
						else//Caso nao achou o voo
						{
							printf("Voo com essa origem nao encontrado\n-------------------\n");
						}
						
						break;
					//Caso for por destino
					case 'D':
						printf("Digite o destino para consultar\n");
						fflush(stdin);
						gets(aux);//Recebo o destino
						
						//Busco o destino no vetor de destinos
						pos=0;
						while(pos<TF&& strcmp(aux,vetDestino[pos])!=0)
							pos++;
						
						//Verifico se achou o voo
						if(pos<TF)
						{
							printf("Voo de numero [%d]\nOrigem [%s]\nDestino [%s]\nLugares Disponiveis [%d]\n----------------\n",vetNum[pos],vetOrigem[pos],vetDestino[pos],vetLugares[pos]);
						}
						else//Caso nao achou
						{
							printf("Voo com essa origem nao encontrado\n-------------------\n");
						}
						
						break;
						
					//Caso for pelo numero do voo
					case 'N':
						printf("Digite o numero do voo para consultar\n");
						scanf("%d",&num);//Recebo o numero
						
						//Busco o numero no vetor de numeros de voo
						pos=0;
						while(pos<TF&&num!=vetNum[pos])
							pos++;
						
						//Verifico se achou
						if(pos<TF)
						{
							printf("Voo de numero [%d]\nOrigem [%s]\nDestino [%s]\nLugares Disponiveis [%d]\n----------------\n",vetNum[pos],vetOrigem[pos],vetDestino[pos],vetLugares[pos]);
						}
						else//Caso nao achou
						{
							printf("Voo com essa origem nao encontrado\n-------------------\n");
						}
						break;
				}
				break;
			//Caso queira reservar um voo
			case 'R':
					printf("----------\nDigite o numero do voo que deseja reservar um lugar\n");
					scanf("%d",&num);//Leio o numero do voo
					
					//Busco o numero no vetor de numeros de voo
					pos=0;
					while(pos<TF&&num!=vetNum[pos])
						pos++;
					
					//Verifico se achou
					if(pos<TF)
					{
						//Verifico se ainda tem lugares disponiveis
						if(vetLugares[pos]>0)
						{
							//Printo todas as informações sobre o voo
							printf("Voo encontrado\n");
							printf("Lugares Disponiveis : %d\n",vetLugares[pos]);
							printf("Origem : %s\n",vetOrigem[pos]);
							printf("Destino : %s\n",vetDestino[pos]);
							
							//Pergunto se ele realmente quer reservar
							printf("Confirma reserva?[S][N]\n");
							fflush(stdin);
							scanf("%c",&op2);//Leio a operação
							//Caso queira reservar
							if(toupper(op2)=='S')
							{
								printf("Reserva comprada com sucesso\n");
								vetLugares[pos]--;//Retiro um lugar desse voo
							}
							else//Cancelo a reserva
							{
								printf("Reserva cancelada\n");
							}
						}
						else//Caso nao tenha lugares
						{
							printf("Voo lotado\n");
						}

					}
					else//Caso nao tenha encontrado o numero do voo
					{
						printf("Voo nao encontrado\n");
					}
					
					
				break;
				
			//Caso a pessoa tenha digitado uma opcao invalida
			default:
				printf("ERRO, OPCAO INVALIDA\n");
				break;
		}
		printf("Digite a opcao que deseja\n");
		printf("CONSULTAR [C]\nRESERVAR[R]\nSAIR[S]\n");
		fflush(stdin);
		scanf("%c",&op);
		op=toupper(op);		
	}
	
	return 0;
	
}
