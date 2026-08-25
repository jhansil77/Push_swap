#include "push_swap.h"

void    strategy_complex(t_stack **a, t_stack **b)
{
    int    size;
    int    max_bits;
    int    i;
    int    j;

    size = stack_size(*a);
    max_bits = 0;
    while ((size - 1) >> max_bits != 0)
        max_bits++;
    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            if ((((*a)->index >> i) & 1) == 1)
                ra(a);
            else
                pb(a, b);
            j++;
        }
        while (*b)
            pa(a, b);
        i++;
    }
}