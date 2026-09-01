#include "push_swap.h"

int   strategy_adaptive(t_stack **a, t_stack **b)
{
    double disorder;

    if (is_sorted(*a))
        return (0);
    disorder = compute_disorder(*a);
    if (disorder < 0.2)
        return (strategy_simple(a, b));
    else if (disorder < 0.5)
        return (strategy_medium(a, b));
    else
        return (strategy_complex(a, b));
}
