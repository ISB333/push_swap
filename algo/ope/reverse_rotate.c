/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:30:34 by isb3              #+#    #+#             */
/*   Updated: 2024/02/27 11:21:22 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	do_rra(t_stack **stack)
{
	t_stack	*last;

	last = *stack;
	while (last->next)
		last = last->next;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	last = (*stack)->prev;
	(*stack)->prev = NULL;
	last->next = NULL;
	last->position = 1;
	while (last)
	{
		last = last->prev;
		if (last)
			last->position = last->next->position + 1;
	}
}

void	do_rrb(t_stack **stack)
{
	t_stack	*last;

	last = *stack;
	while (last->next)
		last = last->next;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	last = (*stack)->prev;
	(*stack)->prev = NULL;
	last->next = NULL;
	last->position = 1;
	while (last)
	{
		last = last->prev;
		if (last)
			last->position = last->next->position + 1;
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	do_rra(stack_a);
	do_rrb(stack_b);
	printf("rr\n");
}

void	rra(t_stack **stack_a)
{
	do_rra(stack_a);
	printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	do_rrb(stack_b);
	printf("rrb\n");
}
