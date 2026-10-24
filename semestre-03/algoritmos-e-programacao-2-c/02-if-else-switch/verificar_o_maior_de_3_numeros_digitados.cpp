#include <stdio.h>
#include <locale.h>

int main(int arg, char *argv[])
{
	setlocale(LC_ALL, "portuguese-brazilian");

    int num1, num2, num3;
    
    if (num1 == num2 && num2 == num3); {
    	scanf("%d%d%d",&num1, &num2, &num3);
	}
    else if (num1 >= num2 && num1 >= num3) {
    	printf("%d é o maior.\n", num1)
	}	
    else if (num2 >= num1 && num2 >= num3) {
    	printf("%d é o maior.\n", num2);	
    }
    else {
    	printf("%d é o maior.\n", num3);
	}
		 
	  return 0;
}

