/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:54:15 by adesille          #+#    #+#             */
/*   Updated: 2024/03/01 09:30:30 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	freememory(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
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

int	overflow_protector(int *int_array, char *argv[], int len)
{
	char	**after_itoa;
	char	**initial_array;
	size_t	k;
	int		secu;

	secu = 0;
	k = -1;
	after_itoa = (char **)malloc((len + 1) * sizeof(char *));
	if (!after_itoa)
		return (0);
	while (int_array[++k])
		after_itoa[k] = ft_itoa(int_array[k]);
	after_itoa[k] = NULL;
	initial_array = argv_init(argv);
	secu = overflow_checker(after_itoa, initial_array);
	freememory(after_itoa);
	freememory(initial_array);
	if (secu != 0)
		return (-1);
	return (0);
}

// void	ptr_check(t_stack_a *stack_a, t_stack_b *stack_b)
// {
// 	t_data	*stack_a_head;
// 	t_data	*stack_b_head;

//     printf("\n================================= PTR_CHECK =================================\n");
//     stack_a_head = stack_a->head;
// 	if (stack_a_head->position == 1)
// 		printf("\nStack_a Head OK!");
// 	else
// 		printf("\nStack_b Head ERROR!!!");
// 	while (stack_a_head->next)
//     {
// 		stack_a_head = stack_a_head->next;
//     }
// 	if (stack_a->tail->value == stack_a_head->value)
// 		printf("\nStack_a Tail OK\n");
// 	else
// 		printf("\nTail ERROR!!!");
//     if(stack_b->head)
//     {
//         stack_b_head = stack_b->head;
//         if (stack_b_head->position == 1)
//             printf("\nStack_b Head OK!");
//         else
//             printf("\nStack_b Head ERROR!!!\n");
//         while (stack_b_head->next)
//             stack_b_head = stack_b_head->next;
//         if (stack_b->tail->value == stack_b_head->value)
//             printf("\nStack_b Tail OK");
//         else
//             printf("\nStack_b Tail ERROR!!!");
//     }
//     printf("\n================================= PTR_CHECK =================================\n");
// }

// void    ope_check(t_stack_a *stack_a, t_stack_b *stack_b)
// {
// 	int i = 6;
// 	while (i-- > 0)
// 		pb(stack_a, stack_b);
// 	printf("================ pb ================\n");
// 	// ptr_check(stack_a, stack_b);
// 	printer(stack_a, stack_b);

// 	///////////////	ROTATE DOWN ///////////////	
// 	i = 3;
// 	while (i-- > 0)
// 		rr(stack_a, stack_b);
// 	printf("================ rr ================\n");
// 	// ptr_check(stack_a, stack_b);
// 	printer(stack_a, stack_b);

// 	///////////////	ROTATE UP ///////////////	
// 	i = 3;
// 	while (i-- > 0)
// 		rrr(stack_a, stack_b);
// 	printf("================ rrr ================\n");
// 	// ptr_check(stack_a, stack_b);
// 	printer(stack_a, stack_b);
// 	///////////////	SWAP ///////////////	
// 	i = 3;
// 	ss(stack_a, stack_b);
// 	printf("================ ss ================\n");
// 	printer(stack_a, stack_b);
// 	ptr_check(stack_a, stack_b);

// }