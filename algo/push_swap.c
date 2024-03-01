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

void    push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	n;

	// printf("\n");
	// printer(*stack_a, *stack_b, 2);
	if (ruler(*stack_a) <= 3)
		three_sorter_stack_a(stack_a);
	else if (ruler(*stack_a) <= 5)
		five_sorter_stack_a(stack_a, stack_b);
	else
	{
		n = n_selector(*stack_a);
		// int i = 3;
		// while (i-- > 0)
		while (ruler(*stack_a) > 5)
			n_smallest_extractor(stack_a, stack_b, n);
		printer(*stack_a, *stack_b, 2);
		// pushing_back_to_a(stack_a, stack_b);
	}
}
