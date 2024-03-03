/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:36:46 by adesille          #+#    #+#             */
/*   Updated: 2024/03/03 11:45:25 by isb3             ###   ########.fr       */
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

void	initialize_stacks(int *array, t_stack **stack_a)
{
	int	i;	

	i = 0;
	while (array[i])
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
	return (ft_atoi_n_split(array, str));
}

char	*argv_join(char *str1, char *str2)
{
	char	*str;
	int		i;
	int		k;

	i = 0;
	k = 0;
	str = malloc(ft_strlen(str1) + ft_strlen(str2) + 2);
	if (!str)
		return (NULL);
	if (str1 != NULL)
	{
		while (str1[i])
		{
			str[i] = str1[i];
			i++;
		}
	}
	while (str2[k])
		str[i++] = str2[k++];
	str[i] = ' ';
	str[++i] = '\0';
	return (free(str1), str);
}

int	*initializer(char *argv[])
{
	char	*str;
	int		*array;
	int		sec;
	int		i;

	sec = security_check(argv);
	if (sec == -1)
		return (0);
	str = NULL;
	i = 1;
	while (argv[i])
		str = argv_join(str, argv[i++]);
	array = int_array_init(str);
	i = 0;
	while (array[i])
		i++;
	sec = overflow_protector(array, argv, i);
	free(str);
	if (sec != 0)
		return ((int *)0);
	else
		return (array);
}
