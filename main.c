/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:29:02 by adesille          #+#    #+#             */
/*   Updated: 2024/02/19 12:55:57 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	main(int argc, char *argv[])
{
	// t_stack_a	stack_a;
	// t_stack_b	stack_b;
	int			*array;
    int         i = 0;

	if (argc <= 1)
		return (printf("u're dumb or what !? I need arguments, blyat !"));
	else
	{
        /////////////////////////////////////////// NEED TO CORRECT MEMORY LEAKS ETC ////////////////////////////////////////////////////////////
		array = initializer(argv);
        while (array[i])
            printf("%d\n", array[i++]);
		if (array == 0)
			return (printf("error"), 0);
        free(array);
		// initialize_stacks(array, &stack_a, &stack_b); 
        // lst_freememory(&stack_a, &stack_b);
		/// ALGO ///
		// push_swap(&stack_a, &stack_b);
	}
}
