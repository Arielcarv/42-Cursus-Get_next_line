/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:14:09 by arcarval          #+#    #+#             */
/*   Updated: 2023/01/31 22:44:00 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char	*extract_line_from_buffer(char *static_buffer)
{
	int		size_till_linebreak;
	char	*line;

	size_till_linebreak = ft_strchr(static_buffer, '\n') - static_buffer;
	line = malloc(sizeof(char) * (size_till_linebreak + 1));
	if (!line)
		return (NULL);
	ft_strlcpy(line, static_buffer, size_till_linebreak);
	return (line);
}

char	*read_file_to_buffer(int fd, char *static_buffer)
{
	char	*temp_buffer;
	int		bytes_read;

	temp_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp_buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(static_buffer, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(temp_buffer);
			return (NULL);
		}
		temp_buffer[bytes_read] = '\0';
		static_buffer = ft_strjoin(static_buffer, temp_buffer);
		printf("static_buffer: %s\n", static_buffer);
	}
	free(temp_buffer);
	return (static_buffer);
}

char	*get_next_line(int fd)
{
	static char	*static_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	// 1. Read file and store it in static_buffer till find a '\n'
	static_buffer = read_file_to_buffer(fd, static_buffer);
	// 2. Find the first '\n' in static_buffer
	line = NULL;
	line = extract_line_from_buffer(static_buffer);

	// 3. Move static till the next '\n'
	// move_static_buffer(&static_buffer);
	return (line);
}
