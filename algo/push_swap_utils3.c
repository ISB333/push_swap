/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:29:19 by adesille          #+#    #+#             */
/*   Updated: 2024/02/25 09:47:24 by isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	n_selector(t_stack *stack_a)
{
	int	a_size;

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
	t_stack  *stack_a_head;
	int     i;

	stack_a_head = stack_a;
	while (stack_a_head->position < mid)
	{
		i = -1;
		while (largest_values[++i])
			if (stack_a_head->value == largest_values[i])
				up++;
		stack_a_head = stack_a_head->next;
	}
	while (stack_a_head)
	{
		i = -1;
		while (largest_values[++i])
			if (stack_a_head->value == largest_values[i])
				low++;
		stack_a_head = stack_a_head->next;
	}
	if (up >= low)
		return ('L');
	return ('U');
}

void	pusher(t_stack *stack_a, t_stack *stack_b, int mid_value)
{
	t_stack	*stack_b_head;
	t_stack	*stack_b_tail;
	t_stack	*stack_a_tail;

	stack_b_head = stack_b;
	stack_b_tail = stack_b;
	stack_a_tail = stack_a;
	if (!stack_b_head || stack_b_head == stack_b_tail)
	{
		pb(&stack_a, &stack_b);
		return ;
	}
	if (stack_a_tail->value > mid_value)
		pb(&stack_a, &stack_b);
	else
	{
		pb(&stack_a, &stack_b);
		rrb(&stack_b); // rotating into low
	}
}

void    extractor_utils(t_stack *stack_a, t_stack *stack_b, int n, int *largest_values)
{
	t_stack	*s_a_tmp;
	t_stack	*stack_a_tail;
	int i;
	int mid;
	int side;

	stack_a_tail = stack_a;
	while (n > 0)
	{
		mid = stack_a_tail->position / 2;
		side = side_chooser(largest_values, stack_a, mid, 0, 0);
		s_a_tmp = stack_a_tail;
		i = -1;
		while (largest_values[++i])
			if (s_a_tmp && s_a_tmp->value == largest_values[i])
            {
				// pusher(stack_a, stack_b, mid_calculator(largest_values));
				pb(&stack_a, &stack_b);
				n--;
            }
		if (side == 'U')
			rra(&stack_a);
		else if (side == 'L')
			ra(&stack_a);
	}
}
