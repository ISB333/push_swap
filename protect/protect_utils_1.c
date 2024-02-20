/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:08:46 by adesille          #+#    #+#             */
/*   Updated: 2024/02/20 13:22:51 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static size_t	digitcount(int n)
{
	size_t	digitlen;
	int		temp;

	temp = n;
	digitlen = 1;
	if (temp < 0)
		temp = -temp;
	while (temp >= 10)
	{
		temp /= 10;
		digitlen++;
	}
	return (digitlen);
}

static char	*ft_putnbr_pos(int n, int digitlen)
{
	int		end;
	int		trueend;
	char	*numbers;

	numbers = malloc(digitlen + 1);
	if (numbers == NULL)
		return (NULL);
	end = digitlen - 1;
	trueend = digitlen;
	while (end >= 0)
	{
		numbers[end] = n % 10 + '0';
		n /= 10;
		end--;
	}
	numbers[trueend] = '\0';
	return (numbers);
}

static char	*ft_putnbr_neg(int n, int digitlen)
{
	int		end;
	int		trueend;
	char	*numbers;

	numbers = malloc(digitlen + 1);
	if (numbers == NULL)
		return (NULL);
	end = digitlen - 1;
	trueend = digitlen;
	numbers[0] = '-';
	n = -n;
	while (end > 0)
	{
		numbers[end] = n % 10 + '0';
		n /= 10;
		end--;
	}
	numbers[trueend] = '\0';
	return (numbers);
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	digitlen;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	digitlen = digitcount(n);
	if (n < 0)
		result = ft_putnbr_neg(n, digitlen + 1);
	else
		result = ft_putnbr_pos(n, digitlen);
	return (result);
}
