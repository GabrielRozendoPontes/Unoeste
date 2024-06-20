#include <stdio.h>
#define Tam 10001

int main() 
{
    int TF, TL, teste = 1, maior, menor, media_atual, soma, medicoes[Tam], i, j;
    scanf("%d", &TF);
    scanf("%d", &TL);
    
    while (TF != 0 && TL != 0) 
	{
        for (i = 0; i < TF; i++)
            scanf("%d", &medicoes[i]);
        
        maior = menor = 0;
        
        for (i = 0; i < TF - TL + 1; i++) 
		{
            soma = 0;
            for (j = i; j < TL + i; j++) 
                soma += medicoes[j];
                
            media_atual = soma / TL; 
            
            if (i == 0) 
                maior = menor = media_atual;
			else 
			{
            	if (media_atual > maior)
                    maior = media_atual;
                if (media_atual < menor)
                    menor = media_atual;
            }
        }
        printf("Teste %d\n", teste++);
        printf("%d %d\n\n", menor, maior);
        
        scanf("%d", &TF);
        scanf("%d", &TL);
    }
    
    return 0;
}
