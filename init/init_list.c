/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:13:55 by adesille          #+#    #+#             */
/*   Updated: 2024/03/14 13:14:14 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_node(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->value = value;
	if (!(*stack))
	{
		*stack = new_node;
		new_node->position = 1;
		new_node->prev = NULL;
	}
	else
	{
		last_node = return_tail(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
		new_node->position = last_node->position + 1;
	}
}

void	initialize_stacks(int *array, t_stack **stack_a, int len)
{
	int	i;	

	i = 0;
	while (len-- > 0)
		add_node (&*stack_a, array[i++]);
	free(array);
}

int	*int_array_init(char *str)
{
	int	*array;
	int	rows;

	rows = ft_count_words(str, ' ');
	array = (int *)malloc((rows + 1) * sizeof(int));
	if (!array)
		return (NULL);
	return (ft_atoi_n_split(array, str, 0, -1));
}

char	*argv_join_all(char *argv[])
{
	char	*str;
	int		i;

	i = 1;
	str = NULL;
	while (argv[i])
		str = argv_join(str, argv[i++]);
	return (str);
}

int	*initializer(char *argv[])
{
	char	*str;
	int		*array;
	int		sec;

	sec = security_check(argv);
	if (sec == -1)
		return (0);
	str = argv_join_all(argv);
	array = int_array_init(str);
	if (array[0] == 0)
		return (free(array), free(str), (int *)0);
	sec = el_protector(array, argv, ft_count_words(str, ' '));
	free(str);
	if (sec != 0)
		return (free(array), (int *)0);
	else
		return (array);
}
