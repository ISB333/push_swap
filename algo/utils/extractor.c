/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extractor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 10:25:36 by isb3              #+#    #+#             */
/*   Updated: 2024/03/03 11:37:21 by isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	side_select_utils(int *lowest, int *largest, t_stack *stack_a, size_t mid)
{
	t_stack	*a_tail;
	int		low;
	int		i;

	low = 0;
	a_tail = return_tail(stack_a);
	while (a_tail && a_tail->position > mid)
	{
		i = -1;
		while (lowest[++i])
			if (a_tail->value == lowest[i] && not_in(largest, lowest[i]) == 0)
				low++;
		a_tail = a_tail->prev;
	}
	return (low);
}

char	side_selector(int *lowest, int *largest, t_stack *stack_a, int up)
{
	t_stack		*a_head;
	size_t		mid;
	int			i;
	int			low;

	a_head = stack_a;
	mid = ruler(stack_a) / 2;
	while (a_head && a_head->position < mid)
	{
		i = -1;
		while (lowest[++i])
			if (a_head->value == lowest[i] && not_in(largest, lowest[i]) == 0)
				up++;
		a_head = a_head->next;
	}
	low = side_select_utils(lowest, largest, stack_a, mid);
	if (up > low)
		return ('U');
	return ('L');
}

t_stack	*pusher(t_stack **stack_a, t_stack **stack_b, int *largest)
{
	t_stack	*a_head;

	a_head = *stack_a;
	if (!not_in(largest, a_head->value))
		pb(stack_a, stack_b);
	else
	{
		pb(stack_a, stack_b);
		rb(stack_b);
	}
	return (*stack_a);
}

void	extractor(t_stack **stack_a, t_stack **stack_b, int n)
{
	t_stack	*a_head;
	int		*largest;
	int		*lowest;
	int		i;
	char	side;

	while (ruler(*stack_a) > 5)
	{
		n = n_selector(*stack_a);
		lowest = n_smallest_scrapper((*stack_a), n);
		largest = half_n_scrapper(lowest, n);
		side = side_selector(lowest, largest, *stack_a, 0);
		a_head = *stack_a;
		i = -1;
		while (lowest[++i])
			if (a_head && a_head->value == lowest[i])
				a_head = pusher(stack_a, stack_b, largest);
		if (side == 'U')
			ra(stack_a);
		else if (side == 'L')
			rra(stack_a);
		free_int(lowest, largest);
	}
	while (*stack_a)
		pb(stack_a, stack_b);
}
