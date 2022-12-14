/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:20:32 by llevasse          #+#    #+#             */
/*   Updated: 2022/12/14 16:20:13 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stach;
	static char	buff[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, buff, 0) < 0)
	{
		if (!stach)
			return (NULL);
		free(stach);
		stach = NULL;
		return (NULL);
	}
	stach = get_stach(stach, fd, buff);
	if (!stach)
		return (NULL);
	line = malloc((ft_strlen(stach) + 1) * sizeof(char));
	if (!line)
		return (NULL);
	fill_char(line, stach, 1);
	if (ft_strcmp(line, stach))
		return (get_left_over(line, stach), line);
	free(stach);
	stach = NULL;
	return (line);
}

char	*get_stach(char *stach, int fd, char buff[BUFFER_SIZE])
{
	int	count;

	if (ft_strcmp(stach, "") == 0)
	{
		count = read(fd, buff, BUFFER_SIZE);
		buff[count] = '\0';
		if (count <= 0)
			return (NULL);
		stach = malloc((count + 1) * sizeof(char));
		if (!stach)
			return (NULL);
		stach[count] = '\0';
		fill_char(stach, buff, 0);
		empty_buff(buff);
	}
	return (check_stach_has_nl(stach, buff, fd));
}

char	*check_stach_has_nl(char *stach, char buff[BUFFER_SIZE], int fd)
{
	int	count;

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

void	get_left_over(char *line, char *stach)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (!line[i] && !stach[i])
	{
		while (j <= i)
		{
			stach[j] = 0;
			j++;
		}
		return ;
	}
	i++;
	while (stach[i] != '\0')
	{
		stach[j] = stach[i];
		i++;
		j++;
	}
	stach[j] = '\0';
}
