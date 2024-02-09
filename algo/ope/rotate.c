/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:30:34 by isb3              #+#    #+#             */
/*   Updated: 2024/02/09 12:41:42 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	do_ra(t_stack_a *stack)
{
	t_data	*first_node;
	t_data	*last_node;
	
	first_node = stack->head;
	last_node = stack->tail;

	first_node->prev = last_node;
	last_node->next = first_node;
	first_node->next->prev = NULL;
	stack->head = first_node->next;
	first_node->next = NULL;
	stack->tail = first_node;
	
	first_node->position = last_node->position + 1;
	while(first_node)
	{
		first_node->position--;
		first_node = first_node->prev;
	}
}

void	do_rb(t_stack_b *stack)
{
	t_data	*first_node;
	t_data	*last_node;
	
	first_node = stack->head;
	last_node = stack->tail;

	first_node->prev = last_node;
	last_node->next = first_node;
	first_node->next->prev = NULL;
	stack->head = first_node->next;
	first_node->next = NULL;
	stack->tail = first_node;
	
	first_node->position = last_node->position + 1;
	while(first_node)
	{
		first_node->position--;
		first_node = first_node->prev;
	}
}

void	rr(t_stack_a *stack_a, t_stack_b *stack_b)
{
	do_ra(stack_a);
	do_rb(stack_b);
	printf("rr\n");
}
void	ra(t_stack_a *stack_a)
{
	do_ra(stack_a);
	printf("ra\n");
}

void	rb(t_stack_b *stack_b)
{
	do_rb(stack_b);
	printf("rb\n");
}
