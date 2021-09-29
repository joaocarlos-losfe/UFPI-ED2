#include "operations.h"

void printEnWold(AVLNode root_node, char *wold_e)
{
    if (root_node != NULL)
	{   
        if(listSeach(root_node->list, wold_e) != NULL)
        {
            printf("\n %s", root_node->key);
        }
                
		printEnWold(root_node->left, wold_e);
		printEnWold(root_node->right, wold_e);
	}
}

void op2(AVL arr_tree[], int total_chapter, char *wold_e)
{
    int i = 0;

    for (i = 0; i < total_chapter; i++)
    {
        if (arr_tree[i]->root_node != NULL)
            printEnWold(arr_tree[i]->root_node, wold_e);
    }
    
}

void op3(AVL arr_tree[], int chapter, char *wold_p)
{    
    if(listSeach(arr_tree[chapter]->root_node->list, wold_p)  != NULL)
    {
        arr_tree[chapter]->root_node = avlNodeDelete(arr_tree[chapter]->root_node, arr_tree[chapter]->root_node->key);
    }
}