/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:04:18 by ael-azra          #+#    #+#             */
/*   Updated: 2019/10/29 21:38:55 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*str;
	const unsigned char	*sourc;
	size_t				i;

	i = 0;
	str = (unsigned char*)dst;
	sourc = (unsigned char*)src;
	while (i < n)
	{
		if (sourc[i] == (unsigned char)c)
		{
			str[i] = sourc[i];
			return (dst + i + 1);
		}
		else
		{
			str[i] = sourc[i];
			i++;
		}
	}
	return (NULL);
}
