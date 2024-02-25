/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:10:58 by adesille          #+#    #+#             */
/*   Updated: 2024/02/25 09:42:35 by isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ruler(t_stack **stack_a, t_stack **stack_b, int stack)
{
	if (stack == 'A' && stack_a)
		return ((*stack_a)->position);
	else if (stack == 'B' && stack_b)
		return ((*stack_b)->position);
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

int	b_pos_finder(int stack_a_value, t_stack *stack_b)
{
	t_stack	*stack_b_head;

	stack_b_head = stack_b;
	while (stack_b_head && stack_a_value < stack_b_head->value)
		stack_b_head = stack_b_head->next;	
    if(stack_b_head)
        return(stack_b_head->position);
	else
		return (0);
}

// void	cost_initializer(t_stack *stack_a, t_stack *stack_b)
// {
// 	t_stack *stack_a_head;
// 	t_stack *stack_b_head;

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
