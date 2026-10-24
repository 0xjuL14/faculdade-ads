#include <stdio.h>
#include <locale.h>
#include <math.h> 
#include <stdlib.h>

int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");

	int esc, C1 = 0, C2 = 0, C3 = 0, C4 = 0, nul = 0, bran = 0, total = 0, mqtdv = 0;
	float pnul = 0.0, pbran = 0.0;
	
    do
    {
        system("cls");
        printf("URNA ELETRÔNICA\n");
		printf("1 - Candidato 1\n");
        printf("2 - Candidato 2\n");
        printf("3 - Candidato 3\n");
        printf("4 - Candidato 4\n");
        printf("5 - Voto Nulo\n");
        printf("6 - Voto em Branco\n");
        printf("0 - Sair\n");
        scanf("%d", &esc);
        
        switch (esc) { 
            case 1:
                C1++;
                total++;
            	if(C1 >= mqtdv) { mqtdv = C1; }
                break;

            case 2:
                C2++;
                total++;
           		if(C2 >= mqtdv) { mqtdv = C2; }
				break;
            case 3:
                C3++;
                total++;
                if(C3 >= mqtdv) { mqtdv = C3; }
				break;
            
            case 4:
                C4++;
                total++;
            	if(C4 >= mqtdv) { mqtdv = C4; }
				break;
				
			case 5:
                nul++;
                total++;
				break;
				
			case 6:
                bran++;
                total++;
				break;
			case 0:
                printf("\nSaindo...\n");
                break;

            default:
                printf("Opção Inválida.\n");
                
                break;
        }
    } while(esc != 0);
    
    printf("RESULTADOS:\n");
    
    if (total > 0) {
    	pnul = ((float)nul * 100) / total;
	    pbran = ((float)bran * 100) / total;
    
	    if(C1 == mqtdv && mqtdv > 0) { printf("Vitorioso: Candidato 1\n"); }
		if(C2 == mqtdv && mqtdv > 0) { printf("Vitorioso: Candidato 2\n"); }
		if(C3 == mqtdv && mqtdv > 0) { printf("Vitorioso: Candidato 3\n"); }
		if(C4 == mqtdv && mqtdv > 0) { printf("Vitorioso: Candidato 4\n"); }
		if(mqtdv == 0) { printf("Nenhum candidato recebeu votos.\n"); }
		
			printf("Candidato 1: %d votos.\nCandidato 2: %d votos.\nCandidato 3: %d votos.\nCandidato 4: %d votos.\n", C1, C2, C3, C4);
			printf("Votos Nulos: %d\nVotos em Branco: %d\n", nul, bran);
			printf("A %% de votos nulos sobre o total de votos é de %.1f%%\n", pnul);
			printf("A %% de votos brancos sobre o total de votos é de %.1f%%\n", pbran);
	}
    else {
        printf("Nenhum voto foi computado.\n");
    }
	return 0;
}

