/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 22:44:36 by acollon           #+#    #+#             */
/*   Updated: 2025/07/16 19:48:56 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../gnl/get_next_line.h"
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>

# define SILENT 1
# define RETURN 0

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

/* stack_parsing.c */
void	parse_split(t_stack **stack, char **split);
t_stack	*parse_args(int argc, char **argv);
void	check_args(int argc, char **argv);

/* stack_check.c */
int		is_valid_number(const char *str);
int		has_duplicates(t_stack *stack);
void	free_stack(t_stack **stack);

/* stack_operations.c */
void	stack_swap(t_stack **stack, char pile, int mode);
void	stack_push(t_stack **dest, t_stack **src, char to, int mode);
void	stack_rotate(t_stack **stack, char pile, int mode);
void	stack_reverse_rotate(t_stack **stack, char pile, int mode);
void	push_all_to_a(t_stack **a, t_stack **b, int mode);

/* stack_double_operation */
void	double_rotate(t_stack **a, t_stack **b, int mode);
void	double_swap(t_stack **a, t_stack **b, int mode);
void	double_reverse_rotate(t_stack **a, t_stack **b, int mode);

/* error_handling.c */
void	error_exit(const char *message);
void	free_split(char **split);
void	free_all(t_stack **a, t_stack **b);
void	safe_free(void *ptr);
void	print_error_and_exit(void);


#endif