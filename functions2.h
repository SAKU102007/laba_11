#ifndef FUNCTIONS2_H
#define FUNCTIONS2_H

#include <stdio.h>
#include <stdlib.h>


typedef struct tag_obj
{
    int data;
    struct tag_obj* next;
} OBJ;

OBJ* push(OBJ* top, int data);
OBJ* pop(OBJ* top);
void show_stack(const OBJ* top);
int input_stack_size();
OBJ* input_stack_elements(int stack_size, int choose);
OBJ* create_third_stack(OBJ* top_1, OBJ* top_2);
OBJ* delete_stack(OBJ* top);

#endif
