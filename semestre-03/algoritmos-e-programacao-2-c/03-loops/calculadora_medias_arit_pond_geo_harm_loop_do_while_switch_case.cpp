#include <stdio.h>
#include <locale.h>
#include <math.h> 
#include <stdlib.h>

int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");

	int esc;
	float n1, n2, n3, n4, n5, p1, p2, p3, nt;
	float mediaarit = 0.0, mediapond = 0.0, mediageo = 0.0, mediahar = 0.0;
	
    do
    {
        system("cls");
        printf("\nCálculadora de Médias\n");
		printf("1 - Média Aritmética\n");
        printf("2 - Média Ponderada\n");
        printf("3 - Média Geométrica\n");
        printf("4 - Média Harmônica\n");
        printf("5 - Sair\n");
        scanf("%d", &esc);
        
        switch (esc) { 
            case 1:
                printf("Infome as duas notas a serem calculadas:\n");
                scanf("%f%f", &n1, &n2);
                mediaarit = (n1 + n2) / 2.0;
				printf("Média Aritmética: %.2f\n", mediaarit);
				system("pause");
                break;

            case 2:
                printf("Infome as três notas a serem calculadas, respectivamente:\n");
                scanf("%f%f%f", &n1, &n2, &n3);
                printf("Infome os três pesos das notas a serem calculadas anteriormente, respectivamente:\n");
                scanf("%f%f%f", &p1, &p2, &p3);
                
                nt = (n1 * p1) + (n2 * p2) + (n3 * p3);
                mediapond = nt / (p1 + p2 + p3);
                
				printf("Média Ponderada: %.2f\n", mediapond);
				system("pause");
				break;
            case 3:
               	printf("Infome as quatro notas a serem calculadas, respectivamente:\n");
                scanf("%f%f%f%f", &n1, &n2, &n3, &n4);
                
                nt = n1 * n2 * n3 * n4;
                mediageo = pow(nt, 1/4.0);
                
                printf("Média Geométrica: %.2f\n", mediageo);
                system("pause");
				break;
            
            case 4:
                printf("Infome as cinco notas a serem calculadas, respectivamente:\n");
                scanf("%f%f%f%f%f", &n1, &n2, &n3, &n4, &n5);
                
				nt = pow(n1, -1.0) + pow(n2, -1.0) + pow(n3, -1.0) + pow(n4, -1.0) + pow(n5, -1.0);
				mediahar = 5.0 / nt;
				
				printf("Média Harmônica: %.2f\n", mediahar);
				system("pause");				
				break;
				
			case 5:
               	
               	printf("Saindo da operação...\n");
               	system("pause");
				break;
				
            default:
            	
                printf("Opção Inválida.\n");
                system("pause");                
                break;
        } 
        
    } while(esc != 5);
    	
	return 0;
}

