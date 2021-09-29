#include <stdio.h>
#include <stdlib.h>

#include "./BST/bst.h"
#include "sys/time.h"



int RandomInteger(int low, int high);
int sheetLevelsDepth(BST bst, int arr1[], int arr2[], int i);
void search(BST bst);
void startInsertions(int number_of_trees, int number_of_elements, int data_range);
