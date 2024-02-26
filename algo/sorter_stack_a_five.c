/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_stack_a_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:09:49 by adesille          #+#    #+#             */
/*   Updated: 2024/02/26 15:59:04 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    a_four_sorter(t_stack **stack_a, t_stack **stack_b)
{
	t_stack  *a_head;
	t_stack  *a_tail;
	t_stack  *b_tail;

	a_head = *stack_a;
	a_tail = a_tail_return((*stack_a));
	b_tail = b_tail_return((*stack_b));
	if (b_tail->value > a_tail->value)
		pa(stack_a, stack_b);
	else if (b_tail->value < a_tail->value && b_tail->value > a_tail->prev->value)
	{
		// printf("------------------------BEFORE 4sort_scen2------------------------\n");
		// stack_printer_a(stack_a);
		// printf("4sort_scen2\n");
		rra(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	else if (b_tail->value > a_head->value && b_tail->value < a_head->next->value)
	{
		// printf("4sort_scen3\n");
		ra(stack_a);
		pa(stack_a, stack_b);
		rra(stack_a);
		rra(stack_a);
	}
	else 
	{
		// printf("4sort_scen4\n");
		pa(stack_a, stack_b);
		rra(stack_a);
	}
}

void	a_last_sorter(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a_head;
	t_stack	*a_tail;
	t_stack	*b_head;

	a_head = *stack_a;
	a_tail = a_tail_return((*stack_a));
	b_head = *stack_a;
	if (b_head->value > a_tail->value)
	{
		pa(stack_a, stack_b);
	}
	else if(b_head->value > a_tail->prev->value)
	{
		ra(stack_a);
		pa(stack_a, stack_b);
		rra(stack_a);
	}
	else if (b_head->value > a_head->next->value)
	{
		ra(stack_a);
		ra(stack_a);
		pa(stack_a, stack_b);
		rra(stack_a);
		rra(stack_a);
	}
	else if (b_head->value > a_head->value)
	{
		rra(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
		ra(stack_a);
	}
	else
	{
		pa(stack_a, stack_b);
		rra(stack_a);
	}
}

void    five_sorter_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b_head;
	t_stack	*b_tail;
	// int *lowest;

	b_head = *stack_b;
	b_tail = b_tail_return(*stack_b);
	// lowest = smallest_finder(stack_b);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	// printf("-----------------BEFORE----------------\n");
	// stack_printer_a(stack_a);
	three_sorter_stack_a(stack_a);
	// printf("-----------------AFTER 3 SORTER----------------\n");
	// stack_printer_a(stack_a);
	if (b_tail->value > b_head->value)
		rb(stack_b);
	a_four_sorter(stack_a, stack_b);
	// printf("-----------------AFTER 4 SORTER----------------\n");
	// stack_printer_a(stack_a);
	a_last_sorter(stack_a, stack_b);
	// printf("-----------------AFTER 5 SORTER----------------\n");
	// stack_printer_a(stack_a);
	// printer(stack_a, stack_b);
}