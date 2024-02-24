/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:30:39 by isb3              #+#    #+#             */
/*   Updated: 2024/02/24 16:18:09 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	do_sa(t_stack **stack)
{
	*stack = (*stack)->next;
	(*stack)->prev->next = (*stack)->next; 
	(*stack)->next = (*stack)->prev;
	(*stack)->prev->prev = *stack;
	(*stack)->prev = NULL;
	(*stack)->position++;
	(*stack)->next->position--;
}

void	do_sb(t_stack **stack)
{
	*stack = (*stack)->next;
	(*stack)->prev->next = (*stack)->next; 
	(*stack)->next = (*stack)->prev;
	(*stack)->prev->prev = *stack;
	(*stack)->prev = NULL;
	(*stack)->position++;
	(*stack)->next->position--;
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	do_sa(stack_a);
	do_sb(stack_b);
	printf("ss\n");
}

void	sa(t_stack **stack_a)
{
	do_sa(stack_a);
	printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	do_sb(stack_b);
	printf("sb\n");
}
