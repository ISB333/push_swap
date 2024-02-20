/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:40:28 by adesille          #+#    #+#             */
/*   Updated: 2024/02/20 13:27:49 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	initialize_stacks(int *array, t_stack_a *stack_a, t_stack_b *stack_b)
{
	int	i;	

	stack_a->head = NULL;
	stack_a->tail = NULL;
	stack_b->head = NULL;
	stack_b->tail = NULL;
	i = 0;
	while (array[i])
		add_node (stack_a, array[i++]);
	free(array);
}

void	add_node(t_stack_a *stack, int value)
{
	t_data	*new_node;

	new_node = malloc(sizeof(t_data));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->prev = NULL;
	new_node->next = NULL;
	if (!stack->head)
	{
		new_node->position = 1;
		stack->head = new_node;
		stack->tail = new_node;
	}
	else
	{
		new_node->position = stack->tail->position + 1;
		stack->tail->next = new_node;
		new_node->prev = stack->tail;
		stack->tail = new_node;
	}
}

void	stack_printer_a(t_stack_a *stack)
{
	t_data	*current;

	current = stack->head;
	while (current)
	{
		printf("Val:    %d\n", current->value);
		printf("\033[0;32m");
		printf("Pos: %d\n", current->position);
		current = current->next;
		printf("\033[0;37m");
	}
}

void	stack_printer_b(t_stack_b *stack)
{
	t_data	*current;

	current = stack->head;
	while (current)
	{
		printf("Val:    %d\n", current->value);
		printf("\033[0;32m");
		printf("Pos: %d\n", current->position);
		current = current->next;
		printf("\033[0;37m");
	}
}
