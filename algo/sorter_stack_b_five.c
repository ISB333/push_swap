/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_stack_b_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:09:49 by adesille          #+#    #+#             */
/*   Updated: 2024/02/25 09:56:46 by isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    b_four_sorter(t_stack *stack_a, t_stack *stack_b)
{
	t_stack  *stack_b_head;
	t_stack  *stack_b_tail;
	t_stack  *stack_a_tail;

	stack_b_head = stack_b;
	stack_b_tail = stack_b;
	stack_a_tail = stack_a;
	if (stack_a_tail->value < stack_b_tail->value)
		pb(&stack_a, &stack_b);
	else if (stack_a_tail->value > stack_b_tail->value && stack_a_tail->value < stack_b_tail->prev->value)
	{
		rrb(&stack_b);
		pb(&stack_a, &stack_b);
		rb(&stack_b);
	}
	else if (stack_a_tail->value < stack_b_head->value && stack_a_tail->value > stack_b_head->next->value)
	{
		rb(&stack_b);
		pb(&stack_a, &stack_b);
		rrb(&stack_b);
		rrb(&stack_b);
	}
	else 
	{
		pb(&stack_a, &stack_b);
		rrb(&stack_b);
	}
}

void	b_last_sorter(t_stack *stack_a, t_stack *stack_b)
{
	t_stack  *stack_b_head;
	t_stack  *stack_b_tail;
	t_stack  *stack_a_tail;

	stack_b_head = stack_b;
	stack_b_tail = stack_b;
	stack_a_tail = stack_a;
	if (stack_a_tail->value < stack_b_tail->value)
	{
		pb(&stack_a, &stack_b);
	}
	else if(stack_a_tail->value < stack_b_tail->prev->value)
	{
		rrb(&stack_b);
		pb(&stack_a, &stack_b);
		rb(&stack_b);
	}
	else if (stack_a_tail->value < stack_b_head->next->value)
	{
		rrb(&stack_b);
		rrb(&stack_b);
		pb(&stack_a, &stack_b);
		rb(&stack_b);
		rb(&stack_b);
	}
	else if (stack_a_tail->value < stack_b_head->value)
	{
		rb(&stack_b);
		pb(&stack_a, &stack_b);
		rrb(&stack_b);
		rrb(&stack_b);
	}
	else
	{
		pb(&stack_a, &stack_b);
		rb(&stack_b);
	}
}

void    five_sorter_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*stack_a_tail;

	stack_a_tail = stack_a;
	if(stack_a_tail->value < stack_a_tail->prev->value)
		sa(&stack_a);
	b_four_sorter(stack_a, stack_b);
	b_last_sorter(stack_a, stack_b);
	// printer(stack_a, stack_b);
}