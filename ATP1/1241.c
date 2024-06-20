#include <stdio.h>
#include <string.h>
int main()
{
	int N, tamanho_a, tamanho_b;
	char A[1001], B[1001];
	scanf("%d", &N);
	while (N--)
	{
		scanf("%s %s", A, B);
		tamanho_a = strlen(A);
		tamanho_b = strlen(B);
		if (tamanho_b > tamanho_a)
			printf("nao encaixa\n");
		else if (tamanho_b == tamanho_a)
		{
			if (strcmp(A,B)==0)
				printf("encaixa\n");
			else
				printf("nao encaixa\n");
			
		}
		else if (strcmp(A + (tamanho_a - tamanho_b), B) == 0)
			printf("encaixa\n");
		else
			printf("nao encaixa\n");	
	}
	return 0;
}
