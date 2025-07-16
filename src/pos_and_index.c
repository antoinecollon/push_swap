/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_and_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:58:32 by acollon           #+#    #+#             */
/*   Updated: 2025/07/16 00:00:59 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	assign_index(t_stack **a)
{
	int		index;
	t_stack	*min_value;
	t_stack	*current_value;

	index = 0;
	while (1)
	{
		min_value = NULL;
		current_value = *a;
		while (current_value)
		{
			if (current_value->index == -1
				&& (!min_value || current_value->value < min_value->value))
				min_value = current_value;
			current_value = current_value->next;
		}
		if (!min_value)
			break ;
		min_value->index = index;
		index++;
	}
}

void	find_pos(t_stack *stack)
{
	int		pos;
	t_stack	*current;

	pos = 0;
	current = stack;
	while (current)
	{
		current->pos = pos;
		current = current->next;
		pos++;
	}
}

int	get_lowest_pos(t_stack *a)
{
	int		lowest_index;
	int		lowest_pos;
	t_stack	*current;

	current = a;
	lowest_index = INT_MAX;
	lowest_pos = 0;
	while (current)
	{
		if (current->index < lowest_index)
		{
			lowest_index = current->index;
			lowest_pos = current->pos;
		}
		current = current->next;
	}
	return (lowest_pos);
}

int	find_target_pos(t_stack *a, int b_index)
{
	t_stack	*current;
	int		best_index;
	int		best_pos;

	current = a;
	best_index = INT_MAX;
	best_pos = 0;
	while (current)
	{
		if (current->index > b_index && current->index < best_index)
		{
			best_index = current->index;
			best_pos = current->pos;
		}
		current = current->next;
	}
	if (best_index != INT_MAX)
		return (best_pos);
	return (get_lowest_pos(a));
}

void	compute_target_pos(t_stack *a, t_stack *b)
{
	t_stack	*current;

	find_pos(a);
	find_pos(b);
	current = b;
	while (current)
	{
		current->target_pos = find_target_pos(a, current->index);
		current = current->next;
	}
}
