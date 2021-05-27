/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sorte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <ael-azra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 08:32:36 by ael-azra          #+#    #+#             */
/*   Updated: 2021/05/24 10:00:15 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		partition(int **arr, int low, int hight)
{
	int		pivot;
	int		i;
	int		j;

	pivot = (*arr)[hight];
	i = low;
	j = low;
	while (j < hight)
	{
		if ((*arr)[j] < pivot)
		{
			ft_swap(&(*arr)[j], &(*arr)[i]);
			i++;
		}
		j++;
	}
	ft_swap(&(*arr)[hight], &(*arr)[i]);
	return (i);
}

void	quick_sort(int  **arr, int low, int hight)
{
	int		pi;

	if (low < hight)
	{
		pi = partition(arr, low, hight);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, hight);
	}
}