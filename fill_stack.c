/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <ael-azra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:21:35 by ael-azra          #+#    #+#             */
/*   Updated: 2021/05/22 11:30:04 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack		*swap;
	t_stack		*tmp;

	tmp = *stack;
	while (tmp)
	{
		swap = tmp;
		tmp = tmp->next;
		free(swap);
	}
	*stack = NULL;
}

int		strtoint(char *str, int *status)
{
	int				i;
	int				len;
	int				sign;
	unsigned	int	res;

	len = ft_strlen(str);
	res = 0;
	i = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (i < len)
	{
		res = res * 10 + str[i] - 48;
		if ((res > 2147483647 && sign == 1) || (res > 2147483648 && sign == -1) || !ft_isdigit(str[i]))
		{
			*status = 1;
			return (0);
		}
		i++;
	}
	return (res * sign);
}

t_stack		*find_duplicate(t_stack **stack)
{
	int		*arr;
	int		len;
	int		i;
	int		j;

	i = 0;
	len = stack_len(*stack);
	arr = convert_stack_to_array(*stack, len);
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[j] == arr[i])
			{
				free_stack(stack);
				free(arr);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	free(arr);
	return (*stack);
}

void		ft_reverse(t_stack **stack)
{
	t_stack		*swap;

	swap = NULL;
	while (!is_empty(*stack))
		push(&swap, pop(stack));
	*stack = swap;
}

t_stack     *fill_stack(int ac, char **av)
{
    t_stack     *stack;
	int			data;
	int			status;
    int         i;

	status = 0;
	stack = NULL;
	i = 1;
    while (i < ac)
    {
        data = strtoint(av[i], &status);
		push(&stack, data);
		if (status)
		{
			free_stack(&stack);
			return (NULL);
		}
		i++;
    }
	ft_reverse(&stack);
	return (find_duplicate(&stack));
}