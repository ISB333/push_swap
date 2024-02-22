/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_stack_a_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:09:49 by adesille          #+#    #+#             */
/*   Updated: 2024/02/22 13:56:07 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    a_four_sorter(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_data  *stack_a_head;
	t_data  *stack_a_tail;
	t_data  *stack_b_tail;

	stack_a_head = stack_a->head;
	stack_a_tail = stack_a->tail;
	stack_b_tail = stack_b->tail;
	if (stack_b_tail->value < stack_a_tail->value)
		pa(stack_a, stack_b);
	else if (stack_b_tail->value > stack_a_tail->value && stack_b_tail->value < stack_a_tail->prev->value)
	{
		rra(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	else if (stack_b_tail->value < stack_a_head->value && stack_b_tail->value > stack_a_head->next->value)
	{
		ra(stack_a);
		pa(stack_a, stack_b);
		rra(stack_a);
		rra(stack_a);
	}
	else 
	{
		pa(stack_a, stack_b);
		rra(stack_a);
	}
}

void	a_last_sorter(t_stack_a *stack_a, t_stack_b *stack_b)
{
	if (stack_b->head->value < stack_a->tail->value)
	{
		pa(stack_a, stack_b);
	}
	else if(stack_b->head->value < stack_a->tail->prev->value)
	{
		rra(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	else if (stack_b->head->value < stack_a->head->next->value)
	{
		rra(stack_a);
		rra(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
		ra(stack_a);
	}
	else if (stack_b->head->value < stack_a->head->value)
	{
		ra(stack_a);
		pa(stack_a, stack_b);
		rra(stack_a);
		rra(stack_a);
	}
	else
	{
		pa(stack_a, stack_b);
		ra(stack_a);
	}
}

void    five_sorter_stack_a(t_stack_a *stack_a, t_stack_b *stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	three_sorter_stack_a(stack_a);
	if(stack_b->tail->value < stack_b->head->value)
		rb(stack_b);
	a_four_sorter(stack_a, stack_b);
	a_last_sorter(stack_a, stack_b);
	// printer(stack_a, stack_b);
}