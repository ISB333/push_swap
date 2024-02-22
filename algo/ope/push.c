/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:30:24 by isb3              #+#    #+#             */
/*   Updated: 2024/02/22 10:18:52 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////          SHIT IS HERE MODAFUCKA         /////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void	pa(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_data	*penultimate_node;
	t_data	*new_node;
	t_data	*stack_b_tail;

	if (!stack_b->head)
		return ;
	penultimate_node = stack_b->tail->prev;
	new_node = malloc(sizeof(t_data));
	if (!new_node)
		return ;
	new_node->value = stack_b->tail->value;
	if (!stack_a->head)
	{
		new_node->prev = NULL;
		new_node->position = 1;
		stack_a->head = new_node;
	}
	else
	{
		new_node->prev = stack_a->tail;
		stack_a->tail->next = new_node;
		new_node->position = stack_a->tail->position + 1;
	}
	new_node->next = NULL;
	stack_a->tail = new_node;
	stack_b_tail = stack_b->tail;
	free(stack_b_tail);
	stack_b->tail = penultimate_node;
	if (penultimate_node)
		penultimate_node->next = NULL;
	else
		stack_b->head = NULL;
	// printf("pa\n");
}

void	pb(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_data	*penultimate_node;
	t_data	*new_node;
	t_data	*stack_a_tail;

	penultimate_node = stack_a->tail->prev;
	new_node = malloc(sizeof(t_data));
	if (!new_node)
		return ;
	new_node->value = stack_a->tail->value;
	if (!stack_b->head)
	{
		new_node->prev = NULL;
		new_node->position = 1;
		stack_b->head = new_node;
	}
	else
	{
		new_node->prev = stack_b->tail;
		stack_b->tail->next = new_node;
		new_node->position = stack_b->tail->position + 1;
	}
	new_node->next = NULL;
	stack_b->tail = new_node;
	stack_a_tail = stack_a->tail;
	// free(stack_a_tail);
	stack_a->tail = penultimate_node;
	if (penultimate_node)
	{
		penultimate_node->next = NULL;
	}
	else
		stack_a->head = NULL;
	// printf("pb\n");
}

// void    pb(t_stack_a *stack_a, t_stack_b *stack_b)
// {
//     t_data  *penultimate_node;
//     t_data  *new_node;

//     penultimate_node = stack_a->tail->prev;
//     new_node = malloc(sizeof(t_data));
//     if (!new_node)
//         return ;
//     new_node->value = stack_a->tail->value;
//     if (!stack_b->head)
//     {
//         new_node->prev = NULL;
//         new_node->position = 1;
//         stack_b->head = new_node;
//     }
//     else
//     {
//         new_node->prev = stack_b->tail;
//         stack_b->tail->next = new_node;
//         new_node->position = stack_b->tail->position + 1;
//     }
//     new_node->next = NULL;
//     stack_b->tail = new_node;

//     // Update pointers in stack_a before freeing stack_a_tail
//     if (penultimate_node)
//         penultimate_node->next = NULL;
//     else
//         stack_a->head = NULL;

//     // Adjust stack_a->tail after updating pointers
//     stack_a->tail = penultimate_node;

//     printf("pb\n");
// }

