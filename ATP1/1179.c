#include <stdio.h>
int main()
{
	int par[5], impar[5], total[15], i, j, p=0, imp=0;
	for (i=0; i<15; i++)
	{
		scanf("%d", &total[i]);
		if (total[i]%2==0)
		{
			par[p] = total[i];	
			p++;
			if (p==5)
			{
				for (j=0; j<5; j++)
					printf("par[%d] = %d\n", j, par[j]);
				p=0;
			}			
		}
		else
		{
			impar[imp] = total[i];
			imp++;
			if (imp==5)
			{
				for (j=0; j<5; j++)
					printf("impar[%d] = %d\n", j, impar[j]);
				imp=0;
			}
		}

	}
	for (i = 0; i < imp; i++)
        printf("impar[%d] = %d\n", i, impar[i]);
        
	for (i = 0; i < p; i++) 
        printf("par[%d] = %d\n", i, par[i]);
        
	return 0;
	
}
