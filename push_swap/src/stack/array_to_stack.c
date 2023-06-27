#include "stack.h"

t_stack *array_to_stack_backward(const int *array, int len, int is_a) {
    t_stack *top = NULL;

    for (int i = len - 1; i >= 0; i--) {
        t_stack *new_element = (t_stack *) malloc(sizeof(t_stack));
        new_element->data = array[i];
        new_element->index = i;
        new_element->score = 0;
        new_element->is_a = is_a;

        new_element->next = top;
        top = new_element;
    }

    return top;
}

int *stack_to_array(t_stack *stack, int len) {
    int *array = (int *) malloc(sizeof(int) * len);

    for (int i = 0; i < len; i++) {
        array[i] = stack->data;
        stack = stack->next;
    }

    return array;
}