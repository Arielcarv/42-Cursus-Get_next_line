/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:13:50 by arcarval          #+#    #+#             */
/*   Updated: 2023/02/09 00:13:47 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char const *str, int caracter)
{
	char	temp_caracter;
	int		index;

	if (!str)
		return (0);
	temp_caracter = caracter;
	index = 0;
	while (*(str + index) && (*(str + index) != temp_caracter))
		index++;
	if (*(str + index) == temp_caracter)
		return ((char *)str + index);
	return (0);
}

int	ft_strlen(char const *str)
{
	int	length;

	if (!str)
		return (0);
	length = 0;
	while (str[length])
		length++;
	return (length);
}

void	*ft_calloc(size_t number_spaces, size_t size)
{
	char	*empty_str;
	size_t	total_size;

	total_size = number_spaces * size;
	empty_str = malloc(total_size);
	if (empty_str != 0)
	{
		while (total_size-- > 0)
			empty_str[total_size] = 0;
		return (empty_str);
	}
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t char_number)
{
	char	*temp_dest_pointer;
	char	*temp_src_pointer;

	if (!dest)
		return (NULL);
	temp_dest_pointer = (char *) dest;
	temp_src_pointer = (char *) src;
	if (temp_dest_pointer != 0)
		while (char_number-- > 0)
			*(temp_dest_pointer++) = *(temp_src_pointer++);
	return (dest);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		str1_length;
	int		str2_length;
	char	*dest;

	if (!str1)
		str1 = ft_calloc(1, sizeof(char));
	if (!str2)
	{
		free(str2);
		return (NULL);
	}
	str1_length = ft_strlen(str1);
	str2_length = ft_strlen(str2);
	dest = malloc((str1_length + str2_length + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_memcpy(dest, str1, str1_length);
	ft_memcpy(dest + str1_length, str2, str2_length);
	// ft_strlcpy(dest, str1, str1_length);
	// ft_strlcpy(dest + str1_length, str2, str2_length);
	*(dest + str1_length + str2_length) = '\0';
	free(str1);
	return (dest);
}
