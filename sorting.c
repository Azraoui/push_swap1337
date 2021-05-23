/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <ael-azra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 10:33:08 by ael-azra          #+#    #+#             */
/*   Updated: 2021/05/23 18:22:11 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_sorte(t_stack **stack, int len)
{
	while (!is_sorted(*stack))
	{
		if (len == 2)
			sab(stack, 1, "sa");
		else if ((*stack)->data > (*stack)->next->data && (*stack)->data > (*stack)->next->next->data
		&& (*stack)->next->data < (*stack)->next->next->data)
			rab(stack, 1, "ra");
		else if (((*stack)->data > (*stack)->next->data && (*stack)->data < (*stack)->next->next->data) || 
		((*stack)->data < (*stack)->next->data && (*stack)->data < (*stack)->next->next->data) ||
		((*stack)->data > (*stack)->next->data && (*stack)->data > (*stack)->next->next->data))
			sab(stack, 1, "sa");
		else
			rrab(stack, 1, "rra");
	}
}

void	long_sorte(t_stack **stack_a, int len)
{
	
}

void	five_nbr_sorte(t_stack **stack_a, int len)
{
	t_stack		*stack_b;

	stack_b = NULL;
	
}

void	sorte_stack(t_stack **stack_a)
{
	int		len;

	len = stack_len(*stack_a);
	if (len < 4)
		short_sorte(stack_a, len);
	else if (len < 6)
		five_nbr_sortr(stack_a, len);
	else
		long_sorte(&stack_a, len);
}