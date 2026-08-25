#ifdef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int	value;
	int	index;
	struct s_stack	*next;
	t_stack;
}

typedef struct s_config
{
	int	flag_simple;
	int	flag_medium;
	int	flag_complex;
	int flag_adaptative;
	int	flag_bench;
	t_config;
}

int	main(int argc, char **argv);
t_stack *stack_last(t_stack *stack);
int stack_size(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *new_node);
t_stack	*stack_new(int value);
void	free_stack(t_stack **stack);
void	free_split(char **args);
void	print_error(t_stack **a, t_stack **b);
int	has_duplicates(t_stack *stack);
int	is_within_int_limits(long num);
long	ft_atol(const char *str);
int	is_number(char *str);
void	parser_input(int argc, char **argv, t_stack **a, t_config * config);
void	parser_args(char **args, t_stack **a, int is_split);
int	parser_flags(char *arg, t_config *config);
/* Swap */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

/* Push */
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

/* Rotate */
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

/* Reverse Rotate */
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

void	index_stack(t_stack *stack);
double	compute_disorder(t_stack *stack);
int		is_sorted(t_stack *stack);

void	sort_three(t_stack **a);
void	sort_small(t_stack **a, t_stack **b);