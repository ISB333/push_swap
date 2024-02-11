/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:59:56 by adesille          #+#    #+#             */
/*   Updated: 2024/02/11 11:19:06 by isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	sorting_algo(t_stack_a *stack_a, t_stack_b *stack_b, int a_pos, int b_top)
// {
// 	t_data	*stack_a_tail;
// 	int		b_pos;
// 	int 	a_top;

// 	stack_a_tail = stack_a->tail;
// 	a_top = ruler(stack_a, stack_b, 'A');
// 	while (stack_a_tail && stack_a_tail->position != a_pos)
// 		stack_a_tail = stack_a_tail->prev;
// 	b_pos = b_pos_finder(stack_a_tail->value, stack_b);
// 	if (a_pos == a_top && b_pos == b_top)
// 		pb(stack_a, stack_b);
// 	else if (a_pos == a_top && b_pos == (b_top - 1))
//     {
//         printf("a_pos = %d\na_top = %d\nb_pos = %d\nb_top = %d\n", a_pos, a_top, b_pos, b_top);
// 		scen_minus1toptop(stack_a, stack_b);
//     }
// 	else if (a_pos == (a_top - 1) && b_pos == (b_top - 1))
// 		scen_minus1toptopminus1(stack_a, stack_b);
// 	else if (a_pos == 1 && b_pos == 1)
// 		scen_bottbott(stack_a, stack_b);
// 	else if (a_pos == 2 && b_pos == 2)
// 		scen_bottplusbottplus(stack_a, stack_b);
// 	else
// 		inside_stacks_sorting(stack_a, stack_b, a_pos, b_pos);
// }

void	sorting_algo(t_stack_a *stack_a, t_stack_b *stack_b, int a_pos, int b_top)
{
	t_data	*stack_a_tail;
	int		b_pos;
	int 	a_top;

	stack_a_tail = stack_a->tail;
	a_top = ruler(stack_a, stack_b, 'A');
	while (stack_a_tail && stack_a_tail->position != a_pos)
		stack_a_tail = stack_a_tail->prev;
	b_pos = b_pos_finder(stack_a_tail->value, stack_b);
	if (a_pos == a_top && b_pos == b_top)
	{
		pb(stack_a, stack_b);
		if (stack_b->tail->value > stack_b->tail->prev->value)
			sb(stack_b);
	}
	else if (a_pos == a_top && b_pos == (b_top - 1))
    {
        // printf("a_pos = %d\na_top = %d\nb_pos = %d\nb_top = %d\n", a_pos, a_top, b_pos, b_top);
		scen_minus1toptop(stack_a, stack_b);
    }
	else if (a_pos == (a_top - 1) && b_pos == (b_top - 1))
		scen_minus1toptopminus1(stack_a, stack_b);
	else if (a_pos == 1 && b_pos == 1)
		scen_bottbott(stack_a, stack_b);
	else if (a_pos == 2 && b_pos == 2)
		scen_bottplusbottplus(stack_a, stack_b);
	else
	{
		// printf("\n============================================================================\n");
		// printer(stack_a, stack_b);
		// printf("============================================================================\n");
		inside_stacks_sorting(stack_a, stack_b, a_pos, b_pos);
	}
}

void    push_swap(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int a_cheapest_pos;

	if (ruler(stack_a, stack_b, 'A') <= 3)
		three_sorter_stack_a(stack_a);
	else if (ruler(stack_a, stack_b, 'A') <= 5)
		five_sorter_stack_a(stack_a, stack_b);
	else
	{
		while(ruler(stack_a, stack_b, 'B') < 3)
			pb(stack_a, stack_b);
		three_sorter_stack_b(stack_b);
		five_sorter_stack_b(stack_a, stack_b);

        //////////////////////////////////////////////////////////////////////////////////
                                /// THE SHIT IS INSIDE THIS ///
        //////////////////////////////////////////////////////////////////////////////////
		while(ruler(stack_a, stack_b, 'A') > 3)
		{
			cost_initializer(stack_a, stack_b);
			a_cheapest_pos = cheapest_pos_finder(stack_a, stack_b);
			sorting_algo(stack_a, stack_b, a_cheapest_pos, ruler(stack_a, stack_b, 'B'));
			// printer(stack_a, stack_b);
		}
        //////////////////////////////////////////////////////////////////////////////////

        cost_initializer(stack_a, stack_b);
		three_sorter_stack_a(stack_a);
        // printf("\n============================================================================\n");
		while(ruler(stack_a, stack_b, 'A') > 0)
		{
			cost_initializer(stack_a, stack_b);
			a_cheapest_pos = cheapest_pos_finder(stack_a, stack_b);
			sorting_algo(stack_a, stack_b, a_cheapest_pos, ruler(stack_a, stack_b, 'B'));
        }
		while(ruler(stack_a, stack_b, 'B') > 0)
            pa(stack_a, stack_b);
		printer(stack_a, stack_b);
	}
}
