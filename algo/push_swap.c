/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:59:56 by adesille          #+#    #+#             */
/*   Updated: 2024/02/14 14:39:14 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void	n_smallest_extractor(t_stack_a *stack_a, t_stack_b *stack_b, int n)
{
	int		*lowest_values;
	// char	side;
	// int 	n;
	int 	i;
	int 	up;
	int		low;

	up = 0;
	low = 0;
	i = -1;
	if (ruler(stack_a, stack_b, 'A') < 10)
		n = ruler(stack_a, stack_b, 'A') - n; 
	lowest_values = n_smallest_finder(stack_a, n);
	// n = n_selector(stack_a, stack_b);
	// side = side_chooser(lowest_values, stack_a, ruler(stack_a, stack_b, 'A') / 2, up, low);
	while (lowest_values[++i])
		printf("value n%d = %d\n", i, lowest_values[i]);
	extractor_utils(stack_a, stack_b, n, lowest_values);
	printer(stack_a, stack_b);
}

void    push_swap(t_stack_a *stack_a, t_stack_b *stack_b)
{
	// int a_cheapest_pos;
	int	n;

	printf("\n\n");
	if (ruler(stack_a, stack_b, 'A') <= 3)
		three_sorter_stack_a(stack_a);
	else if (ruler(stack_a, stack_b, 'A') <= 5)
		five_sorter_stack_a(stack_a, stack_b);
	else
	{
		n = n_selector(stack_a, stack_b);
		while (ruler(stack_a, stack_b, 'A') > 5)
			n_smallest_extractor(stack_a, stack_b, n);
		five_sorter_stack_a(stack_a, stack_b);
		while(ruler(stack_a, stack_b, 'A') > 0)
			pb(stack_a, stack_b);
		// while(ruler(stack_a, stack_b, 'A') > 3)
		// {
		// 	cost_initializer(stack_a, stack_b);
		// }
		printer(stack_a, stack_b);
	}
}
