/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:30:35 by ael-azra          #+#    #+#             */
/*   Updated: 2019/10/27 23:13:28 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = ft_strlen((char*)s);
	if (c == '\0')
		return ((char*)s + i);
	while (*s && *s != c)
		s++;
	if (*s == '\0')
		return (NULL);
	return ((char*)s);
}
