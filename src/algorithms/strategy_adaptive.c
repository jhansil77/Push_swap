#include "push_swap.h"

void   strategy_adaptive(t_stack **a, t_stack **b, t_config *config)
{
    double disorder;
    if (is_sorted(*a))
        return ;
    disorder = compute_disorder(*a);
    if (disorder < 0.2)
        strategy_simple(a, b, config);
    else if (disorder < 0.5)
        strategy_medium(a, b, config);
    else
        strategy_complex(a, b, config);

}