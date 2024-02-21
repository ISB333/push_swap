/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:59:56 by adesille          #+#    #+#             */
/*   Updated: 2024/02/21 09:34:25 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	n_smallest_extractor(t_stack_a *stack_a, t_stack_b *stack_b, int n)
{
	int		*lowest_values;
	int 	i;
	int 	up;
	int		low;

	up = 0;
	low = 0;
	i = -1;
	if (ruler(stack_a, stack_b, 'A') < 10)
		n = ruler(stack_a, stack_b, 'A') - n; 
	lowest_values = n_smallest_finder(stack_a, n);
	extractor_utils(stack_a, stack_b, n, lowest_values);
	free(lowest_values);
}

void    push_swap(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int	n;

	printf("\n\n");
	if (ruler(stack_a, stack_b, 'A') <= 3)
		three_sorter_stack_a(stack_a);
	else if (ruler(stack_a, stack_b, 'A') <= 5)
		five_sorter_stack_a(stack_a, stack_b);
	else
	{
		printer(stack_a, stack_b);
		n = n_selector(stack_a, stack_b);
		while (ruler(stack_a, stack_b, 'A') > n)
			n_smallest_extractor(stack_a, stack_b, n);
		n = n_selector(stack_a, stack_b);
		while (ruler(stack_a, stack_b, 'A') > 5)
			n_smallest_extractor(stack_a, stack_b, n);
		pushing_back_to_a(stack_a, stack_b);
		printer(stack_a, stack_b);
	}
}

// void    pushing_back_to_a(t_stack_a *stack_a, t_stack_b *stack_b)
// {
// 	t_data 	*stack_b_tail;
// 	int		*larg_and_penult;

// 	stack_b_tail = stack_b->tail;
// 	while (ruler(stack_a, stack_b, 'B') > 3)
// 	{
// 		larg_and_penult = largest_finder(stack_b);
// 		if (stack_b_tail->value == larg_and_penult[1])
// 			penult_swapper(stack_a, stack_b, larg_and_penult[0]);
// 		else if (stack_b_tail->value == larg_and_penult[0])
// 			pa(stack_a, stack_b);
// 		rb(stack_b);
// 		stack_b_tail = stack_b->tail;
// 	}
// 	last_push(stack_a, stack_b);
// }
