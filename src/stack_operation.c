/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:46:42 by acollon           #+#    #+#             */
/*   Updated: 2025/05/09 16:33:56 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void stack_swap(t_stack **stack, char pile)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	if (pile == 'a')
		write(1, "sa\n", 3);
	if (pile == 'b')
		write(1, "sb\n", 3);
}

void stack_push(t_stack **dest, t_stack **src, char to)
{
    t_stack *tmp;

	if (!dest || !src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
	if (to == 'a')
		write (1, "pa\n", 3);
	if (to == 'b')
		write (1, "pb\n", 3);	
}

void stack_rotate(t_stack **stack, char pile)
{
    t_stack	*tmp;
	t_stack	*head;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	head = *stack;
	*stack = (*stack)->next;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = head;
	head->next = NULL;
	if (pile == 'a')
		write (1, "ra\n", 3);
	if (pile == 'b')
		write (1, "rb\n", 3);
}

void stack_reverse_rotate(t_stack **stack, char pile)
{
    t_stack	*tmp;
	t_stack *last;
	
	tmp = *stack;
	if (!stack || !*stack || !(*stack)->next)
		return ;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *stack;
	*stack = last;
	if (pile == 'a')
		write(1, "rra\n", 4);
	if (pile == 'b')
		write(1, "rrb\n", 4);	
}
void	push_all_to_a(t_stack **a, t_stack **b)
{
	while (*b)
		stack_push(a, b, 'a');
}
