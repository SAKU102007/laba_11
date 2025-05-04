// 02.05.2025

// Сакута

// 4. Создать два стека для целых чисел. Первый стек – организовать ввод по убыванию, второй
// стек – организовать ввод по возрастанию. Без сортировок и переворачивания исходных
// стеков сформировать третий стек упорядоченный по убыванию

#include "functions2.h"



int main(void) 
{
    OBJ *top_1 = NULL;
    OBJ *top_2 = NULL;
    OBJ *top_3 = NULL;
    
    printf("Введите максимальный размер 1-ого стека: ");
    int stack_size_1 = input_stack_size();
    top_1 = input_stack_elements(stack_size_1, 1);
    // printf("Вывод элементов 1 стека:\n");
    // show_stack(top_1);

    printf("Введите максимальный размер 2-ого стека: ");
    int stack_size_2 = input_stack_size();
    top_2 = input_stack_elements(stack_size_2, 2);
    // printf("Вывод элементов 2 стека:\n");
    // show_stack(top_2);

    top_3 = create_third_stack(top_1, top_2);
    printf("Вывод элементов 3 стека:\n");
    show_stack(top_3);

    top_1 = delete_stack(top_1);
    top_2 = delete_stack(top_2);
    top_3 = delete_stack(top_3);

    return 0;
}
