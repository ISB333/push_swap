/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:40:28 by adesille          #+#    #+#             */
/*   Updated: 2024/02/24 15:05:01 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	initialize_stacks(int *array, t_stack **stack_a)
{
	int	i;	

	i = 0;
	while (array[i])
		add_node (&*stack_a, array[i++]);
	free(array);
}

void	add_node(t_stack **stack, int value)
{
	t_stack *new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return;
	new_node->value = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
	{
		(*stack)->prev = new_node;
		new_node->position = (*stack)->position + 1;
	}
	else
		new_node->position = 1;
	*stack = new_node;
}
