/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_extremes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:07:28 by adesille          #+#    #+#             */
/*   Updated: 2024/02/11 16:08:41 by isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    scen_minus1toptop(t_stack_a *stack_a, t_stack_b *stack_b)
{
    printf("\n-1toptop\n");
    // printer(stack_a, stack_b);
    rrb(stack_b);
    rrb(stack_b);
    // printf("\n============================================================================\n");
	// stack_printer_b(stack_b);
	// printf("============================================================================\n");
    pb(stack_a, stack_b);
    // printf("\n============================================================================\n");
	// stack_printer_b(stack_b);
	// printf("============================================================================\n");
    rb(stack_b);
    rb(stack_b);
}
void    scen_minus1toptopminus1(t_stack_a *stack_a, t_stack_b *stack_b)
{
    printf("\n-1toptop-1\n");
    rr(stack_a, stack_b);
    pb(stack_a, stack_b);
    rrb(stack_b);
}

void    scen_bottbott(t_stack_a *stack_a, t_stack_b *stack_b)
{
    printf("\nbottbott\n");
    rra(stack_a);
    pb(stack_a, stack_b);
    rrb(stack_b);
}

void    scen_bottplusbottplus(t_stack_a *stack_a, t_stack_b *stack_b)
{
    // printf("\n============================================================================\n");
    // printer(stack_a, stack_b);
	// printf("============================================================================\n");
    printf("\nbottplusbottplus\n");
    rrr(stack_a, stack_b);
    rrb(stack_b);
    pb(stack_a, stack_b);
    rb(stack_b);
    rb(stack_b);
    // printf("\n============================================================================\n");
    // printer(stack_a, stack_b);
	// printf("============================================================================\n");
}