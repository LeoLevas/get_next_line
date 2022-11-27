/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:21:50 by levasse           #+#    #+#             */
/*   Updated: 2022/11/27 09:48:01 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*get_next_line(int fd);
void		fill_char(char *dst, char *src);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(const char *str);
char		*fill_string(char *s1, char *s2, int len_line);
int			is_nl(const char *str);
void		stop_at_nl(char *line, char buff[BUFFER_SIZE]);

#endif
