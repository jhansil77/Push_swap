#include "push_swap.h"

static int  ft_sqrt(int n)
{
    int i;

    i = 1;
    if (n <= 0)
        return (0);
    while (i * i <= n)
        i++;
    return (i - 1);

}

static int push_chunks_to_b(t_stack **a, t_stack **b, int chunk_size)
{
    int     i;
    int    ops;

    ops = 0;
    i = 0;
    while (*a)
    {
        if ((*a)->index <= i)
        {
            pb(a, b);
            rb(b);
            ops += 2;
            i++;
        }
        else if ((*a)->index <= i + chunk_size)
        {
            pb(a, b);
            ops++;
            i++;
        }
        else
        {
            ra(a);
            ops++;
        }
    }
    return (ops);
}

static int push_back_to_a(t_stack **a, t_stack **b)
{
    int     max_idx;
    int     ops;

    ops = 0;
    while (*b)
    {
        max_idx = stack_size(*b) - 1;
        while ((*b)->index != max_idx)
        {
            if (get_min_pos(*b, max_idx) <= stack_size(*b) / 2)
                rb(b);
            else
                rrb(b);
            ops++;
        }
        pa(a, b);
        ops++;
    }
    return (ops);
}

int    strategy_medium(t_stack **a, t_stack **b)
{
    int     chunk_size;
    int     ops;

    ops = 0;
    chunk_size = ft_sqrt(stack_size(*a));
    if (chunk_size < 1)
        chunk_size = 1;
    ops = push_chunks_to_b(a, b, chunk_size);
    ops += push_back_to_a(a, b);
    return (ops);

}
