#include "operations.h"

int sheetLevelsDepth(BST bst) // profundidade das folhas. maior e menor
{
    int max_depth = bstHeight(bst->root_node); // altura da arvore, logo é a maior profudidade de alguma folha
    int min_depth = max_depth;

    bstMinDepth(bst->root_node, 0, &min_depth); // captura a altura minima
    
    printf("\n Nivel de folha de MAIOR profundidade: %d", max_depth);
    printf("\n Nivel de folha de MENOR profundidade: %d", min_depth);

    return max_depth - min_depth;

}

void search(BST bst)
{
    const int elements_to_search[] = {0, 9, 99, 999, 1999, 29999};
    int i = 0;
    BSTNode node;
    printf("\n");

    time_t elapsed_search_time; // guarda o tempo inial
    double time; // guarda o tempo final

    for (i = 0; i < sizeof(elements_to_search) / sizeof(int); i++)
    {
        printf("\n[%6d] - ", elements_to_search[i]);

        elapsed_search_time = clock(); // inicia a contagem

        node = bstSeach(bst->root_node, elements_to_search[i]);
        time = ((double)elapsed_search_time)*1000/CLOCKS_PER_SEC; // finaliza a contagem

        printf("tempo de procura: %.1lf ns. ", time);
        
        if(node != NULL)
            printf("Encontrado");
        else 
            printf("Nao encontrado");
    }
    
}

bool contains(int value, int *array, int len) // guarda as diferenças, mais sem repetir para contagem
{
    bool contains = false;

    int i = 0;

    do
    {
        if (value == array[i])
            contains = true;
        i++;

    } while (i < len && !contains);
    
    return contains;
}

void showOccurrences(int *arr, int arr_len, int *diference_array, int arr_len2) // exibe a quantidade de repetiçoes de profundidade
{
    int i = 0;
    int j = 0;
    int count = 0;

    count = 0;

    for (i = 0; i < arr_len; i++)
    {
        for(j=0; j<arr_len2; j++)
        {
            if (arr[i] == diference_array[j])
                count++;
        }

        printf("\n diferenca de profundidade (%d) que ocorreram repetiu %d vezes", arr[i], count);
        count=0;
    }
}

void diferencesDepth(int *arr, int number_of_trees) // diferença de profundidade
{
    int i=0;
    int j = 0;
    int count = 0;
    int temp_arr[number_of_trees];
    int count2 = 0;

    for(i=0; i<number_of_trees; i++)
    {
        for (j = 0; j < number_of_trees; j++)
        {
            if(arr[i] == arr[j] && !contains(arr[i], temp_arr, count2))
            {
                temp_arr[count2] = arr[i];
                count2++;
            }
                
        }
        count = 0;
    }

    count = 0;

    showOccurrences(temp_arr, count2, arr, number_of_trees); // exibe as ocorrencias
    
}

void startInsertions(int number_of_trees, int number_of_elements, int data_range) // inicia as inserções
{
    BST tree = bstStart();
    srand(time(NULL));

    clock_t insertion_time; // tempo de inserção
    int i = 0;
    int j = 0;
    int number_generated = 0; // salva o numero gerado
    int diferences_depth[number_of_trees]; // guarda todas as difenças de profundidade

    double time;

    for (i = 1; i <= number_of_trees; i++)
    {
        printf("\nArvore [%d]\n", i);

        insertion_time = clock();

        for (j = 1; j <= number_of_elements; j++)
        {
            number_generated = rand() % data_range;
            tree->root_node = bstInsert(tree->root_node, number_generated);
        }

        time = ((double)insertion_time)*1000/CLOCKS_PER_SEC;

        diferences_depth[i-1] = sheetLevelsDepth(tree);

        printf("\n tempo de insercao: %.1lf ns", time);
        search(tree);
        printf("\n\n Total de elementos inseridos com sucesso e sem repeticoes: %d", bstCountNodes(tree->root_node));
        tree->root_node = bstDestroy(tree->root_node);
        
        printf("\n");    
    }

    diferencesDepth(diferences_depth, number_of_trees);
        
}