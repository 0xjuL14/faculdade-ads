#include <stdio.h>
#include <locale.h>
#include <math.h> 

int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");

	int termos, proxtermo;
	int p1 = 0, p2 = 1;
	
    printf("\nInforme a quantidade de termos desejados da Sequência de Fibonacci:\n");
    scanf("%d", &termos);
        
    if(termos > 0) { printf("%d", p1); }
	if(termos > 1) { printf(", %d", p2); }
	
	for(int t = 3; t <= termos; t++) {
		proxtermo = p1 + p2;
		printf(", %d", proxtermo);
		p1 = p2;
		p2 = proxtermo;
	}
    printf("\n");	
    
	return 0;
}

