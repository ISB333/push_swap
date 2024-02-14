/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:13:40 by checkin           #+#    #+#             */
/*   Updated: 2024/02/14 13:47:10 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*ft_memset(int *s, int c, size_t n)
{
	int	i;

	i = 0;
	while (n-- > 0)
		s[i++] = c;
	s[i] = 0;
	return (s);
}

int	*ft_calloc(size_t size)
{
	int		*arr;

	if (!size)
		return (malloc(0));
	arr = malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	ft_memset(arr, 2147483647, size);
	return (arr);
}

// void    fill_intarray(t_stack_a *stack_a, int *lowest_values)
// {
// 	t_data *stack_a_head;
// 	int i = -1;

// 	stack_a_head = stack_a->head;
// 	while(lowest_values[++i])
// 	{
// 		lowest_values[i] = stack_a_head->value;
// 		stack_a_head = stack_a_head->next;
// 	}
// }

t_data *stack_mover(t_data *stack, int pos)
{
	while (pos-- > 0 && stack)
		stack = stack->next;
	return (stack); 
}

int	*n_smallest_finder(t_stack_a *stack_a, int n)
{
	t_data	*stack_a_head;
	int *lowest_values;
	int i = 0;
	int j = 0;

	lowest_values = ft_calloc(n);
	stack_a_head = stack_a->head;
	while (stack_a_head)
	{
		i = -1;
		while (++i < n)
			if (stack_a_head->value < lowest_values[i])
			{
				j = n;
				while(--j > i)
					lowest_values[j] = lowest_values[j - 1];
				lowest_values[i] = stack_a_head->value;
				break;
			}
		stack_a_head = stack_a_head->next;
	}
	return (lowest_values);
}