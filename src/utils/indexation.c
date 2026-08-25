#include "../../includes/push_swap.h"

static t_stack	*get_next_min(t_stack *stack)
{
	t_stack *min_node;
	t_stack *current;

	min_node = NULL;
	current = stack;
	while (current)
	{
		if (current->index == -1)
		{
			if (!min_node || current->value < min_node->value)
				min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}

void	index_stack(t_stack *stack)
{
	t_stack *min_node;
	int		index;

	index = 0;
	min_node = get_next_min(stack);
	while (min_node)
	{
		min_node->index = index++;
		min_node = get_next_min(stack);
	}

}
