/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extractor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 08:48:19 by adesille          #+#    #+#             */
/*   Updated: 2024/03/02 09:45:31by isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char    extract_side_chooser(int *lowest, int *largest, t_stack *stack_a, int up, int low)
{
	t_stack  *a_head;
	int     i;
	size_t		mid;

	if ((!stack_a || !stack_a->next))
		return (0);
	a_head = stack_a;
	mid = ruler(stack_a) / 2;
	while (a_head->position < mid)
	{
		i = 0;
		while (lowest[i])
		{
			if (largest && a_head->value == largest[i])
				up++;
			if (a_head->value == lowest[i])
				up++;
			i++;
		}
		a_head = a_head->next;
	}
	while (a_head)
	{
		i = 0;
		while (lowest[i])
		{
			if (largest && a_head->value == largest[i])
				up++;
			if (a_head->value == lowest[i])
				up++;
			i++;
		}
		a_head = a_head->next;
	}
	if (up >= low)
		return ('L');
	return ('U');
}

// int	*largest_scrapper_test(int *lowest, int *largest, int n)
// {
// 	int i;
// 	int k;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	largest = ft_calloc(n / 2, 1);
// 	while (lowest[i])
// 	{
// 		k = -1;
// 		while (++k < n)
// 			if (lowest[i] > largest[i])
// 			{
// 				j = n;
// 				while(--j > i)
// 					largest[j] = largest[j - 1];
// 				largest[j] = lowest[i];
// 			}
// 		i++;
// 	}
// 	return(largest);
	
// }

int	*largest_scrapper_test(int *lowest, int n)
{
	int *largest;
	int i, k;

	// Allocate memory for the largest array
	largest = ft_calloc(n / 2, sizeof(int));

	i = 0;
	while (lowest[i])
	{
		k = 0;
		while (k < n / 2)
		{
			if (lowest[i] > largest[k])
			{
				// Shift elements to the right to make space for the new largest value
				for (int l = n / 2 - 1; l > k; l--)
				{
					largest[l] = largest[l - 1];
				}
				largest[k] = lowest[i];
				break;
			}
			k++;
		}
		i++;
	}

	return largest;
}


void    extractor(t_stack **stack_a, t_stack **stack_b, int n)
{
	int		*largest;
	int		*lowest;
	t_stack	*a_head;
	// t_stack	*b_tail = return_tail(*stack_b);
	// char	side;
	int 	i;

	while (ruler(*stack_a) > 5)
	{
		n = n_selector(*stack_a);
		lowest = n_smallest_scrapper((*stack_a), n);
		///// Try to replace 2nd n Lowest AKA Largest by Largest of Lowest /////
		// largest = n_2nd_scrapper((*stack_a), lowest, n);
		largest = largest_scrapper_test(lowest, n);
		a_head = (*stack_a); 
		i = 0;
		while (lowest[i])
		{
			// if (largest && a_head->value == largest[i])
			// {
			// 	pb(stack_a, stack_b);
			// 	if (ruler(*stack_b) >= 3 && (*stack_b)->value < (*stack_b)->next->value)
			// 		sb(stack_b);
			// 	a_head = (*stack_a); 
			// }
			if (a_head && a_head->value == lowest[i])
			{
				if (not_in(largest, a_head->value) == 0)
					pb(stack_a, stack_b);
				else
				{
					pb(stack_a, stack_b);
					rb(stack_b);
				}
				a_head = (*stack_a); 
			}
			i++;
		}
		ra(stack_a);
		free_int(lowest, largest);
	}
	while(*stack_a)
		pb(stack_a, stack_b);
}
