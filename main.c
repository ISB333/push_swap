/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:29:02 by adesille          #+#    #+#             */
/*   Updated: 2024/03/05 14:51:04 by isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*array;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (0);
	else
	{
		array = initializer(argv);
		if (array == 0)
			return (ft_putstr("Error\n"), 0);
		initialize_stacks(array, &stack_a);
		push_swap(&stack_a, &stack_b);
		lst_freememory(stack_a, stack_b);
	}
}
