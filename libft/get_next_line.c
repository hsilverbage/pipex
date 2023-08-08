/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:02:02 by henrik            #+#    #+#             */
/*   Updated: 2023/08/07 16:19:38 by henrik           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_line(int fd, char *line, char *buffer, int i)
{
	int	j;

	if (line != NULL)
	{
		free(line);
		line = NULL;
	}
	while (read(fd, buffer + i, 1) > 0 && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	if (line != NULL)
	{
		j = 0;
		while (j < i)
		{
			if (buffer[j] != '\n')
				line[j] = buffer[j];
			j++;
		}
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[1];
	char		*line;

	line = NULL;
	line = get_line(fd, line, buffer, 0);
	return (line);
}
