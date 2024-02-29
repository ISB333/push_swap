/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:30:34 by isb3              #+#    #+#             */
/*   Updated: 2024/02/29 11:10:16 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	rev_rotate(t_stack **stack) //Define a funtion that rotates a stack's bottom node, to the top
{
	t_stack	*last; //To store the pointer to the last node

	if (!*stack || !(*stack)->next) //Check if the stack is empty, or if there's one node
		return ;
	last = *return_tail(stack);
	last->prev->next = NULL; //Assign to the `next` attribute of the node before itself, `NULL` effectively setting it as the current last node
	last->next = *stack; //Assign to its own `next` attribute as the top node of the stack
	last->prev = NULL; //Detach itself from the node before it
	*stack = last;  //Complete appending itself to the top of the stack, and now holds the pointer to the top node
	last->next->prev = last; //Update the current last node of the stack
}

void	rra(t_stack **a) //Rotate the bottom of `a` to the top of the stack and print the instruction
{
	rev_rotate(a);
	printf("rra\n");
}

void	rrb(t_stack **b) //Rotate the bottom of `b` to the top of the stack and print the instruction
{
	rev_rotate(b);
	printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b) //Stimultaneously rotate both stacks' bottom nodes to the top of their stacks, halving the cost of instructions
{
	rev_rotate(a);
	rev_rotate(b);
	printf("rrr\n");
}

// void	do_rra(t_stack **stack)
// {
// 	t_stack	*last;

// 	if (!stack || !*stack || !(*stack)->next)
// 		return ;
// 	last = *stack;
// 	while (last->next)
// 		last = last->next;
// 	last->next = *stack;
// 	(*stack)->prev = last;
// 	*stack = last;
// 	last = (*stack)->prev;
// 	(*stack)->prev = NULL;
// 	last->next = NULL;
// 	last->position = 1;
// 	while (last)
// 	{
// 		last = last->prev;
// 		if (last)
// 			last->position = last->next->position + 1;
// 	}
// }

// void	do_rrb(t_stack **stack)
// {
// 	t_stack	*last;

// 	if (!stack || !*stack || !(*stack)->next)
// 		return ;
// 	last = *stack;
// 	while (last->next)
// 		last = last->next;
// 	last->next = *stack;
// 	(*stack)->prev = last;
// 	*stack = last;
// 	last = (*stack)->prev;
// 	(*stack)->prev = NULL;
// 	last->next = NULL;
// 	last->position = 1;
// 	while (last)
// 	{
// 		last = last->prev;
// 		if (last)
// 			last->position = last->next->position + 1;
// 	}
// }

// void	rrr(t_stack **stack_a, t_stack **stack_b)
// {
// 	do_rra(stack_a);
// 	do_rrb(stack_b);
// 	printf("rra\n");
// 	printf("rrb\n");
// 	printf("rrr\n");
// }

// void	rra(t_stack **stack_a)
// {
// 	do_rra(stack_a);
// 	printf("rra\n");
// }

// void	rrb(t_stack **stack_b)
// {
// 	do_rrb(stack_b);
// 	printf("rrb\n");
// }
