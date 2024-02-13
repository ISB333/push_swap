/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:59:56 by adesille          #+#    #+#             */
/*   Updated: 2024/02/13 14:17:54 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	smallest_n_matrix(t_stack_a *stack_a, t_stack_b *stack_b)
// {

// }

int	n_selector(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int	a_size;

	a_size = ruler(stack_a, stack_b, 'A');
	if (a_size <= 20)
		return (a_size / 2);
	else if (a_size <= 60)
		return (a_size / 4);
	else if (a_size <= 100)
		return (a_size / 5);
	else if (a_size <= 500)
		return (a_size / 10);
	return (0);
}

void    fill_intarray(t_stack_a *stack_a, int *lowest_values)
{
	t_data *stack_a_head;
	int i = 0;

	stack_a_head = stack_a->head;
	while(lowest_values[i])
	{
		lowest_values[i] = stack_a_head->value;
		stack_a_head = stack_a_head->next;
		i++;
	}
}

t_data *stack_mover(t_data *stack, int pos)
{
    while (pos-- > 0 && stack)
        stack = stack->next;
    return (stack); 
}

int	*n_smallest_finder(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_data	*stack_a_head;
	int *lowest_values;
	int n;
	int i;

	stack_a_head = stack_a->head;
	n = n_selector(stack_a, stack_b);
	lowest_values = ft_calloc(n);
	if (!lowest_values)
		return (0);
	fill_intarray(stack_a, lowest_values);
	stack_a_head = stack_mover(stack_a_head, n);
	while (stack_a_head)
	{
		i = 0;
		while (lowest_values[i] && stack_a_head->next)
		{
			if (stack_a_head->value < lowest_values[i])
			{
				lowest_values[i] = stack_a_head->value;
				stack_a_head = stack_a_head->next;
			}
			i++;
		}
		stack_a_head = stack_a_head->next;
	}
	return (lowest_values);
}

void	n_smallest_extractor(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_data	*stack_a_head;
	int *lowest_values;
	int i = 0;
	int n;
	
	stack_a_head = stack_a->head;
	lowest_values = n_smallest_finder(stack_a, stack_b);
	n = n_selector(stack_a, stack_b);
	while (lowest_values[i])
	{
		printf("value n%d = %d\n", i, lowest_values[i]);
		i++;
	}
	while (n > 0)
	{
		stack_a_head = stack_a->head;
		i = 0;
		while (lowest_values[i])
		{
			if (stack_a_head->value == lowest_values[i])
			{
				pb(stack_a, stack_b);
				n--;
			}
			i++;
		}
		ra(stack_a);
	}
	printer(stack_a, stack_b);
}

void    push_swap(t_stack_a *stack_a, t_stack_b *stack_b)
{
	// int a_cheapest_pos;

	printf("\n\n");
	if (ruler(stack_a, stack_b, 'A') <= 3)
		three_sorter_stack_a(stack_a);
	else if (ruler(stack_a, stack_b, 'A') <= 5)
		five_sorter_stack_a(stack_a, stack_b);
	else
	{
		n_smallest_extractor(stack_a, stack_b);
		// while(ruler(stack_a, stack_b, 'A') > 3)
		// {
		// 	cost_initializer(stack_a, stack_b);
		// }
		// printer(stack_a, stack_b);
	}
}
