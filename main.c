/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 20:35:04 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/09 20:19:23 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void	gnl(int fd, char *res);


int	main()
{
	int	fd;

	fd = open("files/41_with_nl", O_RDONLY);
	gnl(1000, NULL);
	gnl(-1, NULL);
	close(fd);
	gnl(fd, NULL);
}

void	gnl(int fd, char *res)
{
	char	*line;

	line = get_next_line(fd);
	if (ft_strcmp(line, res) || (res && !line))
		printf("%s instead of %s\n", line, res);
	else if (!line)
		printf ("(NULL)\n");
	else
		printf("%s\n", line);
	free (line);
}
