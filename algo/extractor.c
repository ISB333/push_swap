/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extractor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 08:48:19 by adesille          #+#    #+#             */
/*   Updated: 2024/03/01 10:47:54 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char    side_chooser(int *lowest, int *largest, t_stack *stack_a, int up, int low)
{
	t_stack  *a_head;
	int     i;
	int		mid;

	if ((!stack_a || !stack_a->next))
		return (0);
	a_head = stack_a;
	mid = ruler(stack_a) / 2;
	while (a_head->position < mid)
	{
		i = 0;
		while (largest[i])
		{
			if (a_head->value == largest[i] || a_head->value == lowest[i])
				up++;
			i++;
		}
		a_head = a_head->next;
	}
	while (a_head)
	{
		i = 0;
		while (largest[i])
		{
			if (a_head->value == largest[i] || a_head->value == lowest[i])
				low++;
			i++;
		}
		a_head = a_head->next;
	}
	if (up >= low)
		return ('U');
	return ('L');
}

void    extractor(t_stack **stack_a, t_stack **stack_b, int n, int *lowest, int *largest)
{
	t_stack	*a_head;
	int 	side;
	int 	i;

	while (n > 0)
	{
		side = side_chooser(lowest, largest, (*stack_a), 0, 0);
		a_head = (*stack_a); 
		i = -1;
		while (largest[++i])
			if (a_head->value == largest[i])
            {
				pb(stack_a, stack_b);
				a_head = (*stack_a); 
				n--;
            }
			else if (a_head->value == lowest[i])
            {
				pb(stack_a, stack_b);
				rb(stack_b);
				a_head = (*stack_a); 
            }
		if (side == 'U')
			ra(stack_a);
		else if (side == 'L')
			rra(stack_a);
	}
}

void	n_smallest_extractor(t_stack **stack_a, t_stack **stack_b, int n)
{
	t_stack	*b_head;
	int		*largest;
	int		*lowest;

	b_head = *stack_b;
	if (ruler(*stack_a) < 10)
		n = 2;
	lowest = n_smallest_scrapper((*stack_a), n);
	largest = n_2nd_scrapper((*stack_a), lowest, n);
	// int i = 0;
	// while(lowest[i])
	// 	printf("lowest = %d\n", lowest[i++]);
	// i = 0;
	// printf("\n");
	// while(largest[i])
	// 	printf("largest = %d\n", largest[i++]);
	extractor(stack_a, stack_b, n, lowest, largest);
	// printer(*stack_a, *stack_b, 2);
	free(lowest);
	free(largest);
}


// void	pusher(t_stack **stack_a, t_stack **stack_b, int mid_value)
// {
// 	t_stack	*b_head;
// 	t_stack	**b_tail;
// 	t_stack	**a_tail;

// 	b_head = *stack_b;
// 	b_tail = return_tail(stack_b);
// 	a_tail = return_tail(stack_a);
// 	if (!b_head || b_head == (*b_tail))
// 	{
// 		pb(stack_a, stack_b);
// 		return ;
// 	}
// 	if ((*a_tail)->value > mid_value)
// 		pb(stack_a, stack_b);
// 	else
// 	{
// 		pb(stack_a, stack_b);
// 		rrb(stack_b); // rotating into low
// 	}
// }