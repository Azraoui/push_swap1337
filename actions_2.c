/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <ael-azra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 10:14:53 by ael-azra          #+#    #+#             */
/*   Updated: 2021/05/23 14:59:11 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     rr(t_stack **stack_a, t_stack **stack_b, int true, char *str)
{
    rab(stack_a, 0, str);
    rab(stack_b, 0, str);
	if (true)
    {
        ft_putstr_fd(str, 1);
        write(1, "\n", 1);
    }
    return (0);
}

int     rrab(t_stack **stack, int true, char *str)
{
	t_stack		*tmp;
	int			swap;

	tmp = NULL;
	if (is_empty(*stack))
		return (0);
	while (!is_empty(*stack))
	{
		swap = pop(stack);
		if (!is_empty(*stack))
			push(&tmp, swap);
	}
    while (!is_empty(tmp))
        push(stack, pop(&tmp));
	push(stack, swap);
	if (true)
    {
        ft_putstr_fd(str, 1);
        write(1, "\n", 1);
    }
    return (0);
}

int		rrr(t_stack **stack_a, t_stack **stack_b, int true, char *str)
{
	rrab(stack_a, 0, str);
	rrab(stack_b, 0, str);
	if (true)
    {
        ft_putstr_fd(str, 1);
        write(1, "\n", 1);
    }
	return (0);
}