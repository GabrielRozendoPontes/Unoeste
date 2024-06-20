#include <stdio.h>
#define TF 5
int main()
{
	int vet1[TF], vet2[TF], vetUniao[TF*2], i, pos, TLU=0, vetIntersec[TF], TLI=0;
	for (i=0; i<TF; i++)
	{
		printf("Digite o %d num do vet1:\n", i+1);
		scanf("%d", &vet1[i]);
		printf("Digite o %d num do vet2:\n", i+1);
		scanf("%d", &vet2[i]);
	}
	for (i=0; i<TF; i++)
	{
		pos=0;
		while(pos<TLU && vet1[i]!=vetUniao[pos])
			pos++;
		if(pos==TLU)
		{
			vetUniao[TLU]=vet1[i];
			TLU++;
		}
	}
	for (i=0; i<TF; i++)
	{
		pos=0;
		while(pos<TLU && vet2[i]!=vetUniao[pos])
			pos++;
		if(pos==TLU)
		{
			vetUniao[TLU]=vet2[i];
			TLU++;
		}
	}
	printf("UNIAO\n");
	for (i=0; i<TLU; i++)
		printf("%d ", vetUniao[i]);
	
	printf("\n");	
	for(i=0; i<TF; i++)
	{
		pos=0;
		while (pos<TF && vet1[i]!=vet2[pos])
			pos++;
		if (pos<TF)
		{
			pos=0;
			while (pos<TLI && vet1[i]!=vetIntersec[pos])
				pos++;
			if (pos==TLI)
			{
				vetIntersec[TLI]=vet1[i];
				TLI++;
			}
		}
	}
	printf("INTERSECCAO\n");
	for (i=0; i<TLI; i++)
		printf("%d ", vetIntersec[i]);
	
	return 0;
}
