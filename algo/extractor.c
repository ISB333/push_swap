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


int	*largest_scrapper_test(int *lowest, int n)
{
	int *largest;
	int i;
	int	k;
	int	j;

	largest = ft_calloc(n / 2, sizeof(int));
	i = -1;
	while (lowest[++i])
	{
		k = -1;
		while (++k < n / 2)
		{
			if (lowest[i] > largest[k])
			{
				j = n / 2;
				while (--j > k)
					largest[j] = largest[j - 1];
				largest[k] = lowest[i];
				break;
			}
		}
	}
	return (largest);
}

char	extract_side_chooser(int *lowest, int *largest, t_stack *stack_a, int up, int low)
{
	t_stack	*a_head;
	t_stack	*a_tail;
	size_t		mid;
	int			i;

	a_head = stack_a;
	a_tail = return_tail(stack_a);
	mid = ruler(stack_a) / 2;
	while (a_head && a_head->position < mid)	
	{
		i = -1;
		while (lowest[++i])
			if (a_head->value == lowest[i] && not_in(largest, lowest[i]) == 0)
				up++;
		a_head = a_head->next;
	}
	while (a_tail && a_tail->position > mid)	
	{
		i = -1;
		while (lowest[++i])
			if (a_tail->value == lowest[i] && not_in(largest, lowest[i]) == 0)
				low++;
		a_tail = a_tail->prev;
	}
	if (up > low)
		return ('U');
	return ('L');
}

void    extractor(t_stack **stack_a, t_stack **stack_b, int n)
{
	int		*largest;
	int		*lowest;
	t_stack	*a_head;
	// t_stack	*a_tail = return_tail(*stack_b);
	char	side;
	int 	i;

	side = 'U';
	while (ruler(*stack_a) > 5)
	{
		n = n_selector(*stack_a);
		lowest = n_smallest_scrapper((*stack_a), n);
		largest = largest_scrapper_test(lowest, n);
		side = extract_side_chooser(lowest, largest, *stack_a, 0, 0);
		a_head = (*stack_a); 
		i = 0;
		while (lowest[i])
		{
			if (a_head && a_head->value == lowest[i])
			{
				if (not_in(largest, a_head->value) == 0)
					pb(stack_a, stack_b);
				else
				{
					pb(stack_a, stack_b);
					rb(stack_b);
				}
				a_head = (*stack_a); 
			}
			i++;
		}
		if (side == 'U')
			ra(stack_a);
		else if (side ==  'L')
			rra(stack_a);
		free_int(lowest, largest);
	}
	while(*stack_a)
		pb(stack_a, stack_b);
}
