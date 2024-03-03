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

// void	sorter()


void	two_swapper(t_stack **stack_a, t_stack **stack_b, int value)
{
	t_stack *b_head;

	pa(stack_a, stack_b);
	b_head = *stack_b;
	while (b_head->value != value)
	{
		rb(stack_b);
		b_head = *stack_b;
	}
	if (b_head->value == value)
	{
		pa(stack_a, stack_b);
		sa(stack_a);
	}
}

char	side_chooser(t_stack *stack_b, int value)
{
	t_stack	*b_head;
	t_stack	*b_tail;
	size_t		mid;

	b_head = stack_b;
	b_tail = return_tail(stack_b);
	mid = ruler(stack_b) / 2;
	while (b_head && b_head->value != value && b_head->position < mid)	
		b_head = b_head->next;
	if (b_head->value == value)
		return ('U');
	while (b_tail && b_tail->value != value && b_tail->position > mid)	
		b_tail = b_tail->prev;
	if (b_tail->value == value)
		return ('L');
	return (0);
}

void	pre_sorting_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a_head;
	t_stack	*a_tail;
	int a_size;

	a_head = *stack_a;
	a_tail = return_tail(*stack_a);
	a_size = ruler(*stack_a);
	if (a_size == 5)
	{
		// printf("size 5\n");
		five_sorter_stack_a(stack_a, stack_b);
	}
	else if (a_size == 4)
	{
		// printf("size 4\n");
		pa(stack_a, stack_b);
		five_sorter_stack_a(stack_a, stack_b);
	}
	else if (a_size == 3)
	{
		// printf("size 3\n");
		three_sorter_stack_a(stack_a);
	}
	else if (a_size == 2)
	{
		// printf("size 2\n");
		if (a_head->value > a_tail->value)
			sa(stack_a);
	}

}

void    sorter(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b_head;
	int		*largest;
	int		token;
	char	side;

	pre_sorting_a(stack_a, stack_b);
	while (ruler(*stack_b) > 0)
	{
		b_head = *stack_b;
		largest = largest_scrapper(b_head, 3, 0, 0);
		// printf("largest[0] = %d\nlargest[1] = %d\n", largest[0], largest[1]);
		side = side_chooser(*stack_b, largest[0]);
		token = 0;
		if (side == 'U')
		{
			while(b_head->value != largest[0])
			{
				rb(stack_b);
				b_head = *stack_b;
				if (b_head->value == largest[1])
				{
					pa(stack_a, stack_b);
					b_head = *stack_b;
					token = 1;
				}
			}
			pa(stack_a, stack_b);
			if (token == 1)
				sa(stack_a);

		}
		else if (side == 'L')
		{
			while(b_head->value != largest[0])	
			{
				rrb(stack_b);
				b_head = *stack_b;
				if (b_head->value == largest[1])
				{
					pa(stack_a, stack_b);
					b_head = *stack_b;
					token = 1;
				}
			}
			pa(stack_a, stack_b);
			if (token == 1)
				sa(stack_a);
		}
		free(largest);
	}
	pa(stack_a, stack_b);
}

void    push_swap(t_stack **stack_a, t_stack **stack_b)
{
	// printf("\n");
	// printer(*stack_a, *stack_b, 2);
	if (ruler(*stack_a) <= 3)
		three_sorter_stack_a(stack_a);
	else if (ruler(*stack_a) <= 5)
		five_sorter_stack_a(stack_a, stack_b);
	else
	{
		extractor(stack_a, stack_b, n_selector(*stack_a));
		sorter(stack_a, stack_b);
		// printer(*stack_a, *stack_b, 2);
		sorting_checker(*stack_a);
	}
}
