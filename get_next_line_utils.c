/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:41:42 by rgilles           #+#    #+#             */
/*   Updated: 2020/05/02 15:41:44 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	const char	*charptr;
	size_t		i;

	charptr = str;
	i = 0;
	while (*charptr++)
		i++;
	return (i);
}

char	*ft_strdup(const char *src)

char	*ft_strjoin(const char *s1, const char *s2)

int		ft_strchr(const char *str, int c)
{
	while (*str)
		if (*str++ == (char)c)
			return (1);
	if (*str == (char)c)
		return (1);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*toreturn;
	int		i;

	i = 0;
	if (!s || !(toreturn = (char*)malloc(len + 1)))
		return (NULL);
	if (start < ft_strlen(s))
		while (s[start + i] && len--)
		{
			toreturn[i] = s[start + i];
			i++;
		}
	toreturn[i] = 0;
	return (toreturn);
}
