/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_stack_b_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:09:49 by adesille          #+#    #+#             */
/*   Updated: 2024/02/27 12:38:28 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    b_four_sorter(t_stack **stack_a, t_stack **stack_b)
{
	t_stack  *b_head;
	t_stack  **b_tail;
	t_stack  **a_tail;

	b_head = *stack_b;
	b_tail = return_tail(stack_b);
	a_tail = return_tail(stack_a);
	if ((*a_tail)->value < (*b_tail)->value)
		pb(stack_a, stack_b);
	else if ((*a_tail)->value > (*b_tail)->value && (*a_tail)->value < (*b_tail)->prev->value)
	{
		rrb(stack_b);
		pb(stack_a, stack_b);
		rb(stack_b);
	}
	else if ((*a_tail)->value < b_head->value && (*a_tail)->value > b_head->next->value)
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

void	b_last_sorter(t_stack **stack_a, t_stack **stack_b)
{
	t_stack  *b_head;
	t_stack  **b_tail;
	t_stack  **a_tail;

	b_head = *stack_b;
	b_tail = return_tail(stack_b);
	a_tail = return_tail(stack_a);
	if ((*a_tail)->value < (*b_tail)->value)
	{
		pb(stack_a, stack_b);
	}
	else if((*a_tail)->value < (*b_tail)->prev->value)
	{
		rrb(stack_b);
		pb(stack_a, stack_b);
		rb(stack_b);
	}
	else if ((*a_tail)->value < b_head->next->value)
	{
		rrb(stack_b);
		rrb(stack_b);
		pb(stack_a, stack_b);
		rb(stack_b);
		rb(stack_b);
	}
	else if ((*a_tail)->value < b_head->value)
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

void    five_sorter_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	**a_tail;

	a_tail = return_tail(stack_a);
	if((*a_tail)->value < (*a_tail)->prev->value)
		sa(stack_a);
	b_four_sorter(stack_a, stack_b);
	b_last_sorter(stack_a, stack_b);
	// printer(stack_a, stack_b);
}