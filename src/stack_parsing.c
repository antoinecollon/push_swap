/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:55:30 by acollon           #+#    #+#             */
/*   Updated: 2025/07/16 20:44:21 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*parse_args(int ac, char **av)
{
	char			**split;
	t_stack			*stack;
	int				i;

	i = 1;
	stack = NULL;
	if (ac < 2)
		exit(0);
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		if (!split)
		{
			free(split);
			print_error_and_exit();
		}
		parse_split(&stack, split);
		free_split(split);
		i++;
	}
	return (stack);
}

void	parse_split(t_stack **stack, char **split)
{
	int		j;
	long	check_max;

	j = 0;
	while (split[j])
	{
		if (!is_valid_number(split[j]))
		{
			free_stack(stack);
			free_split(split);
			print_error_and_exit();
		}
		check_max = ft_atol(split[j]);
		if (check_max < INT_MIN || check_max > INT_MAX)
		{
			free_stack(stack);
			free_split(split);
			print_error_and_exit();
		}
		stack_add_back(stack, stack_new(ft_atoi(split[j])));
		j++;
	}
}

void	check_args(int ac, char **av)
{
	t_stack	*stack;

	stack = parse_args(ac, av);
	if (!stack)
		exit (0);
	if (!has_duplicates(stack))
	{
		free_stack(&stack);
		print_error_and_exit();
	}
	free_stack(&stack);
}
