/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sorter_stack_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:09:49 by adesille          #+#    #+#             */
/*   Updated: 2024/02/08 09:45:31 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    b_four_sorter(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_data  *stack_b_head;
	t_data  *stack_b_tail;
	t_data  *stack_a_tail;

	stack_b_head = stack_b->head;
	stack_b_tail = stack_b->tail;
	stack_a_tail = stack_a->tail;
	if (stack_a_tail->value < stack_b_tail->value)
		pb(stack_a, stack_b);
	else if (stack_a_tail->value > stack_b_tail->value && stack_a_tail->value < stack_b_tail->prev->value)
	{
		rrb(stack_b);
		pb(stack_a, stack_b);
		rb(stack_b);
	}
	else if (stack_a_tail->value < stack_b_head->value && stack_a_tail->value > stack_b_head->next->value)
	{
		rb(stack_b);
		pb(stack_a, stack_b);
		rrb(stack_b);
		rrb(stack_b);
	}
	else 
	{
		pb(stack_a, stack_b);
		rrb(stack_b);
	}
}

void	b_last_sorter(t_stack_a *stack_a, t_stack_b *stack_b)
{
	if (stack_a->tail->value < stack_b->tail->value)
	{
		pb(stack_a, stack_b);
	}
	else if(stack_a->tail->value < stack_b->tail->prev->value)
	{
		rrb(stack_b);
		pb(stack_a, stack_b);
		rb(stack_b);
	}
	else if (stack_a->tail->value < stack_b->head->next->value)
	{
		rrb(stack_b);
		rrb(stack_b);
		pb(stack_a, stack_b);
		rb(stack_b);
		rb(stack_b);
	}
	else if (stack_a->tail->value < stack_b->head->value)
	{
		rb(stack_b);
		pb(stack_a, stack_b);
		rrb(stack_b);
		rrb(stack_b);
	}
	else
	{
		pb(stack_a, stack_b);
		rb(stack_b);
	}
}

void    five_sorter_stack_b(t_stack_a *stack_a, t_stack_b *stack_b)
{
	if(stack_a->tail->value < stack_a->tail->prev->value)
		sa(stack_a);
	b_four_sorter(stack_a, stack_b);
	b_last_sorter(stack_a, stack_b);
	// printer(stack_a, stack_b);
}