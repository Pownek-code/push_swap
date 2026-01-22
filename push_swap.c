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

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*full_arg_str;
	char			**split_args;
	int			i;

	a = NULL;
	b = NULL;
	full_arg_str = NULL;
	split_args = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	i = 1;
	while (i < argc)
	{
		char *temp = full_arg_str;
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
	init_stack_a(&a, split_args + 1);
	free_argv(split_args);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			tiny_sort(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}
