/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:12:41 by ael-azra          #+#    #+#             */
/*   Updated: 2019/10/23 18:54:57 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int				i;
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	nb = n;
	i = 1;
	while ((nb /= 10) > 0)
		i *= 10;
	nb = n;
	while (i)
	{
		ft_putchar_fd((nb / i) + '0', fd);
		nb %= i;
		i /= 10;
	}
}
