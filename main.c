/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:29:02 by adesille          #+#    #+#             */
/*   Updated: 2024/02/29 10:12:10 by adesille         ###   ########.fr       */
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
		printf("Pos: %d\n", stack_b->position);
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
		printf("Pos: %d\n", stack_a->position);
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
			printf("Pos: %d\n", stack_a->position);
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
			printf("Pos: %d\n", stack_b->position);
			stack_b = stack_b->next;
			printf("\033[0;37m");
		}
	}
	printf("===================================================================================\n");
}

int	main(int argc, char *argv[])
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			*array;
	// int         i;
	
	stack_a = NULL;
	stack_b = NULL;
	// i = 0;
	if (argc <= 1)
		return (printf("u're dumb or what !? I need arguments, blyat !"));
	else
	{
		array = initializer(argv);
		if (array == 0)
			return (printf("error"), 0);
		initialize_stacks(array, &stack_a); 
		// free(array);
		/// ALGO ///
		// printer(stack_a, stack_b, 2);
		// pb(&stack_a, &stack_b);
		// pb(&stack_a, &stack_b);
		// pb(&stack_a, &stack_b);
		// pb(&stack_a, &stack_b);
		// printer(stack_a, stack_b, 2);
		// rr(&stack_a, &stack_b);
		// rr(&stack_a, &stack_b);
		// rr(&stack_a, &stack_b);
		// printer(stack_a, stack_b, 2);
		// sa(&stack_a);
		// printer_a(stack_a);
		push_swap(&stack_a, &stack_b);	
		printer(stack_a, stack_b, 2);
		lst_freememory(stack_a, stack_b);
	}
}
