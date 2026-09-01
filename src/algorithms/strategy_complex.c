#include "push_swap.h"

static int get_max_bits(t_stack *a)
{
    int max_idx;
    int max_bits;

    max_idx = stack_size(a) - 1;
    max_bits = 0;
    while ((max_idx >> max_bits) > 0)
        max_bits++;
    return (max_bits);

}
static int process_bit_level(t_stack **a, t_stack **b, int bit, int size)
{
    int     ops;
    int     j;

    ops = 0;
    j = 0;
    while (j < size)
    {
        if ((((*a)->index >> bit) & 1) == 1)
        {
            ra(a);
            ops++;
        }
        else
        {
            pb(a, b);
            ops++;
        }
        j++;
    }
    while (*b && ++ops)
        pa(a, b);
    return (ops);
}
int    strategy_complex(t_stack **a, t_stack **b)
{
    int    bit;
    int    max_bits;
    int    size;
    int    ops;

    size = stack_size(*a);
    max_bits = get_max_bits(*a);
    bit = 0;
    ops = 0;
    while (bit < max_bits)
    {
        ops += process_bit_level(a, b, bit, size);
        bit++;
    }
    return (ops);
}
