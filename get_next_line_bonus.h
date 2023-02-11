/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:14:17 by arcarval          #+#    #+#             */
/*   Updated: 2023/02/10 20:53:43 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int file_descriptor);

void	*ft_calloc(size_t number_spaces, size_t size);
char	*ft_strchr(char const *str, int caracter);
int		ft_strlcpy(char *dest, char const *src, int size);
int		ft_strlen(char const *str);
char	*ft_strjoin(char *str1, char *str2);

#endif