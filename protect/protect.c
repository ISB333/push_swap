/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:54:15 by adesille          #+#    #+#             */
/*   Updated: 2024/03/25 11:20:01 by isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	freememory(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	while (i-- > 0)
		free(array[i]);
	free(array);
}

void	lst_freememory(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current;
	t_stack	*next;

	current = stack_a;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	if (stack_b)
	{
		current = stack_b;
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
	}
}

int	overflow_checker(char **after_itoa, char **initial_array)
{
	int	sec;
	int	i;

	i = 0;
	while (after_itoa[i] && initial_array[i++])
	{
		sec = ft_strcmp(initial_array[i], after_itoa[i]);
		if (sec != 0)
			return (-1);
	}
	return (0);
}

char	**argv_init(char *argv[])
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	while (argv[++i])
		str = argv_join(str, argv[i]);
	return (ft_split(str, ' '));
}

int	el_protector(int *int_array, char *argv[], int len)
{
	char	**after_itoa;
	char	**initial_array;
	int		secu;
	int		len_tmp;

	secu = 0;
	len_tmp = len;
	after_itoa = (char **)malloc((len + 1) * sizeof(char *));
	if (!after_itoa)
		return (0);
	after_itoa[len] = NULL;
	while (len-- > 0)
		after_itoa[len] = ft_itoa(int_array[len]);
	initial_array = argv_init(argv);
	secu = overflow_checker(after_itoa, initial_array);
	secu = duplicate_sec(int_array, len_tmp);
	freememory(after_itoa);
	freememory(initial_array);
	if (secu != 0)
		return (-1);
	return (0);
}
