#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");
	
	float a, b, c, delta, x1, x2;

	printf("Informe um valor para o coeficiente 'a': ");
    scanf("%f", &a);
	fflush(stdin);
    printf("Informe um valor para o coeficiente 'b': ");
    scanf("%f", &b);
	fflush(stdin);
	printf("Informe um valor para o coeficiente 'c': ");
    scanf("%f", &c);
	fflush(stdin);
	
    if (a == 0) {
    	
        printf("a = 0. Não é uma equação de 2º grau\n");
        
    } else {
    	
    	delta = pow(b, 2) - 4 * a * c;
    	
    	if (delta > 0) {
           
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);
            
            printf("\nA equação possui duas raízes reais:\n");
            printf("x1 = %.2f\n", x1);
            printf("x2 = %.2f\n", x2);
            
        } else if (delta == 0) {
          
            x1 = -b / (2 * a);
            
            printf("\nA equação possui uma única raiz real:\n");
            printf("x1 = %.2lf\n", x1);
            
        } else {
           
            printf("\nO delta é negativo.\n");
        }

    return 0;
    
	}
}

