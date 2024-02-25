/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:21:37 by adesille          #+#    #+#             */
/*   Updated: 2024/02/25 09:54:06 by isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*smallest_finder(t_stack *stack_b)
{
	t_stack	*b_head;
	int 	*lowest;
	// int 	i;

	// i = 0;
	lowest = ft_calloc(2, 2147483647);
	b_head = stack_b;
	while (b_head)
	{
		if (b_head->value < lowest[0])
			lowest[0] = b_head->value;
		b_head = b_head->next;
	}
	b_head = stack_b;
	while (b_head)
	{
		if (b_head->value > lowest[0] && b_head->value < lowest[1])
			lowest[1] = b_head->value;
		b_head = b_head->next;
	}
	b_head = stack_b;
	while (b_head)
	{
		if (b_head->value > lowest[0] && b_head->value < lowest[1])
			lowest[1] = b_head->value;
		b_head = b_head->next;
	}
	return (lowest);
}

void	third_low_swapper(t_stack *stack_a, t_stack *stack_b, int *lowest)
{
	t_stack	*b_tail;
	int		count;

	count = 0;
	pa(&stack_a, &stack_b);
	ra(&stack_a);
	b_tail = stack_b;
	while (b_tail->value != lowest[0] || b_tail->value != lowest[1])
	{
		rb(&stack_b);
		count++;
		b_tail = stack_b;
	}
	if (b_tail->value == lowest[1])
	{
		pa(&stack_a, &stack_b);
		pa(&stack_a, &stack_b);
		rra(&stack_a);
	}
	else
	{
		pa(&stack_a, &stack_b);
		pa(&stack_a, &stack_b);
		sa(&stack_a);
		rra(&stack_a);
	}
	while (count-- > 0)
		rb(&stack_b);
}

void	two_low_swapper(t_stack *stack_a, t_stack *stack_b, int value)
{
	t_stack *stack_b_tail;

	stack_b_tail = stack_b;
	pa(&stack_a, &stack_b);
	checker(stack_a);
	while (stack_b_tail->value != value)
	{
		rrb(&stack_b);
		stack_b_tail = stack_b;
	}
	if (stack_b_tail->value == value)
	{
		pa(&stack_a, &stack_b);
		sa(&stack_a);
	}
}

void	last_push(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*stack_b_head;
	t_stack	*stack_a_tail;

	stack_b_head = stack_b;
	stack_a_tail = stack_a;
	if (ruler(&stack_a, &stack_b, 'B') == 3)
	{
		three_sorter_stack_b(stack_b);
		pa(&stack_a, &stack_b);
		pa(&stack_a, &stack_b);
		pa(&stack_a, &stack_b);
	}
	else
	{
		if (stack_b_head->value < stack_b_head->next->value)
		{
			rrb(&stack_b);
			pa(&stack_a, &stack_b);
			pa(&stack_a, &stack_b);
		}
		else
		{
			pa(&stack_a, &stack_b);
			pa(&stack_a, &stack_b);
		}
	}
	if (stack_a_tail->value < stack_a_tail->prev->value)
		sa(&stack_a);
}

void	checker(t_stack *stack_a)
{
	t_stack	*stack_a_tail;

	stack_a_tail = stack_a;
	static int i = 1;
	if (i > 0)
	{
		// printf("a_tail = %d\na_tail_prev = %d\n", stack_a->tail->value, stack_a->tail->prev->value);
		i--;
	}
	if (stack_a_tail->value < stack_a_tail->prev->value)
	{
		sa(&stack_a);
	}
	else if(stack_a_tail->prev->value < stack_a_tail->prev->prev->value)
	{
		rra(&stack_a);
		sa(&stack_a);
		ra(&stack_a);
	}
}

void	sorting_checker(t_stack *stack_a)
{
	t_stack	*stack_a_tmp;

	stack_a_tmp = stack_a;
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
