#include "push_swap.h"

static int  find_min_pos(t_stack *a)
{
    t_stack *tmp;
    int     min_idx;
    int     min_pos;
    int     pos;

    tmp = a;
    min_idx = tmp->index;
    min_pos = 0;
    pos = 0;
    while (tmp)
    {
        if (tmp->index < min_idx)
        {
            min_idx = tmp->index;
            min_pos = pos;
        }
        pos++;
        tmp = tmp->next;
    }
    return (min_pos);

}

int    strategy_simple(t_stack **a, t_stack **b)
{
    int     pos;
    int    size;

    while (stack_size(*a) > 3 && !is_sorted(*a))
    {
        pos = find_min_pos(*a);
        size = stack_size(*a);
        if (pos <= size / 2)
        {
            while (pos-- > 0)
                ra(a);
        }
        else
        {
            while (pos++ < size)
                rra(a);
        }
        pb(a, b);
    }
    if (!is_sorted(*a))
        sort_three(a);
    while (*b)
        pa(a, b);
}
