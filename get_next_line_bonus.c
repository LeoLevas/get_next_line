/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:57:39 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/16 17:45:30 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*stach[OPEN_MAX];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
	{
		if (stach[fd])
			return (free(stach[fd]), stach[fd] = NULL, NULL);
		return (NULL);
	}
	if (ft_strcmp(buff, "") == 0)
		stach[fd] = stach_empty(stach[fd], fd, buff);
	else
	{
		stach[fd] = malloc((ft_strlen(buff) + 1) * sizeof(char));
		if (!stach[fd])
			return (NULL);
		fill_char(stach[fd], buff, 0);
	}
	if (!stach[fd] && buff[0] != 0)
		return (NULL);
	stach[fd] = check_stach_has_nl(stach[fd], buff, fd);
	if (!stach[fd])
		return (NULL);
	if (stach[fd][0] == '\0')
		return (free(stach[fd]), stach[fd] = NULL, NULL);
	line = malloc((ft_strlen(stach[fd]) + 1) * sizeof(char));
	if (!line)
		return (NULL);
	fill_char(line, stach[fd], 1);
	if (ft_strcmp(line, stach[fd]))
		return (get_left_over(line, stach[fd], buff), line);
	return (free(stach[fd]), stach[fd] = NULL, line);
}

char	*stach_empty(char *stach, int fd, char buff[BUFFER_SIZE])
{
	int	count;

	count = read(fd, buff, BUFFER_SIZE);
	buff[count] = '\0';
	if (count < 0)
		return (NULL);
	stach = malloc((count + 1) * sizeof(char));
	if (!stach)
		return (NULL);
	stach[count] = '\0';
	fill_char(stach, buff, 0);
	empty_buff(buff);
	return (stach);
}

char	*check_stach_has_nl(char *stach, char buff[BUFFER_SIZE], int fd)
{
	int	count;

	if (!stach)
		return (stach);
	if (!is_nl(stach))
	{
		count = read(fd, buff, BUFFER_SIZE);
		buff[count] = '\0';
		while (!is_nl(stach) && count > 0)
		{
			stach = ft_strjoin(stach, buff);
			empty_buff(buff);
			if (!stach)
				return (NULL);
			if (!is_nl(stach))
				count = read(fd, buff, BUFFER_SIZE);
			buff[count] = '\0';
		}
		if (count <= 0)
			stach = ft_strjoin(stach, "\0");
	}
	return (stach);
}

void	empty_buff(char buff[BUFFER_SIZE])
{
	int	i;

	i = 0;
	while (i <= BUFFER_SIZE && buff[i] != 0)
	{
		buff[i] = 0;
		i++;
	}
}

void	get_left_over(char *line, char *stach, char buff[BUFFER_SIZE])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (!line[i])
		return (free(stach));
	i++;
	while (stach[i] != '\0')
	{
		buff[j] = stach[i];
		i++;
		j++;
	}
	buff[j] = '\0';
	free(stach);
	stach = NULL;
}
