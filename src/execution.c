/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:46:06 by acollon           #+#    #+#             */
/*   Updated: 2025/07/15 12:04:59 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_min_pos(t_stack *a)
{
	t_stack *current;
	
	find_pos(a);
	current = a;
	while (current)
	{
		if (current->index == 0)
			return (current->pos);
		current = current->next;
	}
	return (0);
}

void	rotate_stack_to_min_top(t_stack **a)
{
	int	min_pos;
	int	size;
	int	i;

	min_pos = get_min_pos(*a);
	size = stack_size(*a);
	if (min_pos <= size / 2)
	{
		i = min_pos;
		while (i--)
		{
			stack_rotate(a, 'a');
		}
	}
	else
	{
		i = size - min_pos;
		while (i--)
			stack_reverse_rotate(a, 'a');		
	}
}

void	push_to_b(t_stack **a, t_stack **b)
{
	int	i;
	int	chunk_size;

	i = 0;
	chunk_size = 30;
	while (stack_size(*a) > 3)
	{
		if ((*a)->index <= i)
		{
			stack_push(b, a, 'b');
			i++;
		}
		else if ((*a)->index <= i + chunk_size)
		{
			stack_push(b, a, 'b');
			stack_rotate(b, 'b');
			i++;
		}
		else
			stack_rotate(a, 'a');
	}
}

void	sort_big(t_stack **a, t_stack **b)
{
	push_to_b(a, b);
	sort_three(a);
	while (*b)
	{
		find_pos(*a);
		find_pos(*b);
		compute_target_pos(*a, *b);
		compute_ops_required(*a, *b);
		execute_cheapest_move(a, b);
	}
}

int	main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;

	if (ac < 2)
		return (0);
	check_args(ac, av);
	a = parse_args(ac, av);
	if (!a)
		print_error_and_exit();
	b = NULL;
	assign_index(&a);
	if (stack_is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	if (stack_size(a) == 2)
		sort_two(&a);
	else if (stack_size(a) == 3)
		sort_three(&a);
	else
		sort_big(&a, &b);
	rotate_stack_to_min_top(&a);
	return (0);	
}
