#include "push_swap.h"

void	free_mem(t_moves *moves)
{
     t_moves *tmp;

    while (moves)
    {
        tmp = moves->next;
        free(moves);
        moves = tmp;
    }

}

void	free_doubly(t_stack *head)
{
    if (!head)
        return;

    t_stack *tmp;
    t_stack *current = head->next;

    while (current != head)
    {
        tmp = current->next;
        free(current);
        current = tmp;
    }
    free(head);
}