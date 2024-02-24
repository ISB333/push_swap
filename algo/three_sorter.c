/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:36:48 by adesille          #+#    #+#             */
/*   Updated: 2024/02/24 17:09:14 by adesille         ###   ########.fr       */
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
	else if (stack->value > stack->next->value && stack->next->value > first_value)
		return (2);
	else if (stack->value < first_value && first_value < stack->next->value)
		return (3);
	else if (stack->value > first_value && first_value > stack->next->value)
		return (4);
	else if (stack->value < stack->next->value && stack->next->value < first_value)
		return (5);
	else if (first_value > stack->value && stack->value > stack->next->value)
		return (6);
	return (0);
}

void	three_sorter_utils_stack_a(t_stack	*stack_a, int scenario)
{
	if (scenario == 3)
	{
		// printf("scen3\n");
		ra(stack_a);
		sa(stack_a);
	}
	else if (scenario == 4)
	{
		// printf("scen4\n");
		rra(stack_a);
	}
	else if (scenario == 5)
	{
		// printf("scen5\n");
		ra(stack_a);
	}
	else if (scenario == 6)
	{
		// printf("-----------------------BEFORE SCEN6-----------------------\n");
		// stack_printer_a(stack_a);
		// printf("scen6\n");
		sa(stack_a);
		ra(stack_a);
	}
}

void	three_sorter_stack_a(t_stack *stack_a)
{
	t_stack	*stack;
	int 	scenario;
    
	// printf("----------------------------------------------\n");
	// stack_printer_a(stack_a);
	// printf("----------------------------------------------\n");
    stack = stack_a->head;
	scenario = scenario_finder(stack);
	if (scenario == 1)
		return ;
	else if (scenario == 2)
		sa(stack_a);
	else if (scenario >= 3)
		three_sorter_utils_stack_a(stack_a, scenario);
	// printf("----------------------------------------------\n");
	// stack_printer_a(stack_a);
}


void	three_sorter_utils_stack_b(t_stack *stack_b, int scenario)
{
	if (scenario == 3)
	{
		// printf("scen3\n");
		rrb(stack_b);
	}
	else if (scenario == 4)
	{
		// printf("scen4\n");
		rb(stack_b);
		sb(stack_b);
	}
	else if (scenario == 5)
	{
		// printf("scen5\n");
		sb(stack_b);
	}
	else if (scenario == 6)
	{
		// printf("scen6\n");
		// sb(stack_b);
		// rb(stack_b);
		return ;
	}
	// stack_printer_b(stack_b);
}

void	three_sorter_stack_b(t_stack *stack_b)
{
	t_stack	*stack;
	int 	scenario;
    
	// stack_printer_b(stack_b);
	// printf("-----------------LAAAAAAAAAAAAST-----------------------------\n");
    stack = stack_b->head;
	scenario = scenario_finder(stack);
	if (scenario == 1)
	{
		sb(stack_b);
		rb(stack_b);
	}
	else if (scenario == 2)
	{
		// printf("scen2\n");
		rb(stack_b);
	}
	else if (scenario >= 3)
		three_sorter_utils_stack_b(stack_b, scenario);
	// stack_printer_b(stack_b);
}
