/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:29:19 by adesille          #+#    #+#             */
/*   Updated: 2024/03/02 14:49:09 by isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	n_selector(t_stack *stack_a)
{
	size_t	a_size;

	if (!stack_a || !stack_a->next)
		return 0;
	a_size = ruler(stack_a);
	if (a_size <= 15)
		return (4);
	else if (a_size <= 30)
		return (6);
	else if (a_size <= 60)
		return (10);
	else if (a_size <= 100)
		return (14);
	else if (a_size <= 250)
		return (10);
	else if (a_size <= 500)
		return (15);
	// if (a_size <= 15)
	// 	return (2);
	// else if (a_size <= 30)
	// 	return (3);
	// else if (a_size <= 60)
	// 	return (5);
	// else if (a_size <= 100)
	// 	return (7);
	// else if (a_size <= 250)
	// 	return (10);
	// else if (a_size <= 500)
	// 	return (15);
	return (0);
}

t_stack	*return_tail(t_stack *stack)
{    
	if (!stack)
        return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	free_int(int *int_arr1, int *int_arr2)
{
	if (int_arr1)
		free(int_arr1);
	if (int_arr2)
		free(int_arr2);
}

void	sorting_checker(t_stack *stack_a)
{
	t_stack	*a_tmp;

	a_tmp = stack_a;
	while (a_tmp->next)
	{
		if (a_tmp->value > a_tmp->next->value)
		{
			printf("\033[0;31m");
			printf("==============================================================================\n");
			printf("NOT SORTED MUDAFUKA SHGIEHBKGHBADGKHBEGLKJ!@!##$#@$^$@$^@#!^^$@$TYWQHYNG$VTTRH\n");
			printf("==============================================================================\n");
			printf("\033[0;37m");
			return ;
		}
		a_tmp = a_tmp->next;
	}
	printf("\033[0;34m");
	printf("----------------------------------------------------------------------------------\n");
	printf("                         SORTING OK BROoOoOooOOoOOoO!\n");
	printf("----------------------------------------------------------------------------------\n");
	printf("\033[0;37m");
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