/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:37:34 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/06 16:34:48 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(char const *str)
{
	size_t len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		str_in_newline(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*ret;
	size_t	len;
	size_t	idx;

	idx = 0;
	if (!s1)
	{
		ret = gnl_strdup(s2);
		return (ret);
	}
	len = gnl_strlen(s1) + gnl_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	while (*(s1 + idx))
	{
		*(ret + idx) = *(s1 + idx);
		idx++;
	}
	free(s1);
	while (*s2)
		*(ret + idx++) = *s2++;
	*(ret + idx) = '\0';
	return (ret);
}

char	*gnl_strdup(char *s1)
{
	char	*ptr;
	int		len;
	int		i;

	i = 0;
	len = gnl_strlen(s1);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
