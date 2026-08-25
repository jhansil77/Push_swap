#include "../../../includes/push_swap.h"

int	parser_flags(char *arg, t_config *config)
{
	if (!ft_strcmp(arg, "--simple"))
		config->flag_simple = 1;
	else if (!ft_strcmp(arg, "--medium"))
		config->flag_medium = 1;
	else if (!ft_strcmp(arg, "--complex"))
		config->flag_complex = 1;
	else if (!ft_strcmp(arg, "--adaptive"))
		config->flag_adaptive = 1;
	else if (!ft_strcmp(arg, "--bench"))
		config->flag_bench = 1;
	else
		return (0);
	return (1);
}

static void	process_number(char *str, t_stack **a, char **args, int is_split)
{
	long	val;
	t_stack *new_node;

	if (!is_number(str))
	{
		if (is_split)
			free_split(args);
		print_error(a, NULL);
	}
	val = ft_atol(str);
	if (!is_within_int_limits(val))
	{
		if (is_split)
			free_split(args);
		print_error(a, NULL);
	}
	new_node = stack_new((int)val);
	if (!new_node)
	{
		if (is_split)
			free_split(args);
			print_error(a, NULL);
	}
	stack_add_back(a, new_node);

}

void	parser_args(char **args, t_stack **a, int is_split)
{
	int	i;

	i = 0;
	while (args[i])
	{
		process_number(args[i], a, args, is_split);
		i++;
	}
	if (has_duplicates(*a))
	{
		if (is_split)
			free_split(args);
		print_error(a, NULL);
	}

}

void	parser_input(int argc, char **argv, t_stack **a, t_config * config)
{
	int		i;
	char	**split_args;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && parser_flags(argv[i], config))
		{
			i++;
			continue ;
		}
		if (ft_strchr(argv[i], ' '))
		{
			split_args = ft_split(argv[i], ' ')
			if (!split_args)
				print_error(a, NULL);
			parser_args(split_args, a, 1);
			free_split(split_args);
		}
		else
			process_number(argv[i], a, NULL, 0);
		i++;
	}
	if (has_duplicates(*a))
		print_error(a, NULL);
}