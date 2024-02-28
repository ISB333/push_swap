/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_stack_a_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:09:49 by adesille          #+#    #+#             */
/*   Updated: 2024/02/27 14:10:06 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    a_four_sorter(t_stack **stack_a, t_stack **stack_b)
{
	t_stack  *a_head;
	t_stack  **a_tail;
	t_stack  *b_head;

	a_head = *stack_a;
	a_tail = return_tail(stack_a);
	b_head = *stack_b;
	if (b_head->value < a_head->value)
		pa(stack_a, stack_b);
	else if (b_head->value < (*a_tail)->value && b_head->value > (*a_tail)->prev->value)
	{
		// printf("4sort_scen2 = b_head == pos2\n");
		rra(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
		ra(stack_a);
	}
	else if (b_head->value > a_head->value && b_head->value < a_head->next->value)
	{
		// printf("4sort_scen3 = b_head == penult_top\n");
		pa(stack_a, stack_b);
		sa(stack_a);
	}
	else 
	{
		// printf("4sort_scen4\n");
		pa(stack_a, stack_b);
		ra(stack_a);
	}
}

void	a_last_sorter(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a_head;
	t_stack	**a_tail;
	t_stack	*b_head;

	a_head = *stack_a;
	a_tail = return_tail(stack_a);
	b_head = *stack_b;
	// printf("a_head = %d\na_tail = %d\nb_head = %d\n", a_head->value, (*a_tail)->value, b_head->value);
	if (b_head->value < a_head->value)
		pa(stack_a, stack_b);
	else if (b_head->value > (*a_tail)->value)
	{
		// printf("LAST = scen2\n");
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	else if (b_head->value > a_head->value && b_head->value < a_head->next->value)
	{
		// printf("LAST = scen3\n");
		pa(stack_a, stack_b);
		sa(stack_a);
	}
	else if (b_head->value < (*a_tail)->value && b_head->value > (*a_tail)->prev->value)
	{
		// printf("LAST = scen4\n");
		rra(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
		ra(stack_a);
	}
	else
	{
		// printf("LAST = scen5\n");
		ra(stack_a);
		pa(stack_a, stack_b);
		sa(stack_a);
		rra(stack_a);
	}
}

void    five_sorter_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	three_sorter_stack_a(stack_a);
	a_four_sorter(stack_a, stack_b);
	a_last_sorter(stack_a, stack_b);
}