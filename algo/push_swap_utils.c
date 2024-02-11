/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:10:58 by adesille          #+#    #+#             */
/*   Updated: 2024/02/11 15:56:27 by isb3             ###   ########.fr       */
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

void    printer(t_stack_a *stack_a, t_stack_b *stack_b)
{
		////////////   	PRINTER   ////////////
		printf("-----------------------------------STACK_A-----------------------------------\n");
		stack_printer_a(stack_a);
		printf("------------------STACK_B---------------------\n");
		stack_printer_b(stack_b);
}

void	cost_initializer(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_data *stack_a_head;
	t_data *stack_b_head;

	stack_a_head = stack_a->head;
	stack_b_head = stack_b->head;
	while (stack_a_head->position <= (ruler(stack_a, stack_b, 'A') / 2))
	{
		stack_a_head->cost = stack_a_head->position;
		stack_a_head = stack_a_head->next;
	}
	while (stack_a_head && stack_a_head->position <= ruler(stack_a, stack_b, 'A'))
	{
		stack_a_head->cost = ruler(stack_a, stack_b, 'A') - stack_a_head->position;
		stack_a_head = stack_a_head->next;
	}
	while (stack_b_head->position <= (ruler(stack_a, stack_b, 'B') / 2))
	{
		stack_b_head->cost = stack_b_head->position;
		stack_b_head = stack_b_head->next;
	}
	while (stack_b_head && stack_b_head->position <= ruler(stack_a, stack_b, 'B'))
	{
		stack_b_head->cost = ruler(stack_a, stack_b, 'B') - stack_b_head->position;
		stack_b_head = stack_b_head->next;
	}
}

int	cheapest_pos_finder(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_data	*stack_a_tail;
	int		b_cost;
	int		cheapest_cost;
	int		a_cheapest_pos;
	int		abs_dif;
	
	stack_a_tail = stack_a->tail;
	cheapest_cost = 2147483647;
	while (stack_a_tail->prev)
	{
		b_cost = b_pos_finder(stack_a_tail->value, stack_b);
		abs_dif = abs_diff(stack_a_tail->cost, b_cost) + b_cost;
		// printf("abs_diff+b_cost = %d\n", abs_diff(stack_a_tail->cost, b_cost) + b_cost);
		if (abs_dif < cheapest_cost)
		{
			// printf("abs_diff = %d\nabs_diff+b_cost = %d\n", abs_diff(stack_a_tail->cost, b_cost), abs_diff(stack_a_tail->cost, b_cost) + b_cost);
			cheapest_cost = abs_diff(stack_a_tail->cost, b_cost) + b_cost;
			a_cheapest_pos = stack_a_tail->position;
		}
		stack_a_tail = stack_a_tail->prev;
	}
	return (a_cheapest_pos);
}