/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:36:49 by isb3              #+#    #+#             */
/*   Updated: 2024/03/03 09:53:02 by isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	last_push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b_head;
	int		i;

	b_head = *stack_b;
	// if (ruler(stack_a, stack_b, 'B') == 5)
	// {
	// 	i = 5;
	// 	five_sorter_stack_b(stack_a, stack_b);
	// 	while (i-- > 0)
	// 		pa(stack_a, stack_b);
	// }
	if (ruler(*stack_b) == 4)
	{
		printf("scen1, size == 4\n");
		i = 3;
		pb(stack_a, stack_b);
		five_sorter_stack_b(stack_a, stack_b);
		while (i-- > 0)
			pa(stack_a, stack_b);
	}
	else if (ruler(*stack_b) == 3)
	{
		printf("scen2, size == 3\n");
		i = 3;
		three_sorter_stack_b(stack_b);
		while (i-- > 0)
			pa(stack_a, stack_b);
	}
	else
	{
		printf("scen3, size == 2\n");
		if (b_head->value < b_head->next->value)
		{
			sb(stack_b);
			pa(stack_a, stack_b);
			pa(stack_a, stack_b);
		}
		else
		{
			pa(stack_a, stack_b);
			pa(stack_a, stack_b);
		}
	}
}