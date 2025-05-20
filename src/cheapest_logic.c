/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_logic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:33:03 by acollon           #+#    #+#             */
/*   Updated: 2025/05/09 17:03:48 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);	
}
void	compute_ops_required(t_stack *a, t_stack *b)
{
	t_stack *current;
	int		size_a;
	int		size_b;
	
	size_a = stack_size(a);
	size_b = stack_size(b);
	current = b;
	while (current)
	{
		if (current->pos <= size_b / 2)
			current->cost_b = current->pos;
		else
			current->cost_b = (size_b - current->pos) * -1;
		if (current->target_pos <= size_a / 2)
			current->cost_a = current->target_pos;
		else
			current->cost_a = (size_a - current->target_pos) * -1;
		current = current->next;
	}
}

t_stack	*find_cheapest_node(t_stack *b)
{
	t_stack	*current;
	t_stack	*cheapest;
	int	cheapest_cost;
	int	total_cost;

	current = b;
	cheapest = NULL;
	cheapest_cost = INT_MAX;
	while (current)
	{
		total_cost = ft_abs(current->cost_a) + ft_abs(current->cost_b);
		if (total_cost < cheapest_cost)
		{
			cheapest_cost = total_cost;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}
void	execute_simple_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	while (cost_a > 0)
	{
		stack_rotate(a, 'a');
		cost_a--;
	}
	while (cost_a < 0)
	{
		stack_reverse_rotate(a, 'a');
		cost_a++;
	}
	while (cost_b > 0)
	{
		stack_rotate(b, 'b');
		cost_b--;
	}
	while (cost_b < 0)
	{
		stack_reverse_rotate(b, 'b');
		cost_b++;
	}
}

void	execute_cheapest_move(t_stack **a, t_stack **b)
{
	t_stack	*target;
	int		cost_a;
	int		cost_b;

	target = find_cheapest_node(*b);
	cost_a = target->cost_a;
	cost_b = target->cost_b;
	while (cost_a > 0 && cost_b > 0)
	{
		double_rotate(a, b);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		double_reverse_rotate(a, b);
		cost_a++;
		cost_b++;
	}
	execute_simple_move(a, b, cost_a, cost_b);
	stack_push(a, b, 'a');
}

