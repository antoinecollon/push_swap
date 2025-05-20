/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:57:48 by acollon           #+#    #+#             */
/*   Updated: 2025/04/28 17:36:38 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void error_exit(const char *message)
{
	if (message)
		write (2, message, ft_strlen(message));
	exit (EXIT_FAILURE);
}

void free_split(char **split)
{
    int	i;

	i = 0;
	while(split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void free_all(t_stack **a, t_stack **b)
{
	if (a && *a)
		free_stack(a);
	if (b && *b)
		free_stack(b);
}

void safe_free(void *ptr)
{
    if (ptr)
		free(ptr);
}

void print_error_and_exit(void)
{
    error_exit("Error\n");
}
