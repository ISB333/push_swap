/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:59:56 by adesille          #+#    #+#             */
/*   Updated: 2024/02/25 10:32:04y isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pre_sorting_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*stack_a_head;
	t_stack	*stack_a_tail;

	stack_a_head = stack_a;
	stack_a_tail = stack_a;
	int a_size;

	a_size = ruler(&stack_a, &stack_b, 'A');
	if (a_size == 5)
	{
		// printf("size 5\n");
		five_sorter_stack_a(stack_a, stack_b);
	}
	else if (a_size == 4)
	{
		// printf("size 4\n");
		pa(&stack_a, &stack_b);
		five_sorter_stack_a(stack_a, stack_b);
		// printf("=======================================AFTER size 4=======================================");
		// stack_printer_a(stack_a);
	}
	else if (a_size == 3)
	{
		// printf("size 3\n");
		three_sorter_stack_a(stack_a);
	}
	else if (a_size == 2)
	{
		// printf("size 2\n");
		if (stack_a_head->value > stack_a_tail->value)
			sa(&stack_a);
	}
}

void    pushing_back_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack 	*stack_b_tail;
	int		*three_lowest;

	// int i = 1;
	pre_sorting_a(stack_a, stack_b);
	// stack_printer_a(stack_a);
	stack_b_tail = stack_b;
	while (ruler(&stack_a, &stack_b, 'B') > 3)
	{
		three_lowest = smallest_finder(stack_b);
		if (stack_b_tail->value == three_lowest[0])
			pa(&stack_a, &stack_b);
		else if (stack_b_tail->value == three_lowest[2])
			third_low_swapper(stack_a, stack_b, three_lowest);
		else if (stack_b_tail->value == three_lowest[1])
			two_low_swapper(stack_a, stack_b, three_lowest[0]);
		else 
			rb(&stack_b);
		checker(stack_a);
		stack_b_tail = stack_b;
	}
	// printer(stack_a, stack_b);
	last_push(stack_a, stack_b);
	// sorting_checker(stack_a);
}

void	n_smallest_extractor(t_stack *stack_a, t_stack *stack_b, int n)
{
	int		*lowest_values;
	// int 	i;

	// i = -1;
	lowest_values = n_largest_finder(stack_a, n);
	extractor_utils(stack_a, stack_b, n, lowest_values);
	free(lowest_values);
}

void    push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	n;

	// printf("\n\n");
	if (ruler(stack_a, stack_b, 'A') <= 3)
		printf("SIZE 3\n");
		// three_sorter_stack_a(stack_a);
	else if (ruler(stack_a, stack_b, 'A') <= 5)
		printf("SIZE 5\n");
		// five_sorter_stack_a(stack_a, stack_b);
	else
	{
		n = n_selector((*stack_a));
		while (ruler(stack_a, stack_b, 'A') >= n)
			pb(stack_a, stack_b);
			// n_smallest_extractor((*stack_a), (*stack_b), n);
		// n = n_selector(stack_a, stack_b);
		// while (ruler(stack_a, stack_b, 'A') > 5)
		// 	n_smallest_extractor(stack_a, stack_b, n);
		// printer(stack_a, stack_b);
		// pushing_back_to_a(stack_a, stack_b);
		printer((*stack_a), (*stack_b), 2);
	}
}
