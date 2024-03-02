/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extractor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 08:48:19 by adesille          #+#    #+#             */
/*   Updated: 2024/03/02 09:45:31by isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    extractor(t_stack **stack_a, t_stack **stack_b, int n)
{
	int		*largest;
	int		*lowest;
	t_stack	*a_head;
	int 	i;

	while (ruler(*stack_a) > 5)
	{
		lowest = n_smallest_scrapper((*stack_a), n);
		largest = n_2nd_scrapper((*stack_a), lowest, n);
		a_head = (*stack_a); 
		i = 0;
		// int k = -1;
		// while (lowest[++k])
		// 	printf("lowest[%d] = %d\n", k, lowest[k]);
		// k = -1;
		// while (largest[++k])
		// 	printf("largest[%d] = %d\n", k, largest[k]);
		// printf("\n");
		while (lowest[i])
		{
			if (largest && a_head->value == largest[i])
			{
				pb(stack_a, stack_b);
				if (ruler(*stack_b) >= 3 && (*stack_b)->value < (*stack_b)->next->value)
					sb(stack_b);
				a_head = (*stack_a); 
			}
			else if (a_head->value == lowest[i])
			{
				pb(stack_a, stack_b);
				rb(stack_b);
				a_head = (*stack_a); 
			}
			i++;
		}
		ra(stack_a);
		free_int(lowest, largest);
	}
}
