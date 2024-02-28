/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:29:19 by adesille          #+#    #+#             */
/*   Updated: 2024/02/28 08:53:01 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	n_selector(t_stack *stack_a)
{
	int	a_size;

	if (!stack_a || !stack_a->next)
		return 0;
	a_size = stack_a->position;
	if (a_size <= 20)
		return (4);
	else if (a_size <= 40)
		return (6);
	else if (a_size <= 60)
		return (10);
	else if (a_size <= 100)
		return (20);
	else if (a_size <= 250)
		return (40);
	else if (a_size <= 500)
		return (50);
	return (0);
}

t_stack	**return_tail(t_stack **stack)
{    
	if (stack == NULL || *stack == NULL) 
        return NULL;
	while ((*stack)->next)
		stack = &((*stack)->next);
	return (stack);
}


// void    extractor_utils(t_stack **stack_a, t_stack **stack_b, int n, int *largest)
// {
// 	t_stack	*a_head;
// 	int mid;
// 	int i;
// 	int side;

// 	side = 'U';
// 	n = 214578623;
// 	mid = (*stack_a)->position / 2;
// 	a_head = (*stack_a); 
// 	i = -1;
// 	while (largest[++i])
// 	{
// 		if (a_head && a_head->value == largest[i])
// 		{
// 			// pusher(stack_a, stack_b, mid_calculator(largest_values));
// 			pb(stack_a, stack_b);
// 			a_head = (*stack_a); 
// 			// n--;
// 		}
// 	}
// }

// int		mid_calculator(int *largest_values)
// {
// 	int	i;
// 	int	mid;

// 	i = 0;
// 	while (largest_values[i])
// 		i++;
// 	mid = i / 2;
// 	return (largest_values[mid]);
// }