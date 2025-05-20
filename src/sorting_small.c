/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:59:04 by acollon           #+#    #+#             */
/*   Updated: 2025/05/09 12:51:15 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sort_two(t_stack **stack)
{
	if ((*stack)->value > (*stack)->next->value)
		stack_swap(stack, 'a');
}

void sort_three(t_stack **stack)
{
    int	a;
	int	b;
	int	c;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if (a < b && b < c)
		return;
	if (a > b &&  b < c && a < c)
		stack_swap(stack, 'a');
	else if (a > b && b > c)
	{
		stack_swap(stack, 'a');
		stack_reverse_rotate(stack, 'a');
	}
	else if (a > b && b < c && a > c)
		stack_rotate(stack, 'a');
	else if (a < b && b > c && a < c)
	{
		stack_swap(stack, 'a');
		stack_rotate(stack, 'a');
	}
	else if (a < b && b > c && a > c)
		stack_reverse_rotate(stack, 'a');
}

void sort_five(t_stack **a, t_stack **b)
{
    int i;

	i = 0;
	if (stack_is_sorted(*a))
    	return ;
	while (i < 2)
	{
		sort_five_safety(a, b);
		i++;
	}
	sort_three(a);
	stack_push(a, b, 'a');
	stack_push(a, b, 'a');
}

