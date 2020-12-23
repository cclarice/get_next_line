/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:15:08 by cclarice          #+#    #+#             */
/*   Updated: 2020/12/01 17:32:24 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_strlen(const char *str)
{
	int c;

	c = 0;
	while (str[c] != '\0' && str[c] != '\n')
		c++;
	return (c);
}

char	*ft_strjoin(char **s1, char *s2)
{
	char	*str;
	char	*p;
	int		len;
	char	*s1p;

	s1p = *s1;
	len = (ft_strlen(*s1) + ft_strlen(s2));
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	p = str;
	while (s1p[0] && *s1p != '\n')
		*(p++) = *(s1p++);
	while (*s2 && *s2 != '\n')
		*(p++) = *(s2++);
	free(*s1);
	str[len] = '\0';
	return (str);
}
