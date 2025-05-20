/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_double_operation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:22:48 by acollon           #+#    #+#             */
/*   Updated: 2025/04/29 14:26:13 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void double_rotate(t_stack **a, t_stack **b)
{
    stack_rotate(a, 'x');
	stack_rotate(b, 'x');
	write(1, "rr\n", 3);
}
void	double_swap(t_stack **a, t_stack **b)
{
	stack_swap(a, 'x');
	stack_swap(b, 'x');
	write(1, "ss\n", 3);
}
void	double_reverse_rotate(t_stack **a, t_stack **b)
{
	stack_reverse_rotate(a, 'x');
	stack_reverse_rotate(b, 'x');
	write(1, "rrr\n", 4);
}