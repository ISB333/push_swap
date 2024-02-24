/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:30:34 by isb3              #+#    #+#             */
/*   Updated: 2024/02/24 16:51:51 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	do_ra(t_stack **stack)
{
	t_stack	*last;

	last = *stack;
	while (last->next)
		last = last->next;
	last->next = *stack;
	(*stack)->prev = last;
	last = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next = NULL;
}

void	do_rb(t_stack **stack)
{
	t_stack	*last;

	last = *stack;
	while (last->next)
		last = last->next;
	last->next = *stack;
	(*stack)->prev = last;
	last = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next = NULL;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	do_ra(stack_a);
	do_rb(stack_b);
	printf("rrr\n");
}

void	ra(t_stack **stack_a)
{
	do_ra(stack_a);
	printf("rra\n");
}

void	rb(t_stack **stack_b)
{
	do_rb(stack_b);
	printf("rrb\n");
}
