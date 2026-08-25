#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prev;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;

}

void	rra(t_stack **a, t_config *config)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
	config->total_ops++;

}

void	rrb(t_stack **b, t_config *config)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
	config->total_ops++;

}

void	rrr(t_stack **a, t_stack **b, t_config *config)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write (1, "rrr\n", 4);
	config->total_ops++;

}