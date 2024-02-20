/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:29:02 by adesille          #+#    #+#             */
/*   Updated: 2024/02/20 15:17:22 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	main(int argc, char *argv[])
{
	t_stack_a	stack_a;
	t_stack_b	stack_b;
	int			*array;
	int         i;
	
	i = 0;
	if (argc <= 1)
		return (printf("u're dumb or what !? I need arguments, blyat !"));
	else
	{
		array = initializer(argv);
		if (array == 0)
			return (printf("error"), 0);
		while(array[i])
			i++;
		initialize_stacks(array, &stack_a, &stack_b); 
		/// ALGO ///
		push_swap(&stack_a, &stack_b);
		lst_freememory(&stack_a, &stack_b);
	}
}
