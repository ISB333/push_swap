/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:03:19 by adesille          #+#    #+#             */
/*   Updated: 2024/02/16 11:45:25 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	int		size;

	if (s == NULL)
		return (NULL);
	size = (ft_strlen(s));
	if (start >= ((unsigned int)size))
		return (ft_strdup(""));
	if (len > size - start)
		len = size - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
	{
		free(s);
		return (NULL);
	}
	ft_strlcpy(str, &s[start], len + 1);
	str[len] = '\0';
	return (str);
}

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
	// free(array);
}

void    lst_freememory(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_data *current;
	t_data *next;

	current = stack_a->head;
	while(current)
	{
		next = current->next;
		free(current);
		current = next;

	}
	free(stack_a);
	current = stack_b->head;
	while(current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack_b);
}

char	*ft_strdup(char *s)
{
	char	*str;
	int		size;

	size = ft_strlen(s) + 1;
	str = malloc(size);
	if (str == NULL)
	{
		free(s);
		return (NULL);
	}
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
