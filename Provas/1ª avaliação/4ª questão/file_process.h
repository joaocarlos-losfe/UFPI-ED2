#ifndef __FILES__
#define __FILES__

#include "./AVL/avl.h"
#include "string.h"
#include "stdbool.h"

void separateWords(int *i, char *str_wolds, char *save_wold);
bool isChapter(char *str);
int processFile(char *path, AVL *chapter_tree);

#endif