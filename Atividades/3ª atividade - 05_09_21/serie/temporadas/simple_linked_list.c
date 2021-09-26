#include "simple_linked_list.h"
#include "string.h"

List listCreate() 
{
    List list = malloc(sizeof(struct List));
    list->size = 0;
    list->head = NULL;
    return list;
}

List listDelete(List list) 
{

    Data tmp = list->head;

    while (tmp != NULL) 
    {
        list->head = tmp->next;
        tmp = dataDelete(tmp);
        tmp = list->head;
    }

    free(list);
    list = NULL;
    return list;
}


void listAppend(List list, Data data) 
{

    Data current = list->head;
    Data previous = NULL;

    while (current != NULL) 
    {
        previous = current;
        current = current->next;
    }

    if(list->head == NULL) 
    {
        list->head = data;
    } 
    else if(previous == NULL) 
    {
        current->next = data;
    } else 
    {
        previous->next = data;
    }

    list->size++;
}

void listInsertOrdered(List list, Data data) 
{

    Data current = list->head;
    Data previous = NULL;

    while ((current!=NULL) && (current->numero < data->numero)) 
    {
        previous = current;
        current = current->next;
    }

    data->next = current;
    if (previous == NULL) 
    {
        list->head = data;
    } 
    else 
    {
        previous->next = data;
    }

    list->size++;
}

void listInsert(List list, unsigned index, Data data) 
{

    Data current = list->head;
    Data previous = NULL;

    while ((current!=NULL) && index > 0) 
    {
        previous = current;
        current = current->next;
        index--;
    }

    data->next = current;

    if (previous == NULL) 
    {
        list->head = data;
    } 
    else 
    {
        previous->next = data;
    }

    list->size++;
}

bool listIsEmpty(List list) 
{
    return list->head == NULL;
}

Data listPop(List list) 
{

    Data current = list->head;

    if (current != NULL) 
    {

        Data previous = NULL;

        while ((current->next != NULL)) 
        {
            previous = current;
            current = current->next;
        }

        if(previous == NULL) 
        {
            list->head = NULL;
        }
        else 
        {
            previous->next = NULL;
        }
        list->size--;
    }
    return current;
}

Data listPopFront(List list) 
{

    Data current = list->head;

    if (current != NULL) {
        list->head = current->next;
        list->size--;
    }
    return current;
}

void listPrint(List list) 
{
    if (listIsEmpty(list)) 
    {
        printf("empty list\n");
    } 
    else 
    {
        Data data = list->head;

        while(data != NULL) 
        {
            dataPrint(data);
            data = data->next;
        }
    }
}

void listPush(List list, Data data) 
{
    data->next = list->head;
    list->head = data;
    list->size++;
}

Data listRemove(List list, unsigned index) 
{

    Data current = list->head;

    if (current != NULL) {
        Data previous = NULL;
        while ((current->next != NULL) && (index > 0)) 
        {
            previous = current;
            current = current->next;
            index--;
        }

        if (previous == NULL) 
        {
            list->head = current->next;
        }else if(current != NULL) 
        {
            previous->next = current->next;
        }

        list->size--;
    }
    return current;
}

Data listRemoveValue(List list, int numero) 
{

    Data current = list->head;

    if (current != NULL) 
    {
        Data previous = NULL;

        while ((current != NULL) && current->numero != numero) 
        {
            previous = current;
            current = current->next;
        }

        if (previous == NULL) 
        {
            list->head = current->next;
            list->size--;
        } 
        else if (current != NULL) 
        {
            previous->next = current->next;
            list->size--;
        }
    }

    return current;
}

Data ListSeach(List list, int numero)
{
    Data current = list->head;

    if (current != NULL)
    {
        while (current!=NULL)
        {
            if(numero == current->numero)
                return current;

            current = current->next;
        }
        
    }
    
    return current;
    
}