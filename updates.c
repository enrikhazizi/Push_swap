
#include "push_swap.h"

static void    push_all_b(t_stack **stack_a, t_stack **stack_b, t_logs *logs)
{
    while (*stack_a)
        push_b(stack_a, stack_b, logs);
}

int seach_backwards(t_stack **stack_b, int bottom, int top)
{
    t_stack *ptr;
    int     i;

    i = 0;
    ptr = *stack_b;
    while (ptr->data >= bottom && ptr->data < top)
    {
        if (ptr->data == top - 1)
            return (top - i - 1);
        ptr = ptr->prev;
        ++i;
    }
    return (-1);
}

void    find_and_push(int index, t_stack **stack_b, t_stack **stack_a, t_logs *logs)
{
    int i;
    int size;

    size = get_list_size(stack_b);
    i = 0;
    if (index < size / 2)
        while (i <= size - index - 1)
        {
            rrotate_b(stack_b, logs);
            ++i;
        }
    else
        while (i <= index)
        {
            rotate_b(stack_b, logs);
            ++i;
        }    
    push_a(stack_a, stack_b, logs);
}

int search_forwards(t_stack **stack_b, int bottom, int top)
{
    t_stack *ptr;
    int     i;

    i = 0;
    ptr = *stack_b;
    while (ptr->data >= bottom && ptr->data < top)
    {
        if (ptr->data == top - 1)
            return (i);
        ptr = ptr->next;
        ++i;
    }
    return (-1);
}

void    chunk_sort_list(t_stack **stack_a, t_stack **stack_b, t_logs *logs)
{
    //pretend first half is done and to b we pass alrady chunked elements
    push_all_b(stack_a, stack_b, logs);

    print_list(*stack_b);

    //now pass to a and sort the bitch

    int size;
    int elements_of_chunk;
    int total_elements_of_chunk;
    int i;
    int index;
    t_stack *ptr;
    int top;

    //elements of the first chunk are not guaranteed to be full
        //if the total size of the stack % with thet total_elements_chunk gives zero then you give it full size
    //this is going to happen for every chunk
    //do this nr of chunks times
        elements_of_chunk = total_elements_of_chunk - (size % total_elements_of_chunk);
        while (elements_of_chunk >= 0)
        {
            top = get_list_size(*stack_b);
            i = search_backwards(stack_b, top - elements_of_chunk, top);
            if (i < 0)
                i = search_forwards(stack_b, top - elements_of_chunk, top);
            if (i >= 0)
                find_and_push(i, stack_b, stack_a, logs);
            --elements_of_chunk;
        }
        elements_of_chunk = total_elements_of_chunk;
}