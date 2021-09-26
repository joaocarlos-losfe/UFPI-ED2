#include <stdio.h>
#include <stdlib.h>

#include "./BST/bst.h"
#include "operations.h"

void menu()
{
    printf("\n\n0 - sair");
    printf("\n1 - Alterar parametros pre definidos");
    printf("\n2 - rodar simulacao");
    printf("\n>> ");
}

int main()
{
    
    BST tree = bstStart();
    
    srand(time(NULL));
    
    int total_trees = 30; // total de arvores
    int number_of_elements = 1060; // numero de elementos para inserção
    int data_range = number_of_elements * 10; // range da função rand  
    int op = 0;
    int i = 0;

    do
    {
        menu();
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\n\n Numero de arvores: "); scanf("%d", &total_trees);
            printf("\n Numero de elementos para insercao: "); scanf("%d", &number_of_elements);
            printf("\n Range dos dados: 0 ate "); scanf("%d", &data_range);
            break;
        
        case 2:
            printf("\n rodando simulacao [BST]...\n");
            startInsertions(total_trees, number_of_elements, data_range);
            printf("\n\ntotal de arvores [%d]. Numero de elementos [%d]. Range [%d] \n", total_trees, number_of_elements, data_range);
            break;
        default:
            break;
        }
        
    } while (op != 0);
    
    return 0;
}