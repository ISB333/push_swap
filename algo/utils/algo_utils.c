/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:10:58 by adesille          #+#    #+#             */
/*   Updated: 2024/03/03 10:34:24 by isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ruler(t_stack *stack)
{
	t_stack	*last;

	if ((!stack || !stack->next))
		return (0);
	last = return_tail(stack);
	return (last->position);
}

int	*ft_memset(int *s, int c, size_t n)
{
	int	i;

	i = 0;
	while (n-- > 0)
		s[i++] = c;
	s[i] = 0;
	return (s);
}

void	pos_update(t_stack *stack)
{
	if (!stack || !stack->next)
		return ;
	stack->position = 1;
	stack = stack->next;
	while (stack)
	{
		stack->position = stack->prev->position + 1;
		stack = stack->next;
	}
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
