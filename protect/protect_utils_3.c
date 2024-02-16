/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:13:15 by adesille          #+#    #+#             */
/*   Updated: 2024/02/16 15:21:56 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp(char *str1, char *str2)
{
	size_t	i;

    i = 0;
	if (!str1 || !str2)
		return (0);
	while (str1[i])
	{
		if (str1[i] != str2[i])
        {
            printf("%s\n%s\n", str1, str2);
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
        }
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
	return (array);
}
