/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_double_operation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:22:48 by acollon           #+#    #+#             */
/*   Updated: 2025/07/16 18:07:52 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	double_rotate(t_stack **a, t_stack **b, int mode)
{
	if (mode == RETURN)
	{
		stack_rotate(a, 'x', RETURN);
		stack_rotate(b, 'x', RETURN);
		write(1, "rr\n", 3);
	}
	else
	{
		stack_rotate(a, 'x', SILENT);
		stack_rotate(b, 'x', SILENT);
	}
}

void	double_swap(t_stack **a, t_stack **b, int mode)
{
	if (mode == RETURN)
	{
		stack_swap(a, 'x', RETURN);
		stack_swap(b, 'x', RETURN);
		write(1, "ss\n", 3);
	}
	else
	{
		stack_swap(a, 'x', SILENT);
		stack_swap(b, 'x', SILENT);
	}
}

void	double_reverse_rotate(t_stack **a, t_stack **b, int mode)
{
	if (mode == RETURN)
	{
		stack_reverse_rotate(a, 'x', RETURN);
		stack_reverse_rotate(b, 'x', RETURN);
		write(1, "rrr\n", 4);
	}
	else
	{
		stack_reverse_rotate(a, 'x', SILENT);
		stack_reverse_rotate(b, 'x', SILENT);
	}
}
