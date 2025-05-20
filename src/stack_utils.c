/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:10:40 by acollon           #+#    #+#             */
/*   Updated: 2025/04/28 11:48:27 by acollon          ###   ########.fr       */
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
/*
#include <stdio.h> // juste pour printf dans le test

int main(void)
{
    t_stack *stack = NULL;

    // Création de quelques éléments
    stack_add_back(&stack, stack_new(1));
    stack_add_back(&stack, stack_new(2));
    stack_add_back(&stack, stack_new(3));

    // Affichage de la pile
    printf("Stack contents:\n");
    t_stack *tmp = stack;
    while (tmp)
    {
        printf("Value: %d, Index: %d\n", tmp->value, tmp->index);
        tmp = tmp->next;
    }

    // Test de stack_size
    printf("Stack size: %d\n", stack_size(stack));

    // Test de stack_is_sorted
    if (stack_is_sorted(stack))
        printf("Stack is sorted ✅\n");
    else
        printf("Stack is NOT sorted ❌\n");

    // Ajout d'un élément désordonné pour tester
    stack_add_back(&stack, stack_new(0));
    
    // Affichage de la pile après ajout
    printf("\nAfter adding 0 at the end:\n");
    tmp = stack;
    while (tmp)
    {
        printf("Value: %d, Index: %d\n", tmp->value, tmp->index);
        tmp = tmp->next;
    }

    // Nouveau test de stack_is_sorted
    if (stack_is_sorted(stack))
        printf("Stack is sorted ✅\n");
    else
        printf("Stack is NOT sorted ❌\n");

    // Libération mémoire
    //free_stack(&stack);

    return (0);
}
*/