/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schanqou <schanqou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 09:02:11 by schanqou          #+#    #+#             */
/*   Updated: 2026/01/12 09:06:18 by schanqou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
// Helper to rotate both stacks if needed
static void	rotate_both(t_stack_node **a,
						t_stack_node **b,
						t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void	rev_rotate_both(t_stack_node **a,
							t_stack_node **b,
							t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = *a;
	while (cheapest_node && !cheapest_node->cheapest)
	{
		cheapest_node = cheapest_node->next;
	}
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	while (*a != cheapest_node)
	{
		if (cheapest_node->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
	while (*b != cheapest_node->target_node)
	{
		if (cheapest_node->target_node->above_median)
			rb(b, false);
		else
			rrb(b, false);
	}
	pb(b, a, false);
}

// Initializing nodes for B to A return
void init_nodes_b(t_stack_node *a, t_stack_node *b)
{
    current_index(a);
    current_index(b);
    
    // Set target for B (Find closest BIGGER number in A)
    t_stack_node *current_a;
    t_stack_node *target_node;
    long best_match_index;

    while (b)
    {
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
            b->target_node = find_min(a); // Defined in stack_utils
        else
            b->target_node = target_node;
        b = b->next;
    }
}

// Move B back to A
static void move_b_to_a(t_stack_node **a, t_stack_node **b)
{
    while (*a != (*b)->target_node)
    {
        if ((*b)->target_node->above_median)
            ra(a, false);
        else
            rra(a, false);
    }
    pa(a, b, false);
}

static void min_on_top(t_stack_node **a)
{
    t_stack_node *min_node;

    min_node = find_min(*a); // Defined in stack_utils
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
