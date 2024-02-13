/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:13:40 by checkin           #+#    #+#             */
/*   Updated: 2024/02/13 14:00:45 by adesille         ###   ########.fr       */
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
	ft_memset(arr, 1, size);
	return (arr);
}
