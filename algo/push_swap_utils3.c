/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:29:19 by adesille          #+#    #+#             */
/*   Updated: 2024/02/21 09:19:38 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	n_selector(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int	a_size;

	a_size = ruler(stack_a, stack_b, 'A');
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

int		mid_calculator(int *lowest_values)
{
	int	i;
	int	mid;

	i = 0;
	while (lowest_values[i])
		i++;
	mid = i / 2;
	return (lowest_values[mid]);
}

char    side_chooser(int *lowest_values, t_stack_a *stack_a, int mid, int up, int low)
{
	t_data  *stack_a_head;
	int     i;

	stack_a_head = stack_a->head;
	while (stack_a_head->position < mid)
	{
		i = -1;
		while (lowest_values[++i])
			if (stack_a_head->value == lowest_values[i])
				up++;
		stack_a_head = stack_a_head->next;
	}
	while (stack_a_head)
	{
		i = -1;
		while (lowest_values[++i])
			if (stack_a_head->value == lowest_values[i])
				low++;
		stack_a_head = stack_a_head->next;
	}
	if (up >= low)
		return ('L');
	return ('U');
}

void	pusher(t_stack_a *stack_a, t_stack_b *stack_b, int mid_value)
{
	if (!stack_b->head || stack_b->head == stack_b->tail)
	{
		pb(stack_a, stack_b);
		return ;
	}
	if (stack_a->tail->value > mid_value)
		pb(stack_a, stack_b);
	else
	{
		pb(stack_a, stack_b);
		rrb(stack_b); // rotating into low
	}
}

void    extractor_utils(t_stack_a *stack_a, t_stack_b *stack_b, int n, int *lowest_values)
{
	t_data	*s_a_tmp;
	int i;
	int mid;
	int side;

	while (n > 0)
	{
		mid = stack_a->tail->position / 2;
		side = side_chooser(lowest_values, stack_a, mid, 0, 0);
		s_a_tmp = stack_a->tail;
		i = -1;
		while (lowest_values[++i])
			if (s_a_tmp && s_a_tmp->value == lowest_values[i])
            {
				pusher(stack_a, stack_b, mid_calculator(lowest_values));
				n--;
            }
		if (side == 'U')
			rra(stack_a);
		else if (side == 'L')
			ra(stack_a);
	}
}
