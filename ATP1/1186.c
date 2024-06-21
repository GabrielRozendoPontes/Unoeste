#include <stdio.h>
#define TF 12
int main()
{
	int i, l, c, cont=0;
	float M[TF][TF], soma=0;
	char op;
	fflush(stdin);
	scanf("%c", &op);
	
	for (l=0; l<TF; l++)
		for (c=0; c<TF; c++)
			scanf("%f", &M[l][c]);
				
	for (l=0; l<TF; l++)
		for (c=0; c<TF; c++)
			if (l + c > 11)
			{
				soma+=M[l][c];
				cont++;
			}			
	
	if (op == 'S')
    	printf("%.1f\n", soma);
    else if (op == 'M')
        printf("%.1f\n", soma/cont);	
		
	return 0;
	
}
