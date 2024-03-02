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
		i = -1;
		while (largest[++i])
			if (a_head->value == largest[i])
            {
				pb(stack_a, stack_b);
				a_head = (*stack_a); 
            }
			else if (a_head->value == lowest[i])
            {
				pb(stack_a, stack_b);
				a_head = (*stack_a); 
            }
		ra(stack_a);
		free_int(lowest, largest);
	}
}
