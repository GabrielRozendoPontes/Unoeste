#include <stdio.h>

int main ()
{	
	int VetQtdeVend[10], posmaior, i;
	float VetPrecoUnit[10], VendaObj, MaiorQtdeVend,VendaTot=0, Comissao;
	
	printf("Informe a Quantidade e o valor unitario de cada objeto:\n");
	for(i=0;i<10;i++)
	{
		printf("Quantidade Vendida: ");
		scanf("%d",&VetQtdeVend[i]);
		printf("Preco Unitario: ");
		scanf("%f", &VetPrecoUnit[i]);
	}
	
	MaiorQtdeVend = VetQtdeVend[0];
	posmaior = 0;
	
	for(i=0; i<10; i++)
	{
		if(VetQtdeVend[i] > MaiorQtdeVend)
		{
			MaiorQtdeVend = VetQtdeVend[i];
			posmaior = i;
		}
		
		VendaObj = VetQtdeVend[i]*VetPrecoUnit[i];
		VendaTot += VendaObj; // VendaTot = VendaTot + VendaObj;
		
		printf("Quantidade Vendida: %d\n", VetQtdeVend[i]);
		printf("Preco Unitario: R$%.2f\n", VetPrecoUnit[i]);
		printf("Valor da Venda do Objeto: R$%.2f\n", VendaObj);
	}
	
	printf("Valor Geral das Vendas: R$%.2f\n", VendaTot);
	Comissao = VendaTot * 0.05;
	printf("Comissao a ser paga ao vendedor: R$%.2f\n", Comissao);
	
	printf("Posicao do Objeto mais vendido: %d\n", posmaior);
	printf("Preco Unitario: R$%.2f\n", VetPrecoUnit[posmaior]);
}
