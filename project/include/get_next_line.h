/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:36:27 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/13 16:54:00 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

size_t				gnl_strlen(char const *str);
char				*gnl_strjoin(char *s1, char *s2);
//int					make_line(char **str, char **line);
int					str_in_newline(char *str);
char				*gnl_strdup(char *s1);
int					get_next_line(int fd, char **line);
//int					decide_ret(int ret, char **str, char **line);

#endif
