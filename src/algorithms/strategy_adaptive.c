#include "push_swap.h"

void   strategy_adaptive(t_stack **a, t_stack **b)
{
    double disorder;
    if (is_sorted(*a))
        return ;
    disorder = compute_disorder(*a);
    if (disorder < 0.2)
        strategy_simple(a, b);
    else if (disorder < 0.5)
        strategy_medium(a, b);
    else
        strategy_complex(a, b);

}