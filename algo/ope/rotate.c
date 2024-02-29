/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:30:34 by isb3              #+#    #+#             */
/*   Updated: 2024/02/29 11:10:02 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	rotate(t_stack **stack) //Define a function that rotates the stack's top node to the bottom of the stack
{
	t_stack	*last_node; //To store a pointer to the last node of a stack

	if (!*stack || !(*stack)->next) //Check if the stack is empty, or if there's one node
		return ;
	last_node = *return_tail(stack); 
	last_node->next = *stack; //Assign to the last node, its `next` attribute as the top node, effectively setting the current top node as the last node
	*stack = (*stack)->next; //Assign to the pointer of the top node, the node after it (second from the top)
	(*stack)->prev = NULL; //Complete setting the current top node by detaching it from its previous top node
	last_node->next->prev = last_node; //Reconnect the second node's prev pointer to point to what was previously the last node in the stack
	last_node->next->next = NULL; //Assign to the `next` attribute of the current last node, `NULL` effectively setting it as the current last node, and properly null terminating the stack
}		

void	ra(t_stack **a) //Rotate the top `a` node to the bottom of the stack, and print the instruction
{
	rotate(a);
	printf("ra\n");
}

void	rb(t_stack **b) //Rotate the top `b` node to the bottom of the stack, and print the instruction
{
	rotate(b);
	printf("rb\n");
}

void	rr(t_stack **a, t_stack **b) //Stimultaneously rotate both the top `a` and `b` nodes to the bottom of the stack, and print the instruction
{
	rotate(a);
	rotate(b);
	printf("rr\n");
}

// void	do_ra(t_stack **stack)
// {
// 	t_stack	*last;
// 	int		pos;

// 	last = *stack;
// 	while (last->next)
// 		last = last->next;
// 	last->next = *stack;
// 	(*stack)->prev = last;
// 	last = *stack;
// 	*stack = (*stack)->next;
// 	(*stack)->prev = NULL;
// 	last->next = NULL;
// 	pos = 1;
// 	while (last)
// 	{
// 		if (last->position)
// 			last->position = pos++;
// 		last = last->prev;
// 	}
// }

// void	do_rb(t_stack **stack)
// {
// 	t_stack	*last;
// 	int		pos;

// 	last = *stack;
// 	while (last->next)
// 		last = last->next;
// 	last->next = *stack;
// 	(*stack)->prev = last;
// 	last = *stack;
// 	*stack = (*stack)->next;
// 	(*stack)->prev = NULL;
// 	last->next = NULL;
// 	pos = 1;
// 	while (last)
// 	{
// 		if (last->position)
// 			last->position = pos++;
// 		last = last->prev;
// 	}
// }

// void	rr(t_stack **stack_a, t_stack **stack_b)
// {
// 	do_ra(stack_a);
// 	do_rb(stack_b);
// 	printf("rr\n");
// }

// void	ra(t_stack **stack_a)
// {
// 	do_ra(stack_a);
// 	printf("ra\n");
// }

// void	rb(t_stack **stack_b)
// {
// 	do_rb(stack_b);
// 	printf("rb\n");
// }
