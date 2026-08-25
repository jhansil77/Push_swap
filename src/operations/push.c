#include "push_swap.h"

static void	push(t_stack **src, t_stack **dest)
{
	t_stack *tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;

}

void	pa(t_stack **a, t_stack **b, t_config *config)
{
	push(b, a);
	write(1, "pa\n", 3);
	config->total_ops++;

}

void	pb(t_stack **a, t_stack **b, t_config *config)
{
	push(a, b);
	write(1, "pb\n", 3);
	config->total_ops++;

}
