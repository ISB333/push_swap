/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extractor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 08:48:19 by adesille          #+#    #+#             */
/*   Updated: 2024/02/28 09:45:30 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	n_smallest_extractor(t_stack **stack_a, t_stack **stack_b, int n)
{
	t_stack	*b_head;
	int		*lowest;
	int		*topmid;
	int 	i;

	i = 0;
	b_head = *stack_b;
	lowest = n_smallest_scrapper((*stack_a), n);
	topmid = n_largest_scrapper((*stack_a), n);
	while(lowest[i])
		printf("lowest = %d\n", lowest[i++]);
	i = 0;
	printf("\n");
	while(topmid[i])
		printf("topmid = %d\n", topmid[i++]);
	// extractor_utils(stack_a, stack_b, n, largest);
	free(lowest);
	free(topmid);
}

void    extractor_utils(t_stack **stack_a, t_stack **stack_b, int n, int *largest)
{
	t_stack	*a_head;
	int 	mid;
	int 	i;
	int 	side;

	side = 'U';
	mid = (*stack_a)->position / 2;
	while (n > 0)
	{
		side = side_chooser(largest, (*stack_a), mid, (*stack_a)->position, 0);
		a_head = (*stack_a); 
		i = -1;
		while (largest[++i])
			if (a_head && a_head->value == largest[i])
            {
				// pusher(stack_a, stack_b, mid_calculator(largest_values));
				pb(stack_a, stack_b);
				a_head = (*stack_a); 
				n--;
            }
		if (side == 'U')
			ra(stack_a);
		else if (side == 'L')
			rra(stack_a);
	}
}

char    side_chooser(int *largest_values, t_stack *stack_a, int mid, int up, int low)
{
	t_stack  *a_head;
	int     i;

	if ((!stack_a || !stack_a->next))
		return (0);
	a_head = stack_a;
	while (a_head->position > mid)
	{
		i = -1;
		while (largest_values[++i])
			if (a_head->value == largest_values[i])
				up++;
		a_head = a_head->next;
	}
	while (a_head)
	{
		i = -1;
		while (largest_values[++i])
			if (a_head->value == largest_values[i])
				low++;
		a_head = a_head->next;
	}
	if (up >= low)
		return ('L');
	return ('U');
}

void	pusher(t_stack **stack_a, t_stack **stack_b, int mid_value)
{
	t_stack	*b_head;
	t_stack	**b_tail;
	t_stack	**a_tail;

	b_head = *stack_b;
	b_tail = return_tail(stack_b);
	a_tail = return_tail(stack_a);
	if (!b_head || b_head == (*b_tail))
	{
		pb(stack_a, stack_b);
		return ;
	}
	if ((*a_tail)->value > mid_value)
		pb(stack_a, stack_b);
	else
	{
		pb(stack_a, stack_b);
		rrb(stack_b); // rotating into low
	}
}
