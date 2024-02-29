/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:30:24 by isb3              #+#    #+#             */
/*   Updated: 2024/02/29 11:06:10 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////          SHIT IS HERE MODAFUCKA         /////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static void	push(t_stack **dst, t_stack **src) //Define a function that pushes a top node, from one stack to another's top node
{
	t_stack	*push_node; //Used to store the pointer to the node to be pushed

	if (!*src) //The top node of a stack to be pushed
		return ;
	push_node = *src; //The top node to push is assigned to the `t_stack_node` variable
	*src = (*src)->next; //Move the pointer of the stack to the next node, which will become the next `top node` after the node before is "popped off"
	if (*src) //Check if the current node exists
		(*src)->prev = NULL; //Set the current node as the head of the stack
	push_node->prev = NULL; //Detach the node to push from its stack
	if (!*dst) //Check if the other stack is empty
	{
		*dst = push_node; //If it's empty, assign as the first node of that stack, the node we want pushed
		push_node->next = NULL; //Ensure it is also set as the last node, e.g. properly null terminate the stack
	}
	else //If the other stack we want to push to is not empty
	{
		push_node->next = *dst; //Assign the node to push, to the top of the current top node of the stack
		push_node->next->prev = push_node; //Assign to the "second node" `prev` attribute, the pushed node as the current top node
		*dst = push_node; //Complete appending the node. The pointer to the top node of the stack is now pointing to our recently pushed node
	}
}

void	pa(t_stack **a, t_stack **b) //Push on top of `b`, the top `a` and print the instruction
{
	push(a, b); 
	printf("pa\n");
}

void	pb(t_stack **b, t_stack **a) //Push on top of `a`, the top `b` and print the instruction
{
	push(b, a);
	printf("pb\n");
}

// void	pb(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_stack	*new_node;

// 	if (!*stack_a)
// 		return ;
// 	new_node = malloc(sizeof(t_stack));
// 	if (!new_node)
// 		return ;
// 	new_node->value = (*stack_a)->value;
// 	if (!*stack_b)
// 	{
// 		new_node->prev = NULL;
// 		new_node->next = NULL;
// 		new_node->position = 1;
// 	}
// 	else
// 	{
// 		new_node->next = (*stack_b);
// 		(*stack_b)->prev = new_node;
// 		new_node->position = (*stack_b)->position + 1;
// 	}
// 	if (!(*stack_a)->next)
// 	{
// 		free(*stack_a);
// 		*stack_a = NULL;
// 	}
// 	else
// 	{
// 		*stack_a = (*stack_a)->next;
// 		free((*stack_a)->prev);
// 		(*stack_a)->prev = NULL;
// 	}
// 	*stack_b = new_node;
// 	// *stack_b = new_node;
// 	// *stack_a = (*stack_a)->next;
// 	// free((*stack_a)->prev);
// 	printf("pa\n");
// }

// void	pa(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_stack	*new_node;

// 	if (!*stack_b)
// 		return ;
// 	new_node = malloc(sizeof(t_stack));
// 	if (!new_node)
// 		return ;
// 	new_node->value = (*stack_b)->value;
// 	if (!*stack_a)
// 	{
// 		new_node->prev = NULL;
// 		new_node->next = NULL;
// 		new_node->position = 1;
// 	}
// 	else
// 	{
// 		new_node->next = (*stack_a);
// 		(*stack_a)->prev = new_node;
// 		new_node->position = (*stack_a)->position + 1;
// 	}
// 	if (!(*stack_b)->next)
// 	{
// 		free(*stack_b);
// 		*stack_b = NULL;
// 	}
// 	else
// 	{
// 		*stack_b = (*stack_b)->next;
// 		free((*stack_b)->prev);
// 		(*stack_b)->prev = NULL;
// 	}
// 	*stack_a = new_node;
// 	printf("pb\n");
// }
