/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:21:37 by adesille          #+#    #+#             */
/*   Updated: 2024/02/15 13:22:08 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// int	*largest_finder(t_stack_b *stack_b)
// {
// 	t_data	*stack_b_head;
// 	int 	*larg_and_penult;
// 	int 	i;

// 	i = 0;
// 	larg_and_penult = ft_calloc(2, 1);
// 	stack_b_head = stack_b->head;
// 	while (stack_b_head)
// 	{
// 		if (stack_b_head->value > larg_and_penult[0])
// 			larg_and_penult[0] = stack_b_head->value;
// 		stack_b_head = stack_b_head->next;
// 	}
// 	stack_b_head = stack_b->head;
// 	while (stack_b_head)
// 	{
// 		if (stack_b_head->value < larg_and_penult[0] && stack_b_head->value > larg_and_penult[1])
// 			larg_and_penult[1] = stack_b_head->value;
// 		stack_b_head = stack_b_head->next;
// 	}
// 	return (larg_and_penult);
// }

// void	penult_swapper(t_stack_a *stack_a, t_stack_b *stack_b, int value)
// {
// 	t_data *stack_b_tail;
// 	int		count;

// 	count = 0;
// 	stack_b_tail = stack_b->tail;
// 	pa(stack_a, stack_b);
// 	while (stack_b_tail)
// 	{
// 		if (stack_b_tail->value == value)
// 		{
// 			pa(stack_a, stack_b);
// 			sa(stack_a);
// 			break ;
// 		}
// 		else
// 		{
// 			// printf("AAAAAAAAAAAAa\n");
// 			rb(stack_b);
// 			count++;
// 		}
// 		stack_b_tail = stack_b->tail;
// 	}
// 	while (count-- > 0)
// 		rrb(stack_b);
// }

// void	last_push(t_stack_a *stack_a, t_stack_b *stack_b)
// {
// 	if (ruler(stack_a, stack_b, 'B') == 3)
// 	{
// 		three_sorter_stack_b(stack_b);
// 		pa(stack_a, stack_b);
// 		pa(stack_a, stack_b);
// 		pa(stack_a, stack_b);
// 	}
// 	else
// 	{
// 		if (stack_b->head->value > stack_b->head->next->value)
// 		{
// 			rb(stack_b);
// 			pa(stack_a, stack_b);
// 			pa(stack_a, stack_b);
// 		}
// 		else
// 		{
// 			pa(stack_a, stack_b);
// 			pa(stack_a, stack_b);
// 		}
// 	}
// 	printer(stack_a, stack_b);
// }