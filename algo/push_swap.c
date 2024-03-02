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

// void	sorter()

void	pre_sorting_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a_head;
	t_stack	*a_tail;
	int a_size;

	a_head = *stack_a;
	a_tail = return_tail(*stack_a);
	a_size = ruler(*stack_a);
	if (a_size == 5)
	{
		// printf("size 5\n");
		five_sorter_stack_a(stack_a, stack_b);
	}
	else if (a_size == 4)
	{
		// printf("size 4\n");
		pa(stack_a, stack_b);
		five_sorter_stack_a(stack_a, stack_b);
	}
	else if (a_size == 3)
	{
		// printf("size 3\n");
		three_sorter_stack_a(stack_a);
	}
	else if (a_size == 2)
	{
		// printf("size 2\n");
		if (a_head->value > a_tail->value)
			sa(stack_a);
	}

}

void    sorter(t_stack **stack_a, t_stack **stack_b)
{
	// t_stack	*b_head;
	// int		*largest;
	// char	side;

	pre_sorting_a(stack_a, stack_b);
	// b_head = *stack_b;
	// while (ruler(*stack_b) > 3)
	// {
	// 	largest = largest_scrapper(*stack_b, 3);
	// 	side = b_to_a_side_chooser(largest, (*stack_b), (*stack_b)->position, 0);
	// 	if (b_head->value == largest[0])
	// 		pa(stack_a, stack_b);
	// 	else if (b_head->value == largest[1])
	// 		two_swapper(stack_a, stack_b, largest[0]);
	// 	else 
	// 		if (side == 'U')
	// 			rb(stack_b);
	// 		else if (side == 'L')
	// 			rrb(stack_b);
	// 	b_head = *stack_b;
	// 	free(largest);
	// }
	// last_push(stack_a, stack_b);
	sorting_checker(*stack_a);
}

void    push_swap(t_stack **stack_a, t_stack **stack_b)
{
	// printf("\n");
	// printer(*stack_a, *stack_b, 2);
	if (ruler(*stack_a) <= 3)
		three_sorter_stack_a(stack_a);
	else if (ruler(*stack_a) <= 5)
		five_sorter_stack_a(stack_a, stack_b);
	else
	{
		extractor(stack_a, stack_b, n_selector(*stack_a));
		// sorter(stack_a, stack_b);
		sorter(stack_a, stack_b);
		printer(*stack_a, *stack_b, 0);
	}
}
