/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extractor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 10:25:36 by isb3              #+#    #+#             */
/*   Updated: 2024/03/15 10:45:09 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	side_select_utils(int *lowest, int *largest, t_stack *stack_a, size_t mid, int n)
{
	t_stack	*a_tail;
	int		low;
	int		i;

	low = 0;
	a_tail = return_tail(stack_a);
	while (a_tail && a_tail->position > mid)
	{
		i = n;
		while (i-- > 0)
			if (a_tail->value == lowest[i] && not_in(largest, lowest[i], n / 2) == 0)
				low++;
		a_tail = a_tail->prev;
	}
	return (low);
}

char	side_selector(int *lowest, int *largest, t_stack *stack_a, int n)
{
	t_stack	*a_head;
	size_t	mid;
	int		i;
	int		low;
	int		up;

	up = 0;
	a_head = stack_a;
	mid = ruler(stack_a) / 2;
	while (a_head && a_head->position < mid)
	{
		i = n;
		while (i-- > 0)
			if (a_head->value == lowest[i] && not_in(largest, lowest[i], n / 2) == 0)
				up++;
		a_head = a_head->next;
	}
	low = side_select_utils(lowest, largest, stack_a, mid, n);
	if (up > low)
		return ('U');
	return ('L');
}

int	pusher(t_stack **stack_a, t_stack **stack_b, int *largest, int n)
{
	if (!not_in_extract(largest, (*stack_a)->value, n/2))
	{
		pb(stack_a, stack_b);
		if ((*stack_b)->next && (*stack_b)->value < (*stack_b)->next->value)
			sb(stack_b);
		if ((*stack_a) && (*stack_a)->value < (*stack_b)->value)
			pb(stack_a, stack_b);
		if ((*stack_b)->next && (*stack_b)->value < (*stack_b)->next->value)
			sb(stack_b);
	}
	else
	{
		pb(stack_a, stack_b);
		rb(stack_b);
		if ((*stack_b)->next && (*stack_b)->value < (*stack_b)->next->value)
			sb(stack_b);
	}
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
		while (--i >= 0)
			if ((*stack_a) && (*stack_a)->value == lowest[i])
				pusher(stack_a, stack_b, largest, n);
		ra(stack_a);
		free_int(lowest, largest);
	}
}
