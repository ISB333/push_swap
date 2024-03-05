/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:40:28 by adesille          #+#    #+#             */
/*   Updated: 2024/03/05 11:38:00 by adesille         ###   ########.fr       */
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

int	security_check(char *argv[])
{
	int	i;
	int	k;

	k = 1;
	while (argv[k])
	{
		i = 0;
		while (argv[k][i])
		{
			if ((argv[k][i] >= '0' && argv[k][i] <= '9')
				|| argv[k][i] == ' ' || argv[k][i] == '-')
			{
				if (argv[k][i] == '-' && argv[k][i + 1] == '-')
					return (-1);
			}
			else if ((argv[k][i] >= 'a' && argv[k][i] <= 'z')
					|| (argv[k][i] >= 'A' && argv[k][i] <= 'Z'))
				return (-1);
			i++;
		}
		k++;
	}
	return (0);
}

int	duplicate_sec(int *int_array)
{
	int	i;
	int	k;

	i = -1;
	while (int_array[++i])
	{
		k = -1;
		while (int_array[++k])
			if (int_array[k] == int_array[i] && k != i)
				return (-1);
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}
