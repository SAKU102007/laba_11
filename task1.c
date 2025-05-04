// 01.05.2025

// Сакута

// 4. Создать стек для целых чисел. Максимальный размер стека вводится с экрана. Найти сумму
// после максимального элемента стека.

#include "functions1.h"



int main(void) 
{
    OBJ *top = NULL;
    
    printf("Введите максимальный размер стека: ");
    int stack_size = input_stack_size();
    
    top = input_stack_elements(stack_size);
    
    int max_element = find_max_element(top);
    printf("Максимальный элемент стека: %d\n", max_element);
    
    int sum = sum_after_max(top, max_element);
    printf("Сумма элементов после максимального: %d\n", sum);
    
    printf("Вывод элементов стека:\n");
    show_stack(top);
    
    top = delete_stack(top);

    return 0;
}
