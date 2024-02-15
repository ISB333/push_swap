/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:59:56 by adesille          #+#    #+#             */
/*   Updated: 2024/02/15 11:59:57 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void	n_smallest_extractor(t_stack_a *stack_a, t_stack_b *stack_b, int n)
{
	int		*lowest_values;
	// char	side;
	// int 	n;
	int 	i;
	int 	up;
	int		low;

	up = 0;
	low = 0;
	i = -1;
	if (ruler(stack_a, stack_b, 'A') < 10)
		n = ruler(stack_a, stack_b, 'A') - n; 
	lowest_values = n_smallest_finder(stack_a, n);
	// n = n_selector(stack_a, stack_b);
	// side = side_chooser(lowest_values, stack_a, ruler(stack_a, stack_b, 'A') / 2, up, low);
	// while (lowest_values[++i])
		// printf("value n%d = %d\n", i, lowest_values[i]);
	extractor_utils(stack_a, stack_b, n, lowest_values);
	// printer(stack_a, stack_b);
}

int	*largest_finder(t_stack_b *stack_b)
{
	t_data	*stack_b_head;
	int 	*larg_and_penult;
	int 	i;

	i = 0;
	larg_and_penult = ft_calloc(2, 1);
	stack_b_head = stack_b->head;
	while (stack_b_head)
	{
		if (stack_b_head->value > larg_and_penult[0])
			larg_and_penult[0] = stack_b_head->value;
		stack_b_head = stack_b_head->next;
	}
	stack_b_head = stack_b->head;
	while (stack_b_head)
	{
		if (stack_b_head->value < larg_and_penult[0] && stack_b_head->value > larg_and_penult[1])
			larg_and_penult[1] = stack_b_head->value;
		stack_b_head = stack_b_head->next;
	}
	return (larg_and_penult);
}

void	penult_swapper(t_stack_a *stack_a, t_stack_b *stack_b, int value)
{
	t_data *stack_b_tail;
	int		count;

	count = 0;
	stack_b_tail = stack_b->tail;
	pa(stack_a, stack_b);
	while (stack_b_tail)
	{
		if (stack_b_tail->value == value)
		{
			pa(stack_a, stack_b);
			sa(stack_a);
			break ;
		}
		else
		{
			// printf("AAAAAAAAAAAAa\n");
			rb(stack_b);
			count++;
		}
		stack_b_tail = stack_b->tail;
	}
	while (count-- > 0)
		rrb(stack_b);
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
		if (stack_b->head->value > stack_b->head->next->value)
		{
			rb(stack_b);
			pa(stack_a, stack_b);
			pa(stack_a, stack_b);
		}
		else
		{
			pa(stack_a, stack_b);
			pa(stack_a, stack_b);
		}
	}
	printer(stack_a, stack_b);
}

void    pushing_back_to_a(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_data 	*stack_b_tail;
	int		*larg_and_penult;

	stack_b_tail = stack_b->tail;
	while (ruler(stack_a, stack_b, 'B') > 3)
	{
		larg_and_penult = largest_finder(stack_b);
		if (stack_b_tail->value == larg_and_penult[1])
			penult_swapper(stack_a, stack_b, larg_and_penult[0]);
		else if (stack_b_tail->value == larg_and_penult[0])
			pa(stack_a, stack_b);
		rb(stack_b);
		stack_b_tail = stack_b->tail;
	}
	last_push(stack_a, stack_b);
}

void    push_swap(t_stack_a *stack_a, t_stack_b *stack_b)
{
	// int a_cheapest_pos;
	int	n;

	printf("\n\n");
	if (ruler(stack_a, stack_b, 'A') <= 3)
		three_sorter_stack_a(stack_a);
	else if (ruler(stack_a, stack_b, 'A') <= 5)
		five_sorter_stack_a(stack_a, stack_b);
	else
	{
		n = n_selector(stack_a, stack_b);
		while (ruler(stack_a, stack_b, 'A') > 5)
			n_smallest_extractor(stack_a, stack_b, n);
		five_sorter_stack_a(stack_a, stack_b);
		while(ruler(stack_a, stack_b, 'A') > 0)
			pb(stack_a, stack_b);
		pushing_back_to_a(stack_a, stack_b);
		// while(ruler(stack_a, stack_b, 'A') > 3)
		// {
		// 	cost_initializer(stack_a, stack_b);
		// }
		// printer(stack_a, stack_b);
	}
}
