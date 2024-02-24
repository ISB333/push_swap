/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:30:34 by isb3              #+#    #+#             */
/*   Updated: 2024/02/24 16:19:50 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
/// TOP become LAST





void	rr(t_stack **stack_a, t_stack **stack_b)
{
	do_ra(stack_a);
	do_rb(stack_b);
	printf("rrr\n");
}

void	ra(t_stack **stack_a)
{
	do_ra(stack_a);
	printf("rra\n");
}

void	rb(t_stack **stack_b)
{
	do_rb(stack_b);
	printf("rrb\n");
}
