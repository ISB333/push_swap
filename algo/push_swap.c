/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:59:56 by adesille          #+#    #+#             */
/*   Updated: 2024/02/12 13:44:45 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    push_swap(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int a_cheapest_pos;

	if (ruler(stack_a, stack_b, 'A') <= 3)
		three_sorter_stack_a(stack_a);
	else if (ruler(stack_a, stack_b, 'A') <= 5)
		five_sorter_stack_a(stack_a, stack_b);
	else
	{
		while(ruler(stack_a, stack_b, 'B') < 3)
			pb(stack_a, stack_b);
		three_sorter_stack_b(stack_b);
		five_sorter_stack_b(stack_a, stack_b);
 
		while(ruler(stack_a, stack_b, 'A') > 3)
		{
			cost_initializer(stack_a, stack_b);
        }
		printer(stack_a, stack_b);
	}
}
