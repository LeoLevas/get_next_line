/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:20:32 by levasse           #+#    #+#             */
/*   Updated: 2022/11/23 06:43:32 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
	char	*line;
	char	*temp;
	char	buff[1];
	int		len_line;
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
	len_line = 1;
	while (count != 0 && buff[0] != '\n' && buff[0] != '\0')
	{
		temp = malloc((len_line + 1)* sizeof(char));
		if (!temp)
		{
			free(line);
			return (NULL);
		}
		fill_char(temp, line);
		free(line);
		line = malloc((len_line + 2) * sizeof(char));
		if (!line)
		{
			free(temp);
			return (NULL);
		}
		fill_char(line, temp);
		free(temp);
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

/* #include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd;
	char *res;
	
	fd = open("./gnlTester/files/41_no_nl", O_RDWR);
	res = get_next_line(fd);
	printf("%s", res);
} */