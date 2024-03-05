/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 10:59:46 by isb3              #+#    #+#             */
/*   Updated: 2024/03/05 10:33:12 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	sorter(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b_head;
	int		*largest;
	char	side;

	pre_sorting_a(stack_a, stack_b);
	while (ruler(*stack_b) > 0)
	{
		b_head = *stack_b;
		largest = largest_scrapper(b_head, 3, 0, 0);
		side = side_chooser(*stack_b, largest[0]);
		if (side == 'U')
			up_sorter(stack_a, stack_b, largest);
		else if (side == 'L')
			low_sorter(stack_a, stack_b, largest);
		free(largest);
	}
	pa(stack_a, stack_b);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	if (ruler(*stack_a) <= 3)
		three_sorter_stack_a(stack_a);
	else if (ruler(*stack_a) <= 5)
		five_sorter_stack_a(stack_a, stack_b);
	else
	{
		extractor(stack_a, stack_b, n_selector(*stack_a), 0);
		while (*stack_a)
			pb(stack_a, stack_b);
		sorter(stack_a, stack_b);
	}
	sorting_checker(*stack_a);
}
