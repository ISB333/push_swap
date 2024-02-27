/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:13:40 by checkin           #+#    #+#             */
/*   Updated: 2024/02/27 14:26:51 by adesille         ###   ########.fr       */
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

int	*n_smallest_finder(t_stack *stack_a, int n)
{
	t_stack	*a_head;
	int *smallest;
	int i = 0;
	int j = 0;

	smallest = ft_calloc(n, 2147483647);
	a_head = stack_a;
	while (a_head)
	{
		i = -1;
		while (++i < n)
			if (a_head->value < smallest[i])
			{
				j = n;
				while(--j > i)
					smallest[j] = smallest[j - 1];
				smallest[i] = a_head->value;
				break;
			}
		a_head = a_head->next;
	}
	return (smallest);
}
