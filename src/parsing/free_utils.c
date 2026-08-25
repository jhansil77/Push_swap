#include "push_swap.h"

void	free_Stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	free_split(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void print_error(t_stack **a, t_stack **b)
{
	if (a)
		free_Stack(a);
	if (b)
		free_Stack(b);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);

}