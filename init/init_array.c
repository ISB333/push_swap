/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:36:46 by adesille          #+#    #+#             */
/*   Updated: 2024/02/24 14:24:16 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_count_words(char	*str, char c)
{
	int	rows;
	int	i;

	rows = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			rows++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (rows);
}

int	*ft_atoi_n_split(int *array, char *str)
{
	int	rows;
	int	sign;
	int	n;
	int	i;

	rows = -1;
	i = 0;
	while (str[i])
	{
		sign = 1;
		n = 0;
		while (((str[i] >= '0' && str[i] <= '9')
				|| str[i] == '-') && str[i] != ' ')
		{
			if (str[i] == '-' && i++ > 0)
				sign = -1;
			while (str[i] >= '0' && str[i] <= '9')
				n = (n * 10) + (str[i++] - '0');
			array[++rows] = n * sign;
		}
		i++;
	}
	array[++rows] = 0;
	return (array);
}

int	*int_array_init(char *str)
{
	int	*array;
	int	rows;

	rows = ft_count_words(str, ' ');
	array = (int *)malloc((rows + 1) * sizeof(int));
	if (!array)
		return (NULL);
	return (ft_atoi_n_split(array, str));
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

int	*initializer(char *argv[])
{
	char	*str;
	int		*array;
	int		sec;
	int		i;

	sec = security_check(argv);
	if (sec == -1)
		return (0);
	str = NULL;
	i = 1;
	while (argv[i])
		str = argv_join(str, argv[i++]);
	array = int_array_init(str);
	i = 0;
	while (array[i])
		i++;
	sec = overflow_protector(array, argv, i);
	free(str);
	if (sec != 0)
		return ((int *)0);
	else
		return (array);
}
