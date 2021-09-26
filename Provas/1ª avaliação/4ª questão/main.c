#include <stdio.h>
#include <stdlib.h>

#include "./AVL/avl.h"
#include "file_process.h"
#include "operations.h"

void menu()
{
    printf("\n 0 - Sair");
    printf("\n 1 - Imprimir todas a palavras da unidade");
    printf("\n 2 - Imprimir todas as palavras em ingles equivalentes a uma palavra em portugues dada");
    printf("\n 3 - Remover uma determinada palavra em portugues de uma unidade");
    printf("\n >> ");
}

int main()
{
    AVL chapter_tree[100];
    int i, j, op;
    char wold[100];

    j = processFile("dicionario.txt", chapter_tree);
    
    do
    {
       menu();
       scanf("%d", &op);

       switch (op)
       {
       case 1:
            printf("\n Unidade : "); scanf("%d", &i);
            if(i-1 < 0 || i > j)
                printf("\n Unidade nao existe...\n");
            else
            {
                printf("\n");
                avlPrint(chapter_tree[i-1]->root_node);
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
            break;

       default:
           break;
       }

    } while (op != 0);
    
    return 0;
}