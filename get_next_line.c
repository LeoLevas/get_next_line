/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:20:32 by levasse           #+#    #+#             */
/*   Updated: 2022/11/27 10:01:06 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buff[BUFFER_SIZE];
	int			count;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	count = read(fd, buff, BUFFER_SIZE);
	if (count <= 0)
		return (NULL);
	line = malloc(BUFFER_SIZE * sizeof(char));
	if (!line)
		return (NULL);
	fill_char(line, buff);
	count = read(fd, buff, BUFFER_SIZE);
	while (!is_nl(line) && count > 0)
	{
		line = ft_strjoin(line, buff);
		if (!line)
			return (NULL);
		count = read(fd, buff, BUFFER_SIZE);
	}
	stop_at_nl(line, buff);
	return (line);
}

void	stop_at_nl(char *line, char buff[BUFFER_SIZE])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] != '\n' && line[i])
		i++;
	i++;
	while (line[i])
	{
		buff[j] = line[i];
		line[i] = '\0';
		i++;
		j++;
	}
	buff[j] = '\0';
}

char	*fill_string(char *s1, char *s2, int len_line)
{
	s1 = malloc((len_line) * sizeof(char));
	if (!s1)
		return (NULL);
	fill_char(s1, s2);
	return (s1);
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

#include <fcntl.h>
#include <stdio.h>
int main()
{
    int fd;
    char *res;
    
    fd = open("./gnlTester/files/41_with_nl", O_RDWR);
    res = get_next_line(fd);
    printf("%s", res);
    res = get_next_line(fd);
    printf("%s", res);
}

int	is_nl(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n' && str[i] != 0)
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	unsigned long	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	joined = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!joined)
		return (NULL);
	while (s1[i] != '\0')
	{
		joined[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		joined[j] = s2[i];
		j++;
		i++;
	}
	joined[j] = '\0';
	free(s1);
	return (joined);
}