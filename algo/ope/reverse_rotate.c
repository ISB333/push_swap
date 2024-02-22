/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:30:34 by isb3              #+#    #+#             */
/*   Updated: 2024/02/22 10:18:44 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// void	do_rra(t_stack_a *stack)
// {
// 	t_data	*first_node;
// 	t_data	*last_node;
// 	t_data	*penultimate_node;

// 	first_node = stack->head;
// 	last_node = stack->tail;
// 	penultimate_node = stack->tail->prev;
// 	last_node->prev = first_node->prev;
// 	penultimate_node->next = last_node->next;
// 	last_node->next = first_node;
// 	first_node->prev = last_node;
// 	last_node->position = 1;
// 	while (first_node)
// 	{
// 		first_node->position++;
// 		first_node = first_node->next;
// 	}
// 	stack->head = last_node;
// 	stack->tail = penultimate_node;
// }

// void	do_rrb(t_stack_b *stack)
// {
// 	t_data	*first_node;
// 	t_data	*last_node;
// 	t_data	*penultimate_node;

// 	first_node = stack->head;
// 	last_node = stack->tail;
// 	penultimate_node = stack->tail->prev;
// 	last_node->prev = first_node->prev;
// 	penultimate_node->next = last_node->next;
// 	last_node->next = first_node;
// 	first_node->prev = last_node;
// 	last_node->position = 1;
// 	while (first_node)
// 	{
// 		first_node->position++;
// 		first_node = first_node->next;
// 	}
// 	stack->head = last_node;
// 	stack->tail = penultimate_node;
// }

// void do_rra(t_stack_a *stack)
// {
//     if (stack && stack->tail && stack->tail->prev)
//     {
//         t_data *new_tail = stack->tail->prev;
//         t_data *current = stack->tail;
//         current->prev = NULL;
//         current->next = stack->head;
//         stack->head->prev = current;
//         stack->head = current;
//         new_tail->next = NULL;
//         stack->tail = new_tail;

//         // Update positions
//         current = stack->head;
//         int position = 1;
//         while (current)
//         {
//             current->position = position++;
//             current = current->next;
//         }
//     }
// }

void do_rra(t_stack_a *stack)
{
    if (stack && stack->tail && stack->tail->prev)
    {
        t_data *new_tail = stack->tail->prev;
        t_data *current = stack->tail;
		while (current->prev)
			current = current->prev;
        current->prev = stack->tail;
        // current->next = stack->head;
        stack->tail->next = current;
        stack->tail->prev = NULL;
        new_tail->next = NULL;
		stack->head = stack->tail;
        stack->tail = new_tail;

        // Update positions
        current = stack->head;
        int position = 1;
        while (current)
        {
            current->position = position++;
            current = current->next;
        }
    }
}

void do_rrb(t_stack_b *stack)
{
    if (stack && stack->tail && stack->tail->prev)
    {
        t_data *new_tail = stack->tail->prev;
        t_data *current = stack->tail;
		while (current->prev)
			current = current->prev;
        current->prev = stack->tail;
        // current->next = stack->head;
        stack->tail->next = current;
        stack->tail->prev = NULL;
        new_tail->next = NULL;
		stack->head = stack->tail;
        stack->tail = new_tail;

        // Update positions
        current = stack->head;
        int position = 1;
        while (current)
        {
            current->position = position++;
            current = current->next;
        }
    }
}

// void	do_rb(t_stack_b *stack)
// {
// 	if (stack && stack->head && stack->head->next)
// 	{
// 		t_data *new_head = stack->head->next;
// 		t_data *current = new_head;
// 		while (current->next)
// 		{
// 			current = current->next;
// 		}
// 		current->next = stack->head;
// 		stack->head->prev = current;
// 		stack->head->next = NULL;
// 		new_head->prev = NULL;
// 		stack->tail = stack->head;
// 		stack->head = new_head;

// 		// Update positions
// 		current = stack->head;
// 		int position = 1;
// 		while (current)
// 		{
// 			current->position = position++;
// 			current = current->next;
// 		}
// 	}
// }

void	rrr(t_stack_a *stack_a, t_stack_b *stack_b)
{
	do_rra(stack_a);
	do_rrb(stack_b);
	// printf("rrr\n");
}

void	rra(t_stack_a *stack_a)
{
	do_rra(stack_a);
	// printf("rra\n");
}

void	rrb(t_stack_b *stack_b)
{
	do_rrb(stack_b);
	// printf("rrb\n");
}
