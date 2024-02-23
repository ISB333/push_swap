/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:21:37 by adesille          #+#    #+#             */
/*   Updated: 2024/02/23 10:20:47 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*smallest_finder(t_stack_b *stack_b)
{
	t_data	*b_head;
	int 	*lowest;
	int 	i;

	i = 0;
	lowest = ft_calloc(2, 2147483647);
	b_head = stack_b->head;
	while (b_head)
	{
		if (b_head->value < lowest[0])
			lowest[0] = b_head->value;
		b_head = b_head->next;
	}
	b_head = stack_b->head;
	while (b_head)
	{
		if (b_head->value > lowest[0] && b_head->value < lowest[1])
			lowest[1] = b_head->value;
		b_head = b_head->next;
	}
	b_head = stack_b->head;
	while (b_head)
	{
		if (b_head->value > lowest[0] && b_head->value < lowest[1])
			lowest[1] = b_head->value;
		b_head = b_head->next;
	}
	return (lowest);
}

void	penult_swapper(t_stack_a *stack_a, t_stack_b *stack_b, int value)
{
	t_data *stack_b_tail;
	// int		count;

	// count = 0;
	stack_b_tail = stack_b->tail;
	pa(stack_a, stack_b);
	while (stack_b_tail->value != value)
	{
		rrb(stack_b);
		// count++;
		stack_b_tail = stack_b->tail;
	}
	if (stack_b_tail->value == value)
	{
		pa(stack_a, stack_b);
		sa(stack_a);
	}
	// while (count-- > 0)
	// 	rb(stack_b);
}

void	last_push(t_stack_a *stack_a, t_stack_b *stack_b)
{
	if (ruler(stack_a, stack_b, 'B') == 3)
	{
		three_sorter_stack_b(stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	else
	{
		if (stack_b->head->value < stack_b->head->next->value)
		{
			rrb(stack_b);
			pa(stack_a, stack_b);
			pa(stack_a, stack_b);
		}
		else
		{
			pa(stack_a, stack_b);
			pa(stack_a, stack_b);
		}
	}
	if (stack_a->tail->value < stack_a->tail->prev->value)
		sa(stack_a);
}

void	sorting_checker(t_stack_a *stack_a)
{
	t_data	*stack_a_tmp;

	stack_a_tmp = stack_a->head;
	while (stack_a_tmp->next)
	{
		if (stack_a_tmp->value > stack_a_tmp->next->value)
		{
			printf("NOT SORTED MUDAFUKA SHGIEHBKGHBADGKHBEGLKJ!@!##$#@$^$@$^@#!^^$@$TYWQHYNG$VTTRH\n");
			return ;
		}
		stack_a_tmp = stack_a_tmp->next;
	}
	printf("SORTING OK BROoOoOooOOoOOoO!\n");
}
