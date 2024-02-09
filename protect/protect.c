/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:54:15 by adesille          #+#    #+#             */
/*   Updated: 2024/02/09 13:06:08 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	overflow_protector(int *int_array, char *argv[])
{
	char	**after_itoa;
	char	**initial_array;
	int		i;
	int		k;
	int		secu;

	i = 0;
	k = 0;
	while (int_array[i])
		i++;
	after_itoa = malloc(i * sizeof(char *));
	if (!after_itoa)
		return (0);
	while (i-- > 0)
	{
		after_itoa[k] = ft_itoa(int_array[k]);
		k++;
	}
	after_itoa[k] = NULL;
	initial_array = argv_init(argv);
	secu = overflow_checker(after_itoa, initial_array);
	if (secu != 0)
		return (-1);
	return (0);
}

char	**argv_init(char *argv[])
{
	char	*str;
	int		i;

	i = 1;
	str = NULL;
	while (argv[i])
		str = argv_join(str, argv[i++]);
	return (ft_split(str, ' '));
}

void	ptr_check(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_data	*stack_a_head;
	t_data	*stack_b_head;

    printf("\n================================= PTR_CHECK =================================\n");
    stack_a_head = stack_a->head;
	if (stack_a_head->position == 1)
		printf("\nStack_a Head OK!");
	else
		printf("\nStack_b Head ERROR!!!");
	while (stack_a_head->next)
    {
		stack_a_head = stack_a_head->next;
    }
	if (stack_a->tail->value == stack_a_head->value)
		printf("\nStack_a Tail OK\n");
	else
		printf("\nTail ERROR!!!");
    if(stack_b->head)
    {
        stack_b_head = stack_b->head;
        if (stack_b_head->position == 1)
            printf("\nStack_b Head OK!");
        else
            printf("\nStack_b Head ERROR!!!\n");
        while (stack_b_head->next)
            stack_b_head = stack_b_head->next;
        if (stack_b->tail->value == stack_b_head->value)
            printf("\nStack_b Tail OK");
        else
            printf("\nStack_b Tail ERROR!!!");
    }
    printf("\n================================= PTR_CHECK =================================\n");
}

void    ope_check(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int i = 6;
	while (i-- > 0)
		pb(stack_a, stack_b);
	printf("================ pb ================\n");
	// ptr_check(stack_a, stack_b);
	printer(stack_a, stack_b);

	///////////////	ROTATE DOWN ///////////////	
	i = 3;
	while (i-- > 0)
		rr(stack_a, stack_b);
	printf("================ rr ================\n");
	// ptr_check(stack_a, stack_b);
	printer(stack_a, stack_b);

	///////////////	ROTATE UP ///////////////	
	i = 3;
	while (i-- > 0)
		rrr(stack_a, stack_b);
	printf("================ rrr ================\n");
	// ptr_check(stack_a, stack_b);
	printer(stack_a, stack_b);
	///////////////	SWAP ///////////////	
	i = 3;
	ss(stack_a, stack_b);
	printf("================ ss ================\n");
	printer(stack_a, stack_b);
	ptr_check(stack_a, stack_b);

}