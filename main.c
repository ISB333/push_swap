/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:29:02 by adesille          #+#    #+#             */
/*   Updated: 2024/03/25 14:13:52 by isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	true_sorting_check(t_stack *stack_a)
{
	t_stack	*a_tmp;

	a_tmp = stack_a;
	while (a_tmp->next)
	{
		if (a_tmp->value > a_tmp->next->value)
		{
			printf("\033[0;31m");
			printf("NOT SORTED MUDAFUKA SHGIEHBKGHBADGKHBEGLKJ!@!##$#@$^$@$^@#!^^$@$TYWQHYNG$VTTRH\n");
			printf("\033[0;37m");
			return (-1);
		}
		a_tmp = a_tmp->next;
	}
	printf("\033[0;34m");
	printf("-------------------------SORTING OK BROoOoOooOOoOOoO!-----------------------------\n");
	printf("\033[0;37m");
	return (0);
}

int	sorting_checker(t_stack *stack_a)
{
	t_stack	*a_tmp;

	a_tmp = stack_a;
	while (a_tmp->next)
	{
		if (a_tmp->value > a_tmp->next->value)
			return (-1);
		a_tmp = a_tmp->next;
	}
	return (0);
}

void	printer_b(t_stack *stack_b)
{
	printf("------------------------------------- STACK b -------------------------------------\n");
	while (stack_b)
	{
		printf("Val:    %d\n", stack_b->value);
		printf("\033[0;32m");
		printf("Pos: %ld\n", stack_b->position);
		printf("\033[0;37m");
		stack_b = stack_b->next;
	}
	printf("===================================================================================\n");
}

void	printer_a(t_stack *stack_a)
{
	printf("------------------------------------- STACK A -------------------------------------\n");
	while (stack_a)
	{
		printf("Val:    %d\n", stack_a->value);
		printf("\033[0;32m");
		printf("Pos: %ld\n", stack_a->position);
		printf("\033[0;37m");
		stack_a = stack_a->next;
	}
	printf("===================================================================================\n");
}

void	printer(t_stack *stack_a, t_stack *stack_b, int c)
{
	if (c == 0 || c == 2)
	{
		printf("------------------------------------- STACK A -------------------------------------\n");
		while (stack_a)
		{
			printf("Val:    %d\n", stack_a->value);
			printf("\033[0;32m");
			printf("Pos: %ld\n", stack_a->position);
			printf("\033[0;37m");
			stack_a = stack_a->next;
		}
	}
	if (c == 1 || c == 2)
	{
		printf("------------------------------------- STACK B -------------------------------------\n");
		while (stack_b)
		{
			printf("Val:    %d\n", stack_b->value);
			printf("\033[0;32m");
			printf("Pos: %ld\n", stack_b->position);
			stack_b = stack_b->next;
			printf("\033[0;37m");
		}
	}
	printf("===================================================================================\n");
}


////////////// TEST WITH COST_INIT CONDITION /////////////////
///////////// +++ Overflow_protect NOT Working ///////////////


int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*array;
	char	*str;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (0);
	else
	{
		array = initializer(argv);
		if (array == (int *)-1)
			return (ft_putstr("Error\n"), 0);
		str = argv_join_all(argv);
		initialize_stacks(array, &stack_a, ft_count_words(str, ' '));
		if (!sorting_checker(stack_a))
			return (lst_freememory(stack_a, stack_b), 0);
		else
			push_swap(&stack_a, &stack_b);
		true_sorting_check(stack_a);
		// printer(stack_a, stack_b, 2);
		return(free(str), lst_freememory(stack_a, stack_b), 0);
	}
}
