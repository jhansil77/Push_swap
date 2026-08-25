#include "push_swap.h"

void	sort_three(t_stack **a, t_config *config)
{
	int	top;
	int	mid;
	int	bot;

	if (is_sorted(*a))
		return ;
	top = (*a)->index;
	mid = (*a)->next->index;
	bot = (*a)->next->next->index;
	if (top > mid && mid < bot && top < bot)
		sa(*a, config);
	else if (top > mid && mid > bot)
	{
		sa(*a, config);
		rra(a, config);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a, config);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(*a, config);
		ra(a, config);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a, config);

}

int	get_min_pos(t_stack *a, int target_index)
{
	int	pos;
	pos = 0;
	while (a)
	{
		if (a->index == target_index)
			return (pos);
		pos++;
		a = a->next;
	}
	return (0);

}

static void	push_min_to_b(t_stack **a, t_stack **b, int target_index,
		t_config *config)
{
	int	pos;
	int	size;

	pos = get_min_pos(*a, target_index);
	size = stack_size(*a);
	if (pos <= size / 2)
	{
		while ((*a)->index != target_index)
			ra(a, config);
	}
	else
	{
		while ((*a)->index != target_index)
			rra(a, config);
	}
	pb(a, b, config);

}

void	sort_small(t_stack **a, t_stack **b, t_config *config)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
	{
		if ((*a)->index > (*a)->next->index)
			sa(*a, config);
		return ;
	}
	if (size == 4)
		push_min_to_b(a, b, 0, config);
	else if (size == 5)
	{
		push_min_to_b(a, b, 0, config);
		push_min_to_b(a, b, 1, config);
	}
	sort_three(a, config);
	while (*b)
		pa(a, b, config);

}