/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:10:58 by adesille          #+#    #+#             */
/*   Updated: 2024/02/24 16:20:30 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ruler(t_stack_a *stack_a, t_stack_b *stack_b, int stack)
{
	if (stack == 'A' && stack_a->tail)
    {
		return (stack_a->tail->position);
    }
	else if (stack == 'B' && stack_b->tail)
    {
		return (stack_b->tail->position);
    }
    return (0);
}

int	abs_diff(int a, int b)
{
	if (a > b)
		return (a);
	else if (b >= a)
		return (b);
	return (0);
}

int	b_pos_finder(int stack_a_value, t_stack_b *stack_b)
{
	t_data	*stack_b_head;

	stack_b_head = stack_b->head;
	while (stack_b_head && stack_a_value < stack_b_head->value)
		stack_b_head = stack_b_head->next;	
    if(stack_b_head)
        return(stack_b_head->position);
	else
		return (0);
}

// void	cost_initializer(t_stack_a *stack_a, t_stack_b *stack_b)
// {
// 	t_data *stack_a_head;
// 	t_data *stack_b_head;

// 	stack_a_head = stack_a->head;
// 	stack_b_head = stack_b->head;
// 	while (stack_a_head->position <= (ruler(stack_a, stack_b, 'A') / 2))
// 	{
// 		stack_a_head->cost = stack_a_head->position;
// 		stack_a_head = stack_a_head->next;
// 	}
// 	while (stack_a_head && stack_a_head->position <= ruler(stack_a, stack_b, 'A'))
// 	{
// 		stack_a_head->cost = ruler(stack_a, stack_b, 'A') - stack_a_head->position;
// 		stack_a_head = stack_a_head->next;
// 	}
// 	while (stack_b_head->position <= (ruler(stack_a, stack_b, 'B') / 2))
// 	{
// 		stack_b_head->cost = stack_b_head->position;
// 		stack_b_head = stack_b_head->next;
// 	}
// 	while (stack_b_head && stack_b_head->position <= ruler(stack_a, stack_b, 'B'))
// 	{
// 		stack_b_head->cost = ruler(stack_a, stack_b, 'B') - stack_b_head->position;
// 		stack_b_head = stack_b_head->next;
// 	}
// }
