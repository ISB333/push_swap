/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:29:19 by adesille          #+#    #+#             */
/*   Updated: 2024/02/14 14:34:38 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	n_selector(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int	a_size;

	a_size = ruler(stack_a, stack_b, 'A');
	if (a_size <= 20)
		return (a_size / 2);
	else if (a_size <= 60)
		return (a_size / 4);
	else if (a_size <= 100)
		return (a_size / 5);
	else if (a_size <= 500)
		return (a_size / 10);
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
	int i;

	i = -1;
    while (n > 0)
    {
        stack_a_tmp = stack_a->tail;
        i = -1;
        while (lowest_values[++i])
            if (stack_a_tmp->value == lowest_values[i] && n-- > 0)
                pb(stack_a, stack_b);
        ra(stack_a);
    }
}

// void    extractor_utils_w_side(t_stack_a *stack_a, t_stack_b *stack_b, int n, int *lowest_values, int side)
// {
// 	t_data	*stack_a_tmp;
// 	int i;

// 	i = -1;
// 	if (side == 'U')
// 		while (n > 0)
// 		{
// 			stack_a_tmp = stack_a->tail;
// 			i = -1;
// 			while (lowest_values[++i])
// 				if (stack_a_tmp->value == lowest_values[i] && n-- > 0)
// 					pb(stack_a, stack_b);
// 			ra(stack_a);
// 		}
// 	else
// 		while (n > 0)
// 		{
// 			stack_a_tmp = stack_a->tail;
// 			i = -1;
// 			while (lowest_values[++i])
// 				if (stack_a_tmp->value == lowest_values[i] && n-- > 0)
// 					pb(stack_a, stack_b);
// 			rra(stack_a);
// 		}
// }