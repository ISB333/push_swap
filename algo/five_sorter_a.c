/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sorter_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:09:49 by adesille          #+#    #+#             */
/*   Updated: 2024/03/05 09:55:56 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	four_sorter_utils(t_stack **stack_a, t_stack **stack_b, int scen)
{
	if (scen == 1)
	{
		rra(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
		ra(stack_a);
	}
	else if (scen == 2)
	{
		pa(stack_a, stack_b);
		sa(stack_a);
	}
	else if (scen == 3)
	{
		pa(stack_a, stack_b);
		ra(stack_a);
	}
}

void	a_four_sorter(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a_head;
	t_stack	*a_tail;
	t_stack	*b_head;

	if (!*stack_a || !(*stack_a)->next || !stack_a)
		return ;
	else if (!*stack_b || !(*stack_b)->next || !stack_b)
		return ;
	a_head = *stack_a;
	a_tail = return_tail(*stack_a);
	b_head = *stack_b;
	if (b_head->value < a_head->value)
		pa(stack_a, stack_b);
	else if (b_head->value < a_tail->value
		&& b_head->value > a_tail->prev->value)
		four_sorter_utils(stack_a, stack_b, 1);
	else if (b_head->value > a_head->value
		&& b_head->value < a_head->next->value)
		four_sorter_utils(stack_a, stack_b, 2);
	else
		four_sorter_utils(stack_a, stack_b, 3);
}

void	last_sorter_utils(t_stack **stack_a, t_stack **stack_b, int scen)
{
	if (scen == 1)
	{
		pa(stack_a, stack_b),
		ra(stack_a);
	}
	else if (scen == 2)
	{
		pa(stack_a, stack_b);
		sa(stack_a);
	}
	else if (scen == 3)
	{
		rra(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
		ra(stack_a);
	}
	else if (scen == 4)
	{
		ra(stack_a);
		pa(stack_a, stack_b);
		sa(stack_a);
		rra(stack_a);
	}
}

void	a_last_sorter(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a_head;
	t_stack	*a_tail;
	t_stack	*b_head;

	if (!*stack_a || !(*stack_a)->next || !stack_a)
		return ;
	else if (!*stack_b || !stack_b)
		return ;
	a_head = *stack_a;
	a_tail = return_tail(*stack_a);
	b_head = *stack_b;
	if (b_head->value < a_head->value)
		pa(stack_a, stack_b);
	else if (b_head->value > a_tail->value)
		last_sorter_utils(stack_a, stack_b, 1);
	else if (b_head->value > a_head->value
		&& b_head->value < a_head->next->value)
		last_sorter_utils(stack_a, stack_b, 2);
	else if (b_head->value < a_tail->value
		&& b_head->value > a_tail->prev->value)
		last_sorter_utils(stack_a, stack_b, 3);
	else
		last_sorter_utils(stack_a, stack_b, 4);
}

void	five_sorter_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	while (ruler(*stack_a) > 3)
		pb(stack_a, stack_b);
	three_sorter_stack_a(stack_a);
	a_four_sorter(stack_a, stack_b);
	a_last_sorter(stack_a, stack_b);
}
