/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:36:48 by adesille          #+#    #+#             */
/*   Updated: 2024/02/09 13:07:21 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	scenario_finder(t_data *stack)
{
	int		first_value;

	first_value = stack->value;
	stack = stack->next;
	if (first_value > stack->value && stack->value > stack->next->value)
		return (1);
	else if (stack->value < stack->next->value && stack->next->value < first_value)
		return (2);
	else if (stack->value > first_value && first_value > stack->next->value)
		return (3);
	else if (stack->value < first_value && first_value < stack->next->value)
		return (4);
	else if (stack->value > stack->next->value && stack->next->value > first_value)
		return (5);
	else if (first_value < stack->value && stack->value < stack->next->value)
		return (6);
	return (0);
}

void	three_sorter_utils_stack_a(t_stack_a	*stack_a, int scenario)
{
	if (scenario == 3)
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if (scenario == 4)
		rra(stack_a);
	else if (scenario == 5)
		ra(stack_a);
	else if (scenario == 6)
	{
		sa(stack_a);
		ra(stack_a);
	}
}

void	three_sorter_stack_a(t_stack_a *stack_a)
{
	t_data	*stack;
	int 	scenario;
    
    stack = stack_a->head;
	scenario = scenario_finder(stack);
	if (scenario == 1)
		return ;
	else if (scenario == 2)
		sa(stack_a);
	else if (scenario >= 3)
		three_sorter_utils_stack_a(stack_a, scenario);
}


void	three_sorter_utils_stack_b(t_stack_b	*stack_b, int scenario)
{
	if (scenario == 3)
	{
		rb(stack_b);
		sb(stack_b);
	}
	else if (scenario == 4)
		rrb(stack_b);
	else if (scenario == 5)
		rb(stack_b);
	else if (scenario == 6)
	{
		sb(stack_b);
		rb(stack_b);
	}
}

void	three_sorter_stack_b(t_stack_b *stack_b)
{
	t_data	*stack;
	int 	scenario;
    
    stack = stack_b->head;
	scenario = scenario_finder(stack);
	if (scenario == 1)
		return ;
	else if (scenario == 2)
		sb(stack_b);
	else if (scenario >= 3)
		three_sorter_utils_stack_b(stack_b, scenario);
}