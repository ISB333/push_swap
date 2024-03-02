/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrapper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 08:43:59 by adesille          #+#    #+#             */
/*   Updated: 2024/03/02 12:36:41 by isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	not_in(int *lowest, int value)
{
	int	i;

	i = 0;
	while (lowest[i])
	{
		if (lowest[i] == value)
			return (-1);
		i++;
	}
	return (0);
}

int	not_in_largest(t_stack *stack_a, int *lowest, int value)
{
	int	i;

	i = 0;
	if (ruler(stack_a) < 20)
		return (-1);
	while (lowest[i])
	{
		if (lowest[i] == value)
			return (-1);
		i++;
	}
	return (0);
}

int	*larg_scrapper_n2(t_stack *stack_a, int *largest, int n)
{
	t_stack	*a_head;
	int 	*lowest;
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	lowest = ft_calloc(n, 1);
	a_head = stack_a;
	while (a_head)
	{
		i = -1;
		while (++i < n)
			if (a_head->value > lowest[i] && not_in(largest, a_head->value) == 0)
			{
				j = n;
				while(--j > i)
					lowest[j] = lowest[j - 1];
				lowest[i] = a_head->value;
				break;
			}
		a_head = a_head->next;
	}
	return (lowest);
}

int	*largest_scrapper(t_stack *stack_b, int n)
{
	t_stack	*b_head;
	int 	*largest;
	int 	i;

	largest = ft_calloc(n, sizeof(int)); // Allocate memory for the largest array
	if (!largest) {
		// Handle memory allocation failure
		return NULL;
	}

	b_head = stack_b;
	while (b_head)
	{
		i = 0;
		while (i < n)
		{
			if (b_head->value > largest[i])
			{
				// Shift elements to the right to make space for the new largest value
				for (int j = n - 1; j > i; j--)
				{
					largest[j] = largest[j - 1];
				}
				largest[i] = b_head->value;
				break;
			}
			i++;
		}
		b_head = b_head->next;
	}

	return largest;
}

// int	*largest_scrapper(t_stack *stack_b, int n)
// {
// 	t_stack	*b_head;
// 	int 	*largest;
// 	int 	i;
// 	int 	j;

// 	i = 0;
// 	j = 0;
// 	largest = ft_calloc(n, 1);
// 	b_head = stack_b;
// 	while (b_head)
// 	{
// 		i = -1;
// 		while (++i < n)
// 			if (b_head->value > largest[i])
// 			{
// 				j = n;
// 				while(--j > i)
// 					largest[j] = largest[j - 1];
// 				largest[i] = b_head->value;
// 				break;
// 			}
// 		b_head = b_head->next;
// 	}
// 	return (largest);
// }

// int	*largest_finder(t_stack *stack_b)
// {
// 	t_stack	*b_head;
// 	int 	*lowest;
// 	// int 	i;

// 	// i = 0;
// 	lowest = ft_calloc(2, 1);
// 	b_head = stack_b;
// 	while (b_head)
// 	{
// 		if (b_head->value > lowest[0])
// 			lowest[0] = b_head->value;
// 		b_head = b_head->next;
// 	}
// 	b_head = stack_b;
// 	while (b_head)
// 	{
// 		if (b_head->value < lowest[0] && b_head->value > lowest[1])
// 			lowest[1] = b_head->value;
// 		b_head = b_head->next;
// 	}
// 	b_head = stack_b;
// 	// while (b_head)
// 	// {
// 	// 	if (b_head->value < lowest[0] && b_head->value > lowest[1])
// 	// 		lowest[1] = b_head->value;
// 	// 	b_head = b_head->next;
// 	// }
// 	return (lowest);
// }

int	*n_2nd_scrapper(t_stack *stack_a, int *lowest, int n)
{
	t_stack	*a_head;
	int		*largest;
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	if (ruler(stack_a) < 10)
		return ((int *)0);
	largest = ft_calloc(n, 2147483647);
	a_head = stack_a;
	while (a_head)
	{
		i = -1;
		while (++i < n)
			if (a_head->value < largest[i] && not_in_largest(stack_a, lowest, a_head->value) == 0)
			{
				j = n;
				while(--j > i)
					largest[j] = largest[j - 1];
				largest[i] = a_head->value;
				break;
			}
		a_head = a_head->next;
	}
	return (largest);
}

int	*n_smallest_scrapper(t_stack *stack_a, int n)
{
	t_stack	*a_head;
	int 	*smallest;
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	smallest = ft_calloc(n, 2147483647);
	a_head = stack_a;
	while (a_head)
	{
		i = -1;
		while (++i < n)
			if (a_head->value < smallest[i])
			{
				j = n;
				while(--j > i)
					smallest[j] = smallest[j - 1];
				smallest[i] = a_head->value;
				break;
			}
		a_head = a_head->next;
	}
	return (smallest);
}
