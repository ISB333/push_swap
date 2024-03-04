/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:38:26 by isb3              #+#    #+#             */
/*   Updated: 2024/03/04 13:25:50 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	two_swapper(t_stack **stack_a, t_stack **stack_b, int value)
{
	t_stack	*b_head;

	pa(stack_a, stack_b);
	b_head = *stack_b;
	while (b_head->value != value)
	{
		rb(stack_b);
		b_head = *stack_b;
	}
	if (b_head->value == value)
	{
		pa(stack_a, stack_b);
		sa(stack_a);
	}
}

char	side_chooser(t_stack *stack_b, int value)
{
	t_stack	*b_head;
	t_stack	*b_tail;
	size_t	mid;

	b_head = stack_b;
	b_tail = return_tail(stack_b);
	mid = ruler(stack_b) / 2;
	while (b_head && b_head->value != value && b_head->position < mid)
		b_head = b_head->next;
	if (b_head->value == value)
		return ('U');
	while (b_tail && b_tail->value != value && b_tail->position > mid)
		b_tail = b_tail->prev;
	if (b_tail->value == value)
		return ('L');
	return (0);
}

void	pre_sorting_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a_head;
	t_stack	*a_tail;
	int		a_size;

	a_head = *stack_a;
	a_tail = return_tail(*stack_a);
	a_size = ruler(*stack_a);
	if (a_size == 5)
		five_sorter_stack_a(stack_a, stack_b);
	else if (a_size == 4)
	{
		pa(stack_a, stack_b);
		five_sorter_stack_a(stack_a, stack_b);
	}
	else if (a_size == 3)
		three_sorter_stack_a(stack_a);
	else if (a_size == 2)
		if (a_head->value > a_tail->value)
			sa(stack_a);
}

void	up_sorter(t_stack **stack_a, t_stack **stack_b, int *largest)
{
	t_stack	*b_head;
	int		token;

	token = 0;
	b_head = *stack_b;
	while (b_head->value != largest[0])
	{
		rb(stack_b);
		b_head = *stack_b;
		if (b_head->value == largest[1])
		{
			pa(stack_a, stack_b);
			b_head = *stack_b;
			token = 1;
		}
	}
	pa(stack_a, stack_b);
	if (token == 1)
		sa(stack_a);
}

void	low_sorter(t_stack **stack_a, t_stack **stack_b, int *largest)
{
	t_stack	*b_head;
	int		token;

	token = 0;
	b_head = *stack_b;
	while (b_head->value != largest[0])
	{
		rrb(stack_b);
		b_head = *stack_b;
		if (b_head->value == largest[1])
		{
			pa(stack_a, stack_b);
			b_head = *stack_b;
			token = 1;
		}
	}
	pa(stack_a, stack_b);
	if (token == 1)
		sa(stack_a);
}
