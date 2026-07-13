#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
    int             value;
    struct s_node   *next;
} t_node;

int     valid_nbr_check(char *str);
int     int_range_check(char *str);
int     duplicate_check(t_node *stack);
void	error_exit(t_node *stack_a);
void    add_nodes(t_node **stack, int value);
void	swap(t_node **stack);
long	ft_atol(const char *nptr);
void    free_stack(t_node *stack);
void    print_stack(t_node *stack);
void    swap(t_node **stack);
void    sa(t_node **stack_a);
void    sb(t_node **stack_b);
void    ss(t_node **stack_a, t_node **stack_b);
void    pa(t_node **stack_a, t_node **stack_b);
void    pb(t_node **stack_a, t_node **stack_b);
void    rotate(t_node **stack);
void    ra(t_node **stack_a);
void    rb(t_node **stack_b);
void    rr(t_node **stack_a, t_node **stack_b);

#endif