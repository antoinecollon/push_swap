/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:10:40 by acollon           #+#    #+#             */
/*   Updated: 2025/07/15 23:15:20 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*stack_new(int value)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->value = value;
	stack->index = -1;
	stack->next = NULL;
	return (stack);
}

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	stack_add_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last;

	if (!stack || !new_node)
		return ;
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		last = stack_last(*stack);
		last->next = new_node;
	}
}

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	stack_is_sorted(t_stack *stack)
{
	int	comp_val;

	if (!stack)
		return (1);
	comp_val = stack->value;
	stack = stack->next;
	while (stack)
	{
		if (comp_val < stack->value)
			comp_val = stack->value;
		else
			return (0);
		stack = stack->next;
	}
	return (1);
}
