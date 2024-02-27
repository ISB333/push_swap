/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:29:19 by adesille          #+#    #+#             */
/*   Updated: 2024/02/27 15:29:17 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	n_selector(t_stack *stack_a)
{
	int	a_size;

	if (!stack_a || !stack_a->next)
		return 0;
	a_size = stack_a->position;
	if (a_size <= 20)
		return (4);
	else if (a_size <= 40)
		return (6);
	else if (a_size <= 60)
		return (10);
	else if (a_size <= 100)
		return (20);
	else if (a_size <= 250)
		return (40);
	else if (a_size <= 500)
		return (50);
	return (0);
}

t_stack	**return_tail(t_stack **stack)
{    
	if (stack == NULL || *stack == NULL) 
        return NULL;
	while ((*stack)->next)
		stack = &((*stack)->next);
	return (stack);
}

int		mid_calculator(int *largest_values)
{
	int	i;
	int	mid;

	i = 0;
	while (largest_values[i])
		i++;
	mid = i / 2;
	return (largest_values[mid]);
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

// void    extractor_utils(t_stack **stack_a, t_stack **stack_b, int n, int *largest)
// {
// 	t_stack	*a_head;
// 	int mid;
// 	int i;
// 	int side;

// 	side = 'U';
// 	n = 214578623;
// 	mid = (*stack_a)->position / 2;
// 	a_head = (*stack_a); 
// 	i = -1;
// 	while (largest[++i])
// 	{
// 		if (a_head && a_head->value == largest[i])
// 		{
// 			// pusher(stack_a, stack_b, mid_calculator(largest_values));
// 			pb(stack_a, stack_b);
// 			a_head = (*stack_a); 
// 			// n--;
// 		}
// 	}
// }

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
