/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 15:48:42 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/06 17:13:53 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		make_line(char **str, char **line)
{
	int		n_idx;
	char	*tmp;

	n_idx = str_in_newline(*str);
	(*str)[n_idx] = '\0';
	*line = gnl_strdup(*str);
	tmp = gnl_strdup((*str) + (n_idx + 1));
	free(*str);
	*str = tmp;
	return (1);
}

static int		decide_ret(int ret, char **str, char **line)
{
	if (ret == -1)
		return (-1);
	else if (*str && str_in_newline(*str) >= 0)
	{
		make_line(str, line);
		return (1);
	}
	else if (*str)
	{
		*line = gnl_strdup(*str);
		free(*str);
		*str = 0;
		return (0);
	}
	*line = gnl_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*str;
	char		*buffer;
	int			ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		str = gnl_strjoin(str, buffer);
		if (str_in_newline(str) >= 0)
		{
			free(buffer);
			ret = make_line(&str, line);
			return (ret);
		}
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	ret = decide_ret(ret, &str, line);
	return (ret);
}
