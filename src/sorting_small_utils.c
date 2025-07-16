/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:19:29 by acollon           #+#    #+#             */
/*   Updated: 2025/07/16 18:11:23 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min(t_stack *stack)
{
	int	tmp;

	tmp = stack->value;
	while (stack)
	{
		if (stack->value < tmp)
			tmp = stack->value;
		stack = stack->next;
	}
	return (tmp);
}

int	find_max(t_stack *stack)
{
	int	tmp;

	tmp = stack->value;
	while (stack)
	{
		if (stack->value > tmp)
			tmp = stack->value;
		stack = stack->next;
	}
	return (tmp);
}

void	sort_five_safety(t_stack **a, t_stack **b)
{
	int		min;
	int		pos;
	t_stack	*tmp;

	tmp = *a;
	min = find_min(*a);
	pos = 0;
	while (tmp)
	{
		if (tmp->value == min)
			break ;
		pos++;
		tmp = tmp->next;
	}
	if (pos <= stack_size(*a) / 2)
	{
		while ((*a)->value != min)
			stack_rotate(a, 'a', RETURN);
	}
	else
	{
		while ((*a)->value != min)
			stack_reverse_rotate(a, 'a', RETURN);
	}
	stack_push(b, a, 'b', RETURN);
}
