/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:07:57 by rgilles           #+#    #+#             */
/*   Updated: 2020/05/02 15:08:02 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*rest_of_buffer(char *str)
{
	int				i;
	int				str_len;
	char			*tmp;

	i = 0;
	str_len = ft_strlen(str);
	if (str != NULL)
	{
		while (str[i] != '\0' && str[i] != '\n')
			i++;
		if (str[i] == '\n')
		{
			tmp = str;
			str = ft_substr(str, i + 1, str_len - i - 1);
			free(tmp);
		}
	}
	return (str);
}

void		inject_line(char *str, char **line)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] != '\0' && str[i] != '\n')
			i++;
		if (str[i] == '\n')
			*line = ft_substr(str, 0, i);
		else if (str[i] == 0)
			*line = ft_strdup(str);
	}
	else
		*line = ft_strdup("");
}

char		*get_line_buffered(char *str, int fd, int *nbread)
{
	char			buf[BUFFER_SIZE + 1];
	char			*tmp;

	while ((*nbread = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[*nbread] = '\0';
		if (str == NULL)
			str = ft_strdup(buf);
		else
		{
			tmp = str;
			str = ft_strjoin(str, buf);
			free(tmp);
		}
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (str);
}

int			get_next_line(int fd, char **line)
{
	int				nbread;
	static char		*str;
	int				value;

	if (fd < 0 || line == NULL || BUFFER_SIZE == 0)
		return (-1);
	str = get_line_buffered(str, fd, &nbread);
	if (nbread < 0)
		return (-1);
	inject_line(str, line);
	if (nbread)
		str = rest_of_buffer(str);
	else
	{
		free(str);
		str = NULL;
		return (0);
	}
	return (1);
}
