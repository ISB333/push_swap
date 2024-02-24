/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:29:02 by adesille          #+#    #+#             */
/*   Updated: 2024/02/24 17:09:34 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_printer(t_stack *stack, char c)
{
	printf("-------------------------------------STACK %c-------------------------------------\n", c);
	while (stack)
	{
		printf("Val:    %d\n", stack->value);
		printf("\033[0;32m");
		printf("Pos: %d\n", stack->position);
		stack = stack->next;
		printf("\033[0;37m");
	}
}

int	main(int argc, char *argv[])
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			*array;
	int         i;
	
	stack_a = NULL;
	stack_b = NULL;
	i = 0;
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
		// push_swap(&stack_a, &stack_b);	
		lst_freememory(stack_a, stack_b);
	}
}
