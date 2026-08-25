#include "push_swap.h"

double	compute_disorder(t_stack *stack)
{
	t_stack *i;
	t_stack *j;
	double mistakes;
	double total_pairs;

	if (!stack || !stack->next)
		return (0.0);
	mistakes = 0.0;
	total_pairs = 0.0;
	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs += 1.0;
			if (i->value > j->value)
				mistakes += 1.0;
			j = j->next;
		}
		i = i->next;
	}
	return(mistakes / total_pairs);

}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}