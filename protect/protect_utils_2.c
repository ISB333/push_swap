/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:13:15 by adesille          #+#    #+#             */
/*   Updated: 2024/02/28 08:38:55 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	ft_strcmp(char *str1, char *str2)
{
	size_t	i;

	i = 0;
	if (!str1 || !str2)
		return (0);
	while (str1[i])
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

char	**ft_cut(char **array, char *s, char c, size_t i)
{
	size_t	j;
	size_t	k;

	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			k = i;
			while (s[i] && s[i] != c)
				i++;
			array[j] = ft_substr(s, k, i - k);
			if (!array[j])
			{
				freememory(array);
				return (NULL);
			}
			j++;
		}
	}
	array[j] = NULL;
	return (array);
}

char	**ft_split(char *s, char c)
{
	char	**array;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	array = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	array = ft_cut(array, s, c, i);
	return (free(s), array);
}

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
