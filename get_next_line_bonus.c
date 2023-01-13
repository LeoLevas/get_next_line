/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:57:39 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/10 10:52:04 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buff[65535];
	char		stach;
	char		*line;

	stach = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_strcmp(buff, "") == 0)
		stach = stach_empty(stach, fd, buff);
	else
	{
		stach = malloc((ft_strlen(buff) + 1) * sizeof(char));
		if (!stach)
			return (NULL);
		fill_char(stach, buff, 0);
	}
	if (!stach && buff[0] != 0)
		return (NULL);
	stach = check_stach_has_nl(stach, buff, fd);
	if (!stach)
		return (NULL);
	if (stach[0] == '\0')
	{
		free(stach);
		stach = NULL;
		return (NULL);
	}
	line = malloc((ft_strlen(stach) + 1) * sizeof(char));
	if (!line)
		return (NULL);
	fill_char(line, stach, 1);
	if (ft_strcmp(line, stach))
		return (get_left_over(line, stach, buff), line);
	free(stach);
	stach = NULL;
	return (line);
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
