/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schanqou <schanqou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 08:44:29 by schanqou          #+#    #+#             */
/*   Updated: 2026/01/12 09:11:42 by schanqou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static char	**parse_arguments(int argc, char **argv)
{
	char	*full_arg_str;
	char	**split_args;
	int		i;
	char	*temp;

	full_arg_str = NULL;
	i = 1;
	while (i < argc)
	{
		temp = full_arg_str;
		full_arg_str = ft_strjoin(temp, argv[i]);
		if (temp)
			free(temp);
		if (!full_arg_str)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	split_args = split(full_arg_str, ' ');
	free(full_arg_str);
	return (split_args);
}

static void	perform_sort(t_stack_node **a, t_stack_node **b)
{
	if (!stack_sorted(*a))
	{
		if (stack_len(*a) == 2)
			sa(a);
		else if (stack_len(*a) == 3)
			tiny_sort(a);
		else
			sort_stacks(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**split_args;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	split_args = parse_arguments(argc, argv);
	if (init_stack_a(&a, split_args + 1))
	{
		free_argv(split_args);
		free_stack(&a);
		write(2, "Error\n", 6);
		return (1);
	}
	free_argv(split_args);
	perform_sort(&a, &b);
	free_stack(&a);
	return (0);
}
