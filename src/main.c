#include "../includes/push_swap.h"
#include <stdio.h>

static void	init_config(t_config *config)
{
	config->flag_simple = 0;
	config->flag_medium = 0;
	config->flag_complex = 0;
	config->flag_adaptive = 0;
	config->flag_bench = 0;
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_config	config;

	a = NULL;
	b = NULL;
	init_config(&config);
	if (argc < 2)
		return (0);
	parse_input(argc, argv, &a, &config);
	index_stack(a);
	printf("--- PRUEBA DE ESTADO INICIAL ---\n");
	printf("Elementos en Stack A: %d\n", stack_size(a));
	printf("Indice de desorden: %.2f%%\n", (double)(compute_disorder(a) * 100.0));
	printf("--- EJECUTANDO ORDENACION ---\n");
	if (config.flag_simple)
		strategy_simple(&a, &b);
	else if (config.flag_medium)
		strategy_medium(&a, &b);
	else if (config.flag_complex)
		strategy_complex(&a, &b);
	else
		strategy_adaptive(&a, &b);
	printf("--- RESULTADO ---\n");
	printf("¿Stack A ordenado?: %s\n", is_sorted(a) ? "SI" : "NO");
	printf("¿Stack B vacio?: %s\n", stack_size(b) == 0 ? "SI" : "NO");
	free_stack(&a);
	free_stack(&b);
	return (0);
}
