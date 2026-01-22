/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schanqou <schanqou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 09:02:11 by schanqou          #+#    #+#             */
/*   Updated: 2026/01/21 17:32:51 by gemini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_index;

	best_match_index = LONG_MAX;
	current_a = a;
	while (current_a)
	{
		if (current_a->value > b->value
			&& current_a->value < best_match_index)
		{
			best_match_index = current_a->value;
			target_node = current_a;
		}
		current_a = current_a->next;
	}
	if (best_match_index == LONG_MAX)
		b->target_node = find_min(a);
	else
		b->target_node = target_node;
}

void	init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	while (b)
	{
		set_target_b(a, b);
		b = b->next;
	}
}

static void	min_on_top(t_stack_node **a)
{
	t_stack_node	*min_node;

	min_node = find_min(*a);
	while ((*a)->value != min_node->value)
	{
		if (min_node->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	tiny_sort(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
