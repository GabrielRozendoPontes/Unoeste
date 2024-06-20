#include <stdio.h>
#include <string.h>
#define TFM 6
#define TFV 6
int main()
{
	float matdist[TFM][TFM], somadist, menor, maior;
	int vetcid[TFV], nlinha, ncid, i, l, c, flag=0, lin_me, lin_ma;
	for (l=0; l < TFM-1; l++)
		for (c=l+1; c < TFM; c++)
		{
			printf("Distancia cid %d para %d\n", l, c);
			scanf("%f", &matdist[l][c]);
			matdist[c][l] = matdist [l][c];
		}
		printf("Num da linha:\n");
		scanf("%d", &nlinha);
		while (nlinha!=9999)
		{
			printf("Num de cidades percorridas:\n");
			scanf("%d", &ncid);
			for (i=0; i < ncid; i++)
			{
				printf("Cod da %d cid:\n", i+1);
				scanf("%d", &vetcid[i]);
			}
			somadist = 0;
			for (i=0; i < ncid-1; i++)
				somadist+=matdist[vetcid[i]][vetcid[i+1]];
			printf("Distancia = %.2f\n", somadist);
			if (flag==0)
			{
				menor = somadist;
				maior = somadist;
				lin_me = nlinha;
				lin_ma = nlinha;
				flag=1;
			}
			else
			{
				if (somadist<menor)
				{
					menor = somadist;
					lin_me = nlinha;
				}
				if (somadist>maior)
				{
					maior = somadist;
					lin_ma = nlinha;
				}
			}
			printf("Num da linha:\n");
			scanf("%d", &nlinha);
		}
		printf("Cid %d tem a menor dist\n", lin_me);
		printf("Cid %d tem a maior dist\n", lin_ma);
		return 0;
}
