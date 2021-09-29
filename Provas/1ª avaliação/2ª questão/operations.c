#include "operations.h"

int RandomInteger(int min, int max)
{
    int k;
    
    k = (rand() % max) + min;
    return k;
}

double media(double arr[], int count)
{
    int i;
    double sum = 0;

    for(i=0; i<count; i++)
        sum += arr[i];

    return sum / count;    
}


int sheetLevelsDepth(AVL tree, int arr1[], int arr2[], int i)
{
    int max_depth = avlNodeHeight(tree->root_node);
    int min_depth = max_depth;

    avlMinDepth(tree->root_node, 0, &min_depth);
    
    printf("\n Nivel de folha de MAIOR profundidade: %d", max_depth);
    printf("\n Nivel de folha de MENOR profundidade: %d", min_depth);

    arr1[i] = max_depth;
    arr2[i] = min_depth; 

    return max_depth - min_depth;

}



void search(AVL tree)
{
    const int elements_to_search[] = {0, 9, 99, 999, 1999, 29000};
    int i = 0;
    AVLNode node;
    printf("\n");

    time_t elapsed_search_time;

    double time;

    double media_time[sizeof(elements_to_search) / sizeof(int)];

    for (i = 0; i < sizeof(elements_to_search) / sizeof(int); i++)
    {
        printf("\n[%6d] - ", elements_to_search[i]);

        elapsed_search_time = clock();
        node = avlSeach(tree->root_node, elements_to_search[i]);
        time = ((double)elapsed_search_time)*1000/CLOCKS_PER_SEC;
        printf("tempo de procura: %.0f ns. ", time);

        media_time[i] = time;
        
        if(node != NULL)
            printf("Encontrado");
        else 
            printf("Nao encontrado");
    }
    
    printf("\n\n Tempo medio de procura: %.0f ns.", media(media_time, sizeof(elements_to_search) / sizeof(int)));

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

void insert(AVL tree, int number_of_elements, int data_range)
{
    int i = 0;

    for (i = 1; i <= number_of_elements; i++)
    {
        tree->root_node = avlInsert(tree->root_node, RandomInteger(0, data_range));
    }
}

int mediaDepht(int arr[], int count)
{
    int sum = 0;
    int i;

    for(i=0; i<count; i++)
        sum+=arr[i];

    return sum / count;
}

void startInsertions(int number_of_trees, int number_of_elements, int data_range)
{
    AVL tree = avlStart();

    srand(time(NULL));

    clock_t insertion_time;
    int i = 0;
    int j = 0;
    
    int diferences_depth[number_of_trees];
    double media_time[number_of_trees];

    int media_maxHeight[number_of_trees]; // media das alturas maximas
    int media_minHeight[number_of_trees]; // media das alturas minimas


    double time = 0;

    for (i = 0; i < number_of_trees; i++)
    {
        printf("\nArvore [%d]\n", i+1);

        insertion_time = clock();
        insert(tree, number_of_elements, data_range);
        time = ((double)insertion_time)*1000/CLOCKS_PER_SEC;
        printf("\n tempo de insercao: %.0lf ms", time);
        media_time[i] = time;
        diferences_depth[i] = sheetLevelsDepth(tree, media_maxHeight, media_minHeight, i);
        
        search(tree);
        printf("\n\n Total de elementos inseridos com sucesso e sem repeticoes: %d", avlCountNodes(tree->root_node));
        tree->root_node = avlDestroy(tree->root_node);
        printf("\n");    
    }

    printf("\n Tempo medio das insercoes: %.0lf ns\n", media(media_time, number_of_trees));
    diferencesDepth(diferences_depth, number_of_trees);

    printf("\n\n Media das MAIORES profundidades: %d", mediaDepht(media_maxHeight, number_of_trees));
    printf("\n Media das MENORES profundidades: %d", mediaDepht(media_minHeight, number_of_trees));
    printf("\n");
        
}