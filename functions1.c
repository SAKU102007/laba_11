#include "functions1.h"



OBJ* push(OBJ* top, int data)
{
    OBJ* ptr = malloc(sizeof(OBJ));
    ptr->data = data;
    ptr->next = top;
    return ptr;
}

OBJ* pop(OBJ* top)
{
    if(top == NULL)
        return top;

    OBJ* ptr_next = top->next;
    free(top);

    return ptr_next;
}

void show_stack(const OBJ* top)
{
    const OBJ* current = top;
    while(current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int input_stack_size()
{
    int number_of_elements_in_stack;
    while (1) {
        if (scanf("%d", &number_of_elements_in_stack) != 1 || number_of_elements_in_stack <= 0)
        {
            printf("Ошибка: Введите целое положительное число!\n");
            while (getchar() != '\n');
            continue;
        }
        break;
    }
    return number_of_elements_in_stack;
}

OBJ* input_stack_elements(int stack_size)
{
    OBJ *top = NULL;
    int element_of_stack;
    for (int i = 0; i < stack_size; i++)
    {
        printf("Введите %d элемент стека: ", i+1);
        while (1)
        {
            if (scanf("%d", &element_of_stack) != 1)
            {
                printf("Ошибка: Введите целое число!\n");
                while (getchar() != '\n');
                continue;
            }
            break;
        }
        top = push(top, element_of_stack);
    }
    return top;
}

int find_max_element(OBJ* top)
{
    int max_element;
    OBJ *current = top;
    max_element = current->data;
    current = current->next;
    while (current != NULL)
    {
        if (current->data > max_element)
            max_element = current->data;
        current = current->next;
    }
    return max_element;
}

int sum_after_max(OBJ* top, int max_element)
{
    OBJ *cur = top;
    int sum = 0;
    while (cur != NULL)
    {
        if (cur->data == max_element)
        {
            cur = cur->next;
            while (cur != NULL)
            {
                sum += cur->data;
                cur = cur->next;
            }
            break;
        }
        cur = cur->next;
    }
    return sum;
}

OBJ* delete_stack(OBJ* top)
{
    while(top) {
        top = pop(top);
    }

    if (top == NULL) {
        printf("Стек успешно удален.\n");
    }

    return top;
}
