/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <ael-azra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:21:30 by ael-azra          #+#    #+#             */
/*   Updated: 2021/05/23 18:20:36 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     main(int ac, char **av)
{
    t_stack     *stack_a;

    if (ac > 1)
    {
        stack_a = fill_stack(ac, av);
        if (!stack_a)
            return (ft_error(0, NULL, NULL));
        sorte_stack(&stack_a);
        free_stack(&stack_a);
    }
    return (0);
}