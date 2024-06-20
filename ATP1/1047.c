#include <stdio.h>
int main()
{
	int horI, minI, horF, minF, hor, min, total;
	scanf("%d%d%d%d", &horI,&minI, &horF, &minF);
	if (horI < horF)
	{
		total = horF - horI;
		if (minF >= minI)
		{	
			hor=horF-horI;
			min = minF - minI;
		}
		else
		{
			min = 60 - minI + minF;
			hor = horF - horI - 1;
		}	
	}
	else if (horI > horF)
	{
		total = 24 - horI + horF;
		if (minF >= minI)
		{
			hor=horF-horI;
			min = minF - minI;
		}
		else
		{
			min = 60 - minI + minF;
			hor = 24 - horI + horF - 1;
		}
	}
	else if (horI == horF)
	{
		if(minI == minF)
		{
			printf("O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)\n");	
			return 0;
		}
		else if (minI < minF)
		{
			hor = 0;
			min = minF - minI;
		}
		else
		{
			hor = 23;
			min = 60 - minI + minF;
		}
	}
		printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", hor, min);
	return 0;
}
