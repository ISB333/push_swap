/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:29:19 by adesille          #+#    #+#             */
/*   Updated: 2024/02/20 14:55:27 by adesille         ###   ########.fr       */
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
		return ('U');
	return ('L');
}

void    extractor_utils(t_stack_a *stack_a, t_stack_b *stack_b, int n, int *lowest_values)
{
	t_data	*stack_a_tmp;
	t_data	*stack_b_tmp;
	int i;

	i = -1;
	while(lowest_values[++i])
		printf("%d\n", lowest_values[i]);
	printf("------------------------------\n");
	stack_b_tmp = stack_b->tail;
	while (n > 0)
	{
		stack_a_tmp = stack_a->tail;
		printf("a_tail = %d\n", stack_a->tail->value);
		i = 0;
		while (lowest_values[i])
		{
			if (stack_a_tmp && stack_a_tmp->value == lowest_values[i])
            {
				printf("a_value = %d\nlowest_values = %d\n", stack_a_tmp->value, lowest_values[i]);
				pb(stack_a, stack_b); /// PB = Memory Problems
				n--;
            }
			i++;
		}
		ra(stack_a);
	}
}
