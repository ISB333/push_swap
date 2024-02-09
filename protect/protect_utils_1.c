/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:08:46 by adesille          #+#    #+#             */
/*   Updated: 2024/02/02 06:22:37 by isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_putnbr(int n, int digit_nbr)
{
	char	*str_nbr;
	int		len;
	int		token;

	token = 0;
	len = digit_nbr;
	str_nbr = malloc(digit_nbr + 1);
	if (!str_nbr)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		token = 1;
	}
	while (digit_nbr > 0)
	{
		str_nbr[--digit_nbr] = n % 10 + '0';
		n /= 10;
	}
	if (token == 1)
		str_nbr[0] = '-';
	str_nbr[len] = '\0';
	return (str_nbr);
}

int	digit_counter(int n)
{
	int	count;
	int	temp_n;

	temp_n = n;
	count = 0;
	if (temp_n < 0)
	{
		temp_n *= -1;
		count ++;
	}
	while (temp_n > 0)
	{
		temp_n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		digit_nbr;

	if (n == 0)
		return (NULL);
	if (n == -2147483648)
		return ("-2147483648");
	digit_nbr = digit_counter(n);
	result = ft_putnbr(n, digit_nbr);
	return (result);
}
