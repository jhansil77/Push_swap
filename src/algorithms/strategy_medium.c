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

static void push_chunks_to_b(t_stack **a, t_stack **b, int chunk_size,
		t_config *config)
{
    int     i;

    i = 0;
    while (*a)
    {
        if ((*a)->index <= i)
        {
            pb(a, b, config);
            rb(b, config);
            i++;
        }
        else if ((*a)->index <= i + chunk_size)
        {
            pb(a, b, config);
            i++;
        }
        else
            ra(a, config);
    }
}

void    strategy_medium(t_stack **a, t_stack **b, t_config *config)
{
    int     chunk_size;
    int     max_idx;

    chunk_size = ft_sqrt(stack_size(*a));
    if (chunk_size < 1)
        chunk_size = 1;
    push_chunks_to_b(a, b, chunk_size, config);
    while (*b)
    {
        max_idx = stack_size(*b) - 1;
        while ((*b)->index != max_idx)
        {
            if (get_min_pos(*b, max_idx) <= stack_size(*b) / 2)
                rb(b, config);
            else
                rrb(b, config);
        }
        pa(a, b, config);
    }
}