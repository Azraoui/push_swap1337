/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <ael-azra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:07:55 by ael-azra          #+#    #+#             */
/*   Updated: 2021/05/23 15:40:00 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		do_action(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (!(ft_strcmp(str, "sa")))
		return (sab(stack_a, 0, str));
	else if (!(ft_strcmp(str, "sb")))
		return (sab(stack_b, 0, str));
	else if (!(ft_strcmp(str, "ss")))
		return (ss(stack_a, stack_b, 0, str));
	else if (!(ft_strcmp(str, "pa")))
		return (pab(stack_a, stack_b, 0, str));
	else if (!(ft_strcmp(str, "pb")))
		return (pab(stack_b, stack_a, 0, str));
	else if (!(ft_strcmp(str, "ra")))
		return (rab(stack_a, 0, str));
	else if (!(ft_strcmp(str, "rb")))
		return (rab(stack_b, 0, str));
	else if (!(ft_strcmp(str, "rr")))
		return (rr(stack_a, stack_b, 0, str));
	else if (!(ft_strcmp(str, "rra")))
		return (rrab(stack_a, 0, str));
	else if (!(ft_strcmp(str, "rrb")))
		return (rrab(stack_b, 0, str));
	else if (!(ft_strcmp(str, "rrr")))
		return (rrr(stack_a, stack_b, 0, str));
	else
		return (1);
}

void	is_it_sorted(t_stack *stack_a, t_stack *stack_b)
{
	if (!is_empty(stack_b))
		return ;
	if (is_sorted(stack_a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int     main(int ac, char **av)
{
    t_stack     *stack_a;
    t_stack     *stack_b;
    char        *str;

    if (ac > 1)
    {
        stack_a = fill_stack(ac, av);
        if (!stack_a)
            return (ft_error(0, NULL, NULL));
        stack_b = NULL;
        while (gnl(0, &str))
        {
            if (do_action(&stack_a, &stack_b, str))
            {
                free(str);
                return (ft_error(1, &stack_a, &stack_b));
            }
			free(str);
        }
		is_it_sorted(stack_a, stack_b);
    }
    return (0);
}