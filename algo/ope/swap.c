/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:30:39 by isb3              #+#    #+#             */
/*   Updated: 2024/02/22 13:54:42 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	do_sa(t_stack_a *stack)
{
	t_data	*last_node;
	t_data	*penultimate_node;

	if (!stack->head || !stack->head->next)
		return ;
	last_node = stack->tail;
	penultimate_node = stack->tail->prev;
	last_node->prev = penultimate_node->prev;
	last_node->next = penultimate_node;
	penultimate_node->next = NULL;
	if (penultimate_node->prev)
		penultimate_node->prev->next = last_node;
	else
		stack->head = last_node;
	last_node->position = penultimate_node->position;
	penultimate_node->position++;
	stack->tail = penultimate_node;
	stack->tail->prev = last_node;
}

void	do_sb(t_stack_b *stack)
{
	t_data	*last_node;
	t_data	*penultimate_node;

	if (!stack->head || !stack->head->next)
		return ;
	last_node = stack->tail;
	penultimate_node = stack->tail->prev;
	last_node->prev = penultimate_node->prev;
	last_node->next = penultimate_node;
	penultimate_node->next = NULL;
	if (penultimate_node->prev)
		penultimate_node->prev->next = last_node;
	else
		stack->head = last_node;
	last_node->position = penultimate_node->position;
	penultimate_node->position++;
	stack->tail = penultimate_node;
	stack->tail->prev = last_node;
}

void	ss(t_stack_a *stack_a, t_stack_b *stack_b)
{
	do_sa(stack_a);
	do_sb(stack_b);
	printf("ss\n");
}

void	sa(t_stack_a *stack_a)
{
	do_sa(stack_a);
	printf("sa\n");
}

void	sb(t_stack_b *stack_b)
{
	do_sb(stack_b);
	printf("sb\n");
}
