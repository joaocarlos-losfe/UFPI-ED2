#ifndef __FILES__
#define __FILES__

#include "./BST/bst.h"
#include "string.h"
#include "stdbool.h"

void separateWords(int *i, char *str_wolds, char *save_wold); // separa as palavras da frase
bool isChapter(char *str); // verifica se é unidade
int processFile(char *path, BST *chapter_tree);

#endif