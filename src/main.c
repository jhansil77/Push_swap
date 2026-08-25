#include "push_swap.h"

static void	init_config(t_config *config)
{
	config->flag_simple = 0;
	config->flag_medium = 0;
	config->flag_complex = 0;
	config->flag_adaptive = 0;
	config->flag_bench = 0;
	config->total_ops = 0;
}

static void	execute_strategy(t_stack **a, t_stack **b, t_config *config)
{
	if (config->flag_simple)
		strategy_simple(a, b, config);
	else if (config->flag_medium)
		strategy_medium(a, b, config);
	else if (config->flag_complex)
		strategy_complex(a, b, config);
	else
		strategy_adaptive(a, b, config);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_config	config;
	double		disorder;

	a = NULL;
	b = NULL;
	init_config(&config);
	if (argc < 2)
		return (0);
	parse_input(argc, argv, &a, &config);
	if (!a)
		return (0);
	index_stack(a);
	disorder = compute_disorder(a);
	execute_strategy(&a, &b, &config);
	print_benchmark(&config, disorder);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
