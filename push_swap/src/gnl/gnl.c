/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <ael-azra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:15:13 by ael-azra          #+#    #+#             */
/*   Updated: 2021/02/01 16:00:49 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		gnl(int fd, char **line)
{
	char	*buff;
	char	*ptr;
	char	*tmp;
	int		i;

	ptr = NULL;
	if (!(buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	*line = ft_strdup("");
	while (!ptr && (i = read(fd, buff, BUFFER_SIZE)))
	{
		buff[i] = '\0';
		if ((ptr = ft_strchr(buff, '\n')))
		{
			*ptr = '\0';
			ptr++;
		}
		tmp = *line;
		*line = ft_strjoin(*line, buff);
		free(tmp);
	}
	free(buff);
	return ((i != 0) ? 1 : 0);
}
