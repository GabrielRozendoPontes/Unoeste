#include <stdio.h>
int main()
{
    int soma=0, soma1=0, soma2=0, soma3=0, i, carros;
    printf("Quantos Carros?: <deve ser menor que 500>");
    scanf("%d", &carros);

    float VComp[carros], VMonit[carros], VTecl[carros], VCel[carros], soma_c=0, soma_m=0, soma_T=0, soma_ce=0, media_c, media_m, media_T, media_ce, soma_total, porcentagem;

    for(i=0; i<carros; i++)
	{
        printf("Quant. Computadores do %do. carro:", i+1);
        scanf("%f", &VComp[i]);
        printf("Quant. Monitores do %do. carro:", i+1);
        scanf("%f", &VMonit[i]);
        printf("Quant. Teclados do %do. carro:", i+1);
        scanf("%f", &VTecl[i]);
        printf("Quant. Celulares do %do. carro:", i+1);
        scanf("%f", &VCel[i]);
        printf("\n");

        soma_c += VComp[i];
        soma_m += VMonit[i];
        soma_T += VTecl[i];
        soma_ce += VCel[i];


    }

    media_c = soma_c/carros;
    media_m = soma_m/carros;
    media_T = soma_T/carros;
    media_ce = soma_ce/carros;

    for(i=0; i<carros; i++)
	{
        if(VComp[i] > media_c)
			soma++; 
        if(VMonit[i] > media_m)
			soma1++; 
        if(VTecl[i] > media_T)
			soma2++; 
        if(VCel[i] > media_ce)
			soma3++;
    }

    soma_total = soma_c + soma_m + soma_T + soma_ce;
    porcentagem = soma*100/soma_c;

    int soma_t = soma + soma1 + soma2 + soma3;

    printf("soma: %.0f\n", soma_total);
    printf("porcentagem dos computadores: %.2f %%\n", porcentagem);
    printf("quantidade de carros superior a media do computador: %d\n", soma);
    printf("quantidade de carros1 superior a media do monitor: %d\n", soma1);
    printf("quantidade de carros2 superior a media do teclado: %d\n", soma2);
    printf("quantidade de carros3 superior a media do celular: %d\n", soma3);
    return 0;
}
