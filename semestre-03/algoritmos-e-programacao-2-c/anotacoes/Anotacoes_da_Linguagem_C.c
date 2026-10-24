Anotações em C 

#include <stdio.h> //biblioteca para ler teclado e mostrar dados do dispositivo no caso PC, standard input/output
#include <locale.h> // globalização e adaptação de unidades US para global, ex data, pontuação, vírgula

int main(int arg, char *argv[]) //funcao inicio
{
	setlocale(LC_ALL, "portuguese-brazilian"); //biblioteca utilizarï¿½
	           // constante
	printf("olá¡")
	
	return 0; // significa que o programa terminou com êxito, se diferente de 0, é erro
}

	// REGRAS:
	//CASE SENSITIVE A != a todos os comandos são em letra minuscula
	// {} 
	// ; 99% LINHA DE COMANDO ACABA COM PONTO-VIRGULA 
	
#include <stdio.h>
#include <locale.h>

int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");
	
	printf("O valor a pagar é %.2f", valor)
								// usado para arredondar, mat.arredondar(valor,2) no portugol

	return 0; 
}

inteiro ---- int %d
real ------- float %f
real ------- double (armazena nº maiores) %lf
lógico ----- bool %d
caracter --- char %c
cadeia ----- char[50] %s

int main()
{
	int diaN = 0; // evitar lixo de memória caso for perguntar o valor da variável
	
	printf("Informe o dia que você nasceu: ");
	scanf("%d", &diaN);  // & = endereço de memória 
    fflush(stdin); // esvaziar buffer de teclado
	
	printf("Vc nasceu no dia %d.\n", diaN); // escreve o valor que a pessoa digitou
	printf("Vc nasceu no dia %d.\n", &diaN); // escreve o nº da posição da variável na memória
	
	return 0;
}

#include <stdio.h>
#include <locale.h>

int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian"); // converte o programa todo, data, hora, teclado, etc para a localização desejada
    // mesma coisa que SetConsoleOutputCP(1252); <- nº de pagina corresponde ao país só dos CARACTERES impressos mas mantem a digitação do usuário padrão EUA
	
	char nome[50]; //toda string precisa ter um terminador: \0 que é o null
	
	printf("Escreva seu nome: ");
	scanf("%49[^\n]s", nome); // não precisa da & localização na memoria mas precisa colocar essa fórmula para aparecer toda a string 
	fflush(stdin);
	
	printf("Seu nome é %s ", nome);
	
	return 0;
}

// mediainteira = num1%num2 --> calcular o resto da divisão

pow(x, indice) // power/potenciação
sqrt(x) // raiz quadrada
pow(x, 1/indice.0) // demais raizes

#include <stdio.h>
#include <locale.h>
#include <math.h> // biblioteca matemática

const float pi = 3.14159265359; // vai fora porque é uma constante global, pode ser utilizada em outras funcões

int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");
	
	float V, r;
	
	printf("Informe o raio da esfera: ");
	scanf("%f", &r);
	fflush(stdin);

	V = (4 * pi * pow(r, 3))/3;
	
	printf("O volume da esfera é %.2f\n", V); // %f.2 -> arredonda com base na próxima casa. Ex.: 2,159 = 2,16 
	
	return 0;
}

A regra é simples:

Para um desconto de X%, você usa (1 - X/100). Ex: 9% de desconto -> 1 - 0.09 = 0.91.

Para um acréscimo de X%, você usa (1 + X/100). Ex: 9% de acréscimo -> 1 + 0.09 = 1.09.

// um zero a esquerda não é nada para os inteiros, mas para os decimais um zero à direita

// precedencia de variáveis, hierarquia de pedir para o mais próximo de baixo para cima

somaq = (num1 * num1) + (num2 * num2); // soma dos quadrados 
somaq = (num1 * num2) + (num1 + num2); // quadrado da soma



> número inteiro com três dígitos e exibe o número invertido (ex.: o usuário digitou 136, o programa exibirá 631). <

#include <stdio.h>
#include <locale.h>

int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");
	
	int num, c, d, u, aux, inv;
	
	printf("Digite um nº inteiro de 3 algarismos: ");
	scanf("%d", &num);
	fflush(stdin);
	
	c = num / 100;
	aux = num % 100;
	d = aux / 10;
	aux = aux % 10;
	u = aux / 1;
    
    inv = c * 1 + d * 10 + u * 100;
		
    printf("Inversão = %d", inv);
   
    return 0;
    
}

> Terminal de autoatendimento bancário que realiza saques em dinheiro <

#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");
	
	int valorsaque, ced10, ced5, ced2, ced1, saldo;
	
	printf("Informe o valor do saque desejado: ");
	scanf("%d", &valorsaque);
	fflush(stdin);
	
	ced10 = valorsaque / 10;
	saldo = valorsaque % 10;
	ced5 = saldo / 5;
	saldo = saldo % 5;
	ced2 = saldo / 2;
	saldo = saldo % 2;
	ced1 = saldo;
		
    printf(" Cédula(s) de R$10: %d\n Cédula(s) de R$5: %d\n Cédula(s) de R$2: %d\n Cédula(s) de R$1: %d", ced10, ced5, ced2, ced1);
   
    return 0;
    
}

getch() //comando que espera dar um enter
if (false) // método de testar código para não executar o bloco | false é representado por 0
if(senha == "teste123" && (0)) // método de testar código para não executar o bloco
if(0) // resulta em FALSO
if(2) // resulta em VERDADEIRO
if(2-2) // resulta em FALSO

Lógica Booleana:

#include <stdio.h>
#include <windows.h>
#include <conio.h>
int main()
{
    SetConsoleOutputCP(1252);
    system("cls"); //limpa a tela
    int a,b,c;
    printf("Digite 3 números para serem comparados: ");
    scanf("%d%d%d",&a,&b,&c);
    if(a > b)
    {
        if(a > c)
            printf("a é o maior");
        else
            printf("c é o maior");
    }
    else
        if(b > c)
            printf("b é o maior");
        else
            printf("c é o maior");
    getch();
}


#include <stdio.h>
#include <conio.h>
int main()
{
    int num;
    printf("Digite um número: ");
    scanf("%d",&num);
    if(num > 0)
        printf("O número digitado é Positivo");
    else if(num == 0)
        printf("O número digitado é Zero");
    else
        printf("O número digitado é Negativo");
    getch();
}

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");

    int a,b,c,escolha;

    while(escolha!=3) // loop
    {
        printf("\n 1. Adição");
        printf("\n 2. Subtração");
        printf("\n 3. Fim");
        printf("\n Qual a sua escolha");
        scanf("%d", &escolha);

        switch(escolha) // "escolha-caso"
        {
            case 1:
                printf("Digite 2 números:");
                scanf("%d%d",&a,&b);
                c=a+b;
                printf("A soma é %d",c);
                break;
            case 2:
                printf("Digite 2 números:");
                scanf("%d%d",&a,&b);
                c=a-b;
                printf("A subtração é %d",c);
                break;
            case 3:
                break;
            default:
                printf("Você escolheu um valor inválido");
                printf("\nPressione qualquer tecla para continuar");
        }
    }
    getch();
}

case 1...5
case 'A'...'Z' // de A até Z
                                          // se falso faz a segunda opção da comparação 
percaumento = (temposerv > 25) ? 1.20 : 1.15 // INLINE
                              // se V faz a primeira opção após o inline 
                              
 Separar cada unidade de nº:
 
milhar=num/1000
aux=num%1000
centena=aux/100
aux=aux%100
dezena=aux/10
unidade=aux%10

#include <stdio.h>
#include <locale.h>

int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");

    int mes;
    
    printf("\nDigite o n° do mês (1 a 12): ");
    scanf("%d", &mes);
	printf("\n");
	
	switch (mes) {
        case 1:
            printf("Mês: Janeiro\n");
            printf("Dias: 31\n");
            break; 

        case 2:
            printf("Mês: Fevereiro\n");
            printf("Dias: 28 (desconsiderando anos bissextos)\n");
            break;

        case 3:
            printf("Mês: Março\n");
            printf("Dias: 31\n");
            break;

        case 4:
            printf("Mês: Abril\n");
            printf("Dias: 30\n");
            break;

        case 5:
            printf("Mês: Maio\n");
            printf("Dias: 31\n");
            break;

        case 6:
            printf("Mês: Junho\n");
            printf("Dias: 30\n");
            break;

        case 7:
            printf("Mês: Julho\n");
            printf("Dias: 31\n");
            break;

        case 8:
            printf("Mês: Agosto\n");
            printf("Dias: 31\n");
            break;

        case 9:
            printf("Mês: Setembro\n");
            printf("Dias: 30\n");
            break;

        case 10:
            printf("Mês: Outubro\n");
            printf("Dias: 31\n");
            break;

        case 11:
            printf("Mês: Novembro\n");
            printf("Dias: 30\n");
            break;

        case 12:
            printf("Mês: Dezembro\n");
            printf("Dias: 31\n");
            break;
            
        default:
            printf("Erro: O número do mês informado é inválido.\n");
            break;
    }
}

LOOPS: 
1) for

int main()
{
    for(int i=1; i<=10; i++)
    {
    printf("%d ",i);
    }
}

2) while

int main()
{
    int i;
    i = 1;
    while(i <= 10)
    {
        printf("%d ",i);
        i++;
    }
}

3) do ... while

int main()
{
    int i;
    i = 1;
    do
    {
        printf("%d ",i);
        i++;
    } while(i <= 10);
}



#include <stdio.h>
#include <locale.h>
#include <ctype.h> // Necessário para a função toupper()

int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");
     
     // Escreva um programa que leia o nome e o sexo de 10 pessoas. No final, informe a quantidade total de homens e de mulheres.
     char nome[100], sexo;
     int homens = 0, mulheres = 0;
     
     printf("Escreva o nome e o sexo (M/F) de 15 pessoas, respectivamente:\n");
	    
	for(int i = 1; i <= 5; i++) {
		printf("Digite o nome: ");
        scanf("%s", nome);
        fflush(stdin);
		printf("Digite o sexo (M para Masculino / F para Feminino): ");
        scanf(" %c", &sexo);
        
		switch (toupper(sexo)) { //conta se a pessoa digitou tanto letra maiúscula quanto minúscula
            case 'M':
                homens++;
                break;

            case 'F':
                mulheres++; 
                break;

            default:
                printf("Opção de sexo inválida! '%c' não será contado(a).\n", sexo);
                break;
        }
    }
    
	printf("Total de homens: %d\n", homens);
    printf("Total de mulheres: %d\n", mulheres);
	 
		return 0;
}


#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

system("cls"); // limpa a tela do usuário
system("pause"); // aparece "Pressione qualquer tecla para continuar


#include <stdio.h>
#include <locale.h>
#include <string.h> 
#include <conio.h>

int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");

	char c, nome[35], municipio[30], pais[50];
	int i=0;
	
	printf("Informe o nome: ");
	gets(nome); //ler string
	
	printf("Informe o município: ");
	while((c = getch()) != '\n' && i < 29) 
	{
		printf("%c",c);
		municipio[i++]=c;
	}
	
	municipio[i]='\0';
	
	printf("Informe o país: ");
	scanf("%49[^\n]s", &pais);
	
	printf("%s\n", nome);
	puts(municipio);
	
		for(i=0; pais[i] != '\0'; i++)
		putchar(pais[i]);
		getch();
	
	return 0;
}

Strings em C


printf imprime até encontrar o \0 - null // para evitar lixo de memória 

#include <stdio.h>
#include <locale.h>
#include <string.h> // biblioteca de string 

int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");

	char personagem[50]; // 50-1 = 49 porque o último será o /0
	
	strcpy(personagem, "PATO DONALD"); //atribui uma váriavel a uma string
	strcpy(personagem, "Mickey"); // substitui e tem a sujeira de memória antes do /0
    personagem[6] = 'O'; // no indice 6 atribua o caracter 'O'
    personagem[4] = '\0'; // caracter null
	personagem[3] = 65; // Coloca a letra A de acordo com a tabela ASCII
	// pode ser usado para descobrir senhas, trocar coisas na memória
    printf("%s", personagem+2); // escreve a variável a partir da 2ª casa começando pelo 0    
    
	return 0;
}

letra = 'B'; == letra = 66;
letra = '\0'; == letra = 0;
strcpy(variavelstring, "CONTEUDO");

char nome[] = "Nome" // já está inicializando

char nome[16] = {'F','T','E','C',' ','F','a','c','u','l','d','a','d','e','s','\0’};
char nome[] = {'F','T','E','C',' ','F','a','c','u','l','d','a','d','e','s','\0’};
char nome[16] = “FTEC Faculdades”; // O compilador C inclui automatic. um \0 no final de uma constante string
char nome[] = “FTEC Faculdades”;
char *nome = “FTEC Faculdades”; // inicialização da string usando um ponteiro para caracteres - conteudo do endereço 
strcpy(nome,”UNIFTEC C.Univ.”);

#include <stdio.h>
getch() – Lê um caractere a partir de um fluxo da entrada padrão, não usa o buffer – precisa #include <conio.h> // precisa dar ENTER
getchar() – Lê um caractere a partir de um fluxo da entrada padrão (teclado), usa o buffer
gets() – Lê uma linha a partir da entrada padrão (teclado) e armazena ela em um vetor de caracteres // fgets(nome, sizeof(nome), stdin);
scanf() – Lê dados formatados a partir da entrada padrão (teclado)
getc () – Lê um caractere a partir de um fluxo da entrada, normalmente um arquivo texto
fscanf() – Lê dados formatados a partir de um dado fluxo de entrada, normalmente um arquivo texto
puts() – Escreve uma string na saída padrão (monitor) sem o caractere NULL
printf() – Escreve dados formatados na saída padrão (monitor)
putchar() – Escreve um caractere na saída padrão (monitor)
fprintf() – Escreve dados formatados em um fluxo de saída, normalmente um arquivo texto

	printf("Informe o nome: ");
	gets(nome); //ler string

strcpy() – Copia os caracteres de uma string para outra string
strcat() – Adiciona uma string ao final de outra string (concatenação)
strchr() – Retorna um ponteiro para a substring a partir da primeira ocorrência de um caractere dentro da string, ou ‘\0’ (NULL) caso não encontre o caractere na string

#include <stdio.h>
#include <locale.h>
#include <string.h> 

int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "Portuguese");
	
    char nome[50];
    
    printf("Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin); 
    
    printf("\nSeu nome é: %s\n", nome);

    
    return 0;
}


int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "Portuguese");
	
   	char string[30] = "Bento Gonçalves"; // retorna a quantidade usada de char na string sem contar o NULL
	char* parcial; // declarar um ponteiro tipo_var*
	parcial = strchr(municipio, 'G'); // procurar o valor
	strcpy(municipio, "Pinto Bandeira"); // Passo 2, substitui por outra string
	printf("%d\n", strlen(parcial)); // Resultará: 8 Bandeira
	printf("%d\n", strlen(municipio)); // Resultará: 14 Pinto Bandeira

    
    return 0;
}

#include <stdio.h>
#include <locale.h>
#include <string.h> 

int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "Portuguese");
	
   	char nome1[30] = "Ana";
	char nome2[30] = "Pedro";
	
	int resultado = strcmp(nome1,nome2);
	
	if(strcmp(nome1,nome2)==0) { // 0 = As duas strings são iguais (idênticas caractere a caractere)
		printf("Os nomes são iguais\n"); 
	}
	else if(strcmp(nome1,nome2) == -1); {// -1 : A primeira string é anterior à seguinte (vem antes, se pensarmos na ordem alfabética)
		printf("%s%s\n", nome1, nome2);
	}
	else { // 1: A primeira string é posterior à seguinte (vem depois, se pensarmos na ordem alfabética)              
		printf("%s%s\n", nome2, nome1);
	}
	
	printf("%d", resultado);

    
    return 0;
}

ESCREVER UMA LISTA EM ORDEM SEPARADA

#include <stdio.h>
#include <locale.h>
#include <string.h> 

int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "Portuguese");
	
   	char frutas[50] = "laranja;banana;maçã;pera;bergamota;pêssego";
	char* parcial;
	
	parcial = strtok(frutas,";");
	
	if (parcial==NULL)
		printf("Não encontrado.\n");
	else
	{
		while (parcial != NULL)
		{
			printf("%s\n", parcial);
			parcial = strtok(NULL,";");
		}
	}
    
    return 0;
}

#include <stdio.h>
#include <locale.h>
#include <string.h> 

int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "Portuguese");
	
    char nome[51];
    
    printf("Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin); 
                                     // FORMA CORRETA DE USAR FGETS E TIRAR O ENTER DO TECLADO
    nome[strlen(nome)-1] = NULL;
   // STRCSPN(STRING'\n') = NULL;
    
    printf("\nSeu nome é: %s\nE o tamanho usado é %d\nE o tamanho total é %d", nome, strlen(nome), sizeof(nome));
    
    
    return 0;
}


Sintaxe	    Leitura	                                    Exemplo: "Olá mundo"
%s	        Lê apenas uma palavra.	                    Lê só "Olá".
%[^\n]	    Lê a linha inteira (incluindo espaços).	    Lê "Olá mundo".

A sintaxe "%25[^\n]s" diz para o scanf o seguinte:
"Leia no máximo 25 caracteres, parando somente quando você encontrar um caractere de nova linha (\n), e armazene o que foi lido na variável p1."


#include <stdio.h>
#include <ctype.h>                                                                                                                    
#include <locale.h>
#include <string.h>

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");
    char frase[101], stringConsonants[101];
    int contConsonants = 0;

    printf("Digite uma frase: ");
    scanf("%100[^\n]s", frase);
    fflush(stdin);

    for(int p = 0; p < strlen(frase); p++)
    	if(tolower(frase[p]) != 'a' && tolower(frase[p]) != 'e' && tolower(frase[p]) != 'i' && tolower(frase[p]) != 'o' && tolower(frase[p]) != 'u')
    	{
    		stringConsonants[contConsonants] = frase[p];
    		contConsonants++;
		}
		
	stringConsonants[contConsonants] = NULL;
	
	printf("String com apenas consoantes: %s\n", stringConsonants);
	
    return 0;
}


    char frase[101];

    printf("Digite uma frase: ");
    // Lê a linha inteira de forma segura. O fgets inclui o '\n'.
    fgets(frase, sizeof(frase), stdin);
    // Remove o '\n' que o fgets adiciona, se ele existir.
    frase[strcspn(frase, "\n")] = '\0';
    
    
#include <stdio.h>
#include <locale.h>
#include <string.h>

char* leNome(char* tipoDado)

{
	char dado[51];

	printf("%s",tipoDado);
	scanf("%50[^\n]s",dado);
	fflush(stdin);

	return strdup(dado);

}

int main(void)

{
	setlocale(LC_ALL, "portuguese-brazilian");
	
	char* nomeAluno;
	char* naturalidade;

	nomeAluno = leNome("Informe o seu nome: ");
	naturalidade = leNome("Informe o municipio que você nasceu: ");
	printf("O seu nome é %s, você é natural de %s.\n",nomeAluno,naturalidade);

}


#include <stdio.h>
#include <locale.h>
#include <strings.h>	
#include <conio.h>

int main()
{
	setlocale(LC_ALL, "portuguese-brazilian");

	char c,nome[35], municipio[30], pais[50];
	int i=0;

	printf("Primeira forma de ler uma string - usando gets\n");
	printf("Informe o nome: ");
	gets(nome);

	printf("Segunda forma de ler uma string - usando getch\n");
	printf("Informe o município: ");

	while(i<29)
	{
		c = getch();
		if (c=='\n')
		   break;
		printf("%c", c);
		municipio[i++]=c;
	}

	municipio[i]='\0';
	printf("\n");
	printf("Terceira forma de ler uma string - usando scanf\n");
	printf("Informe o país: ");
	scanf("%49[^\n]s", pais);
	fflush(stdin);
	printf("Primeira forma de escrever uma string - usando printf\n");
	printf("%s\n", nome);
	printf("Segunda forma de escrever uma string - usando puts\n");
	puts(municipio);
	printf("Terceira forma de escrever uma string - usando putchar\n");

	for(i=0; pais[i] != '\0'; i++)
		putch(pais[i]);

	return 0;


#include <stdio.h>
#include <locale.h>
#include <string.h>

// Definição da Função (UDF): dataExtenso
void dataExtenso(int dia, int mes, int ano) { // Tipo de Retorno: 'void' (apenas imprime)
    // Array de strings para os nomes dos meses
    // O índice 0 é deixado vazio ou usado como erro, pois os meses vão de 1 a 12.
    char *nomes_meses[] = {
        "Inválido", // posição 0
        "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", // posições 1, 2, 3, 4, 5, 6
        "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro" // posições 7, 8, 9, 10, 11 e 12 respectivamente
    };
    
    // Verifica se o mês está em um intervalo válido (1 a 12)
    if (mes >= 1 && mes <= 12) {
        // Acessa o array usando o número do mês como índice
        printf("\nData por Extenso: %d de %s de %d\n", dia, nomes_meses[mes], ano);
    } else {
        printf("\nErro: Mês inválido (%d).\n", mes);
    }
}

int main() {
	
    setlocale(LC_ALL, "portuguese-brazilian"); 
    
    int dia, mes, ano;

    // Leitura dos três números
    printf("Digite o dia: ");
    scanf("%d", &dia);
    
    printf("Digite o mês (1 a 12): ");
    scanf("%d", &mes);
    
    printf("Digite o ano: ");
    scanf("%d", &ano);

    // Chama a UDF para imprimir a data por extenso
    dataExtenso(dia, mes, ano);

    return 0;
}


assinatura da função: A 1ª linha de uma função, uma declaração inicial da função sem ter a necessidade dos parâmetros

strdup // só usa para retornar string, cria uma cópia 

bool ehBissexto(int ano)
{
    bool anoBissexto = false;
    if(((ano % 4 == 0 && (ano % 100 != 0) || ano % 400 ==0))
        anoBissexto = true;
    return anoBissexto; //retorna a variável
}



*variavel // ponteiro e busca o que está dentro do endereço 
&variavel // endereço do conteudo da variavel
operacoes(7, 8, &soma, &produto)

void operacoes(int num1, int num2, int* soma, int* produto) // ponteiro para a LOCALIZAÇÃO DA MEMÓRIA, no final da função irá retornar o valor como se fosse o return(variavel)
{
    *soma = num1 + num2;
    *produto = num1 * num2;
    return;
}
// base do hacking de memória, mexer com ponteiros dentro de uma função e interferir na parte de fora da função 


#include <stdio.h>
#include <string.h>  
#include <locale.h>   

// (30 chars + 1 para o '\0')
#define TAMANHO_MAX_NOME 31 // ou const int TAMANHO_MAX_NOME = 31; ou enum { TAMANHO_MAX_NOME = 31 };

void lerNome(char nome[]) {
    
    printf("Digite o nome da pessoa: ");
    fgets(nome, TAMANHO_MAX_NOME, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    
}

int main() {
    setlocale(LC_ALL, "portuguese-brazilian"); 
    
    char nome_do_usuario[TAMANHO_MAX_NOME]; 

    lerNome(nome_do_usuario);

    printf("\nO nome lido foi: %s\n", nome_do_usuario);

    return 0;
}


Constantes Numéricas Simples (PI, TAMANHO)  	const (ou enum para arrays)	    Oferece segurança de tipo, o que #define não faz.
Macros de Função (MULT(a, b))	                #define	                        O único propósito é fazer substituição de código complexa e rápida.


RECURSÃO //sempre deve haver um base case (ponto de saída de looping)

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

void escrevePalavra(char*);
void linhaAst(int);
void triangAst(int);
void triangAstc(int, int);

int main()
{
    //escrevePalavra("Boa noite");
    //linhaAst(5);
    //triangAst(5);
    triangAstc(1,5);
    return 0;
}
void triangAstc(int qtdAst, int limite) { // para a recursão qyando os valores se igualarem
    linhaAst(qtdAst);
    printf("\n");
    if (qtdAst < limite) {
        triangAstc(qtdAst + 1, limite);
    }
}
void triangAst(int qtdAst) {
    linhaAst(qtdAst);
    printf("\n");
    if (qtdAst > 1) {
        triangAst(qtdAst - 1);
    }
}
void escrevePalavra(char* palavra)
{
    printf("%s\n", palavra);
    if (strlen(palavra) > 1) { // fechar o loop
        escrevePalavra(palavra+1);
    }
    return;
}

void linhaAst(int qtdAst) {
    printf("*");
    if (qtdAst > 1)
        linhaAst(qtdAst - 1);
}

/home/juh/Desktop/Notes/teste
Boa noite
oa noite
a noite
 noite
noite
oite
ite
te
e

LEMBRAR DE FATORIAIS QUANDO PENSAR EM RECURSÃO
6! = 6 * 5!
5! = 5 * 4!
4! = 4 * 3!
3! = 3 * 2!
2! = 2 * 1!
1! = 1 * 0!
0! = 1

int fatorial(int 6) {
	if(n == 0) 
		return 1;
	else
		return n * fatorial(6 - 1);

}

VETORES = ARRAYS // é uma matriz unidimensional 

float notas[30]; // endereço de memória onde terão os 30 valores (0 a 29) - Elementos contíguos (um ao lado do outro)
printf("%f", notas[0])


for(int p = 0; p < 30; p++) { 
	printf("Informe o %dº aluno: ", p + 1); // imprime 
	scanf("%f", $notas[p]);
	printf("%f", notas[p]); // para imprimir todo array
}

#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <float.h>

#define tam 7 // facilita o limite do laço

int main() {
    setlocale(LC_ALL, "portuguese-brazilian");

    float notas[tam], media;
    int p;

    for(int p = 0; p < tam; p++) {
        printf("Informe o %dº aluno: ", p + 1);
        scanf("%f", &notas[p]);
        fflush(stdin);
    }
    for(int p = 0; p < tam; p++) {
        printf("Nota do %dº aluno: %.2f ", p + 1, notas[p]);
    }

   // media = (notas[0] + notas[1] + notas[2] + notas[3]) / tam;

    printf("\nA média das notas é %.2f", media);
    return 0;
}

MATRIZES 

bidimensional = como se fosse uma tabela   // jogos: jogo da velha, sudoku, batalha naval, snake, cubo magico (3d)
LI/COR - linha/coluna
ex: x[2][3] = 98

FA/LI/COR - face/linha/coluna

4 dimensões = cubo mágico de cubos magicos 

VELHA

| X|   |   |  0 = null
|  | O |   |  1 = x 
|  |   | O |  2 = O 


if(VELHA[0],[2] == VELHA[1][1] && VELHA[1][1] == VELHA [2][0])


// limpar de cima pra baixo, da esquerda pra direita

	int matriz[3][3];

for(int l = 0; l < 3; l++) {
	for(int c = 0; c < 3; c++) {
		matriz[l][c] = 0;
	}
}

// leitura da matriz

#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <float.h>

#define linha 3
#define coluna 3

int main() {
    setlocale(LC_ALL, "portuguese-brazilian");

    int matriz[linha][coluna];

    for(int l = 0; l < linha; l++) { // loop que limpa a memória da matriz com 0s
        for(int c = 0; c < coluna; c++) {
            matriz[l][c] = 0;
        }
    }
    
    for(int l = 0; l < linha; l++) { // loop que solicita ao user e atribui valores à matriz
        for(int c = 0; c < coluna; c++) {
            printf("informe um valor para a posição [%d,%d] da matriz:\n", l, c);
            scanf("%d", &matriz[l][c]);
            fflush(stdin);
        }
    }
    
    for(int l = 0; l < linha; l++) { // loop que imprime a matriz
        for(int c = 0; c < coluna; c++) {
            printf("%d ", matriz[l][c]);

        }
    }

   return 0;
 }


VER SE UM OU MAIS NUMEROS JÁ FOI DIGITADO E QUANTAS VEZES REPETIU

#include <stdio.h>
#include <math.h>
#include <locale.h>

#define TAMANHO 10

int main() {
    setlocale(LC_ALL, "portuguese-brazilian");

    int numeros[TAMANHO];
    int i, j, contador;

    for (i = 0; i < TAMANHO; i++) {
        printf("Digite o %dº número: ", i + 1);
        scanf("%d", &numeros[i]);

        }

    for (i = 0; i < TAMANHO; i++) {
        if (numeros[i] == -1) {  // Se o elemento foi marcado (alterado para -1), ele já foi contado.
            continue; // Pula para o próximo elemento
        }

        contador = 1; // Começa a contagem com 1 (o próprio elemento)
        
        for (j = i + 1; j < TAMANHO; j++) {
            if (numeros[i] == numeros[j]) { // Se o elemento atual (i) for igual ao elemento posterior (j)
                contador++;
                numeros[j] = -1;  // Marca o elemento repetido com -1 para que não seja contado novamente
            }
        }
        
        if (contador > 1) {  // Se o contador for maior que 1, significa que o número é repetido
            printf("O número %d se repete %d vezes.\n", numeros[i], contador);
        }
    }
    
    return 0;
}

MÉTODO BUBBLE SORT COM VALORES DEFINIDOS DO VETOR

#include <stdio.h>
#include <locale.h>

// Função Bubble Sort
void bubbleSort(int vetor[], int tamanho) { // Ordena o vetor usando comparações e trocas de pares adjacentes.
    int i, j, temp;
    
    // loop externo para percorre o vetor N-1 vezes
    for (i = 0; i < tamanho - 1; i++) {
        
        // Laço Interno (Comparações):
        // Percorre o vetor, comparando pares.
        // Otimização: A cada passagem (i), o último elemento já está ordenado,
        // então não precisamos ir até o final (tamanho - 1 - i).
        for (j = 0; j < tamanho - 1 - i; j++) {
            
            // Condição de Troca: Se o elemento atual for MAIOR que o próximo, troca
            if (vetor[j] > vetor[j+1]) {
                // Troca (Swap) usando uma variável temporária
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }
}

void imprimirVetor(int vetor[], int tamanho) { // Função Auxiliar para Imprimir o Vetor
    printf("[");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", vetor[i]);
        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    setlocale(LC_ALL, "portuguese-brazilian");
    
    int dados[] = {5, 1, 4, 2, 8, 3, 9};
    int tamanho = sizeof(dados) / sizeof(dados[0]);

    printf("Vetor Original: ");
    imprimirVetor(dados, tamanho);

    // Chama a função para ordenar
    bubbleSort(dados, tamanho);

    printf("Vetor Ordenado (Bubble Sort): ");
    imprimirVetor(dados, tamanho);

    return 0;
}


METODO BUBBLE SORT VALORES SORTEADOS

#include <stdio.h> // a de sempre >_<
#include <stdlib.h> // para a função rand() - para sortear números
#include <time.h> // para a função time() - para que o sorteio seja diferente a cada vez
#include <locale.h> // para usar em PT-BR/ABNT2

#define TAMANHO 15 // a lista de números terá 15 índices
#define LIMITE_MAXIMO 15 // números sorteados vão de 1 a 15

//  FUNÇÃO BUBBLE SORT oºOºoº
void bubbleSort(int vetor[], int tamanho) {
    int i, j, temp;

    for (i = 0; i < tamanho - 1; i++) { // repete a organização do bubble sort conforme o tamanho definido
        for (j = 0; j < tamanho - 1 - i; j++) { // COMPARAÇÃO: "tamanho - 1 - i" é para que o loop ignore o que já foi organizado
            if (vetor[j] > vetor[j+1]) { // O número atual (vetor[j]) é maior que o próximo (vetor[j+1])? Se SIM, trocam de lugar:
                temp = vetor[j]; //  Guarda o número maior na variável temporária
                vetor[j] = vetor[j+1]; // Coloca o número menor no lugar do maior
                vetor[j+1] = temp; // Coloca o número maior no lugar que estava vazio
            }
        }
    }
}

// FUNÇÃO Imprimir APENAS os Números Distintos
// obs.: A ordenação é necessária para que a função funcione corretamente
void imprimirDistintos(const char *nome, int vetor[], int tamanho) {
    printf("%s: [", nome); // o %s usa a string para o que estará na main "Vetor Final" + ':' :O

    if (tamanho > 0) {
        printf("%d", vetor[0]); // O 1º número sempre deve ser impresso pois não tem nada antes dele :)
    }

    for (int i = 1; i < tamanho; i++) { // o loop percorre a lista, começando do SEGUNDO número (i = 1)!!
        // nesse ponto, a lista já está organizada, então os repetidos estão lado a lado!!!
        if (vetor[i] != vetor[i-1]) { // Este número (vetor[i]) é diferente do número que veio antes (vetor[i-1])?
            printf(", %d", vetor[i]); // Se SIM, ele é um número único e deve ser impresso :)
        }
    }
    printf("]\n");
}

int main() { // FUNÇÃO PRINCIPAL
    setlocale(LC_ALL, "portuguese-brazilian");

    int vetor[TAMANHO]; // vetor principal com 15 índices vazios

    srand(time(NULL)); // Prepara o sorteador, usando o relógio para garantir que os números sejam novos ;)

    // Sorteio e Preenchimento do Vetor
    for (int i = 0; i < TAMANHO; i++) { // o loop vai do índice 0 até o 14
        vetor[i] = (rand() % LIMITE_MAXIMO) + 1; // sorteia um nº de 1 a 15 e guarda no índice 'i' do vetor
    }

    printf("\tNúmeros Sorteados:\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", vetor[i]); // Exibe o vetor ANTES da ordenação
    }
    printf("\n\n");

    // ORDENAÇÃO
    bubbleSort(vetor, TAMANHO); // manda a lista para a função de organizar
    printf("\tApós Bubble Sort:\n");
    for (int i = 0; i < TAMANHO; i++) { // o loop anda e imprime a lista organizada
        printf("%d ", vetor[i]);
    }
    printf("\n");

    printf("\n\tOrdem crescente dos Nºs Distintos:\n");
    imprimirDistintos("Vetor Final",vetor, TAMANHO); // imprime somente os nºs distintos
    // não precisa de marcadores % pois é a chamada da função, ou seja, na função já tem :)

    return 0; // GG! deu tudo certo >.<'
}


CÓDIGO BASE DE MATRIZ

#include <stdio.h>
#include <locale.h>

#define qtdLin 3
#define qtdCol 4

void inicializaMatriz(int num[][qtdCol], int qtdLinhas, int qtdColunas)
{
    for (int l = 0; l < qtdLinhas; l++)
        for (int c = 0; c < qtdColunas; c++)
            num[l][c] = 0;
}

void leMatriz(int num[][qtdCol], int qtdLinhas, int qtdColunas)
{
    for (int l = 0; l < qtdLinhas; l++)
    {
        for (int c = 0; c < qtdColunas; c++)
        {
            printf("Informe o elemento [%d][%d]: ",l+1,c+1);
            scanf("%d", &num[l][c]);
        }
        printf("\n");
    }
    return;
}

void escreveMatriz(int num[][qtdCol], int qtdLinhas, int qtdColunas)
{
    for (int l = 0; l < qtdLinhas; l++)
    {
        printf("| ");
        for (int c = 0; c < qtdColunas; c++)
            printf("%2d ",num[l][c]);
        printf("|\n");
    }
    return;
}

int main()
{
    setlocale(LC_ALL, "portuguese-brazilian");
    
    int matriz[qtdLin][qtdCol], colInicial, linInicial;
    
    inicializaMatriz(matriz,qtdLin,qtdCol);
    leMatriz(matriz,qtdLin,qtdCol);
    escreveMatriz(matriz,qtdLin,qtdCol);
    
    for (int l = 0; l < qtdLin; l++) {
        for (int c = 0; c < qtdCol; c++) {
            if (c == qtdCol - 1) {
                colInicial = 0;
                linInicial = 1 + l;
            }
            else {
                colInicial = c + 1;
                linInicial = l;
            }
            for (int i = linInicial; i < qtdLin; i++) {
                for (int j = (i == linInicial?colInicial:0); j < qtdCol; j++) {
                    if (matriz[l][c] == matriz[i][j])
                        printf("O elemento %d se repete.\n", matriz[l][c]);
                }
            }
        }
    }
}



Enumerações em C

enum eSexo {
	masculino, // 0
	feminino // 1
} sexo;

sexo = masculino;
sexo = (eSexo)1; // atrib. feminino

printf("%d", sexo)

///////////////////////

enum eSexo {
	masculino = 2;
	feminino = 3
} sexo;

sexo = masculino;
sexo = (eSexo)3;

printf("%d", sexo);


sexo = (eSexo)9; // aceita

///////////////////////////

enum eDiasSemana {
	domingo = 1,
	segunda = 2,
	terca = 3,
	quarta = 4,
	quinta = 5,
	sexta = 6,
	sabado = 7
};

enum eDiasSemana hoje; ou eDiasSemana hoje;
hoje = terca;
printf("%d", hoje);
saida ~ 3 

/////////////////////////

enum eFonte { // usar sempre multiplos de 2 nas opções para não dar erro nas combinações
	ITALICO = 1,
	NEGRITO = 2,
	SUBLINHADO = 4
};

eFonte titulo;
titulo = NEGRITO;
titulo = NEGRITO | SUBLINHADO; // bitwise OR | OPERATOR FLAG
printf("%d", titulo);
saida ~ 6 // combinação de negrito (2) + sublinhado (4)


6 & 1 - falso // 2 + 4 & 1



#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "portuguese-brazilian");

    enum eFonte {
        ITALICO = 1,
        NEGRITO = 2,
        SUBLINHADO = 4
        };

    //enum eFonte titulo;
    //titulo = (enum eFonte)(NEGRITO | SUBLINHADO);
    enum eFonte titulo = (enum eFonte)(NEGRITO | SUBLINHADO); // escrita resumida

    if (titulo & ITALICO) // bitwise AND & operator
        printf("O titulo está em itálico\n");
    if (titulo & NEGRITO) // bitwise AND & operator
        printf("O título está em negrito\n");
    if (titulo & SUBLINHADO) // bitwise AND & operator
        printf("O título está sublinhado\n");
}


Estruturas em C

. (Ponto)	A Estrutura (a ficha real)			estrutura.campo		Acessa campos em estruturas diretas.
-> (Seta)	O Ponteiro (o endereço da ficha)	(*ponteiro).campo	Acessa campos através de um ponteiro.

#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "portuguese-brazilian");

    struct Pessoa { // a estrutura possui 3 atributos
        char nome[50];
        int matricula;
        float salario;
    } dono,funcionarios[20];

    struct Pessoa p1,p2,alunos[100];

    // Acesso aos membros da estrutura:
    strcpy(p1.nome,"Margela Gomes");
    p1.matricula = 202039;
    p1.salario = 2000.00;

    strcpy(alunos[0].nome,"Pedro Henrique Dias");
    alunos[0].matricula = 202049;
    alunos[0].salario = 1500.00;

    strcpy(alunos[1].nome,"Heloísa Gastão");
    alunos[1].matricula = 202051;     // vetor[].atribuição
    alunos[1].salario = 3509.27;

    struct Pessoa* lider;   // Ponteiros para estruturas e acesso aos seus membros
    lider = &alunos[1];
    
    strcpy(lider -> nome,"Margela Gomes");
    lider -> matricula = 202039;  // ponteiro -> atribuição
    lider -> salario = 2000.00;
    (*lider).salario *= 1.2; // lider -> salario *= 1.2;
}

#include <stdio.h>
#include <locale.h>
#include <string.h>

struct pessoa {
    char nome[50]; // 50 bits
    int idade; // 4 bits
    float peso; // 8 bits
};

int main() {
    setlocale(LC_ALL, "portuguese-brazilian");

    struct pessoa *chefePtr, chefe;
    chefePtr = &chefe;
    printf("Informe a idade: ");
    scanf("%d", &chefePtr -> idade);
    printf("Informe o peso: ");
    scanf("%f", &chefe.peso);

    printf("Resultado:\n");
    printf("Idade: %d\n", chefe.idade);
    printf("Peso: %f\n\n", chefePtr -> peso);

    printf("Tamanho da estrutura: %d\n", sizeof(chefe));
    printf("Tamanho do ponteiro: %d\n", sizeof(chefePtr));
    printf("Conteúdo do ponteiro: %d\n", sizeof(*chefePtr));

    return 0;
}


//
// Created by juh on 11/12/25 on CLion
//

#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

enum eSexo { // serve para limitar, tipo uma "etiqueta"
    Masculino, // valor 0
    Feminino, // valor 1
    Outro // valor 3
};

struct stAluno { // estrutura, como um "molde"
    int numMatricula;
    bool ativo;
    enum eSexo sexo; // Reserva um espaço para a "etiqueta" (eSexo)
    char nome[101];
    float valorMensalidade;
};

int main()
{
    setlocale(LC_ALL, "portuguese-brazilian");

        struct stAluno alunosAlgII[5]; // delimita o registro para 5 alunos (indices 0 a 4)
    // preenchimento dos dados do 1º aluno (índice 0):
        alunosAlgII[0].numMatricula = 1000; // o '.' acessa um campo quando tem a estrutura diretamente
        alunosAlgII[0].ativo = true;
        alunosAlgII[0].sexo = Masculino;
        strcpy(alunosAlgII[0].nome,"Aluno 1"); // strcpy porque o nome é uma string
        alunosAlgII[0].valorMensalidade = 250.23;
    // preenchimento dos dados do 2º aluno (índice 1):
        alunosAlgII[1].numMatricula = 1001;
        alunosAlgII[1].ativo = true;
        alunosAlgII[1].sexo = Outro;
        strcpy(alunosAlgII[1].nome,"Aluno 2");
        alunosAlgII[1].valorMensalidade = 198.44;
    // preenchimento dos dados do 3º aluno (índice 2)
        alunosAlgII[2].numMatricula = 1002;
        alunosAlgII[2].ativo = true;
        alunosAlgII[2].sexo = Feminino;
        strcpy(alunosAlgII[2].nome,"Aluna 1");
        alunosAlgII[2].valorMensalidade = 200.00;
    // preenchimento dos dados do 4º aluno (índice 3)
        alunosAlgII[3].numMatricula = 1003;
        alunosAlgII[3].ativo = false;
        alunosAlgII[3].sexo = Feminino;
        strcpy(alunosAlgII[3].nome,"Aluna 2");
        alunosAlgII[3].valorMensalidade = 302.10;
    // preenchimento dos dados do 5º aluno (índice 4)
        alunosAlgII[4].numMatricula = 1004;
        alunosAlgII[4].ativo = true;
        alunosAlgII[4].sexo = Masculino;
        strcpy(alunosAlgII[4].nome,"Aluno 3");
        alunosAlgII[4].valorMensalidade = 270.22;

        printf("Tamanho da estrutura: %lu\n\n", sizeof(struct stAluno)); // Mostra quanto espaço de memória cada ficha ocupa

        for (int i=0; i<5; i++) { // loop para imprimir toda estrutura
            struct stAluno *aluno = alunosAlgII + i; // Cria um ponteiro (aluno) e aponta ele para a ficha atual (alunosAlgII[i])
            printf("Dados da %dª estrutura: (Endereço: %d)\n",i + 1, aluno); // Imprime o número da ficha e o endereço da memória correspondente
            printf("N�mero Matrícula: %d\n", aluno -> numMatricula); // Imprime a Matrícula da ficha que o ponteiro (aluno) está apontando
            printf("Aluno(a) Ativo..: %s\n", aluno -> ativo ? "Sim" : "Não"); // '->' acessa um campo quando tem um ponteiro para a estrutura (o endereço da ficha) e não a ficha em si
            printf("Sexo............: %s\n",
                (aluno -> sexo == Masculino) ? "Masculino" :
                (aluno -> sexo == Feminino)  ? "Feminino" : "Outro");;
            printf("Nome do Aluno...: %s\n", aluno -> nome);
            printf("Valor Mensalid..: %4.2f\n", aluno -> valorMensalidade);
            printf("\n");
        } // o loop volta para o início e repete para a próxima ficha

    return 0; // GG! :)
}

OPERAÇÕES COM 2 MATRIZES

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define LINHAS 3
#define COLUNAS 3
#define TAMANHO_VETOR (LINHAS * COLUNAS) // número total de células na matriz (3x3=9)
#define TAMANHO_MAX_UNIAO (TAMANHO_VETOR * 2) // para que uniao tenha espaço (9 de A + 9 de B)

enum eTipoOperacao { // ETIQUETAS fixas para cada tipo de operação
    UNIAO, INTERSECAO, DIFERENCA_A_B,
    ADICAO, SUBTRACAO, MULTIPLICACAO
};

struct stConjunto { // MOLDE da ficha de dados para cada matriz de entrada
    char nome[5]; // identificar a matriz com um char (A/B)
    int matriz[LINHAS][COLUNAS]; // espaço para a tabela de números (matriz 3x3)
};

void bubbleSort(int vetor[], int tamanho) { // Bubble Sort para organizar a lista do menor para o maior ;)
    int i, j, temp;
    for (i = 0; i < tamanho - 1; i++) { // loop até que todos os maiores estejam no fim
        for (j = 0; j < tamanho - 1 - i; j++) { // loop que compara vizinhos
            if (vetor[j] > vetor[j+1]) { // se o número atual for MAIOR que o próximo...
                temp = vetor[j]; // TROCA 1: Guarda o maior na variável temporária
                vetor[j] = vetor[j+1]; // TROCA 2: O menor vai para o lugar do maior
                vetor[j+1] = temp; // TROCA 3: O maior vai para o lugar do menor
            }
        }
    }
}

int contemElemento(int vetor[], int tamanho, int elemento) {
    for (int k = 0; k < tamanho; k++) { // loop que olha cada número na lista
        if (vetor[k] == elemento) { // se o número procurado for encontrado...
            return 1; // devolve 1 (SIM, está contido!!)
        }
    }
    return 0; // Senão, o loop devolve 0 (NÃO está contido!!)
}

void lerMatrizes(struct stConjunto *conjuntoA, struct stConjunto *conjuntoB) { // pede os números das matrizes pro usuário :D
    printf("--- 1. LEITURA DA MATRIZ %s (%dx%d) ---\n", conjuntoA->nome, LINHAS, COLUNAS); // recebe o ENDEREÇO da Matriz A e usa *ponteiro para preenchê-la
    for (int l = 0; l < LINHAS; l++) {
        for (int c = 0; c < COLUNAS; c++) {
            printf("%s[%d][%d]: ", conjuntoA->nome, l, c);
            scanf("%d", &conjuntoA->matriz[l][c]); // guarda o nº digitado na posição [l][c] da matriz A
        }
    }
    printf("\n--- 2. LEITURA DA MATRIZ %s (%dx%d) ---\n", conjuntoB->nome, LINHAS, COLUNAS); // recebe o ENDEREÇO da Matriz B e usa *ponteiro para preenchê-la
    for (int l = 0; l < LINHAS; l++) {
        for (int c = 0; c < COLUNAS; c++) {
            printf("%s[%d][%d]: ", conjuntoB->nome, l, c);
            scanf("%d", &conjuntoB->matriz[l][c]); // guarda o nº digitado na posição [l][c] da matriz B
        }
    }
}

void imprimirConjunto(struct stConjunto conjunto) { // mostra a matriz A ou B respectivamente (recebe a ficha completa da struct)
    printf("\n>>> MATRIZ %s:\n", conjunto.nome); // imprime o nome da matriz (A/B conforme anda o loop)
    for (int l = 0; l < LINHAS; l++) {
        printf("|");
        for (int c = 0; c < COLUNAS; c++) {
            printf("%4d ", conjunto.matriz[l][c]); // imprime o número que está na posição [l][c]
        }
        printf("|\n");
    }
}

void imprimirMatrizPura(const char *nome, int matriz[][COLUNAS]) { // mostra matrizes de soma/multiplicação
    printf("\n>>> MATRIZ %s:\n", nome); // recebe o nome e a matriz que tem o resultado
    for (int l = 0; l < LINHAS; l++) {
        printf("|");
        for (int c = 0; c < COLUNAS; c++) {
            printf("%4d ", matriz[l][c]); // imprime o número da matriz de resultado
        }
        printf("|\n");
    }
}

void operacaoMatricial(struct stConjunto *A, struct stConjunto *B, int matResultado[][COLUNAS], enum eTipoOperacao operacao) { // operações entre matrizes

    if (operacao == ADICAO || operacao == SUBTRACAO) { // se for SOMA ou SUBTRAÇÃO
        for (int l = 0; l < LINHAS; l++) {
            for (int c = 0; c < COLUNAS; c++) {
                if (operacao == ADICAO) {
                    matResultado[l][c] = A->matriz[l][c] + B->matriz[l][c]; // SOMA o número na mesma posição nas duas matrizes
                } else { // SUBTRACAO
                    matResultado[l][c] = A->matriz[l][c] - B->matriz[l][c]; // SUBTRAI o número na mesma posição nas duas matrizes
                }
            }
        }
    }
    else if (operacao == MULTIPLICACAO) { // se for MULTIPLICAÇÃO, faz várias somas e multiplicações!! :O
        for (int l = 0; l < LINHAS; l++) {
            for (int c = 0; c < COLUNAS; c++) {
                matResultado[l][c] = 0; // atribui 0 para inicializar
                for (int k = 0; k < COLUNAS; k++) {
                    matResultado[l][c] += A->matriz[l][k] * B->matriz[k][c];
                }
            }
        }
    }
}

void imprimirResultadoConjunto(const char *nome, int vetor_original[], int tamanho_original, enum eTipoOperacao tipo) { // operação de conjuntos
    int vetor_copia[tamanho_original]; // recebe o resultado bagunçado
    memcpy(vetor_copia, vetor_original, tamanho_original * sizeof(int)); // cria uma CÓPIA do resultado bagunçado :O

    printf("\n--- %d. RESULTADO CONJUNTO: %s ---\n", tipo + 3, nome);

    printf(">> RESULTADO ORIGINAL: ["); // imprime o resultado bagunçado original, não a cópia ;)
    for (int i = 0; i < tamanho_original; i++) {
        printf("%d", vetor_original[i]);
        if (i < tamanho_original - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    bubbleSort(vetor_copia, tamanho_original); // chama a função bubbleSort para organizar a CÓPIA

    printf(">> SOMENTE ORDENADO (%d elementos): [", tamanho_original); // imprime o resultado organizado e bonitinho a partir da cópia :)
    for (int i = 0; i < tamanho_original; i++) {
        printf("%d", vetor_copia[i]);
        if (i < tamanho_original - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    setlocale(LC_ALL, "portuguese-brazilian");
    // Cria as fichas A e B e dá o nome a elas usando o strcpy
    struct stConjunto conjuntoA;
    struct stConjunto conjuntoB;
    strcpy(conjuntoA.nome, "A");
    strcpy(conjuntoB.nome, "B");
    // cria as caixas para os resultados de cada operação matricial
    int matSoma[LINHAS][COLUNAS];
    int matSubtracao[LINHAS][COLUNAS];
    int matMultiplicacao[LINHAS][COLUNAS];
    // cria as caixas para os resultados de cada operação de conjunto matricial
    int uniao[TAMANHO_MAX_UNIAO];
    int intersecao[TAMANHO_VETOR];
    int diferenca_a_b[TAMANHO_VETOR];
    // cria as caixas para inicializar cada operação de conjunto matricial
    int tam_uniao = 0;
    int tam_intersecao = 0;
    int tam_diferenca = 0;

    int i, j, elemento;

    lerMatrizes(&conjuntoA, &conjuntoB); // chama a função de ler cada matriz

    printf("\n==================================\n");
    printf("   VISUALIZAÇÃO DAS MATRIZES DE ENTRADA"); // imprime as matrizes A e B de acordo com o que foi digitado de uma forma bonitinha :)
    printf("\n==================================");
    imprimirConjunto(conjuntoA); // usa a função para struct de A
    imprimirConjunto(conjuntoB); // usa a função para struct de B
    printf("\n==================================\n");

    // OPERAÇÕES ARITMÉTICAS (matriz)
    operacaoMatricial(&conjuntoA, &conjuntoB, matSoma, ADICAO);
    imprimirMatrizPura("SOMA (A + B)", matSoma);  // função "imprimirMatrizPura" para imprimir o resultado aritmético (que não está na struct) de soma

    operacaoMatricial(&conjuntoA, &conjuntoB, matSubtracao, SUBTRACAO);
    imprimirMatrizPura("SUBTRACAO (A - B)", matSubtracao); // função "imprimirMatrizPura" para imprimir o resultado aritmético (que não está na struct) de subtração

    operacaoMatricial(&conjuntoA, &conjuntoB, matMultiplicacao, MULTIPLICACAO);
    imprimirMatrizPura("MULTIPLICACAO (A * B)", matMultiplicacao); // função "imprimirMatrizPura" para imprimir o resultado aritmético (que não está na struct) de multiplicação

    // OPERAÇÕES DE CONJUNTO (vetor)
    tam_uniao = 0; // UNIÃO (A U B)
    for(i = 0; i < LINHAS; i++) {
        for(j = 0; j < COLUNAS; j++) {
            uniao[tam_uniao++] = conjuntoA.matriz[i][j];
        }
    }
    for(i = 0; i < LINHAS; i++) {
        for(j = 0; j < COLUNAS; j++) {
            uniao[tam_uniao++] = conjuntoB.matriz[i][j];
        }
    }
    imprimirResultadoConjunto("UNIAO (A + B)", uniao, tam_uniao, UNIAO);

    tam_intersecao = 0; // INTERSEÇÃO (A n B)
    for(i = 0; i < LINHAS; i++) {
        for(j = 0; j < COLUNAS; j++) {
            elemento = conjuntoA.matriz[i][j];
            if (contemElemento((int*)conjuntoB.matriz, TAMANHO_VETOR, elemento))
            {
                intersecao[tam_intersecao++] = elemento;
            }
        }
    }
    imprimirResultadoConjunto("INTERSECAO (A n B)", intersecao, tam_intersecao, INTERSECAO);

    tam_diferenca = 0; // DIFERENÇA (A - B)
    for(i = 0; i < LINHAS; i++) {
        for(j = 0; j < COLUNAS; j++) {
            elemento = conjuntoA.matriz[i][j];
            if (!contemElemento((int*)conjuntoB.matriz, TAMANHO_VETOR, elemento))
            {
                diferenca_a_b[tam_diferenca++] = elemento;
            }
        }
    }
    imprimirResultadoConjunto("DIFERENCA (A - B)", diferenca_a_b, tam_diferenca, DIFERENCA_A_B);

    return 0; // GG! <3
}




MANIPULAÇÃO DE ARQUIVOS EM C 

// levar dados da memória ram para um local onde não se perdesse eles mesmo com o fechamento do programa

.txt
arquivos binários 

- operações com arquivos;
1- Criar um novo arquivo
2- Abrir um arquivo existente
2.1- Ler e escrever dados num arquivo
3- Fechar um arquivo
Outras operações incluem:
1- Apagar um arquivo
2- Renomear um arquivo
3- Mover um arquivo para outra pasta
4- Copiar um arquivo para outra pasta ou local


Modo (txt) 		Modo (bin) 		Significado 							Comportamento se arquivo não existir
r 					rb 			Abre para leitura 						Se não existir retorna NULL
w 					wb 			Abre para escrita 						Se não existir é criado, se existir é sobrescrito
a 					ab 			Abre para acrescentar (append) 			Se não existir é criado
r+ 					rb+ 		Abre para leitura e escrita 			Se não existir retorna NULL
w+ 					wb+ 		Abre para leitura e escrita 			Se não existir é criado, se existir é sobrescrito
a+ 					ab+ 		Abre para leitura e acréscimo 			Se não existir é criado


FILE *arquivoPtr; // precisa criar um ponteiro do tipo file para cada arquivo que desejamos mamipular. 
// necessário para realizar a comunicação entre o programa e o arquivo

arquivoPtr = fopen(“nomeArquivo.ext”,”modo”); // fopen() - abre um arquivo

FILE *listaAlunosPtr;
listaAlunosPtr = fopen(“C:\\PastaTeste\\lista.txt”,”w”);

\\ - porque se fosse só uma \ e tivesse um arquivo com 'n', iria dar enter \n 

FILE *arquivoPtr;
arquivoPtr = fopen(“nomeArquivo.ext”,”modo”); // fclose() - fecha um arquivo 
fclose(arquivoPtr); // um arquivo .txt ou bin deve ser fechado sempre após realizadas as operações de leitura e/ou escrita

FILE *arquivoPtr;
arquivoPtr = fopen(“nomeArquivo.ext”,”modo”); // fscanf() e fprintf() - ler e escrever em um arquivo .txt
fscanf(arquivoPtr, “%...”, &variável);
fprintf((arquivoPtr, “%...”, variável);
fclose(arquivoPtr);



FILE *arqNumerosPtr; // sinalizar o ponteiro para o arquivo
int numero;
arqNumerosPtr = fopen(“bingo.txt”,”r”);
if (arqNumerosPtr != NULL)
{
	fscanf(arqNumerosPtr, “%d”, &numero);
	printf(“O número lido no arquivo é %d”, numero);
	fclose(arqNumerosPtr); // só fecho se eu conseguir abrir o arquivo, por isso deve estar aqui, "não pode fechar uma porta fechada"
	// se posto fora das '}' e o arquivo fosse NULL, iria dar erro
}


#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "portuguese-brazilian");

    FILE *arquivo;
    int numero = 79;
    arquivo = fopen("bingo.txt","a");
    if (arquivo != NULL) {
        fprintf(arquivo, "%d", numero); // gravar no arquivo um n inteiro da variavel
        printf(“O número lido no arquivo é %d”, numero);
        fclose(arquivo); // fechar o arquivo
    }
}


Criar uma lista com nome, nascimento e salario:

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "portuguese-brazilian");

    FILE *arquivo;
    char nome[51];        // 50 caracteres + \0
    char nascimento[11];  // DD/MM/AAAA + \0
    float salario;
   
    do {
        printf("\nInforme o nome: \n");
        fgets(nome, 51, stdin);
        nome[strcspn(nome, "\n")] = '\0';
        if (strcmp(nome, "sair") == 0 || strcmp(nome, "SAIR") == 0) {
            break; 
        }
        printf("Informe o nascimento (DD/MM/AAAA): \n");
        fgets(nascimento, 11, stdin);
        nascimento[strcspn(nascimento, "\n")] = '\0';

        printf("Informe o salario: \n");
        if (scanf("%f", &salario) != 1) {
            printf("Entrada de salário inválida. Encerrando.\n");
            break;
        } while (getchar() != '\n');

        arquivo = fopen("lista.txt", "a");
        if (arquivo != NULL) {
            fprintf(arquivo, "Nome: %s\tNascimento: %s\tSalario: %.2f\n", nome, nascimento, salario);
            fclose(arquivo);
        } else {
            printf("Erro ao abrir o arquivo lista.txt\n");
        }

    } while (1);

    return 0;
}



STREAM - é uma abstração para a comunicação de dados. 
Ao manipular arquivos em C, usamos um stream associado a esse arquivo no sistema operacional.

Para interagir com o arquivo é o ponteiro para a estrutura FILE 
FILE * -> Armazena informações sobre o stream, como a posição atual e o modo de acesso.

Funções Essenciais:
Função 		Descrição
fopen() 	Abre um arquivo, associando-o a um FILE *.
fclose() 	Fecha o arquivo, liberando o FILE * e garantindo que todos os dados foram escritos.
feof() 		Verifica se o fim do arquivo (EOF - End Of File) foi atingido.
ferror() 	Verifica se ocorreu um erro de leitura/escrita.

fprintf() - escreve string  
fputc() - escreve char


#include <locale.h>
#include <stdio.h>

void escrever_texto() { // fopen que atribui o valor para o fp 
	FILE *fp = fopen("alunos.txt", "w"); // Abre para escrita (sobrescreve)
	if (fp == NULL) {					// "a" - acrescenta
		printf("Erro ao abrir o arquivo!\n");
		return;
	}
	
	// escreve PRIMEIRO O PONTEIRO e DEPOIS A STRING
	fprintf(fp, "Nome: João Silva, Idade: 22\n"); // Escreve strings formatadas no arquivo
	fprintf(fp, "Nome: Maria Souza, Idade: 25\n");

	// escreve PRIMEIRO O CHAR e DEPOIS A STRING
	char c = 'F';
	fputc(c, fp); // Escreve o caractere 'F' (de Fim)
	fputc('\n', fp);
	fclose(fp);
	printf("Dados escritos em alunos.txt com sucesso.\n");
}
	
int main() {
	setlocale(LC_ALL, "portuguese-brazilian");

	escrever_texto();
}


fscanf() - leitura de string
fgetc() - leitura de char 


#include <locale.h>
#include <stdio.h>

#include <stdio.h>
void ler_texto() {
	FILE *fp = fopen("alunos.txt", "r"); // Abre para leitura
	if (fp == NULL) {
		printf("Arquivo não encontrado ou erro na abertura!\n");
		return;
	}
	char linha[100];
	/* Leitura caractere por caractere até o final do arquivo (EOF)
	printf("Conteúdo do arquivo:\n");
	int c; // pode colocar char c; -> relação com a lógica da tabela ASCII
	while ((c = fgetc(fp)) != EOF) { // lê 1 char do .txt até o último char ctl z = 26 e atribui ao char c
		putchar(c); // Exibe o caractere na tela
	} */
	// OU, para leitura formatada (como scanf):
	
	char nome[50];
	int idade;
	// Tenta ler até que a formatação não seja mais satisfeita (EOF), lê linha por linha
	while (fscanf(fp, "Nome: %[^,], Idade: %d\n", nome, &idade) == 2) { // lê até encontrar uma vírgula. iguala a 2 porque são duas variáveis
	printf("Lido -> Nome: %s, Idade: %d\n", nome, idade);
	} // não lê o 'F' pois 'F' = 1

	fclose(fp);
}
	
int main() {
	setlocale(LC_ALL, "portuguese-brazilian");

	ler_texto();
}



#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "portuguese-brazilian");

    char frase1[101];
    char frase2[101];
    FILE *arq;

    printf("Digite a primeira frase: \n");
    fgets(frase1, 101, stdin);
    frase1[strcspn(frase1,"\n")] = '\0';
    fflush(stdin);

    arq = fopen("frase.txt", "w");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo frase.txt");
        return 0;
    }
    fprintf(arq, frase1);
    fputc('\n', arq);
    fclose(arq);

    printf("Digite a segunda frase: \n");
    fgets(frase2, 101, stdin);
    frase2[strcspn(frase2,"\n")] = '\0';
    fflush(stdin);

    arq = fopen("frase.txt", "a");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo frase.txt");
        return 0;
    }
    fprintf(arq, frase2);
    fclose(arq);

    arq = fopen("frase.txt", "r");
    char c;
    while ((c = fgetc(arq))!= EOF)
        putchar(c);
    fclose(arq);
    return 0;
}



FUNÇÕES DE LEITURA E ESCRITA DE ARQUIVOS BINÁRIOS 

fread() - leitura
fwrite() - escrita 

utiliza blocos de bytes (memória)

size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);

size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);

- ptr: Ponteiro para os dados na memória.
- size: Tamanho de um item em bytes (geralmente sizeof(struct)).
- nmemb: Número de itens a serem lidos/escritos.
- stream: O ponteiro de arquivo (FILE *).


#include <stdio.h>
#include <stdlib.h> // Para exit()
// Estrutura que será salva no arquivo binário
typedef struct {
    int id;
    char nome[30];
    float nota;
} RegistroAluno;
void salvar_binario(RegistroAluno a) {
    FILE *fp = fopen("registros.bin", "wb");  // Modo "wb" (write binary)
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }
    // Escreve 1 elemento do tamanho de RegistroAluno, a partir do endereço &a
    size_t escritos = fwrite(&a, sizeof(RegistroAluno), 1, fp); // sizeof(registro alunos) = 40 bites
    if (escritos != 1) {
        printf("Erro na escrita binária!\n");
    } else {
        printf("Registro do aluno ID %d salvo em registros.bin.\n", a.id);
    }
    fclose(fp);
}
void carregar_binario() {
    RegistroAluno a_lido;
    FILE *fp = fopen("registros.bin", "rb"); // Modo "rb" (read binary)
    if (fp == NULL) {
        printf("Arquivo binário não encontrado!\n");
        return;
    }
    // Tenta ler 1 elemento do tamanho de RegistroAluno, para o endereço &a_lido
    size_t lidos = fread(&a_lido, sizeof(RegistroAluno), 1, fp);
    if (lidos == 1) {
        printf("\nRegistro lido:\n");
        printf("ID: %d\n", a_lido.id);
        printf("Nome: %s\n", a_lido.nome);
        printf("Nota: %.2f\n", a_lido.nota);
    } else {
        printf("Erro na leitura binária ou arquivo vazio.\n");
    }
    fclose(fp);
}
int main() {
    RegistroAluno aluno1 = {101, "Carlos Mendes", 8.5};
    printf("%d\n", sizeof(RegistroAluno)); // quantos bites preciso para armazenar na memoria, todos os blocos são iguais
    salvar_binario(aluno1);
    carregar_binario();
    return 0;
}



acessar dados em posições específicas em .bin: 

ftell(fp): Retorna a posição atual do ponteiro de arquivo (em bytes) a partir do início.
fseek(fp, offset, origin): Move o ponteiro de arquivo.
- offset: Número de bytes a mover.
- origin: Ponto de referência: SEEK_SET (início), SEEK_CUR (atual), SEEK_END(fim).
rewind(fp): Move o ponteiro para o início do arquivo (fseek(fp, 0, SEEK_SET)).

Para ler o N-ésimo registro em um arquivo binário de estruturas:
// Supondo que 'fp' está aberto em modo "rb"
int indice_registro = 2; // Queremos o 3º registro (índice 2)
long deslocamento = indice_registro * sizeof(RegistroAluno);
// Move o ponteiro: deslocamento a partir do início (SEEK_SET)
fseek(fp, deslocamento, SEEK_SET);
// Lê o registro na nova posição
fread(&a_lido, sizeof(RegistroAluno), 1, fp); 


// código para escrever mais registros de alunos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Estrutura que será salva no arquivo binário
typedef struct {
    int id;
    char nome[30];
    float nota;
} RegistroAluno;

void salvarArray_binario(RegistroAluno a[]) {
    FILE *fp = fopen("lista.bin", "wb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }
    size_t escritos = fwrite(a, sizeof(RegistroAluno), 3, fp);
    if (escritos != 3) {
        printf("Erro na escrita bin�ria!\n");
    } else {
        printf("Registro dos 3 alunos salvo em lista.bin.\n");
    }
    fclose(fp);
}

void carregarArray_binario() {
    RegistroAluno a_lido[3];
    FILE *fp = fopen("lista.bin", "rb");
    if (fp == NULL) {
        printf("Arquivo binário não encontrado!\n");
        return;
    }
    size_t lidos = fread(a_lido, sizeof(RegistroAluno), 3, fp);
    if (lidos == 3) {
        for (int a=0;a<lidos;a++)
        {
            printf("\n%d registro lido:\n",a+1);
            printf("ID: %d\n", a_lido[a].id);
            printf("Nome: %s\n", a_lido[a].nome);
            printf("Nota: %.2f\n", a_lido[a].nota);
        }
    } else {
        printf("Erro na leitura binária ou arquivo vazio.\n");
    }
    fclose(fp);
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "portuguese-brazilian");
    RegistroAluno alunos[3];

    alunos[0].id=109;
    strcpy(alunos[0].nome,"Joana das Orquideas");
    alunos[0].nota=7.8;

    alunos[1].id=114;
    strcpy(alunos[1].nome,"Pedro das Roseiras");
    alunos[1].nota=7.0;

    alunos[2].id=115;
    strcpy(alunos[2].nome,"Kelly das Violetas");
    alunos[2].nota=8.3;

    salvarArray_binario(alunos);
    carregarArray_binario();

    return 0;
}