/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:29:02 by adesille          #+#    #+#             */
/*   Updated: 2024/03/03 11:14:37 by isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		return (printf("u're dumb or what !? I need arguments, blyat !"));
	else
	{
		array = initializer(argv);
		if (array == 0)
			return (printf("error"), 0);
		initialize_stacks(array, &stack_a);
		push_swap(&stack_a, &stack_b);
		lst_freememory(stack_a, stack_b);
	}
}
