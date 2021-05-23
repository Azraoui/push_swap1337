/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 23:29:50 by ael-azra          #+#    #+#             */
/*   Updated: 2019/10/27 22:29:18 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*sourc;

	dest = dst;
	sourc = (char*)src;
	if ((!src && !dst) || ((!src || !dst) && len == 0))
		return (NULL);
	if (ft_memcmp(dst, src, len) == 0)
		return (dst);
	if (dst > src)
	{
		while (len--)
			dest[len] = sourc[len];
		return (dest);
	}
	else
		return (ft_memcpy(dst, src, len));
}
