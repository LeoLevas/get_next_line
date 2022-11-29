/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:20:32 by levasse           #+#    #+#             */
/*   Updated: 2022/11/28 20:07:18 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buff[BUFFER_SIZE];
	int			count;

	count = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_strcmp(buff, "") == 0)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count <= 0)
			return (NULL);
	}
	line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (NULL);
	fill_char(line, buff);
	if (!is_nl(line) && count > 0)
	{
		clear_buff(buff);
		count = read(fd, buff, BUFFER_SIZE);
		while (!is_nl(line) && count > 0)
		{
			line = ft_strjoin(line, buff);
			if (!line)
				return (NULL);
			if (!is_nl(buff))
				count = read(fd, buff, BUFFER_SIZE);
		}
	}
	stop_at_nl(line, buff);
	return (line);
}

void	clear_buff(char buff[BUFFER_SIZE])
{
	int	i;

	i = 0;
	while (buff[i] != '\0')
	{
		buff[i] = '\0';
		i++;
	}
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
	if (line[i - 1] == '\n' && line[i] == '\0')
	{
		while (i < BUFFER_SIZE)
		{
			buff[j] = buff[i];
			i++;
			j++;
		}
		buff[j] = '\0';
	}
	else
	{	
		while (buff[j] != '\0')
		{
			buff[j] = line[i];
			line[i] = '\0';
			j++;
			i++;
		}
		buff[j] = '\0';
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] == s2[i] && (s1[i] || s2[i]))
		i++;
	return (s1[i] - s2[i]);
}


void	fill_char(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && src[i] != '\n')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = src[i];
	if (src[i] == '\n')
		dst[i + 1] = '\0';
}
/* 
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
int main()
{
    int fd;
    char *res;
	const char *expectedres;

    fd = open("./gnlTester/files/multiple_line_no_nl", O_RDWR);
	res = get_next_line(fd);
	expectedres = "01234567890123456789012345678901234567890\n";
	if (!strcmp(res, expectedres))
		printf("right : %s\n---------\n", res);
	else
		printf("%s \ninstead of \n%s\n---------\n", res, expectedres);

	res = get_next_line(fd);
	expectedres = "987654321098765432109876543210987654321098\n";
	if (!strcmp(res, expectedres))
		printf("right : %s\n---------\n", res);
	else
		printf("%s \ninstead of \n%s\n---------\n", res, expectedres);
		
	res = get_next_line(fd);
	expectedres = "0123456789012345678901234567890123456789012\n";
	if (!strcmp(res, expectedres))
		printf("right : %s\n---------\n", res);
	else
		printf("%s \ninstead of \n%s\n---------\n", res, expectedres);

    res = get_next_line(fd);
	expectedres = "987654321098765432109876543210987654321098\n";
	if (!strcmp(res, expectedres))
		printf("right : %s\n---------\n", res);
	else
		printf("%s \ninstead of \n%s\n---------\n", res, expectedres);

    res = get_next_line(fd);
	expectedres = "01234567890123456789012345678901234567890";
	if (!strcmp(res, expectedres))
		printf("right : %s\n---------\n", res);
	else
		printf("%s \ninstead of \n%s\n---------\n", res, expectedres);
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
} */