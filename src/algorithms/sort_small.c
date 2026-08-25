#include "../../includes/push_swap.h"

void	sort_three(t_stack **a)
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
		sa(*a);
	else if (top > mid && mid > bot)
	{
		sa(*a);
		rra(*a);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(*a);
		ra(*a);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(*a);

}

static int	get_min_pos(t_stack *a, int target_index)
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

static void	push_min_to_b(t_stack **a, t_stack **b, int target_index)
{
	int	pos;
	int	size;

	pos = get_min_pos(*a, target_index);
	size = stack_size(*a);
	if (pos <= size / 2)
	{
		while ((*a)->index != target_index)
			ra(a);
	}
	else
	{
		while ((*a)->index != target_index)
			rra(a);
	}
	pb(a, b);

}

void	sort_small(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
	{
		if ((*a)->index > (*a)->next->index)
			sa(*a);
		return ;
	}
	if (size == 4)
		push_min_to_b(a, b, 0);
	else if
	{
		push_min_to_b(a, b, 0);
		push_min_to_b(a, b, 1);
	}
	sort_three(a);
	while (*b)
		pa(a, b);

}