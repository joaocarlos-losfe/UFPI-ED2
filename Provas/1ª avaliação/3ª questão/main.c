#include <stdlib.h>
#include <stdio.h>

#include "./BST/bst.h"
#include "file_process.h"
#include "operations.h"

void menu()
{
    printf("\n 0 - Sair");
    printf("\n 1 - Imprimir todas a palavras da unidade");
    printf("\n 2 - Imprimir todas as palavras em inglês equivalentes a uma palavra em português dada");
    printf("\n 3 - Remover uma determinada palavra em português de uma unidade");
    printf("\n >> ");
}

int main()
{
    BST chapter_tree[100];
    int i = 0, j = 0, op = 0;
    char wold[100];
    
    j = processFile("dicionario.txt", chapter_tree);

    do
    {
       menu();
       scanf("%d", &op);

       switch (op)
       {
       case 1:
            printf("Unidade : "); scanf("%d", &i);
            if(i-1 < 0 || i > j)
                printf("\n Unidade nao existe...\n");
            else
            {
                ShowAllNodes(chapter_tree[i-1]->root_node);
                printf("\n");
            }
            break;
        case 2:
            setbuf(stdin, NULL);
            printf("\n Palavra em portugues: "); scanf(" %[^\n]s", wold);
            op2(chapter_tree, j, wold);
            printf("\n");
            break;
        case 3:
            
            printf("\n Unidade para remover: "); scanf("%d", &i);
            setbuf(stdin, NULL);
            printf("\n Palavra portugues: "); scanf(" %[^\n]s", wold);

            if(i-1 < 0 || i > j)
                printf("\n Unidade nao existe...\n");
            else
            {
                op3(chapter_tree, i-1, wold);
            }

       default:
           break;
       }

    } while (op != 0);

    
    
    return 0;
}
