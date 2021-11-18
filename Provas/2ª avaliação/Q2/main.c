#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

#include "2_3Tree/dtt.h"
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
    DTT tree = dttStart();
    setlocale(LC_ALL, "Portuguese");
    tree->root = NULL;
    char var_temp[20];

    processFile("text.txt", &tree);
       
    int op;
    char str[20];
    
    DTNode temp_node;
    
    do
    {
        menu();
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            dttPrint(tree->root);
            break;

        case 2:

            setbuf(stdin, NULL);
            printf("palavra: "); scanf(" %[^\n]s", str);

            temp_node = dttSeach(tree->root, str);

            if(temp_node!= NULL)
            {
                printf("\nlinhas de texto em que a palavra foi usada: ");

                if(strcmp(str, temp_node->palavra_left) == 0)
                    listPrint(temp_node->linhasPalavraLeft);
                
                if(strcmp(str, temp_node->palavra_right) == 0)
                    listPrint(temp_node->linhasPalavraRight);
                
                printf("\n");
            }
            else
                printf("\npalavra não encontrada...");

            printf("\n");
            break;

        case 3:

            printf("palavra: "); scanf(" %[^\n]s", str);
            char temp_str [20];
            
            ddtInsert(NULL, &tree->root, str, var_temp);
            printf("inserido..\n");

            break;
        
        case 4:
            printf("palavra: "); scanf(" %[^\n]s", str);
            DTNode parent = NULL;
            dttDelete(&parent, &tree->root, str); // deleção somente da info em si;            
            printf("\n");
            break;
        default:
            break;
        }

        temp_node = NULL;

    } while (op != 0);

    
    return 0;
}