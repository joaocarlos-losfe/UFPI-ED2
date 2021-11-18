#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "./RedBlackTree/rbt.h"
#include "file.h"

void menu()
{
    printf("\n 1 - imprimir todas as palavras do texto");
    printf("\n 2 - buscar uma palavra");
    printf("\n 3 - acrescentar uma palavra");
    printf("\n 4 - excluir uma palavra");
    printf("\n>> ");
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    RBT tree;
	tree = rbtStart();
    processFile("text.txt", &tree);
    char str[20];
    int op;
    RBTNode temp_node = NULL;

    do
    {
        menu();
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            rbtPrint(tree->root_node);
            break;

        case 2:

            setbuf(stdin, NULL);
            printf("palavra: "); scanf(" %[^\n]s", str);
            temp_node = rbtNodeSearch(tree->root_node, str);

            if(temp_node!= NULL)
            {
                printf("\nlinhas de texto em que a palavra foi usada: ");
                listPrint(temp_node->linhas);
            }
            else
                printf("\npalavra não encontrada...");

            printf("\n");
            break;

        case 3:
            setbuf(stdin, NULL);
            printf("palavra: "); scanf(" %[^\n]s", str);
            tree->root_node = rbtInsert(tree->root_node, str);
            printf("\ninserido...\n");
            break;
        
        case 4:
            setbuf(stdin, NULL);
            printf("palavra: "); scanf(" %[^\n]s", str);

            if(rbtRemove(&tree->root_node, str))
            {
                printf("\nremovido...");
            }
            else
                printf("\npalavra não encontrada...");
            
            printf("\n");
            break;
        default:
            break;
        }

        temp_node = NULL;

    } while (op != 0);
    

    /*
	tree->root_node = rbtInsert(tree->root_node, "c");
	tree->root_node = rbtInsert(tree->root_node, "d");
	tree->root_node = rbtInsert(tree->root_node, "a");
	tree->root_node = rbtInsert(tree->root_node, "g");
	tree->root_node = rbtInsert(tree->root_node, "u");

    Data linha = dataCreate();
    linha->linha = 0;

    RBTNode node = rbtNodeSearch(tree->root_node, "c");
    listInsertOrdered(node->linhas, linha);

    linha = dataCreate();
    linha->linha = 5;
    listInsertOrdered(node->linhas, linha);
    
    */

    
    printf("compilado...\n");
    return 0;
}