/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schanqou <schanqou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 08:43:08 by schanqou          #+#    #+#             */
/*   Updated: 2026/01/12 09:11:00 by schanqou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

// The "Smart Node" - Circular Doubly Linked
typedef struct s_stack_node
{
	int					value;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

// Handle Errors
void			free_stack(t_stack_node **stack);
void			free_argv(char **argv);
void			free_errors(t_stack_node **a);
int				error_duplicate(t_stack_node *a, int n);
int				error_syntax(char *str_n);

// Stack Creation
void			init_stack_a(t_stack_node **a, char **argv);

// Node Utils
t_stack_node	*find_last(t_stack_node *head);
int				stack_len(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);

// Operations
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);

// Algorithm
void			sort_stacks(t_stack_node **a, t_stack_node **b);
// Algorithm Utils
void			tiny_sort(t_stack_node **a);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			current_index(t_stack_node *stack);
void			move_a_to_b(t_stack_node **a, t_stack_node **b);
void			move_b_to_a(t_stack_node **a, t_stack_node **b);
void			set_cheapest(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);

//
char			**split(char *s, char c);

// Libft Utils
size_t			ft_strlen(const char *s);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strjoin(char *s1, char *s2);
#endif
