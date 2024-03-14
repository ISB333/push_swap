/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:41:05 by adesille          #+#    #+#             */
/*   Updated: 2024/03/14 13:09:17 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	unsigned int	dstlen;
	unsigned int	srclen;

	if ((dst == NULL || src == NULL) && size == 0)
		return (0);
	dstlen = ft_strlen(dst);
	srclen = ft_strlen((char *)src);
	if (size <= dstlen)
		return (size + srclen);
	ft_strlcpy(&dst[dstlen], src, size - dstlen);
	return (dstlen + srclen);
}

char	*argv_join(char *str1, char *str2)
{
	char	*str;
	int		i;
	int		k;

	i = 0;
	k = 0;
	str = malloc(ft_strlen(str1) + ft_strlen(str2) + 2);
	if (!str)
		return (NULL);
	if (str1 != NULL)
	{
		while (str1[i])
		{
			str[i] = str1[i];
			i++;
		}
	}
	while (str2[k])
		str[i++] = str2[k++];
	str[i] = ' ';
	str[++i] = '\0';
	return (free(str1), str);
}
