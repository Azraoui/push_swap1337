/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <ael-azra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:01:30 by ael-azra          #+#    #+#             */
/*   Updated: 2021/05/26 18:59:38 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./src/libftt/libft.h"
# include "./src/gnl/get_next_line.h" 

typedef struct	s_stack
{
    int				data;
    struct	s_stack	*next;
}				t_stack;

void	free_stack(t_stack **stack);
void    push(t_stack **root, int data);
int     pop(t_stack **root);
int     peek(t_stack *root);
int     is_empty(t_stack *root);
t_stack *create_node(int data);
void    ft_swap(int *a, int *b);
int     stack_len(t_stack *stack);
int     *convert_stack_to_array(t_stack *stack, int len);
int     sab(t_stack **stack, int true, char *str);
int     ss(t_stack **stack_a, t_stack **stack_b, int true, char *str);
int     pab(t_stack **stack_a, t_stack **stack_b, int true, char *str);
int     rab(t_stack **stack, int true, char *str);
int     rr(t_stack **stack_a, t_stack **stack_b, int true, char *str);
int     rrab(t_stack **stack, int true, char *str);
int		rrr(t_stack **stack_a, t_stack **stack_b, int true, char *str);
t_stack	*fill_stack(int ac, char **av);
int     ft_error(int mod, t_stack **stack_a, t_stack **stack_b);
int		is_sorted(t_stack *stack);
void	sorte_stack(t_stack **stack_a);
void	quick_sort(int  **arr, int low, int hight);
void	print_stack(t_stack *stack);

#endif