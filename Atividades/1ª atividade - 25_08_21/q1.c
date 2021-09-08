#include <stdio.h>
#include <stdlib.h>


int main()
{
    
    /*
        nas 2 funções ("misterio1" e "misterio2") o loop recursivo continua ate somente atigir a quantidade 
        de caracteres existentente na string. 

        Na função "misterio1", é executado em ordem crescente ( posicões do array acessadas 0, 1, 2..) e verificado 
        se o caractere é "1". caso seja, é executado a operação "*dec = *dec + pow(2,i)", onde *dec foi 
        repassado como referencia para atualizar seu valor a cada chamada recursiva sem pendencia.

        Já na função "misterio2", diferente da função "misterio1", ocorre uma recursão com pendencia, 
        onde a função chega no "teto" da pilha de execução, para em seguida retornar a função
        e executar as operações pendentes. um efeito que se observa que a ordem de execução ocorre 
        de forma decresente (posicões do array acessadas 9, 8, 7..)
        
    
    */

    return 0;
}