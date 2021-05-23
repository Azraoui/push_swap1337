/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <ael-azra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 08:29:17 by ael-azra          #+#    #+#             */
/*   Updated: 2021/05/23 15:51:53 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     sab(t_stack **stack, int true, char *str)
{
    if (!is_empty(*stack) && !is_empty((*stack)->next))
        ft_swap(&(*stack)->data, &(*stack)->next->data);
    if (true)
    {
        ft_putstr_fd(str, 1);
        write(1, "\n", 1);
    }
    return (0);
}

int     ss(t_stack **stack_a, t_stack **stack_b, int true, char *str)
{
    sab(stack_a, 0, str);
    sab(stack_b, 0, str);
    if (true)
    {
        ft_putstr_fd(str, 1);
        write(1, "\n", 1);
    }
    return (0);
}

int     pab(t_stack **stack_a, t_stack **stack_b, int true, char *str)
{
    if (is_empty(*stack_b))
        return (0);
    push(stack_a, pop(stack_b));
    if (true)
    {
        ft_putstr_fd(str, 1);
        write(1, "\n", 1);
    }
    return (0);
}

int     rab(t_stack **stack, int true, char *str)
{
    t_stack     *tmp;
    int         swap;

    if (is_empty(*stack))
        return (0);
    swap = pop(stack);
    tmp = NULL;
    while (!is_empty(*stack))
        push(&tmp, pop(stack));
    push(stack, swap);
    while (!is_empty(tmp))
    {
        push(stack, tmp->data);
        tmp = tmp->next;
    }
    if (true)
    {
        ft_putstr_fd(str, 1);
        write(1, "\n", 1);
    }
    return (0);
}