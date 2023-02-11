/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:13:50 by arcarval          #+#    #+#             */
/*   Updated: 2023/02/10 20:47:56 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	free(empty_str);
	return (NULL);
}

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

int	ft_strlcpy(char *dest, char const *src, int size)
{
	int	index;

	index = 0;
	if (size <= 0)
	{
		free(dest);
		dest = NULL;
		return (0);
	}
	while (src[index] && (index < size - 1))
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (index);
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
	ft_strlcpy(dest, str1, str1_length + 1);
	ft_strlcpy(dest + str1_length, str2, str2_length + 1);
	free(str1);
	return (dest);
}
