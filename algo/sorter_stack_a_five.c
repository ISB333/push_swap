/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_stack_a_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:09:49 by adesille          #+#    #+#             */
/*   Updated: 2024/02/25 09:55:48 by isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    a_four_sorter(t_stack *stack_a, t_stack *stack_b)
{
	t_stack  *stack_a_head;
	t_stack  *stack_a_tail;
	t_stack  *stack_b_tail;

	stack_a_head = stack_a;
	stack_a_tail = stack_a;
	stack_b_tail = stack_b;
	if (stack_b_tail->value > stack_a_tail->value)
		pa(&stack_a, &stack_b);
	else if (stack_b_tail->value < stack_a_tail->value && stack_b_tail->value > stack_a_tail->prev->value)
	{
		// printf("------------------------BEFORE 4sort_scen2------------------------\n");
		// stack_printer_a(stack_a);
		// printf("4sort_scen2\n");
		rra(&stack_a);
		pa(&stack_a, &stack_b);
		ra(&stack_a);
	}
	else if (stack_b_tail->value > stack_a_head->value && stack_b_tail->value < stack_a_head->next->value)
	{
		// printf("4sort_scen3\n");
		ra(&stack_a);
		pa(&stack_a, &stack_b);
		rra(&stack_a);
		rra(&stack_a);
	}
	else 
	{
		// printf("4sort_scen4\n");
		pa(&stack_a, &stack_b);
		rra(&stack_a);
	}
}

void	a_last_sorter(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*stack_a_head;
	t_stack	*stack_a_tail;
	t_stack	*stack_b_head;

	stack_a_head = stack_a;
	stack_a_tail = stack_a;
	stack_b_head = stack_a;
	if (stack_b_head->value > stack_a_tail->value)
	{
		pa(&stack_a, &stack_b);
	}
	else if(stack_b_head->value > stack_a_tail->prev->value)
	{
		ra(&stack_a);
		pa(&stack_a, &stack_b);
		rra(&stack_a);
	}
	else if (stack_b_head->value > stack_a_head->next->value)
	{
		ra(&stack_a);
		ra(&stack_a);
		pa(&stack_a, &stack_b);
		rra(&stack_a);
		rra(&stack_a);
	}
	else if (stack_b_head->value > stack_a_head->value)
	{
		rra(&stack_a);
		pa(&stack_a, &stack_b);
		ra(&stack_a);
		ra(&stack_a);
	}
	else
	{
		pa(&stack_a, &stack_b);
		rra(&stack_a);
	}
}

void    five_sorter_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*stack_b_head;
	t_stack	*stack_b_tail;
	// int *lowest;

	stack_b_head = stack_b;
	stack_b_tail = stack_b;
	// lowest = smallest_finder(stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	// printf("-----------------BEFORE----------------\n");
	// stack_printer_a(stack_a);
	three_sorter_stack_a(stack_a);
	// printf("-----------------AFTER 3 SORTER----------------\n");
	// stack_printer_a(stack_a);
	if (stack_b_tail->value > stack_b_head->value)
		rb(&stack_b);
	a_four_sorter(stack_a, stack_b);
	// printf("-----------------AFTER 4 SORTER----------------\n");
	// stack_printer_a(stack_a);
	a_last_sorter(stack_a, stack_b);
	// printf("-----------------AFTER 5 SORTER----------------\n");
	// stack_printer_a(stack_a);
	// printer(stack_a, stack_b);
}