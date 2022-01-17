/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 18:05:45 by jrobert           #+#    #+#             */
/*   Updated: 2021/05/13 10:16:05 by jrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (*s++)
		size++;
	return (size);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	char	*tmp;
	int		size;

	if (!s1)
		size = ft_strlen(s2);
	else
		size = ft_strlen(s1) + ft_strlen(s2);
	tmp = (char *)s1;
	dst = malloc((size + 1) * sizeof(char));
	if (!dst)
	{
		if (tmp)
			free(tmp);
		return (NULL);
	}
	while (s1 && *s1)
		*dst++ = *s1++;
	if (tmp)
		free(tmp);
	while (*s2)
		*dst++ = *s2++;
	*dst = 0;
	return (dst - size);
}
