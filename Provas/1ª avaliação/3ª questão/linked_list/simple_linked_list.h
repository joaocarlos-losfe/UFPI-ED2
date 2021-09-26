#ifndef _LIST_H_
#define _LIST_H_

#include <stdbool.h>
#include "data.h"

struct List {
    unsigned size;
    Data head;
};
typedef struct List* List;

List listCreate();
List listDelete(List list);
void listAppend(List list, Data data);
bool listIsEmpty(List list);
void listInsertOrdered(List list, Data data);
void listInsert(List list, unsigned index, Data data);
Data listPop(List list);
Data listPopFront(List list);
void listPrint(List list);
void listPush(List list, Data data);
Data listRemove(List list, unsigned index);
Data listRemoveValue(List list, char *str_value);
Data listSeach(List list, char *wold);

#endif