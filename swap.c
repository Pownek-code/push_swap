/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schanqou <schanqou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 08:54:46 by schanqou          #+#    #+#             */
/*   Updated: 2026/01/12 08:54:50 by schanqou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	swap(t_stack_node **head)
{
	// Check if stack has at least 2 nodes
	if (!*head || !(*head)->next)
		return ;
	
	// Pointers to the two nodes
	t_stack_node *first = *head;
	t_stack_node *second = first->next;

	// Update first node
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	first->prev = second;

	// Update second node
	second->next = first;
	second->prev = NULL;

	// Update head
	*head = second;
}

void	sa(t_stack_node **a, bool print)
{
	swap(a);
	if (!print)
		write(1, "sa\n", 3);
}

void	sb(t_stack_node **b, bool print)
{
	swap(b);
	if (!print)
		write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		write(1, "ss\n", 3);
}
