/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:30:24 by isb3              #+#    #+#             */
/*   Updated: 2024/02/26 14:41:29 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////          SHIT IS HERE MODAFUCKA         /////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*new_node;

	if (!*stack_a)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = (*stack_a)->value;
	if (!*stack_b)
	{
		new_node->prev = NULL;
		new_node->next = NULL;
		new_node->position = 1;
	}
	else
	{
		new_node->next = (*stack_b);
		(*stack_b)->prev = new_node;
		new_node->position = (*stack_b)->position + 1;
	}
	if (!(*stack_a)->next)
	{
		free(*stack_a);
		*stack_a = NULL;
	}
	else
	{
		*stack_a = (*stack_a)->next;
		free((*stack_a)->prev);
		(*stack_a)->prev = NULL;
	}
	*stack_b = new_node;
	// *stack_b = new_node;
	// *stack_a = (*stack_a)->next;
	// free((*stack_a)->prev);
	printf("pb\n");
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*new_node;

	if (!*stack_b)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = (*stack_b)->value;
	if (!*stack_a)
	{
		new_node->prev = NULL;
		new_node->next = NULL;
		new_node->position = 1;
	}
	else
	{
		new_node->next = (*stack_a);
		(*stack_a)->prev = new_node;
		new_node->position = (*stack_a)->position + 1;
	}
	if (!(*stack_b)->next)
	{
		free(*stack_b);
		*stack_b = NULL;
	}
	else
	{
		*stack_b = (*stack_b)->next;
		free((*stack_b)->prev);
		(*stack_b)->prev = NULL;
	}
	*stack_a = new_node;
	printf("pa\n");
}
