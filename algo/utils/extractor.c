/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extractor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 10:25:36 by isb3              #+#    #+#             */
/*   Updated: 2024/03/27 11:28:38 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	pusher(t_stack **stack_a, t_stack **stack_b, int *largest, int n)
{
	if (not_in_extract(largest, (*stack_a)->value, n / 4))
	{
		pb(stack_a, stack_b);
		rb(stack_b);
	}
	else
		pb(stack_a, stack_b);
	if ((*stack_b)->next && (*stack_b)->value < (*stack_b)->next->value)
		sb(stack_b);
	if ((*stack_a) && (*stack_a)->value < (*stack_b)->value)
		pusher(stack_a, stack_b, largest, n);
	return (1);
}

void	extractor(t_stack **stack_a, t_stack **stack_b, int n, int i)
{
	int			*largest;
	int			*lowest;

	while (ruler(*stack_a) >= 5)
	{
		n = n_selector(*stack_a);
		lowest = n_smallest_scrapper((*stack_a), n);
		largest = half_n_scrapper(lowest, n);
		i = n + 1;
		while (i-- > 0)
			if ((*stack_a) && (*stack_a)->value == lowest[i])
				pusher(stack_a, stack_b, largest, n);
		ra(stack_a);
		free_int(lowest, largest);
	}
}
