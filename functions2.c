#include "functions2.h"



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
    printf("\n");
}

int input_stack_size()
{
    int number_of_elements_in_stack;
    while (1) {
        if (scanf("%d", &number_of_elements_in_stack) != 1 || number_of_elements_in_stack <= 0)
        {
            printf("Ошибка: Введите целое неотрицательное число!\n");
            while (getchar() != '\n');
            continue;
        }
        break;
    }
    return number_of_elements_in_stack;
}

OBJ* input_stack_elements(int stack_size, int choose)
{
    OBJ *top = NULL;
    int one_element_of_stack;
    int other_element_of_stack;

    printf("Введите 1 элемент стека: ");
            while (1)
            {
                if (scanf("%d", &one_element_of_stack) != 1)
                {
                    printf("Ошибка: Введите целое число!\n");
                    while (getchar() != '\n');
                    continue;
                }
                break;
            }
    top = push(top, one_element_of_stack);

    switch (choose)
    {
    case 1:
        for (int i = 1; i < stack_size; i++)
        {
            printf("Введите %d элемент стека: ", i+1);
            while (1)
            {
                if (scanf("%d", &other_element_of_stack) != 1 || other_element_of_stack > one_element_of_stack)
                {
                    printf("Ошибка: Введите целое число, которое меньше предыдущего введенного\n");
                    printf("Введите %d элемент стека: ", i+1);
                    while (getchar() != '\n')
                        ;
                    continue;
                }
                break;
            }
            top = push(top, other_element_of_stack);
        }
        printf("\n");
        return top;
    case 2:
        for (int i = 1; i < stack_size; i++)
        {
            printf("Введите %d элемент стека: ", i+1);
            while (1)
            {
                if (scanf("%d", &other_element_of_stack) != 1 || other_element_of_stack < one_element_of_stack)
                {
                    printf("Ошибка: Введите целое число, которое больше предыдущего введенного\n");
                    printf("Введите %d элемент стека: ", i+1);
                    while (getchar() != '\n');
                    continue;
                }
                break;
            }
            top = push(top, other_element_of_stack);
        }
        printf("\n");
        return top;
    default:
        return NULL; // но это невозможно
    }
}



OBJ* create_third_stack(OBJ* top_1, OBJ* top_2)
{
    OBJ* top_3 = NULL;
    int limit = 2147483647;

    while(1)
    {
        int count = 0;
        int max_element = -2147483648;

        OBJ* current = top_1;
        while (current != NULL) {
            if (current->data <= limit) {
                if (current->data > max_element) {
                    max_element = current->data;
                    count = 1;
                } else if (current->data == max_element) {
                    count++;
                }
            }
            current = current->next;
        }

        current = top_2;
        while (current != NULL) {
            if (current->data <= limit) {
                if (current->data > max_element) {
                    max_element = current->data;
                    count = 1;
                } else if (current->data == max_element) {
                    count++;
                }
            }
            current = current->next;
        }

        // printf("Максимальный элемент: %d, количество: %d\n", max_element, count);

        for (int i = 0; i < count; i++)
            top_3 = push(top_3, max_element);

        limit = max_element - 1;

        if (count == 0)
            break;
    }
    return top_3;
}


OBJ* delete_stack(OBJ* top)
{
    while(top)
        top = pop(top);

    // if (top == NULL)
    //     printf("Стек успешно удален.\n");

    return top;
}
