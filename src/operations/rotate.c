#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack *first;
	t_stack *last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = stack_last(*stack);
	*stack = first->next;
	first->next = NULL;
	last->next = first;

}

void	ra(t_stack **a, t_config *config)
{
	rotate(a);
	write(1, "ra\n", 3);
	config->total_ops++;

}

void	rb(t_stack **b, t_config *config)
{
	rotate(b);
	write(1, "rb\n", 3);
	config->total_ops++;

}

void	rr(t_stack **a, t_stack **b, t_config *config)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	config->total_ops++;

}