#include <stdio.h>
#include <stdlib.h>

void divisores(int n, int i)
{
    if (i <= n)
    {
        if(n % i == 0)
        {
            printf("%d\n", n / i);
        }
        
        divisores(n, i+1);
    }
}

int main()
{
    
    printf("Numero para mostrar seus divisores");
    int numero; scanf("%d", &numero);

    printf("\n");

    divisores(numero, 1);

    return 0;
}