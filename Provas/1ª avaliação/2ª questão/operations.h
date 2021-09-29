#include <stdio.h>
#include <stdlib.h>

#include "./AVL/avl.h"
#include <time.h>

int sheetLevelsDepth(AVL tree, int arr1[], int arr2[], int i);
void search(AVL tree);
void startInsertions(int number_of_trees, int number_of_elements, int data_range);