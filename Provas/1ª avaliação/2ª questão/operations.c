#include "operations.h"


int sheetLevelsDepth(AVL tree)
{
    int greater_depth = avlHeight(tree->root_node);
    int smaller_depth = greater_depth;

    bstMinDepth(tree->root_node, 0, &smaller_depth);
    
    printf("\n Nivel de folha de MAIOR profundidade: %d", greater_depth);
    printf("\n Nivel de folha de MENOR profundidade: %d", smaller_depth);

    return greater_depth - smaller_depth;

}

void search(AVL tree)
{
    const int elements_to_search[] = {0, 9, 99, 999, 1999};
    int i = 0;
    AVLNode node;
    printf("\n");

    time_t elapsed_search_time;

    double runtime;

    for (i = 0; i < sizeof(elements_to_search) / sizeof(int); i++)
    {
        printf("\n[%6d] - ", elements_to_search[i]);

        elapsed_search_time = clock();

        node = avlSeach(tree->root_node, elements_to_search[i]);
        runtime = ((double)elapsed_search_time)*1000/CLOCKS_PER_SEC;
        printf("tempo de procura: %f. ", runtime);
        
        if(node != NULL)
            printf("Encontrado");
        else 
            printf("Nao encontrado");
    }
    
}

bool contains(int value, int *array, int len)
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

void showOccurrences(int *arr, int arr_len, int *diference_array, int arr_len2)
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

        printf("\n [%d] repetiu %d vezes", arr[i], count);
        count=0;
    }
}

void diferencesDepth(int *arr, int number_of_trees)
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

    showOccurrences(temp_arr, count2, arr, number_of_trees);
    
}

void startInsertions(int number_of_trees, int number_of_elements, int data_range)
{
    AVL tree = avlStart();

    srand(time(NULL));

    clock_t elapsed_insertion_time;
    int i = 0;
    int j = 0;
    
    int diferences_depth[number_of_trees];
    int number_generated = 0;
    double runtime;

    for (i = 1; i <= number_of_trees; i++)
    {
        
        printf("\nArvore [%d]\n", i);

        elapsed_insertion_time = clock();

        for (j = 1; j <= number_of_elements; j++)
        {
            number_generated = rand() % data_range;
            tree->root_node = avlInsert(tree->root_node, number_generated);
            //printf("\r inserindo elemento: %5d (%.2d %% concluidos)", number_generated,  ((j * 100) / number_of_elements));
        }

        runtime = ((double)elapsed_insertion_time)*1000/CLOCKS_PER_SEC;

        diferences_depth[i-1] = sheetLevelsDepth(tree);
        printf("\n tempo de insercao: %lf ms", runtime);
        search(tree);
        printf("\n\n Total de elementos inseridos com sucesso e sem repeticoes: %d", avlCountNodes(tree->root_node));
        tree->root_node = avlDestroy(tree->root_node);
        printf("\n");    
    }

    diferencesDepth(diferences_depth, number_of_trees);
        
}