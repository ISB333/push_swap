/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:24:08 by adesille          #+#    #+#             */
/*   Updated: 2024/02/19 14:30:50 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
