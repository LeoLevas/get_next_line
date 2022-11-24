/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:20:32 by levasse           #+#    #+#             */
/*   Updated: 2022/11/24 16:11:04 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_string(char *s1, char *s2, int len_line)
{
	s1 = malloc((len_line + 1) * sizeof(char));
	if (!s1)
	{
		free(s2);
		return (NULL);
	}
	fill_char(s1, s2);
	free(s2);
	return (s1);
}

static char	*get_next_line_part2(int fd, char *line, char buff[1])
{
	char	*temp;
	int		len_line;
	int		count;

	count = 1;
	len_line = 1;
	while (count != 0 && buff[0] != '\n' && buff[0] != '\0')
	{
		temp = fill_string(temp, line, len_line + 1);
		if (!temp)
			return (NULL);
		line = fill_string(line, temp, len_line + 2);
		if (!line)
			return (NULL);
		count = read(fd, buff, 1);
		line[len_line] = buff[0];
		if (buff[0] != '\n')
			line[len_line + 1] = '\0';
		if (count == 0)
			line[len_line] = '\0';
		len_line++;
	}
	line[len_line] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	buff[1];
	int		count;

	if (!fd || fd <= 0)
		return (NULL);
	count = read(fd, buff, 1);
	if (count <= 0)
		return (NULL);
	line = malloc(2 * sizeof(char));
	if (!line)
		return (NULL);
	line[0] = buff[0];
	line [1] = '\0';
	line = get_next_line_part2(fd, line, buff);
	return (line);
}

void	fill_char(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = src[i];
}
