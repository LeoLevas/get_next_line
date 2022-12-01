/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:20:32 by levasse           #+#    #+#             */
/*   Updated: 2022/12/01 08:56:04 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stach;
	char		buff[BUFFER_SIZE + 1];
	int			count;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
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
	}
	if (!is_nl(stach))
	{
		count = read(fd, buff, BUFFER_SIZE);
		while (!is_nl(stach) && count > 0)
		{
			stach = ft_strjoin(stach, buff);
			if (!stach)
				return (NULL);
			if (!is_nl(stach))
				count = read(fd, buff, BUFFER_SIZE);
		}
		if (count <= 0)
			stach = ft_strjoin(stach, "\0");
	}
	line = malloc((ft_strlen(stach) + 1) * sizeof(char));
	if (!line)
		return (NULL);
	fill_char(line, stach, 1);
	if (ft_strcmp(line, stach))
		get_left_over(line, stach);
	else 
	{
		free(stach);
		stach = NULL;
	}
	return (line);
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

void	fill_char(char *dst, char *src, int till_nl)
{
	int	i;

	i = 0;
	if (!till_nl)
	{
		while (src[i] > 0)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	else
	{
		while (src[i] > 0 && src[i] != '\n')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = src[i];
		if (dst[i] != '\0')
			dst[i + 1] = '\0';
	}
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

	printf("\n---nl---\n");
	fd = open("./gnlTester/files/41_no_nl", O_RDWR);
	res = get_next_line(fd);
	expectedres = "01234567890123456789012345678901234567890";
	if (!ft_strcmp(res, expectedres))
		printf("right : %s---------\n", res);
	else
		printf("%s \ninstead of \n%s\n---------\n", res, expectedres);
	res = get_next_line(fd);
	expectedres = "0";
	if (res == NULL)
		printf("right : %s---------\n", res);
	else
		printf("%s \ninstead of \nNULL\n---------\n", res);
	close(fd);
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
	while (str[i] != '\0')
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

 */