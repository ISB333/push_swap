/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:15:12 by adesille          #+#    #+#             */
/*   Updated: 2024/03/27 11:07:29 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	n_selector(t_stack *stack_a)
{
	size_t	a_size;

	if (!stack_a || !stack_a->next)
		return (0);
	a_size = ruler(stack_a);
	if (a_size <= 30)
		return (a_size / 3);
	else if (a_size <= 60)
		return (a_size / 4);
	else if (a_size <= 100)
		return (a_size / 5);
	else if (a_size <= 300)
		return (a_size / 9);
	else if (a_size <= 500)
		return (a_size / 12);
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

void	ft_putstr(char *s)
{
	if (s == NULL)
		return ;
	write(1, s, ft_strlen(s));
}
