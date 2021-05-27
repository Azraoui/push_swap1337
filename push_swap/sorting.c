/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <ael-azra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 10:33:08 by ael-azra          #+#    #+#             */
/*   Updated: 2021/05/27 20:14:57 by ael-azra         ###   ########.fr       */
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

int		position_of_nbr(t_stack *stack, int nb)
{
	int		i;

	i = 1;
	while (!is_empty(stack))
	{
		if (nb == stack->data)
			return (i);
		stack = stack->next;
		i++;
	}
	return (i);
}

int		calculate_nbr_of_chunk(int len)
{
	if (len % 20)
		return ((len / 20) + 1);
	return (len / 20);
}

t_stack *splite_chunks(int *arr, int first, int len)
{
	t_stack	*chunk;
	int		i;

	chunk = NULL;
	i = first;
	while (i < first + 20 && i < len)
	{
		push(&chunk, arr[i]);
		i++;
	}
	return (chunk);
}

int		find_nbr_in_stack(t_stack *chunk, int target)
{
	while (!is_empty(chunk))
	{
		if (target == chunk->data)
			return (1);
		chunk = chunk->next;
	}
	return (0);
}

void	pop_number(t_stack **chunk, int number)
{
	t_stack *tmp;

	tmp = NULL;
	while (!is_empty(*chunk))
	{
		if (number == (*chunk)->data)
		{
			pop(chunk);
			break ;
		}
		push(&tmp, (*chunk)->data);
		(*chunk) = (*chunk)->next;
	}
	while (!is_empty(tmp))
	{
		push(chunk, tmp->data);
		tmp = tmp->next;
	}
}

int		find_target(t_stack **chunk, t_stack *stack_a, int len, char **str)
{
	int		i;
	int		hold_first;
	int		hold_secend;
	int		position;

	i = 0;
	hold_first = 0;
	position = -1;
	while (i <= (len / 2))
	{
		if (!hold_first && find_nbr_in_stack(*chunk, stack_a->data))
		{
			hold_first = stack_a->data;
			position = i;
		}
		stack_a = stack_a->next;
		i++;
	}
	i = 0;
	while (!is_empty(stack_a) && i < len / 2)
	{
		if (find_nbr_in_stack(*chunk, stack_a->data))
		{
			hold_secend = stack_a->data;
			if (position == -1 || (len - ((len / 2) + (1 + i))) < position)
			{
				pop_number(chunk, hold_first);
				return (hold_secend);
			}
		}
		stack_a = stack_a->next;
		i++;
	}
	*str = ft_strdup("ra");
	pop_number(chunk, hold_first);
	return (hold_first);
}

void	long_sorte(t_stack **stack_a, int len)
{
	t_stack	*stack_b;
	t_stack *chunk;
	char	*str;
	int		*arr;
	int		target;
	int		i;
	int		first;
	int		len_2;

	stack_b = NULL;
	first = 0;
	arr = convert_stack_to_array(*stack_a, len);
	quick_sort(&arr, 0, len - 1);
	i = 0;
	while (stack_len(*stack_a) > 3)
	{
		len_2 = stack_len(*stack_a);
		if (i == 0 || i == 20)
		{
			
			chunk = splite_chunks(arr, first, len - 3);
			first += 20;
			if (first > 20)
			{
				print_stack(chunk);
				printf("break here\n");
				printf("first = %d\n", first);
				return ;
			}
			i = 0;
		}
		if (!is_empty(chunk))
			target = find_target(&chunk, *stack_a, len_2, &str);
		printf("\n------------- Target == %d ---------------\n", target);
		while (target != (*stack_a)->data)
		{
			if (!ft_strcmp("ra", str))
				rab(stack_a, 1, str);
			else if (!ft_strcmp("rra", str))
				rrab(stack_a, 1, str);
		}
		pab(&stack_b, stack_a, 1, "pb");
		i++;
	}
	if (!is_sorted(*stack_a))
		short_sorte(stack_a, 3);
	// while (!is_empty(stack_b))
	// 	pab(stack_a, &stack_b, 1, "pa");
	free(str);
	free(arr);
}

void	sorte_stack(t_stack **stack_a)
{
	int		len;

	len = stack_len(*stack_a);
	if (len < 4)
		short_sorte(stack_a, len);
	else
		long_sorte(stack_a, len);
}