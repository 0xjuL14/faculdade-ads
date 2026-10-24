#include <stdio.h>
#include <locale.h>

int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");

	int n, f = 1;
	
	printf("Informe um nº inteiro e não negativo para calcular seu fatorial:\n");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
    	if(n == 0) {
       		printf("%d! = %d\n", n, f);
	   }
		else {
			f = f * i;
		}
	} 
    printf("%d! = %d\n", n, f);
	
	return 0;
}
