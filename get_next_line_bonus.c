/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 00:05:53 by cclarice          #+#    #+#             */
/*   Updated: 2020/12/01 17:32:35 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_findn(void *m)
{
	unsigned char	*mem;
	int				a;

	a = -1;
	mem = (unsigned char*)m;
	while (++a < BUFFER_SIZE && mem[a] != '\0')
		if (mem[a] == '\n')
			return (a);
	return (-1);
}

int		ft_findz(void *m, int r)
{
	unsigned char	*mem;
	int				a;

	a = -1;
	mem = (unsigned char*)m;
	while (++a < BUFFER_SIZE && a < r)
		if (mem[a] == '\0')
			return (a);
	return (-1);
}

int		ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*pdst;
	unsigned char	*psrc;
	size_t			i;

	pdst = (unsigned char*)dst;
	psrc = (unsigned char*)src;
	i = 0;
	if (psrc == 0 && pdst == 0)
		return (1);
	if (pdst > psrc)
		while (++i <= len)
			pdst[len - i] = psrc[len - i];
	else
		while (len-- > 0)
			*(pdst++) = *(psrc++);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	mem[256][BUFFER_SIZE + 1];
	int			n;
	int			r;

	if (fd <= 0 || line == NULL || BUFFER_SIZE <= 0
			|| !(*line = malloc(sizeof(char))))
		return (-1);
	line[0][0] = '\0';
	*line = ft_strjoin(&(*line), &(*mem[fd]));
	if ((n = ft_findn(&mem[fd][0])) >= 0)
		return (ft_memmove(&mem[fd][0], &mem[fd][n + 1], BUFFER_SIZE));
	while ((r = read(fd, mem[fd], BUFFER_SIZE)) >= 0)
	{
		mem[fd][r] = '\0';
		*line = ft_strjoin(&(*line), &(*mem[fd]));
		if ((n = ft_findn(&mem[fd][0])) >= 0)
			return (ft_memmove(&mem[fd][0], &mem[fd][n + 1], BUFFER_SIZE));
		if (r == 0 || ft_findz(&mem[fd][0], r) >= 0)
		{
			mem[fd][0] = '\0';
			return (0);
		}
	}
	free(*line);
	return (-1);
}
