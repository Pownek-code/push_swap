/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schanqou <schanqou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 08:53:35 by schanqou          #+#    #+#             */
/*   Updated: 2026/01/12 09:03:16 by schanqou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	stack_len(t_stack_node *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		len2 = ft_strlen(s2);
		new_str = (char *)malloc(sizeof(char) * (len2 + 1));
		if (!new_str)
			return (NULL);
		ft_strcpy(new_str, s2);
		return (new_str);
	}
	if (!s2)
	{
		len1 = ft_strlen(s1);
		new_str = (char *)malloc(sizeof(char) * (len1 + 1));
		if (!new_str)
			return (NULL);
		ft_strcpy(new_str, s1);
		return (new_str);
	}

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * (len1 + len2 + 2)); // +1 for space, +1 for null terminator
	if (!new_str)
		return (NULL);
	ft_strcpy(new_str, s1);
	new_str[len1] = ' ';
	ft_strcpy(new_str + len1 + 1, s2);
	return (new_str);
}