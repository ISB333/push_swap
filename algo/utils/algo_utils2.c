/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:29:19 by adesille          #+#    #+#             */
/*   Updated: 2024/03/03 12:03:21 by isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	n_selector(t_stack *stack_a)
{
	size_t	a_size;

	if (!stack_a || !stack_a->next)
		return (0);
	a_size = ruler(stack_a);
	if (a_size <= 15)
		return (4);
	else if (a_size <= 30)
		return (8);
	else if (a_size <= 60)
		return (16);
	else if (a_size <= 100)
		return (20);
	else if (a_size <= 300)
		return (25);
	else if (a_size <= 500)
		return (30);
	return (0);
}

t_stack	*return_tail(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	free_int(int *int_arr1, int *int_arr2)
{
	if (int_arr1)
		free(int_arr1);
	if (int_arr2)
		free(int_arr2);
}
