/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:13:40 by checkin           #+#    #+#             */
/*   Updated: 2024/02/26 14:23:39 by adesille         ###   ########.fr       */
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

int	*ft_calloc(size_t size, int value)
{
	int		*arr;

	if (!size)
		return (malloc(0));
	arr = malloc((size + 1) * sizeof(int));
	if (!arr)
		return (NULL);
	ft_memset(arr, value, size);
	return (arr);
}

t_stack *stack_mover(t_stack *stack, int pos)
{
	while (pos-- > 0 && stack)
		stack = stack->next;
	return (stack); 
}

int	*n_largest_finder(t_stack *stack_a, int n)
{
	t_stack	*stack_a_head;
	int *largest_values;
	int i = 0;
	int j = 0;

	largest_values = ft_calloc(n, 1);
	stack_a_head = stack_a;
	while (stack_a_head)
	{
		i = -1;
		while (++i < n)
			if (stack_a_head->value > largest_values[i])
			{
				j = n;
				while(--j > i)
					largest_values[j] = largest_values[j - 1];
				largest_values[i] = stack_a_head->value;
				break;
			}
		stack_a_head = stack_a_head->next;
	}
	return (largest_values);
}
