#ifndef FUNCTIONS1_H
#define FUNCTIONS1_H

#include <stdio.h>
#include <stdlib.h>

typedef struct tag_obj {
    int data;
    struct tag_obj* next;
} OBJ;

OBJ* push(OBJ* top, int data);
OBJ* pop(OBJ* top);
void show_stack(const OBJ* top);
int input_stack_size();
OBJ* input_stack_elements(int stack_size);
int find_max_element(OBJ* top);
int sum_after_max(OBJ* top, int max_element);
OBJ* delete_stack(OBJ* top);


#endif
