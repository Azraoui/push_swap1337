/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <ael-azra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:59:47 by ael-azra          #+#    #+#             */
/*   Updated: 2021/05/26 18:54:53 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_swap(int *a, int *b)
{
    int     swap;

    swap = *a;
    *a = *b;
    *b = swap;
}

int     stack_len(t_stack *stack)
{
	t_stack     *tmp;
	int         i;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int     *convert_stack_to_array(t_stack *stack, int len)
{
	int			*arr;
	int			i;

	arr = (int*)malloc(sizeof(int) * len);
	i = 0;
	while (i < len && stack)
	{
		arr[i] = stack->data;
		i++;
		stack = stack->next;
	}
	return (arr);
}

int     ft_error(int mod, t_stack **stack_a, t_stack **stack_b)
{
    write(1, "Error\n", 6);
	if (mod)
	{
		if (*stack_a)
			free_stack(stack_a);
		if (*stack_b)
			free_stack(stack_b);
	}
    return (0);
}

int		is_sorted(t_stack *stack)
{
	int		min;

	min = INT_MIN;
	while (!is_empty(stack))
	{
		if (min > stack->data)
			return (0);
		min = stack->data;
		stack = stack->next;
	}
	return (1);
}