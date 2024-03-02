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

char    extract_side_chooser(int *lowest, int *largest, t_stack *stack_a, int up, int low)
{
	t_stack  *a_head;
	int     i;
	size_t		mid;

	if ((!stack_a || !stack_a->next))
		return (0);
	a_head = stack_a;
	mid = ruler(stack_a) / 2;
	while (a_head->position < mid)
	{
		i = 0;
		while (lowest[i])
		{
			if (largest && a_head->value == largest[i])
				up++;
			if (a_head->value == lowest[i])
				up++;
			i++;
		}
		a_head = a_head->next;
	}
	while (a_head)
	{
		i = 0;
		while (lowest[i])
		{
			if (largest && a_head->value == largest[i])
				up++;
			if (a_head->value == lowest[i])
				up++;
			i++;
		}
		a_head = a_head->next;
	}
	if (up >= low)
		return ('L');
	return ('U');
}

void    extractor(t_stack **stack_a, t_stack **stack_b, int n)
{
	int		*largest;
	int		*lowest;
	t_stack	*a_head;
	// t_stack	*b_tail = return_tail(*stack_b);
	// char	side;
	int 	i;

	while (ruler(*stack_a) > 5)
	{
		n = n_selector(*stack_a);
		lowest = n_smallest_scrapper((*stack_a), n);
		largest = n_2nd_scrapper((*stack_a), lowest, n);
		a_head = (*stack_a); 
		i = 0;
		while (lowest[i])
		{
			if (largest && a_head->value == largest[i])
			{
				pb(stack_a, stack_b);
				if (ruler(*stack_b) >= 3 && (*stack_b)->value < (*stack_b)->next->value)
					sb(stack_b);
				a_head = (*stack_a); 
			}
			else if (a_head && a_head->value == lowest[i])
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
	while(*stack_a)
		pb(stack_a, stack_b);
}
