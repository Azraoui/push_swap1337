/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:01:14 by ael-azra          #+#    #+#             */
/*   Updated: 2019/10/29 21:27:03 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*str;
	const unsigned char	*sourc;
	size_t				i;

	str = dst;
	sourc = src;
	i = 0;
	if ((!str && !sourc) || ft_memcmp(str, sourc, n) == 0)
		return (dst);
	while (i < n)
	{
		str[i] = sourc[i];
		i++;
	}
	return (dst);
}
