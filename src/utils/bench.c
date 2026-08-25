#include "push_swap.h"

static void	print_strategy(t_config *config)
{
	ft_putstr_fd("[bench] strategy:   ", 2);
	if (config->flag_simple)
		ft_putstr_fd("Simple / O(n^2)\n", 2);
	else if (config->flag_medium)
		ft_putstr_fd("Medium / O(n√n)\n", 2);
	else if (config->flag_complex)
		ft_putstr_fd("Complex / O(n log n)\n", 2);
	else
		ft_putstr_fd("Adaptive / O(n√n)\n", 2);
}

void	print_benchmark(t_config *config, double disorder)
{
	if (!config->flag_bench)
		return ;
	ft_putstr_fd("[bench] disorder:   ", 2);
	ft_putnbr_fd((int)(disorder * 100), 2);
	ft_putstr_fd(".", 2);
	ft_putnbr_fd((int)(disorder * 10000) % 100, 2);
	ft_putstr_fd("%\n", 2);
	print_strategy(config);
	ft_putstr_fd("[bench] total_ops:  ", 2);
	ft_putnbr_fd(config->total_ops, 2);
	ft_putstr_fd("\n", 2);
}

// void    print_benchmark(t_config *config, double disorder, int total_ops)
// {
//     if (!config->flag_bench)
//         return ;
//     ft_putstr_fd("[bench] -----------------------------------\n", 2);
//     ft_putstr_fd("[bench] Disordering index: ", 2);
//     ft_putnbr_fd((int)(disorder * 100), 2);
//     ft_putstr_fd(".", 2);
//     ft_putnbr_fd((int)(disorder * 10000) % 100, 2);
//     ft_putstr_fd("%\n", 2);
//     ft_putstr_fd("[bench] Selected Strategy:   ", 2);
//     if (config->flag_simple)
//         ft_putstr_fd("Simple\n", 2);
//     else if (config->flag_medium)
//         ft_putstr_fd("Medium\n", 2);
//     else if (config->flag_complex)
//         ft_putstr_fd("Complex\n", 2);
//     else if (config->flag_adaptive)
//         ft_putstr_fd("Adaptive\n", 2);
//     ft_putstr_fd("[bench] Total operations: ", 2);
//     ft_putnbr_fd(total_ops, 2);
//     ft_putstr_fd("\n[bench] -----------------------------------\n", 2);
    
// }
