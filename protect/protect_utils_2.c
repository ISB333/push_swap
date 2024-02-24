/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:03:19 by adesille          #+#    #+#             */
/*   Updated: 2024/02/24 13:59:17 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	free_intmemory(int *array)
// {
// 	int	i;

// 	i = 0;
// 	while (array[i])
// 		free(&array[i++]);
// }

void	freememory(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	lst_freememory(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current;
	t_stack	*next;

	current = stack_a;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	if (stack_b)
	{
		current = stack_b;
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
	}
}

char	*ft_strdup(char *s)
{
	char	*str;
	int		size;

	size = ft_strlen(s) + 1;
	str = malloc(size);
	if (str == NULL)
		return (free(s), NULL);
	ft_strlcpy(str, s, size);
	return (str);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (!size)
		return (src_len);
	while (*src && --size)
		*dst++ = *src++;
	*dst = '\0';
	return (src_len);
}
