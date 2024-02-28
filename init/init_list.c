/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:40:28 by adesille          #+#    #+#             */
/*   Updated: 2024/02/28 08:36:10 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	initialize_stacks(int *array, t_stack **stack_a)
{
	int	i;	

	i = 0;
	while (array[i])
		add_node (&*stack_a, array[i++]);
	free(array);
}

void	add_node(t_stack **stack, int value)
{
	t_stack *new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return;
	new_node->value = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
	{
		(*stack)->prev = new_node;
		new_node->position = (*stack)->position + 1;
	}
	else
		new_node->position = 1;
	*stack = new_node;
}

int	security_check(char *argv[])
{
	int	i;
	int	k;

	k = 1;
	while (argv[k])
	{
		i = 0;
		while (argv[k][i])
		{
			if ((argv[k][i] >= '0' && argv[k][i] <= '9')
				|| argv[k][i] == ' ' || argv[k][i] == '-')
			{
				if (argv[k][i] == '-' && argv[k][i + 1] == '-')
					return (-1);
			}
			else if ((argv[k][i] >= 'a' && argv[k][i] <= 'z')
					|| (argv[k][i] >= 'A' && argv[k][i] <= 'Z'))
				return (-1);
			i++;
		}
		k++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}
