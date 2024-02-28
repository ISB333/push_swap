/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:59:56 by adesille          #+#    #+#             */
/*   Updated: 2024/02/25 10:32:04y isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pre_sorting_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a_head;
	t_stack	**a_tail;

	a_head = *stack_a;
	a_tail = return_tail(stack_a);
	int a_size;

	a_size = ruler(stack_a, stack_b, 'A');
	if (a_size == 5)
	{
		printf("size 5\n");
		five_sorter_stack_a(stack_a, stack_b);
	}
	else if (a_size == 4)
	{
		printf("size 4\n");
		pa(stack_a, stack_b);
		five_sorter_stack_a(stack_a, stack_b);
	}
	else if (a_size == 3)
	{
		printf("size 3\n");
		three_sorter_stack_a(stack_a);
	}
	else if (a_size == 2)
	{
		printf("size 2\n");
		if (a_head->value > (*a_tail)->value)
			sa(stack_a);
	}
}

void    pushing_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	**b_head;
	int		*largest;
	int		*lowest;

	pre_sorting_a(stack_a, stack_b);
	b_head = stack_b;
	// while (ruler(stack_a, stack_b, 'B') > 35)
	// {
		///////////////// NEED TO ADD AN OPTION TO SEND THE LOWEST FIND ON THE ROAD AND PUT HEM AT THE LOW OF THE STACK //////////////////////////////
		largest = largest_scrapper(*stack_b, 3);
		lowest = larg_scrapper_n2(*stack_b, largest, 3);
		int i = 0;
		while(largest[i])
			printf("largest = %d\n", largest[i++]);
		i = 0;
		while(lowest[i])
			printf("lowest = %d\n", lowest[i++]);
		// b_head = stack_b;
		free(largest);
		free(lowest);
	// }
	// printer(stack_a, stack_b);
	// last_push(stack_a, stack_b);
	// sorting_checker(*stack_a);
}

void    push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	n;

	printf("\n");
	// printer(*stack_a, *stack_b, 2);
	if (ruler(stack_a, stack_b, 'A') <= 3)
		three_sorter_stack_a(stack_a);
	else if (ruler(stack_a, stack_b, 'A') <= 5)
		five_sorter_stack_a(stack_a, stack_b);
	else
	{
		n = n_selector(*stack_a);
		while (ruler(stack_a, stack_b, 'A') > 5)
			n_smallest_extractor(stack_a, stack_b, n);
		// printer(*stack_a, *stack_b, 2);
		pushing_back_to_a(stack_a, stack_b);
	}
}

// void    pushing_back_to_a(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_stack	**b_head;
// 	int		*largest;

// 	pre_sorting_a(stack_a, stack_b);
// 	b_head = stack_b;
// 	while (ruler(stack_a, stack_b, 'B') > 35)
// 	{
// 		///////////////// NEED TO ADD AN OPTION TO SEND THE LOWEST FIND ON THE ROAD AND PUT HEM AT THE LOW OF THE STACK //////////////////////////////
// 		largest = largest_finder(*stack_b);
// 		// int i = 0;
// 		// while(largest[i])
// 		// 	printf("largest = %d\n", largest[i++]);
// 		if ((*b_head)->value == largest[0])
// 			pa(stack_a, stack_b);
// 		else if ((*b_head)->value == largest[1])
// 			two_swapper(stack_a, stack_b, largest[0]);
// 		else if ((*b_head)->value == largest[2])
// 			three_swapper(stack_a, stack_b, largest);
// 		else 
// 			rb(stack_b);
// 		b_head = stack_b;
// 		free(largest);
// 	}
// 	// printer(stack_a, stack_b);
// 	// last_push(stack_a, stack_b);
// 	// sorting_checker(*stack_a);
// }