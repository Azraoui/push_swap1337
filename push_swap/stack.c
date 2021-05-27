/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <ael-azra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 07:46:45 by ael-azra          #+#    #+#             */
/*   Updated: 2021/05/26 11:43:23 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack     *create_node(int data)
{
    t_stack     *stack;

    stack = (t_stack*)malloc(sizeof(t_stack));
    stack->data = data;
    stack->next = NULL;
    return (stack);
}

int is_empty(t_stack *root)
{
	return (!root);
}

void push(t_stack **root, int data)
{
	t_stack *stack;

    stack = create_node(data);
	stack->next = *root;
	*root = stack;
}

int pop(t_stack **root)
{
	t_stack *tmp;
	int     popped;

	if (is_empty(*root))
		return (1);
    tmp = *root;
	*root = (*root)->next;
    popped = tmp->data;
	free(tmp);
	return (popped);
}

int peek(t_stack *root)
{
	if (is_empty(root))
		return (1);
	return (root->data);
}