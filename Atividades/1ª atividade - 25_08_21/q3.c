#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "simple_linked_list_library/questao_3/data.h"
#include "simple_linked_list_library/questao_3/simple_linked_list.h"

bool isVogal(char *string)
{
    bool is_vogal = false;

    switch (string[0])
    {
    case 'A':
    case 'a':
        is_vogal = true;
        break;
    
    case 'E':
    case 'e':
        is_vogal = true;
        break;

    case 'I':
    case 'i':
        is_vogal = true;
        break;

    case 'O':
    case 'o':
        is_vogal = true;
        break;
    
    case 'U':
    case 'u':
        is_vogal = true;
        break;
    }

    return is_vogal;
}

void largerString(Data data_header, char *str)
{
    if(data_header != NULL)
    {
        if(strlen(data_header->str_value) > strlen(str))
        {
            strcpy(str, data_header->str_value);
        }
        data_header = data_header->next;
        
        largerString(data_header, str);
    }

}

int numberStartingVowel(Data data_head, int count)
{
    if (data_head != NULL)
    {
        
        if(isVogal(data_head->str_value) == true)
        {
            count += 1;
        }

        data_head = data_head->next;

        count = numberStartingVowel(data_head, count);
    }

    return count;
}

void newVectorStrings(Data data_head_of_list, List filtred_list)
{
    if(data_head_of_list!=NULL)
    {
        
        if(strlen(data_head_of_list->str_value) > 4 && data_head_of_list->str_value[0] >=65 && data_head_of_list->str_value[0] <=90)
        {
            Data temp_data = dataCreate();
            strcpy(temp_data->str_value, data_head_of_list->str_value);
            listAppend(filtred_list, temp_data);
        }
        
        data_head_of_list = data_head_of_list->next;

        newVectorStrings(data_head_of_list, filtred_list);
    }

}

void menu()
{
    printf("\n 0 - Sair");
    printf("\n 1 - Adicionar string");
    printf("\n 2 - devolver a string de maior tamanho");
    printf("\n 3 - devolver a quantidade de strings que iniciam com vogal");
    printf("\n 4 - devolver um vetor contendo somente as strings com tamanho >=4 e que iniciam com letra maiúscula\n : ");
}

int main()
{
    
    List strings = listCreate();

    List new_string_vector = listCreate();

    int op;
    char temp_str[100];
    int temp_count = 0;

    do
    {
        menu();
        scanf("%d", &op);

        switch (op)
        {

        case 1:
            printf("\n str: ");
            setbuf(stdin, NULL);
            scanf(" %[^\n]s", temp_str);

            Data temp_data = dataCreate();
            strcpy(temp_data->str_value, temp_str);

            listAppend(strings, temp_data);

            break;
        
        case 2:
            strcpy(temp_str, "");
            largerString(strings->head, temp_str);
            printf("\n string de maior tamanho: %s\n", temp_str);
            break;

        case 3:
            
            temp_count =  numberStartingVowel(strings->head, 0);
            printf("\n total: %d\n", temp_count);
            temp_count = 0;
            break;

        case 4:
            printf("\n");
            newVectorStrings(strings->head, new_string_vector);
            listPrint(new_string_vector);
            new_string_vector = listDelete(new_string_vector);
            new_string_vector = listCreate();
            printf("\n");
        
        default:
            break;
        }


    } while (op != 0);
    


    return 0;
}