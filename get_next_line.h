/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:21:50 by levasse           #+#    #+#             */
/*   Updated: 2022/11/29 10:41:26 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char		*get_next_line(int fd);
void		fill_char(char *dst, char *src);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(const char *str);
int			is_nl(const char *str);
void		stop_at_nl(char *line, char *buff);
void		clear_buff(char buff[BUFFER_SIZE]);
int	ft_strcmp(const char *s1, const char *s2);


#endif
