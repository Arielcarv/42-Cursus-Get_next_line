/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:14:17 by arcarval          #+#    #+#             */
/*   Updated: 2023/01/28 11:40:13 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int file_descriptor);

#endif