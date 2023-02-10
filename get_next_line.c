/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:14:09 by arcarval          #+#    #+#             */
/*   Updated: 2023/02/10 00:08:16 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	size_or_linebreak(char const *static_buffer)
{
	if (ft_strchr(static_buffer, '\n'))
		return (ft_strchr(static_buffer, '\n') - static_buffer);
	return (ft_strlen(static_buffer));
}

static char	*read_file_to_buffer(int fd, char *static_buffer)
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
		if (bytes_read <= 0)
			break ;
		temp_buffer[bytes_read] = '\0';
		static_buffer = ft_strjoin(static_buffer, temp_buffer);
	}
	free(temp_buffer);
	return (static_buffer);
}

static char	*extract_line_from_buffer(char *static_buffer)
{
	char	*line;
	int		line_length;

	line_length = size_or_linebreak(static_buffer) + 2;
	if (!static_buffer)
		return (NULL);
	line = ft_calloc(line_length, sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, static_buffer, line_length);
	return (line);
}

static char	*update_static_buffer(char *static_buffer)
{
	int		buffer_length;
	char	*buffer;
	int		size_with_compensation;

	if (!static_buffer[size_or_linebreak(static_buffer)])
	{
		free(static_buffer);
		return (NULL);
	}
	size_with_compensation = size_or_linebreak(static_buffer) + 1;
	buffer_length = (ft_strlen(static_buffer) - size_with_compensation + 1);
	buffer = malloc(buffer_length * sizeof(char));
	if (!buffer)
		return (NULL);
	ft_strlcpy(buffer, static_buffer + size_with_compensation, buffer_length);
	free(static_buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*static_buffer;
	char		*line;

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
	line = extract_line_from_buffer(static_buffer);
	static_buffer = update_static_buffer(static_buffer);
	return (line);
}
