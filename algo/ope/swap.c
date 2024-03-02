/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:30:39 by isb3              #+#    #+#             */
/*   Updated: 2024/03/02 10:23:50 by isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	swap(t_stack **stack)
{
	if (!stack || !*stack || !(*stack)->next)
		return ;
	(*stack)->value = (*stack)->value ^ (*stack)->next->value;
	(*stack)->next->value = (*stack)->value ^ (*stack)->next->value;
	(*stack)->value = (*stack)->value ^ (*stack)->next->value;
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	printf("ss\n");
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	printf("sb\n");
}
