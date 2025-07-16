/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:05:46 by acollon           #+#    #+#             */
/*   Updated: 2025/07/16 20:52:49 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	is_rotation(char *instruction)
{
	if (!ft_strcmp(instruction, "ra\n"))
		return (0);
	else if (!ft_strcmp(instruction, "rb\n"))
		return (0);
	else if (!ft_strcmp(instruction, "rr\n"))
		return (0);
	else if (!ft_strcmp(instruction, "rra\n"))
		return (0);
	else if (!ft_strcmp(instruction, "rrb\n"))
		return (0);
	else if (!ft_strcmp(instruction, "rrr\n"))
		return (0);
	return (1);
}

static void	exec_rotate_instruction(char *instruction, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(instruction, "ra\n"))
		stack_rotate(a, 'a', SILENT);
	else if (!ft_strcmp(instruction, "rb\n"))
		stack_rotate(b, 'b', SILENT);
	else if (!ft_strcmp(instruction, "rr\n"))
		double_rotate(a, b, SILENT);
	else if (!ft_strcmp(instruction, "rra\n"))
		stack_reverse_rotate(a, 'a', SILENT);
	else if (!ft_strcmp(instruction, "rrb\n"))
		stack_reverse_rotate(b, 'b', SILENT);
	else if (!ft_strcmp(instruction, "rrr\n"))
		double_reverse_rotate(a, b, SILENT);
	else
	{
		free_all(a, b);
		print_error_and_exit();
	}
}

static int	exec_instruction(char *instruction, t_stack **a, t_stack **b)
{
	if (!instruction || ft_strlen(instruction) < 2)
		return (2);
	if (!ft_strcmp(instruction, "sa\n"))
		stack_swap(a, 'a', SILENT);
	else if (!ft_strcmp(instruction, "sb\n"))
		stack_swap(b, 'b', SILENT);
	else if (!ft_strcmp(instruction, "ss\n"))
		double_swap(a, b, SILENT);
	else if (!ft_strcmp(instruction, "pa\n"))
		stack_push(a, b, 'a', SILENT);
	else if (!ft_strcmp(instruction, "pb\n"))
		stack_push(b, a, 'b', SILENT);
	else if (!is_rotation(instruction))
		exec_rotate_instruction(instruction, a, b);
	else
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	check_args(ac, av);
	a = parse_args(ac, av);
	b = NULL;
	line = get_next_line(0);
	while (line)
	{
		if (!exec_instruction(line, &a, &b))
		{
			free(line);
			free_all(&a, &b);
			print_error_and_exit();
		}
		free(line);
		line = get_next_line(0);
	}
	if (stack_is_sorted(a) && !b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_all(&a, &b);
	return (0);
}
