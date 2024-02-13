/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: checkin <checkin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:29:02 by adesille          #+#    #+#             */
/*   Updated: 2024/02/13 12:52:05 by checkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	main(int argc, char *argv[])
{
	t_stack_a	stack_a;
	t_stack_b	stack_b;
	int			*array;

	if (argc <= 1)
		return (printf("u're dumb or what !? I need arguments, blyat !"));
	else
	{
		array = initializer(argv);
		if (array == 0)
			return (printf("error"), 0);
		initialize_stacks(array, &stack_a, &stack_b); 
		// ptr_check(&stack_a, &stack_b);
		// ope_check(&stack_a, &stack_b);

		// printf("AAAAAAAAAAAAAAAAAAAAAA");
		/// ALGO ///
		push_swap(&stack_a, &stack_b);
	}
}
