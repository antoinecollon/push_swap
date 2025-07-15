/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:23:38 by acollon           #+#    #+#             */
/*   Updated: 2025/07/15 17:08:28 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../gnl/get_next_line.h"
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/* stack_utils.c */
t_stack	*stack_new(int value);
t_stack	*stack_last(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *new_node);
int		stack_size(t_stack *stack);
int		stack_is_sorted(t_stack *stack);

/* stack_operations.c */
void	stack_swap(t_stack **stack, char pile);
void	stack_push(t_stack **dest, t_stack **src, char to);
void	stack_rotate(t_stack **stack, char pile);
void	stack_reverse_rotate(t_stack **stack, char pile);
void	push_all_to_a(t_stack **a, t_stack **b);

/* stack_double_operation */
void	double_rotate(t_stack **a, t_stack **b);
void	double_swap(t_stack **a, t_stack **b);
void	double_reverse_rotate(t_stack **a, t_stack **b);
/* stack_parsing.c */
void	parse_split(t_stack **stack, char **split);
t_stack	*parse_args(int argc, char **argv);
void	check_args(int argc, char **argv);

/* stack_check.c */
int is_valid_number(const char *str);
int has_duplicates(t_stack *stack);
void free_stack(t_stack **stack);

/* sorting_small.c */
void    sort_two(t_stack **stack);
void    sort_three(t_stack **stack);
void    sort_five(t_stack **a, t_stack **b);

/* sorting_small_utils.c */
int     find_min(t_stack *stack);
int     find_max(t_stack *stack);
void    sort_five_safety(t_stack **a, t_stack **b);

/* pos_and_index.c */
void	assign_index(t_stack **a);
void	find_pos(t_stack *stack);
int	get_lowest_pos(t_stack *a);
int	find_target_pos(t_stack *a, int	b_index);
void	compute_target_pos(t_stack *a, t_stack *b);

/* cheapest_logic.c*/
void	compute_ops_required(t_stack *a, t_stack *b);
t_stack	*find_cheapest_node(t_stack *b);
void	move_node_to_top(t_stack **stack, int pos, char pile);
void	execute_cheapest_move(t_stack **a, t_stack **b);
void	rotate_stack_to_min_top(t_stack **a);

/* execution.c */
void	rotate_stack_to_min_top(t_stack **a);
void	move_node_to_top(t_stack **stack, int pos, char pile);
void	sort_big(t_stack **a, t_stack **b);
void	push_to_b(t_stack **a, t_stack **b);

/* error_handling.c */
void	error_exit(const char *message);
void	free_split(char **split);
void	free_all(t_stack **a, t_stack **b);
void	safe_free(void *ptr);
void	print_error_and_exit(void);

//BONUS

#endif
