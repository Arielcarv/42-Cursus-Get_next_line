/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:14:09 by arcarval          #+#    #+#             */
/*   Updated: 2023/02/09 00:48:20 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strlcpy(char *dest, char const *src, int size)
{
	int	index;

	index = 0;
	if (size > 0)
	{
		while (src[index] && (index < size - 1))
		{
			dest[index] = src[index];
			index++;
		}
		dest[index] = '\0';
	}
	return (ft_strlen(src));
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
		if (bytes_read <= 0)
			break ;
		temp_buffer[bytes_read] = '\0';
		static_buffer = ft_strjoin(static_buffer, temp_buffer);
	}
	free(temp_buffer);
	return (static_buffer);
}

char	*extract_line_from_buffer(char *static_buffer, int len_to_linebreak)
{
	char	*line;

	if (!static_buffer)
		return (NULL);
	line = ft_calloc(len_to_linebreak, sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, static_buffer, len_to_linebreak);
	// ft_memcpy(line, static_buffer, len_to_linebreak);
	return (line);
}

// TODO: refactor the update static buffer function to not return leaks and free everything
char	*update_static_buffer(char *static_buffer, int size_till_linebreak)
{
	int		buffer_length;
	char	*buffer;

	if (!static_buffer)
	{
		free(static_buffer);
		return (NULL);
	}
	buffer_length = ft_strlen(static_buffer) - size_till_linebreak + 1;
	if (!static_buffer || !static_buffer[buffer_length])
	{
		free(static_buffer);
		return (NULL);
	}
	buffer = malloc(buffer_length * sizeof(char));
	ft_strlcpy(buffer, static_buffer + size_till_linebreak, buffer_length + 1);
	free(static_buffer);
	static_buffer = NULL;
	static_buffer = ft_strjoin(static_buffer, buffer);
	free(buffer);
	return (static_buffer);
}

int	size_or_linebreak(char const *str)
{
	if (ft_strchr(str, '\n'))
		return ((ft_strchr(str, '\n') - str) + 1);
	return (ft_strlen(str));
}
// Remove a function, by limitations of the norminette
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
	size_with_linebreak = size_or_linebreak(static_buffer) + 1;
	line = extract_line_from_buffer(static_buffer, size_with_linebreak);
	// TODO: check update_static_buffer
	static_buffer = update_static_buffer(static_buffer, size_with_linebreak);
	return (line);
}
