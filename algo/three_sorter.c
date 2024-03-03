/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:36:48 by adesille          #+#    #+#             */
/*   Updated: 2024/03/03 12:12:28 by isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	scenario_finder(t_stack *stack)
{
	int		first_value;

	first_value = stack->value;
	stack = stack->next;
	if (first_value < stack->value && stack->value < stack->next->value)
		return (1);
	else if (stack->value < first_value && first_value < stack->next->value)
		return (2);
	else if (first_value > stack->value && stack->value > stack->next->value)
		return (3);
	else if (stack->value > first_value && first_value > stack->next->value)
		return (4);
	else if (stack->value < stack->next->value
		&& stack->next->value < first_value)
		return (5);
	else if (stack->value > stack->next->value
		&& stack->next->value > first_value)
		return (6);
	return (0);
}

void	three_sorter_utils_stack_a(t_stack	**stack_a, int scenario)
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
		rra(stack_a);
		sa(stack_a);
	}
}

void	three_sorter_stack_a(t_stack **stack_a)
{
	t_stack	*stack;
	int		scenario;

	stack = *stack_a;
	scenario = scenario_finder(stack);
	if (scenario == 1)
		return ;
	else if (scenario == 2)
		sa(stack_a);
	else if (scenario >= 3)
		three_sorter_utils_stack_a(stack_a, scenario);
}
