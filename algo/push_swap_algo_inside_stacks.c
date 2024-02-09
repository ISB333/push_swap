/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_inside_stacks.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:21:59 by adesille          #+#    #+#             */
/*   Updated: 2024/02/09 13:41:07 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    downside_elevator(t_stack_a *stack_a, t_stack_b *stack_b, int a_cost, int b_cost)
{
	int     rollback_cost;

	// printer(stack_a, stack_b);
	rollback_cost = b_cost - 1;
	while (a_cost-- > 0 || b_cost-- > 0)
		rrr(stack_a, stack_b);
	while (a_cost-- > 0)
		rra(stack_a);
	while (b_cost-- > 0)
		rrb(stack_b);
	if(stack_a->tail->value >  stack_b->tail->value)
	{
		rrb(stack_b);
		rollback_cost++;
	}
	// printf("\n============================================================================\n");
	// stack_printer_b(stack_b);
	// printf("============================================================================\n");
	pb(stack_a, stack_b);
	while (rollback_cost-- > 0)
		rb(stack_b);
	printf("\nDOWNSIDE ELEVATOR\n");
}

void    upside_elevator(t_stack_a *stack_a, t_stack_b *stack_b, int a_cost, int b_cost)
{
	int     rollback_cost;

	rollback_cost = b_cost + 1;
	while (a_cost-- > 0 || b_cost-- > 0)
		rr(stack_a, stack_b);
	while (a_cost-- > 0)
		ra(stack_a);
	while (b_cost-- > 0)
		rb(stack_b);
	pb(stack_a, stack_b);
	while (rollback_cost-- > 0)
		rrb(stack_b);
	printf("\nUPSIDE ELEVATOR\n");
}

void    crossed_elevator_ud(t_stack_a *stack_a, t_stack_b *stack_b, int a_cost, int b_cost)
{
	int     rollback_cost;

	// printf("\na_cost = %d\nb_cost = %d\n", a_cost, b_cost);
	rollback_cost = b_cost + 1;
	while (a_cost-- > 0)
		rra(stack_a);
	while (b_cost-- > 0)
		rb(stack_b);
	// printf("\n============================================================================\n");
	// stack_printer_b(stack_b);
	// printf("============================================================================\n");
	pb(stack_a, stack_b);
	while (rollback_cost-- > 0)
		rrb(stack_b);
	printf("\nCROSSED ELEVATOR   UD\n");
}

void    crossed_elevator_du(t_stack_a *stack_a, t_stack_b *stack_b, int a_cost, int b_cost)
{
	int     rollback_cost;

	rollback_cost = b_cost;
	while (a_cost-- > 0)
		rra(stack_a);
	while (b_cost-- > 0)
		rb(stack_b);
	pb(stack_a, stack_b);
	while (rollback_cost-- > 0)
		rrb(stack_b);
	printf("\nCROSSED ELEVATOR   DU\n");
}

void    inside_stacks_sorting(t_stack_a *stack_a, t_stack_b *stack_b, int a_pos, int b_pos)
{
	int a_top;
	int b_top;

	a_top = ruler(stack_a, stack_b, 'A');
	b_top = ruler(stack_a, stack_b, 'B');
	if (a_pos >= (a_top / 2) && b_pos >= (b_top / 2))
		downside_elevator(stack_a, stack_b, (a_top - a_pos), (b_top - b_pos));
	else if (a_pos <= (a_top / 2) && b_pos <= (b_top / 2))
		upside_elevator(stack_a, stack_b, (a_top - a_pos), (b_top - b_pos));
	else if (a_pos <= (a_top / 2) && b_pos <= (b_top / 2))
		downside_elevator(stack_a, stack_b, a_pos, b_pos);
	else if (a_pos >= (a_top / 2) && b_pos <= (b_top / 2))
		crossed_elevator_ud(stack_a, stack_b, (a_top - a_pos), b_pos - 1);
	else if (a_pos <= (a_top / 2) && b_pos >= (b_top / 2))
		crossed_elevator_du(stack_a, stack_b, a_pos, (b_top - b_pos));
}
