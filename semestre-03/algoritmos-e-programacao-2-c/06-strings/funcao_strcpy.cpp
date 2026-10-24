#include <stdio.h>
#include <locale.h>
#include <string.h> 

int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "Portuguese");
	
   	char string1[] = "teste";
	char string2[50];
	
	printf("%s\n", string1) ;
	
	strcpy(string2, string1); //procedimento de copiar o conteudo do endereço string1 para o endereço de string2
	
	printf("%s\n", string2);

    
    return 0;
}

