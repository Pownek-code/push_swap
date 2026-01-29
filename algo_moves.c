/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schanqou <schanqou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:30:21 by gemini            #+#    #+#             */
/*   Updated: 2026/01/29 08:14:11 by schanqou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	rotate_both(t_stack_node **a,
						t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

static void	rev_rotate_both(t_stack_node **a,
							t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}

static void	finish_rotations(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node)
{
	while (*a != cheapest_node)
	{
		if (cheapest_node->above_median)
			ra(a);
		else
			rra(a);
	}
	while (*b != cheapest_node->target_node)
	{
		if (cheapest_node->target_node->above_median)
			rb(b);
		else
			rrb(b);
	}
}

void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = *a;
	while (cheapest_node && !cheapest_node->cheapest)
		cheapest_node = cheapest_node->next;
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	finish_rotations(a, b, cheapest_node);
	pb(b, a);
}

void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	while (*a != (*b)->target_node)
	{
		if ((*b)->target_node->above_median)
			ra(a);
		else
			rra(a);
	}
	pa(a, b);
}
