/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:14:09 by arcarval          #+#    #+#             */
/*   Updated: 2023/02/03 14:19:38 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char	*extract_line_from_buffer(char *static_buffer, int len_to_linebreak)
{
	char	*line;

	line = malloc(sizeof(char) * (len_to_linebreak));
	if (!line)
		return (NULL);
	ft_strlcpy(line, static_buffer, len_to_linebreak);
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
	}
	free(temp_buffer);
	return (static_buffer);
}

char	*update_static_buffer(char *static_buffer, int size_till_linebreak)
{
	int		buffer_length;
	char	*buffer;

	buffer_length = ft_strlen(static_buffer) - size_till_linebreak + 1;
	buffer = malloc(sizeof(char) * buffer_length);
	if (!buffer)
		return (NULL);
	ft_strlcpy(buffer, static_buffer + size_till_linebreak, buffer_length);
	free(static_buffer);
	static_buffer = NULL;
	static_buffer = ft_strjoin(static_buffer, buffer);
	free(buffer);
	return (static_buffer);
}

char	*get_next_line(int fd)
{
	static char	*static_buffer;
	char		*line;
	int			size_with_linebreak;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	static_buffer = read_file_to_buffer(fd, static_buffer);
	if (!static_buffer || ft_strlen(static_buffer) == 0)
	{
		free(static_buffer);
		static_buffer = NULL;
		return (NULL);
	}
	line = NULL;
	size_with_linebreak = (ft_strchr(static_buffer, '\n') - static_buffer) + 1;
	line = extract_line_from_buffer(static_buffer, size_with_linebreak);
	static_buffer = update_static_buffer(static_buffer, size_with_linebreak);
	return (line);
}
