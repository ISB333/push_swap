/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:03:19 by adesille          #+#    #+#             */
/*   Updated: 2024/02/20 15:17:01 by adesille         ###   ########.fr       */
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

void	lst_freememory(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_data	*current;
	t_data	*next;

	current = stack_a->head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	current = stack_b->head;
	while (current)
	{
		printf("%d\n", current->value);
		next = current->next;
		free(current);
		current = next;
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
