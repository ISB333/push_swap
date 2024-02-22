/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:30:34 by isb3              #+#    #+#             */
/*   Updated: 2024/02/22 10:19:01 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
/// HEAD become TAIL



// void	do_ra(t_stack_a *stack)
// {
// 	t_data	*first_node;
// 	t_data	*last_node;

// 	first_node = stack->head;
// 	last_node = stack->tail;

// 	first_node->prev = last_node;
// 	last_node->next = first_node;

// 	first_node->next->prev = NULL;
// 	stack->head = first_node->next;
// 	first_node->next = NULL;

// 	stack->tail = first_node;
// 	first_node->position = last_node->position + 1;
// 	while (first_node)
// 	{
// 		first_node->position--;
// 		first_node = first_node->prev;
// 	}
// }

void	do_rb(t_stack_b *stack)
{
	if (stack && stack->head && stack->head->next)
	{
		t_data *new_head = stack->head->next;
		t_data *current = new_head;
		while (current->next)
		{
			current = current->next;
		}
		current->next = stack->head;
		stack->head->prev = current;
		stack->head->next = NULL;
		new_head->prev = NULL;
		stack->tail = stack->head;
		stack->head = new_head;

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

void	do_ra(t_stack_a *stack)
{
	if (stack && stack->head && stack->head->next)
	{
		t_data *new_head = stack->head->next;
		t_data *current = new_head;
		while (current->next)
		{
			current = current->next;
		}
		current->next = stack->head;
		stack->head->prev = current;
		stack->head->next = NULL;
		new_head->prev = NULL;
		stack->tail = stack->head;
		stack->head = new_head;

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
// 	t_data	*first_node;
// 	t_data	*second_node;
// 	t_data	*f_node;
// 	t_data	*last_node;

// 	first_node = stack->head;
// 	last_node = stack->tail;
// 	second_node = stack->head->next;
// 	printf("first_node_val = %d\n", first_node->value);
// 	first_node->prev = last_node;
// 	last_node->next = first_node;

// 	stack->head = second_node;
// 	// first_node->next->prev = NULL;
// 	second_node->prev = NULL;
// 	first_node->next = NULL;

// 	stack->tail = first_node;
// 	first_node->position = last_node->position + 1;
// 	f_node = stack->head; 
// 	int i = 100;
// 	while (i-- > 50)
// 	{
// 		printf("first_node->pos = %d\n", f_node->position);
// 		printf("first_node_val = %d\n", f_node->value);
// 		f_node->position--;
// 		if (f_node->position == 1)
// 			return ;
// 		f_node = first_node->next;
// 	}
// }

void	rr(t_stack_a *stack_a, t_stack_b *stack_b)
{
	do_ra(stack_a);
	do_rb(stack_b);
	// printf("rr\n");
}

void	ra(t_stack_a *stack_a)
{
	do_ra(stack_a);
	// printf("ra\n");
}

void	rb(t_stack_b *stack_b)
{
	do_rb(stack_b);
	// printf("rb\n");
}
