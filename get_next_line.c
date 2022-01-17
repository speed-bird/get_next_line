/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 18:05:38 by jrobert           #+#    #+#             */
/*   Updated: 2021/05/19 22:04:58 by jrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_save_line(int *endl, char buf[], int *i, char **line)
{
	int	start;

	start = *i;
	while (*i < BUFFER_SIZE && buf[*i] != '\n')
		++*i;
	if (buf[*i] == '\n')
		*endl = 1;
	buf[*i] = 0;
	*line = ft_strjoin(*line, &buf[start]);
	if (!*line)
		return (0);
	while ((*i)--)
		buf[*i] = 0;
	return (1);
}

static int	ft_drain_buf(int *endl, char buf[], char **line)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE && !buf[i])
		i++;
	if (i < BUFFER_SIZE)
		return (ft_save_line(endl, buf, &i, line));
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	int			endl;
	int			r;
	int			i;

	if (fd < 0 || fd >= OPEN_MAX || !line || !BUFFER_SIZE)
		return (-1);
	*line = 0;
	r = 1;
	endl = 0;
	if (!ft_drain_buf(&endl, buf, line))
		return (-1);
	while (!endl && r)
	{	
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
			return (-1);
		i = 0;
		if (!ft_save_line(&endl, buf, &i, line))
			return (-1);
	}
	if (r > 0)
		return (1);
	else
		return (r);
}
