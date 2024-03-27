/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrapper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 08:43:59 by adesille          #+#    #+#             */
/*   Updated: 2024/03/27 11:25:29 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	not_in_extract(int *lowest, int value, int n)
{
	while (n-- > 0)
	{
		if (lowest[n] == value)
			return (-1);
	}
	return (0);
}

int	not_in(int *lowest, int value, int n)
{
	int	i;

	i = n;
	while (i-- > 0)
	{
		if (lowest[i] == value)
			return (-1);
	}
	return (0);
}

int	*largest_scrapper(t_stack *stack_b, int n, int i, int j)
{
	t_stack	*b_head;
	int		*largest;

	if (!stack_b)
		return ((int *)0);
	largest = ft_calloc(n, -2147483648);
	b_head = stack_b;
	while (b_head)
	{
		i = -1;
		while (++i < n)
		{
			if (b_head->value > largest[i])
			{
				j = n;
				while (--j > i)
					largest[j] = largest[j - 1];
				largest[i] = b_head->value;
				break ;
			}
		}
		b_head = b_head->next;
	}
	return (largest);
}

int	*half_n_scrapper(int *lowest, int n)
{
	int	*largest;
	int	i;
	int	k;
	int	j;

	n /= 4;
	largest = ft_calloc((n), sizeof(int));
	i = -1;
	while (++i < n)
	{
		k = -1;
		while (++k < (n))
		{
			if (lowest[i] > largest[k])
			{
				j = (n);
				while (--j > k)
					largest[j] = largest[j - 1];
				largest[k] = lowest[i];
				break ;
			}
		}
	}
	return (largest);
}

int	*n_smallest_scrapper(t_stack *stack_a, int n)
{
	t_stack	*a_head;
	int		*smallest;
	int		i;
	int		j;

	smallest = ft_calloc(n, 2147483647);
	a_head = stack_a;
	while (a_head)
	{
		i = -1;
		while (++i < n)
		{
			if (a_head->value < smallest[i])
			{
				j = n;
				while (--j > i)
					smallest[j] = smallest[j - 1];
				smallest[i] = a_head->value;
				break ;
			}
		}
		a_head = a_head->next;
	}
	return (smallest);
}
