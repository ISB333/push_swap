/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:30:39 by isb3              #+#    #+#             */
/*   Updated: 2024/03/05 10:31:58 by adesille         ###   ########.fr       */
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
	ft_putstr("ss\n");
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_putstr("sa\n");
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_putstr("sb\n");
}
