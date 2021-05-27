/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <ael-azra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:19:08 by ael-azra          #+#    #+#             */
/*   Updated: 2021/05/26 19:01:18 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	while (!is_empty(stack))
	{
		printf("%d, ", stack->data);
		stack = stack->next;
	}
	printf("\n");
}

void	five_nbr_logic(t_stack **stack_a, t_stack **stack_b)
{
	int			len;

	// print_stack(*stack_a);
	if (!is_sorted(*stack_a))
		// printf("\n----------partie 1 -----------\n");
	while (!is_sorted(*stack_a))
	{
		if ((*stack_a)->data < (*stack_a)->next->data)
			pab(stack_b, stack_a, 1, "pb");
		len = stack_len(*stack_b);
		if ((*stack_a)->data > (*stack_a)->next->data && len > 1
		&& (*stack_b)->data < (*stack_b)->next->data)
			ss(stack_a, stack_b, 1, "ss");
		else if ((*stack_a)->data > (*stack_a)->next->data)
			sab(stack_a, 1, "sa");
		else if (len > 1 && (*stack_b)->data < (*stack_b)->next->data)
			sab(stack_b, 1, "sb");
	}
	// printf("\n----------partie 2 -----------\n");
	while (is_sorted(*stack_a) && !is_empty(*stack_b))
	{
		len = stack_len(*stack_b);
		if (len > 1 && (*stack_b)->data < (*stack_b)->next->data)
			sab(stack_b, 1, "sb");
		pab(stack_a, stack_b, 1, "pa");
	}
}

void	test(t_stack **stack_a, t_stack **stack_b)
{
	if (!is_sorted(*stack_a))
	{
		five_nbr_logic(stack_a, stack_b);
		test(stack_a, stack_b);
		// test(stack_a, stack_b);
	}
}

// int		main()
// {
// 	t_stack *stack_a;
// 	t_stack *stack_b;
// 	char *s;
// 	char **str;

// 	stack_b = NULL;
// 	s = ft_strdup("0 40 71 27 49 36 94 28 24 88 100 78 11 62 67 50 9 31 70 95 6");
// 	str = ft_split(s, ' ');
// 	// int i = 0;
// 	// while(str[i])
// 	// 	printf("%s\n", str[i++]);
// 	// stack_a = NULL;
// 	stack_a = fill_stack(21, str);
// 	test(&stack_a, &stack_b);
// 	return (0);
// }